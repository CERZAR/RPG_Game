
#include "../Headers/Random.h"
#include <stdlib.h>
#include <ctime>
int GenerateRandomInt(int max) {
  uint *s = new uint;
  *s = (uint)time(0);
  int randomNumber = rand_r(s);
  float random = randomNumber % max + 1;
  int myRandom = random;
  return myRandom;
}

float GenerateRandomFloat(float min, float max) {
  uint *s = new uint;
  *s = (uint)time(0);
  float f = (float)rand_r(s) / RAND_MAX;
  return min + f * (max - min);
}

int GenerateRandomInt0(int max) {
  uint *s = new uint;
  *s = (uint)time(0);
  int randomNumber = rand_r(s);
  float random = randomNumber % max;
  int myRandom = random;
  return myRandom;
}
