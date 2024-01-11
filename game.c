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
// start the game
void play();
// select the difficult
void difficult(calc calculation);
// select the operation
int account(float answer, calc calculation);
// performs the operation
int operation(float answer, calc calculation);
// replay or not the game
void replay();
// show infos about configuration
void settings(calc calculation);

// global variable
int score = 0;
float answer;

// main function
int main() {
  srand(time(NULL));
  play();
  return 0;
}

// implementation of the functions
void play() {
  calc calculation;
  difficult(calculation);
  operation(answer, calculation);
  replay();
}

void difficult(calc calculation) {
  printf("Select the difficult level do you want (1 - easy, 2 - normal, 3 - hard, 4 - very hard):\n");
  scanf("%d", &calculation.difficult);
  if (calculation.difficult >= 1 && calculation.difficult <= 4) {
    switch (calculation.difficult) {
    case 1:
      calculation.firstValue = rand() % 11;
      calculation.secondValue = rand() % 11;
      break;
    case 2:
      calculation.firstValue = rand() % 101;
      calculation.secondValue = rand() % 101;
      break;
    case 3:
      calculation.firstValue = rand() % 1001;
      calculation.secondValue = rand() % 1001;
      break;
    case 4:
      calculation.firstValue = rand() % 10001;
      calculation.secondValue = rand() % 10001;
      break;
    }
  } else {
    printf("Invalid operation.\n Chose between: 1 - easy, 2 - normal, 3 - hard, 4 - very hard.\n");
    difficult(calculation);
  }
  account(answer, calculation);
}

int account(float answer, calc calculation) {
  calculation.operation = rand() % 4;
  settings(calculation);

  printf("What is the result for the following mathematical operation?\n");
  if (calculation.operation == 1) {
    printf("%.1f + %.1f = ", calculation.firstValue, calculation.secondValue);
    scanf("%f", &answer);
    if (operation(answer, calculation)) {
      score += 1;
      printf("You earned %d point(s).\n", score);
    }
  } else if (calculation.operation == 2) {
    printf("%.1f - %.1f = ", calculation.firstValue, calculation.secondValue);
    scanf("%f", &answer);
    if (operation(answer, calculation)) {
      score += 1;
      printf("You earned %d point(s).\n", score);
    }
  } else if (calculation.operation == 3) {
    printf("%.1f * %.1f = ", calculation.firstValue, calculation.secondValue);
    scanf("%f", &answer);
    if (operation(answer, calculation)) {
      score += 1;
      printf("You earned %d point(s).\n", score);
    }
  } else if (calculation.operation == 4) {
    printf("%.1f / %.1f = ", calculation.firstValue, calculation.secondValue);
    scanf("%f", &answer);
    if (operation(answer, calculation)) {
      score += 1;
      printf("You earned %d point(s).\n", score);
    }
  }
  return 0;
}

void replay() {
  char option;
  printf("Do you want to continue? y (yes), n (no)\n");
  option = getchar();
  if ((option = getchar()) != '\n' && option != EOF) {
    if (option == 'y') {
      play();
    } else if (option == 'n') {
      printf("You ended with %d point(s).", score);
      exit(0);
    }
  }
}

int operation(float answer, calc calculation) {
  if (calculation.operation == 1) {
    calculation.result = calculation.firstValue + calculation.secondValue;
    if (answer == calculation.result) {
      printf("You are right!\n");
      return 1;
    } else {
      printf("You are wrong!\n");
      return 0;
    }
    printf("%.1f + %.1f = %.1f\n", calculation.firstValue, calculation.secondValue, calculation.result);
  }
  if (calculation.operation == 2) {
    calculation.result = calculation.firstValue - calculation.secondValue;
    if (answer == calculation.result) {
      printf("You are right!\n");
      return 1;
    } else {
      printf("You are wrong!\n");
      return 0;
    }
    printf("%.1f - %.1f = %.1f\n", calculation.firstValue, calculation.secondValue, calculation.result);
  }
  if (calculation.operation == 3) {
    calculation.result = calculation.firstValue * calculation.secondValue;
    if (answer == calculation.result) {
      printf("You are right!\n");
      return 1;
    } else {
      printf("You are wrong!\n");
      return 0;
    }
    printf("%.1f * %.1f = %.1f\n", calculation.firstValue, calculation.secondValue, calculation.result);
  }
  if (calculation.operation == 4) {
    calculation.result = calculation.firstValue / calculation.secondValue;
    if (answer == calculation.result) {
      printf("You are right!\n");
      return 1;
    } else {
      printf("You are wrong!\n");
      return 0;
    }
    printf("%.1f / %.1f = %.1f\n", calculation.firstValue, calculation.secondValue, calculation.result);
  }
  return 0;
}

// show selected parameters
void settings(calc calculation) {
  // format the difficult output
  char difficult[20];
  if (calculation.operation == 1) {
    sprintf(difficult, "easy\n");
  } else if (calculation.operation == 2) {
    sprintf(difficult, "normal\n");
  } else if (calculation.operation == 3) {
    sprintf(difficult, "hard\n");
  } else if (calculation.operation == 4) {
    sprintf(difficult, "very hard\n");
  }
  // format the operation output
  char operation[20];
  if (calculation.operation == 1) {
    sprintf(operation, "addition\n");
  } else if (calculation.operation == 2) {
    sprintf(operation, "subtraction\n");
  } else if (calculation.operation == 3) {
    sprintf(operation, "multiplication\n");
  } else if (calculation.operation == 4) {
    sprintf(operation, "division\n");
  }
  printf("First value: %.1f \nSecond value: %.1f \nDifficult: %s \nOperation: %s\n",
        calculation.firstValue, calculation.secondValue, difficult, operation);
}
