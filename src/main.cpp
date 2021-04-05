// Copyright 2021 LongaBonga

#include <ctime>
#include <iostream>
#include <string>

#include "train.h"

int main() {
  Train Train;
  for (size_t i = 0; i < 42; ++i) {
    Cage* cgtmp = new Cage();
    cgtmp->setLight();
    Train.addCage(cgtmp);
  }
  Train.printInfo();
  std::cout << Train.length() << std::endl;
  return 0;
}
