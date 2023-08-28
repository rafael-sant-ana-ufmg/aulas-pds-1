#include <stdio.h>

int main() {
  int firstInputtedNumber, secondInputtedNumber, thirdInputtedNumber;

  scanf("%d", &firstInputtedNumber);
  scanf("%d", &secondInputtedNumber);
  scanf("%d", &thirdInputtedNumber);

  if (firstInputtedNumber == secondInputtedNumber &&
      firstInputtedNumber > thirdInputtedNumber) {
    printf("%d", firstInputtedNumber);
  } else if (secondInputtedNumber > thirdInputtedNumber &&
             secondInputtedNumber > firstInputtedNumber) {
    printf("%d", secondInputtedNumber);
  } else if (firstInputtedNumber > secondInputtedNumber &&
             firstInputtedNumber > thirdInputtedNumber) {
    printf("%d", firstInputtedNumber);
  } else if (secondInputtedNumber > firstInputtedNumber &&
             secondInputtedNumber > thirdInputtedNumber) {
    printf("%d", secondInputtedNumber);
  } else {
    printf("%d", thirdInputtedNumber);
  }

  return 0;
}