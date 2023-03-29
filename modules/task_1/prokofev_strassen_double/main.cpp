// Copyright 2023 Prokofev Denis
#include <gtest/gtest.h>
#include <../../../modules/task_1/prokofev_strassen_double/strassen_double.h>
#include <vector>


TEST(int_test, int_test) {
    std::vector<double> a = { 1.0, 2.0, 3.0, 4.0 };
    std::vector<double> b = { 1.0, 2.0, 3.0, 4.0 };
    std::vector<double> c = { 7.0, 10.0, 15.0, 22.0 };

    EXPECT_EQ(sMult(a,b),c);
}

TEST(seqSobelFilter, randMatrixWithNullSize) {
    ASSERT_ANY_THROW(randImage(0, 0));
}

TEST(seqSobelFilter, emptyMatrix) {
    ASSERT_ANY_THROW(image<uint8_t>(0, 0));
}

TEST(seqSobelFilter, sobelNoThrow) {
    auto img = randImage(5, 5);
    ASSERT_NO_THROW(sobelSequence(img));
}

TEST(seqSobelFilter, sobelChangeMatrix) {
    auto img = randImage(5, 5);
    auto res = sobelSequence(img);
    ASSERT_EQ(img._columns, res._columns);
    ASSERT_EQ(img._rows, res._rows);
    ASSERT_NE(img._matrix, res._matrix);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}