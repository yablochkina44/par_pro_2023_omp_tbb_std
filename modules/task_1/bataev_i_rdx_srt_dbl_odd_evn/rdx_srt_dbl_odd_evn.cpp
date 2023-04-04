// Copyright 2023 Bataev Ivan
#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include "../../../modules/task_1/bataev_i_rdx_srt_dbl_odd_evn/rdx_srt_dbl_odd_evn.h"

using std::uint8_t;
using std::uint64_t;

void srtRdx(std::vector<uint64_t>& inBuf, std::vector<uint64_t>& outBuf, const int size, const int shift, int* countBytes, int* offsets, const int pass) {
    std::memset(countBytes, 0, 256*sizeof(int));
    for (int i = 0; i < size; i++) {
        uint8_t rdxVal = (inBuf[shift + i] >> (pass << 3)) & 0xFF;
        countBytes[rdxVal]++;
    }

    offsets[0] = 0;
    for (int i = 1; i < 256; i++)
        offsets[i] = offsets[i - 1] + countBytes[i - 1];

    for (int i = 0; i < size; i++) {
        uint8_t rdxVal = (inBuf[shift + i] >> (pass << 3)) & 0xFF;
        outBuf[shift + offsets[rdxVal]++] = inBuf[shift + i];
        // increment to keep correct order when identical byte
    }
}

void srtLastRdx(std::vector<uint64_t>& inBuf, std::vector<uint64_t>& outBuf, const int size, const int shift, int* countBytes, int* offsets) {
    std::memset(countBytes, 0, 256*sizeof(int));
    for (int i = 0; i < size; i++) {
        uint8_t rdxVal = (inBuf[shift + i] >> 56) & 0xFF;
        countBytes[rdxVal]++;
    }

    int countNegatives = 0;
    for (int i = 128; i < 256; i++) {
        countNegatives += countBytes[i];
    }
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
        uint8_t rdxVal = (inBuf[shift + i] >> 56) & 0xFF;
        if (rdxVal < 128)  // for positive numbers 
            outBuf[shift + offsets[rdxVal]++] = inBuf[shift + i];
        else  // for negative numbers
            outBuf[shift + --offsets[rdxVal]] = inBuf[shift + i];
    }
}

void srtRdx(std::vector<uint8_t>& inBuf, std::vector<uint8_t>& outBuf, const int sizeBuf, const int shiftBuf, int* countBytes, int* offsets, const int pass) {
    const int dblBytes = sizeof(double);
    std::memset(countBytes, 0, 256*sizeof(int));
    for (int i = pass; i < sizeBuf; i+=dblBytes) {
        uint8_t rdxVal = inBuf[shiftBuf + i];
        countBytes[rdxVal]++;
    }

    offsets[0] = 0;
    for (int i = 1; i < 256; i++)
        offsets[i] = offsets[i - 1] + countBytes[i - 1];

    for (int i = pass; i < sizeBuf; i+=dblBytes) {
        uint8_t rdxVal = inBuf[shiftBuf + i];
        //std::cout << (int)rdxVal << " and " << dblBytes*(offsets[rdxVal]) << " and " << dblBytes*(i / dblBytes);
        std::memcpy(outBuf.data() + shiftBuf + dblBytes*(offsets[rdxVal]++), inBuf.data() + shiftBuf + dblBytes*(i / dblBytes), dblBytes);
        //std::cout << "\n";
    }
}

void srtLastRdx(std::vector<uint8_t>& inBuf, std::vector<uint8_t>& outBuf, const int sizeBuf, const int shiftBuf, int* countBytes, int* offsets, const int pass) {
    const int dblBytes = sizeof(double);
    std::memset(countBytes, 0, 256*sizeof(int));
    for (int i = pass; i < sizeBuf; i+=dblBytes) {
        uint8_t radix = inBuf[shiftBuf + i];
        countBytes[radix]++;
    }

    int countNegatives = 0;
    for (int i = 128; i < 256; i++) {
        countNegatives += countBytes[i];
    }
    offsets[0] = countNegatives;
    offsets[255] = 0;
    for (int i = 1; i < 128; i++) {
        offsets[i] = offsets[i - 1] + countBytes[i - 1];
        offsets[255 - i] = offsets[256 - i] + countBytes[256 - i];
    }
    for (int i = 128; i < 256; i++)
        offsets[i] += countBytes[i];

    for (int i = pass; i < sizeBuf; i+=dblBytes) {
        uint8_t radix = inBuf[shiftBuf + i];
        if (radix < 128)
            std::memcpy(outBuf.data() + shiftBuf + dblBytes*(offsets[radix]++), inBuf.data() + shiftBuf + dblBytes*(i / dblBytes), dblBytes);
        else
            std::memcpy(outBuf.data() + shiftBuf + dblBytes*(--offsets[radix]), inBuf.data() + shiftBuf + dblBytes*(i / dblBytes), dblBytes);
    }
}

void dblRdxSrt(std::vector<uint64_t>& buf, std::vector<uint64_t>& tmpBuf, const int size, const int shift) {
    int countBytes[256];
    int offsets[256];

    for (int pass = 0; pass < 7; pass++) {
        if (pass % 2)
            srtRdx(tmpBuf, buf, size, shift, countBytes, offsets, pass);
        else
            srtRdx(buf, tmpBuf, size, shift, countBytes, offsets, pass);
    }

    // the last pass = 7
    srtLastRdx(tmpBuf, buf, size, shift, countBytes, offsets);
}

void dblRdxSrt(std::vector<uint8_t>& buf, std::vector<uint8_t>& tmpBuf, const int sizeBuf, const int shiftBuf) {
    const int dblBytes = sizeof(double);
    int countBytes[256];
    int offsets[256];

    // #include <bitset>
    // std::bitset<8> out[dblBytes*6];
    // for (int i = 0; i < sizeBuf; ++i)
    //     out[i] = buf[i];
    // for (int i = 0; i < sizeBuf; ++i) {
    //     std::cout << out[i] << ", ";
    //     if ((i+1)%dblBytes == 0)
    //         std::cout << "\n";
    // }
    // // for uint8_t reverse order of bytes (aka: little endian) (why?!) (this is taken into account in the code)
    // // 00000000, 00000000, 00000000, 00000000, 01110000, 11011011, 00011011, 11000001,
    // // 00000000, 00000000, 00000000, 00000000, 00010000, 11011111, 01000001, 01000001,
    // // 00000000, 00000000, 00000000, 00000000, 01110000, 01010111, 00010100, 01000001,
    // // 00000000, 00000000, 00000000, 00000000, 00000000, 00000000, 00100110, 11000000,
    // // 00000000, 00000000, 00000000, 00000000, 00000000, 10001100, 10011111, 11000000,
    // // 00000000, 00000000, 00000000, 00000000, 10000000, 10110100, 11000101, 01000000,
    // // while for uint64_t normal order of bytes (IEEE 754):
    // // 1100000100011011110110110111000000000000000000000000000000000000 (the 1-st elem)

    int pass;
    for (pass = 0; pass < dblBytes - 1; pass++) {
        if (pass % 2)
            srtRdx(tmpBuf, buf, sizeBuf, shiftBuf, countBytes, offsets, pass);
        else
            srtRdx(buf, tmpBuf, sizeBuf, shiftBuf, countBytes, offsets, pass);
    }

    // the last pass
    pass = dblBytes - 1;
    if (pass % 2) {
        srtLastRdx(tmpBuf, buf, sizeBuf, shiftBuf, countBytes, offsets, pass);
    } else {
        srtLastRdx(buf, tmpBuf, sizeBuf, shiftBuf, countBytes, offsets, pass);
        std::copy_n(tmpBuf.begin() + shiftBuf, sizeBuf, buf.begin() + shiftBuf);
    }
}

void oddEvnMrg(std::vector<double>& inBuf, std::vector<double>& outBuf, const int size) {

}

void seqRdxSrt(std::vector<double>& buf, const int size, const int parts) {
    std::vector<double> tmpBuf(buf);

    int lSize = size/parts;
    int shift;
    if (sizeof(double) == sizeof(uint64_t)) {
        for (shift = 0; shift < parts - 1; shift += size/parts)
            dblRdxSrt(*reinterpret_cast<std::vector<uint64_t>*>(&buf), *reinterpret_cast<std::vector<uint64_t>*>(&tmpBuf), lSize, shift);
        lSize += size%parts;
        dblRdxSrt(*reinterpret_cast<std::vector<uint64_t>*>(&buf), *reinterpret_cast<std::vector<uint64_t>*>(&tmpBuf), lSize, shift);
    } else {
        for (shift = 0; shift < parts - 1; shift += size/parts)
            dblRdxSrt(*reinterpret_cast<std::vector<uint8_t>*>(&buf), *reinterpret_cast<std::vector<uint8_t>*>(&tmpBuf), lSize*sizeof(double), shift*sizeof(double));
        lSize += size%parts;
        dblRdxSrt(*reinterpret_cast<std::vector<uint8_t>*>(&buf), *reinterpret_cast<std::vector<uint8_t>*>(&tmpBuf), lSize*sizeof(double), shift*sizeof(double));
    }

    //oddEvnMrg(buf, tmpBuf, size);
}


// for (int p = 1; p < size; p += p)
//     for (int k = p; k >= 1; k /= 2)
//         for (int j = k%p; j < (n-1-k); j += 2k)
//             for (int i = 0; i < k-1; i++)
//                 if (((i+j) / (p*2)) == ((i+j+k) / (p*2)))
//                     if (a[l + j + i] > a[l + j + i + k])
//                         exch(a, l + j + i, l + j + i + k);