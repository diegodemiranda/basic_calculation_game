#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// prototype of the object
typedef struct {
  int difficult;
  float firstValue;
  float secondValue;
  int operation;
  float result;
} calc;

// functions prototypes
//  start the game
void play();
// select the difficult
void difficult(calc calculation);
// show infos about configuration
void settings(calc calculation);
// select the operation
int operation(float answer, calc calculation);
// replay or not the game
void replay();

// global variable
int score = 0;

// main function
int main() {
  srand(time(NULL));
  play();
  return 0;
};