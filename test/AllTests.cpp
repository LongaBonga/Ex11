// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(Train, test1) {
    Train train;
    const size_t n = 30;
    for (size_t i = 0; i < n; ++i) {
        Cage* cage = new Cage();
        train.addCage(cage);
     }
    EXPECT_EQ(n, train.length());
}

TEST(Train, test2) {
    Train train;
    const size_t n = 30;
    for (size_t i = 0; i < n; ++i) {
        Cage* cage = new Cage();
        train.addCage(cage);
     }

     for (size_t i = 0; i < 2 * n; ++i) {
         Cage* cage = new Cage();
         train.addCage(cage);
      }
    EXPECT_EQ(3 * n, train.length());
}

TEST(Train, test1) {
    Train train;
    Cage* cage = new Cage();
    train.addCage(cage);

    EXPECT_EQ(1, train.length());
}
