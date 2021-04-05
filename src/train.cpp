// Copyright 2021 LongaBonga

#include "train.h"
#include <iostream>

void Cage::setLight() { std::rand() % 2 == 0 ? this->on() : this->off(); }

void Cage::changeLight() { light = !light; }

Train::Train() {
  this->first = nullptr;
  this->last = nullptr;
}

void Train::addCage(Cage* _cage) {
  if (!first && !last) {
    first = _cage;
    last = _cage;
    first->prev = last;
    last->next = first;
    return;
  }
  last->next = _cage;
  first->prev = _cage;
  _cage->prev = last;
  _cage->next = first;
  last = _cage;
}

void Train::printInfo() {
  Cage* ptr = first;
  unsigned int cnt = 0;
  while (ptr != first->prev) {
    std::cout << cnt << ":" << ((ptr->getCurStatus()) ? ("on") : ("off"))
              << std::endl;
    ++cnt;
    ptr = ptr->next;
  }
  std::cout << cnt << ":" << (ptr->getCurStatus() ? ("on") : ("off"))
            << std::endl;
}

unsigned Train::length() {
  if (first == nullptr) {
    return 0;
  }
  unsigned length;
  bool startCur = first->getCurStatus();
  unsigned counter = 0;
  Cage* ptr = first;
  first->off();
  while (true) {
    ptr = ptr->next;
    counter++;
    ptr->changeLight();
    Cage* back = ptr;
    for (size_t i = 0; i < counter; ++i) {
      back = back->prev;
    }
    if (back->getCurStatus() != false) return counter;
  }
}
