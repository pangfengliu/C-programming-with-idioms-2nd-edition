typedef struct number {
  int value;
  int bit;
} Number;

#define ARRAYSIZE 1000

typedef struct numberSet {
  Number numbers[ARRAYSIZE];
  int count;
} NumberSet;

