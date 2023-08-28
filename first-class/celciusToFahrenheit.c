#include <stdio.h>

int main() {
  float degreesCelcius, degreesFahrenheit;

  scanf("%f", &degreesCelcius);

  degreesFahrenheit = ((1.8 * degreesCelcius) + 32);

  printf("%.0f ", degreesFahrenheit);

  return 0;
}