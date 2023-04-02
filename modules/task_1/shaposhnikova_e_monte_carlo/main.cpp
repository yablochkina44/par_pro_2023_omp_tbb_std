// Copyright 2023 Shaposhnikova Ekaterina
#include <gtest/gtest.h>
#include "./monte_carlo.h"
#include <gtest-mpi-listener.hpp>

double func(double x, double y, double z) {
  return (x * x + 1) * (x * z + 1) * y * y;
}

TEST(MonteCarloSeq, Test_1) {
  std::vector<double> a{ 0,0,0 };
  std::vector<double> b{ 1,1,1 };
  ASSERT_NO_THROW(MonteCarloSeq(a, b, 20000, func));
}

TEST(MonteCarloSeq, Test_2) {
  std::vector<double> a{ 0,0,0 };
  std::vector<double> b{ 1,1,1 };
  ASSERT_NEAR(MonteCarloSeq(a, b, 20000, func), 0.57, 0.1);
}

TEST(MonteCarloSeq, Test_3) {
  std::vector<double> a{ 1,1,1 };
  std::vector<double> b{ 5,5,5 };
  ASSERT_NO_THROW(MonteCarloSeq(a, b, 20000, func));
}

TEST(MonteCarloSeq, Test_4) {
  std::vector<double> a{ 1,1,1 };
  std::vector<double> b{ 5,5,5 };
  ASSERT_NEAR(MonteCarloSeq(a, b, 20000, func), 0.57, 0.1);
}

TEST(MonteCarloSeq, Test_5) {
  std::vector<double> a{ 3,3,3 };
  std::vector<double> b{ 6,6,6 };
  ASSERT_NO_THROW(MonteCarloSeq(a, b, 20000, func));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  MPI_Init(&argc, &argv);

  ::testing::AddGlobalTestEnvironment(new GTestMPIListener::MPIEnvironment);
  ::testing::TestEventListeners& listeners =
    ::testing::UnitTest::GetInstance()->listeners();

  listeners.Release(listeners.default_result_printer());
  listeners.Release(listeners.default_xml_generator());

  listeners.Append(new GTestMPIListener::MPIMinimalistPrinter);
  return RUN_ALL_TESTS();
}
