// Copyright 2021 LongaBonga

#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Cage {
 private:
  bool light;

 public:
  Cage* next;
  Cage* prev;
  Cage() : light(false), next(nullptr), prev(nullptr) {}
  void on() { light = true; }
  void off() { light = false; }
  bool getCurStatus() const { return light; }
  void setLight();
  void changeLight();
};

class Train {
 private:
  Cage* first = nullptr;
  Cage* last = nullptr;

 public:
  Train();
  void addCage(Cage* _cage);
  void printInfo();
  unsigned length();
};

#endif  //  INCLUDE_TRAIN_H_
