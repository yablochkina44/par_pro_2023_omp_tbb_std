// Copyright 2023 Bataev Ivan
#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <utility>
#include <string>
#include <limits>
#include <random>
#include <cstring>
#include "../../../modules/task_1/bataev_i_rdx_srt_dbl_odd_evn/rdx_srt_dbl_odd_evn.h"

using std::uint8_t;
using std::uint64_t;

void printVector(const std::vector<double>& v, const std::string& prefix) {
    std::cout << prefix << "[";
    for (int i = 0; i < v.size() - 1; i++) { std::cout << v[i] << ", "; }
    std::cout << v[v.size() - 1] << "]\n";
}

std::vector<double> getRandomVector(int size, double left, double right) {
    std::random_device rd;
    std::mt19937 mersenne(rd());
    std::uniform_real_distribution<double> distr(left, right);

    std::vector<double> v(size);
    for (auto& elem : v) { elem = distr(mersenne); }
    return v;
}

void dblRdxSrt(uint64_t* inOutBuf, uint64_t* tmpBuf, const int size) {
    uint64_t* inBuf = inOutBuf;
    uint64_t* outBuf = tmpBuf;
    int countBytes[256];
    int offsets[256];

    for (int pass = 0; pass < 7; pass++) {
        // count number of each byte in input buffer
        std::memset(countBytes, 0, 256*sizeof(int));
        for (int i = 0; i < size; i++) {
            uint8_t rdxVal = (inBuf[i] >> (pass << 3)) & 0xFF;
            countBytes[rdxVal]++;
        }

        // calc index offsets in output buffer for each byte
        offsets[0] = 0;
        for (int i = 1; i < 256; i++)
            offsets[i] = offsets[i - 1] + countBytes[i - 1];

        for (int i = 0; i < size; i++) {
            uint8_t rdxVal = (inBuf[i] >> (pass << 3)) & 0xFF;
            outBuf[offsets[rdxVal]++] = inBuf[i];
            // increment to keep correct order when identical byte
        }

        std::swap(inBuf, outBuf);  // swap ptrs
    }

    // the last pass = 7
    std::memset(countBytes, 0, 256*sizeof(int));
    for (int i = 0; i < size; i++) {
        uint8_t rdxVal = (inBuf[i] >> 56) & 0xFF;
        countBytes[rdxVal]++;
    }

    int countNegatives = 0;
    for (int i = 128; i < 256; i++)
        countNegatives += countBytes[i];
    offsets[0] = countNegatives;
    offsets[255] = 0;
    for (int i = 1; i < 128; i++) {
        offsets[i] = offsets[i - 1] + countBytes[i - 1];  // for positive numbers
        offsets[255 - i] = offsets[256 - i] + countBytes[256 - i];  // for negative numbers
    }
    for (int i = 128; i < 256; i++)
        offsets[i] += countBytes[i];
    // for negative numbers to keep correct order when identical byte
    // (+ prefix decrement below)

    for (int i = 0; i < size; i++) {
        uint8_t rdxVal = (inBuf[i] >> 56) & 0xFF;
        if (rdxVal < 128)  // for positive numbers
            outBuf[offsets[rdxVal]++] = inBuf[i];
        else  // for negative numbers
            outBuf[--offsets[rdxVal]] = inBuf[i];
    }
}

void dblRdxSrt(uint8_t* inOutBuf, uint8_t* tmpBuf, const int sizeBuf) {
    uint8_t* inBuf = inOutBuf;
    uint8_t* outBuf = tmpBuf;
    const int dblBytes = sizeof(double);
    int countBytes[256];
    int offsets[256];

    int pass;
    for (pass = 0; pass < dblBytes - 1; pass++) {
        std::memset(countBytes, 0, 256*sizeof(int));
        for (int i = 0; i < sizeBuf; i+=dblBytes) {
            uint8_t rdxVal = inBuf[i + pass];
            countBytes[rdxVal]++;
        }

        offsets[0] = 0;
        for (int i = 1; i < 256; i++)
            offsets[i] = offsets[i - 1] + countBytes[i - 1];

        for (int i = 0; i < sizeBuf; i+=dblBytes) {
            uint8_t rdxVal = inBuf[i + pass];
            std::memcpy(outBuf + dblBytes*(offsets[rdxVal]++), inBuf + i, dblBytes);
        }

        std::swap(inBuf, outBuf);  // swap ptrs
    }

    // the last pass
    pass = dblBytes - 1;
    std::memset(countBytes, 0, 256*sizeof(int));
    for (int i = 0; i < sizeBuf; i+=dblBytes) {
        uint8_t rdxVal = inBuf[i + pass];
        countBytes[rdxVal]++;
    }

    int countNegatives = 0;
    for (int i = 128; i < 256; i++)
        countNegatives += countBytes[i];
    offsets[0] = countNegatives;
    offsets[255] = 0;
    for (int i = 1; i < 128; i++) {
        offsets[i] = offsets[i - 1] + countBytes[i - 1];
        offsets[255 - i] = offsets[256 - i] + countBytes[256 - i];
    }
    for (int i = 128; i < 256; i++)
        offsets[i] += countBytes[i];

    for (int i = 0; i < sizeBuf; i+=dblBytes) {
        uint8_t rdxVal = inBuf[i + pass];
        if (rdxVal < 128)
            std::memcpy(outBuf + dblBytes*(offsets[rdxVal]++), inBuf + i, dblBytes);
        else
            std::memcpy(outBuf + dblBytes*(--offsets[rdxVal]), inBuf + i, dblBytes);
    }

    // if result is in tmpBuf copy it to inOutBuf
    if (pass%2 == 0)
        std::memcpy(inOutBuf, tmpBuf, sizeBuf);
}

// pair of parts for compare-exchange
struct Comparator {
    int part1;
    int part2;
};

void printVector(const std::vector<Comparator>& v, const std::string& prefix) {
    if (v.size() == 0) { return; }
    std::cout << prefix << "[";
    for (int i = 0; i < v.size() - 1; i++)
        std::cout << "(" << v[i].part1 << ", " << v[i].part2 << "), ";
    std::cout << "(" << v[v.size() - 1].part1 << ", " << v[v.size() - 1].part2 << ")]\n";
}

void mrgNets(const std::vector<int>& partsUp, const std::vector<int>& partsDown, std::vector<Comparator>* comprtrs) {
    size_t sumSize = partsUp.size() + partsDown.size();  // n + m
    if (sumSize == 1) {  // network is empty
        return;
    } else if (sumSize == 2) {  // network contains only one comparator
        (*comprtrs).push_back({ partsUp[0], partsDown[0] });
        return;
    }

    std::vector<int> partsUpOdd;
    std::vector<int> partsUpEven;
    for (int i = 0; i < partsUp.size(); i++) {
        if (i % 2)
            partsUpEven.push_back(partsUp[i]);
        else
            partsUpOdd.push_back(partsUp[i]);
    }
    std::vector<int> partsDownOdd;
    std::vector<int> partsDownEven;
    for (int i = 0; i < partsDown.size(); i++) {
        if (i % 2)
            partsDownEven.push_back(partsDown[i]);
        else
            partsDownOdd.push_back(partsDown[i]);
    }

    mrgNets(partsUpOdd, partsDownOdd, comprtrs);
    mrgNets(partsUpEven, partsDownEven, comprtrs);

    std::vector<int> sumParts(sumSize);
    std::memcpy(sumParts.data(), partsUp.data(), partsUp.size()*sizeof(int));
    std::memcpy(sumParts.data() + partsUp.size(), partsDown.data(), partsDown.size()*sizeof(int));

    for (int i = 1; i + 1 < sumSize; i += 2)
        (*comprtrs).push_back({ sumParts[i], sumParts[i + 1] });
}

void bldNet(const std::vector<int>& parts, std::vector<Comparator>* comprtrs) {
    if (parts.size() == 1)
        return;

    std::vector<int> partsUp(parts.begin(), parts.begin() + parts.size() / 2);
    std::vector<int> partsDown(parts.begin() + parts.size() / 2, parts.end());

    bldNet(partsUp, comprtrs);
    bldNet(partsDown, comprtrs);
    mrgNets(partsUp, partsDown, comprtrs);
}

void compExch(double** bufUp, double** bufDown, double** tmpBufUp, double** tmpBufDown, int lSize) {
    for (int i = 0, j = 0, k = 0; k < lSize; k++) {
        if ((*bufUp)[i] < (*bufDown)[j])
            (*tmpBufUp)[k] = (*bufUp)[i++];
        else
            (*tmpBufUp)[k] = (*bufDown)[j++];
    }

    for (int i = lSize - 1, j = lSize - 1, k = lSize - 1; k >= 0; k--) {
        if ((*bufDown)[i] > (*bufUp)[j])
            (*tmpBufDown)[k] = (*bufDown)[i--];
        else
            (*tmpBufDown)[k] = (*bufUp)[j--];
    }

    // swap ptrs
    std::swap(*tmpBufUp, *bufUp);
    std::swap(*tmpBufDown, *bufDown);
}

void oddEvnMerge(std::vector<double>* buf, std::vector<double>* tmpBuf,
                    std::vector<double*> partsPtrs, std::vector<double*> tmpPartsPtrs, int numParts, int lSize) {
    std::vector<Comparator> comprtrs;
    std::vector<int> parts;
    for (int i = 0; i < numParts; i++)
        parts.push_back(i);

    // build merge network for ordered parts of buffer
    bldNet(parts, &comprtrs);
    // printVector(comprtrs, "");

    // use the network to merge these parts
    for (int i = 0; i < comprtrs.size(); ++i)
        compExch(&(partsPtrs[comprtrs[i].part1]), &(partsPtrs[comprtrs[i].part2]),
                    &(tmpPartsPtrs[comprtrs[i].part1]), &(tmpPartsPtrs[comprtrs[i].part2]), lSize);
    // compare-exchange for each comparator from merge network

    // if partPtr points to tmpBuf copy this part to buf
    for (int i = 0; i < numParts; i++)
        if (partsPtrs[i] != (*buf).data() + i*lSize)
            std::memcpy((*buf).data() + i*lSize, (*tmpBuf).data() + i*lSize, lSize*sizeof(double));
}

void seqRdxSrt(std::vector<double>* buf, int size, const int numParts) {
    // all parts must be the same size for batcher merge
    while ((*buf).size()%numParts)
        (*buf).push_back(std::numeric_limits<double>::max());

    std::vector<double> tmpBuf((*buf).size());

    int lSize = (*buf).size()/numParts;
    std::vector<double*> partsPtrs;
    std::vector<double*> tmpPartsPtrs;
    for (int shift = 0; shift < (*buf).size(); shift += lSize) {
        partsPtrs.push_back((*buf).data() + shift);
        tmpPartsPtrs.push_back(tmpBuf.data() + shift);
    }

    if (sizeof(double) == sizeof(uint64_t)) {
        for (int i = 0; i < numParts; i++)
            dblRdxSrt(reinterpret_cast<uint64_t*&>(partsPtrs[i]),
                        reinterpret_cast<uint64_t*&>(tmpPartsPtrs[i]), lSize);
    } else {  // C++ standard guarantees only a minimum size of double
        for (int i = 0; i < numParts; i++)
            dblRdxSrt(reinterpret_cast<uint8_t*&>(partsPtrs[i]),
                        reinterpret_cast<uint8_t*&>(tmpPartsPtrs[i]), lSize*sizeof(double));
    }
    // printVector(buf);

    oddEvnMerge(buf, &tmpBuf, partsPtrs, tmpPartsPtrs, numParts, lSize);

    while ((*buf).size() - size)
        (*buf).pop_back();
}

