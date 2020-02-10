// Copyright 2019 CERZAR
#include "../Headers/Random.h"

static unsigned int producerseed = 54321;

int GenerateRandomInt(int max) {
  int randomNumber = rand_r(&producerseed);
  float random = static_cast<float>(randomNumber % max) + 1;
  int myRandom = static_cast<int>(random);
  return myRandom;
}

float GenerateRandomFloat(float min, float max) {
  float f = static_cast<float>(rand_r(&producerseed) / RAND_MAX);
  return min + f * (max - min);
}

int GenerateRandomInt0(int max) {
  int randomNumber = rand_r(&producerseed);
  float random = static_cast<float>(randomNumber % max);
  int myRandom = static_cast<int>(random);
  return myRandom;
}
