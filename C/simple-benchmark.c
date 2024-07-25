//
// Created by Djordje Todorovic djolertrk@gmail.com
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Test 1: Prime number calculation.

int x[5] = {0xba, 0xbb, 0xbc, 0xbd, 0xbe};

int p(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int f(int i) { return x[i]; }

void test_1() {
  int sum = 0;
  for (int k = 2; k < 1000000; k++) {
    if (p(k)) {
      sum++;
    }
  }
  printf("Prime count: %d\n", sum);
}

// Test 2: Matrix multiplication.

void test_2() {
  int n = 500;
  int **a = (int **)malloc(n * sizeof(int *));
  int **b = (int **)malloc(n * sizeof(int *));
  int **c = (int **)malloc(n * sizeof(int *));

  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc(n * sizeof(int));
    b[i] = (int *)malloc(n * sizeof(int));
    c[i] = (int *)malloc(n * sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = rand() % 100;
      b[i][j] = rand() % 100;
      c[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  printf("Matrix multiplication completed\n");

  for (int i = 0; i < n; i++) {
    free(a[i]);
    free(b[i]);
    free(c[i]);
  }
  free(a);
  free(b);
  free(c);
}

// Test 3: Sorting algorithm (QuickSort).

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void test_3() {
  int n = 100000;
  int *arr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 1000000;
  }

  quickSort(arr, 0, n - 1);

  printf("QuickSort completed\n");

  free(arr);
}

// Test 4: Fibonacci series (recursive and iterative).

int fib_recursive(int n) {
  if (n <= 1)
    return n;
  return fib_recursive(n - 1) + fib_recursive(n - 2);
}

void test_4() {
  int n = 40; // Limiting to a small number due to exponential growth in
              // recursive calls.
  printf("Fibonacci (recursive) of %d: %d\n", n, fib_recursive(n));
}

void fib_iterative(int n) {
  int *fib = (int *)malloc((n + 1) * sizeof(int));
  fib[0] = 0;
  fib[1] = 1;

  for (int i = 2; i <= n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  printf("Fibonacci (iterative) of %d: %d\n", n, fib[n]);
  free(fib);
}

void test_5() {
  int n = 1000000; // Large number for iterative computation.
  fib_iterative(n);
}

int main() {
  srand(time(0));
  test_1();
  test_2();
  test_3();
  test_4();
  test_5();

  return 0;
}
