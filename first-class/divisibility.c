#include <stdio.h>

int main() {
  int firstInputtedNumber, secondInputtedNumber, thirdInputtedNumber;

  scanf("%d", &firstInputtedNumber);
  scanf("%d", &secondInputtedNumber);
  scanf("%d", &thirdInputtedNumber);

  if (firstInputtedNumber % secondInputtedNumber == 0 &&
      firstInputtedNumber % thirdInputtedNumber == 0) {
    printf("O número é divisível");
  } else {
    printf("O número não é divisível");
  }

  return 0;
}