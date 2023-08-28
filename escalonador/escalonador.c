#include <stdio.h>
#include <stdlib.h>

#define matrixRow = 10;
#define matrixColumns = 10;

void logMatrix(int **matrix, int matrixRowsAmount, int matrixColumnsAmount) {
  for (int i = 0; i < matrixRowsAmount; i++) {
    int rowValues[3];
    for (int j = 0; j < matrixColumnsAmount; j++) {
      rowValues[j] = matrix[i][j];
    }

    printf("Linha %d: [%d, %d, %d]\n", i, rowValues[0], rowValues[1], rowValues[2]);
  }
}

void divideRowByEscalar(int escalar, int *row, int matrixRowsAmount) {
  for (int i = 0; i < matrixRowsAmount; i++) {
    if (row[i] == 0) {
      row[i] = 0;
    } else {
      row[i] = (row[i]) / escalar;
    }
  }
}

void addRowsWithEscalarOnFirst(int escalar, int fromRowPosition, int toRowPosition, int **matrix, int matrixRowsAmount) {
  for (int i = 0; i < matrixRowsAmount; i++) {
    matrix[toRowPosition][i] += escalar * (int)(matrix[fromRowPosition][i]);
  }
}

void exchangeRows(int fromRowPosition, int toRowPosition, int **matrix, int matrixColumnsAmount) {
  int *temp = (int*)malloc(matrixColumnsAmount * sizeof(int));
  for (int i = 0; i < matrixColumnsAmount; i++) {
    
    temp[i] = matrix[fromRowPosition][i];
    matrix[fromRowPosition][i] = matrix[toRowPosition][i];
    matrix[toRowPosition][i] = temp[i];
  }
}

int main() {
  int matrixRowsAmount, matrixColumnsAmount;

  matrixRowsAmount = 3;
  matrixColumnsAmount = 3;
  // matrixRowsAmount = 0;
  // matrixColumnsAmount = 0;

  while (matrixRowsAmount <= 0 || matrixColumnsAmount <= 0) {
    printf("Insira a quantidade de linhas (>= 0): ");
    scanf("%d", &matrixRowsAmount);
    printf("\n");
    printf("Insira a quantidade de colunas (>= 0): ");
    scanf("%d", &matrixColumnsAmount);
    printf("\n");
  }

  // para acessar valores de variaveis que sao ponteiros, se faz o casting *.
  // int n1 = 4;
  // int* n2 = &n1;
  // printf("%d", *n2);

  // aponta pra o lugar que vai apontar pra onde tem as listas ( que tem os valores ).
  // matrix = [] -> [., ., ., ., .] e cada . -> [item1, item2, item3];
  int **matrix = (int**)malloc(matrixRowsAmount * sizeof(int));

  for (int i = 0; i < matrixRowsAmount; i++) {
    matrix[i] = (int*)malloc(matrixColumnsAmount * sizeof(int));
    for (int j = 0; j < matrixColumnsAmount; j++) {
      int columnValue;

      printf("Insira o valor na posição i=%d, j=%d : ", i, j);
      scanf("%d", &columnValue);
      printf("\n");
      matrix[i][j] = columnValue;
    }
  }

  int pivotI, pivotJ, nextPivotJPosition;
  pivotI = 0;
  pivotJ = 0;
  
  while (1) {
    // cannot go outside matrix boundaries
    if (pivotI > (matrixRowsAmount - 1) || pivotJ > (matrixColumnsAmount - 1)) {
      break;
    }

    // pivot must be one
    if (matrix[pivotI][pivotJ] != 1) {
      divideRowByEscalar(
        matrix[pivotI][pivotJ],
        matrix[pivotI],
        matrixRowsAmount 
      );
    }

    for (int i = 0; i < matrixRowsAmount; i++) {
      // cannot go outside matrix boundaries
      if (pivotI > (matrixRowsAmount - 1) || pivotJ > (matrixColumnsAmount - 1)) {
        break;
      }

      // elements below pivot must be zero
      if (pivotI != i) {
        int escalar = matrix[i][pivotJ] / matrix[pivotI][pivotJ];
        addRowsWithEscalarOnFirst(-escalar, pivotI, i, matrix, matrixRowsAmount);
      }

    }
    // going to next pivot
    pivotI++;
    while (1) {
      if (pivotI > (matrixRowsAmount-1) || pivotJ > (matrixColumnsAmount-1)) {
        break;
      }

      if ((matrix)[pivotI][pivotJ] == 0) {
        pivotJ++;
      } else {
        break;
      }
    }
  }

  printf("\n--------\n");
  logMatrix(matrix, matrixRowsAmount, matrixColumnsAmount);
}
