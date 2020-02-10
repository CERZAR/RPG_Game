// Copyright 2019 CERZAR
#include "../Headers/Random.h"

int GenerateRandomInt(int max) {
  int randomNumber = rand();
  float random = static_cast<float>(randomNumber % max) + 1;
  int myRandom = static_cast<int>(random);
  return myRandom;
}

float GenerateRandomFloat(float min, float max) {
  float f = (float)rand() / RAND_MAX;
  return min + f * (max - min);
}

int GenerateRandomInt0(int max) {
  int randomNumber = rand();
  float random = static_cast<float>(randomNumber % max);
  int myRandom = static_cast<int>(random);
  return myRandom;
}
