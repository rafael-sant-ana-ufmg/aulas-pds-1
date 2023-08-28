#include <stdio.h>

int main() {
  // R$ 100, R$ 50, R$ 20, R$10, R$ 5, R$ 2 e R$ 1,
  int totalCurrencyAmount, hundred, fifty, twenty, ten, five, two, one;

  scanf("%d", &totalCurrencyAmount);

  hundred = totalCurrencyAmount / 100;
  totalCurrencyAmount -= (hundred * 100);

  fifty = totalCurrencyAmount / 50;
  totalCurrencyAmount -= (fifty * 50);

  twenty = totalCurrencyAmount / 20;
  totalCurrencyAmount -= (twenty * 20);

  ten = totalCurrencyAmount / 10;
  totalCurrencyAmount -= (ten * 10);

  five = totalCurrencyAmount / 5;
  totalCurrencyAmount -= (five * 5);

  two = totalCurrencyAmount / 2;
  totalCurrencyAmount -= (two * 2);

  one = totalCurrencyAmount / 1;
  totalCurrencyAmount -= (one * 1);

  printf("100:%d\n", hundred);
  printf("50:%d\n", fifty);
  printf("20:%d\n", twenty);
  printf("10:%d\n", ten);
  printf("5:%d\n", five);
  printf("2:%d\n", two);
  printf("1:%d\n", one);
  return 0;
}