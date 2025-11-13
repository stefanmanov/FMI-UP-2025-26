#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_ARRAY_SIZE 1000u


unsigned readNUpTo(unsigned limit)
{
  printf("Enter a natural number N <= %u:\t", limit);
  unsigned n = 0u;
  scanf("%u", &n);
  while (n > limit) {
    fprintf(stderr, "%u > %u; try again:\t", n, limit);
    scanf("%u", &n);
  }
  return n;
}

void inputIntArray(int arr[], unsigned size)
{
  printf("Enter %u integers:\n", size);
  for (unsigned i = 0u; i < size; ++i) {
    scanf("%d", arr+i);
  }
}

void inputDoubleArray(double arr[], unsigned size)
{
  printf("Enter %u real numbers:\n", size);
  for (unsigned i = 0u; i < size; ++i) {
    scanf("%lf", arr+i);
  }
}

/*----------------------------------------------------------------------------*/

void task2(void)
{
  double numbers[MAX_ARRAY_SIZE] = {0.0};
  unsigned n = readNUpTo(MAX_ARRAY_SIZE);
  inputDoubleArray(numbers, n);

  double average = 0.0;
  for (unsigned i = 0u; i < n; ++i) {
    average += (numbers[i] / n);
  }
  printf("Their average is %lf.\n", average);

  unsigned bestIndex = 0u;
  double bestDifference = fabs(numbers[0] - average);
  for (unsigned i = 1u; i < n; ++i) {
    if (fabs(numbers[i] - average) < bestDifference) {
      bestIndex = i;
      bestDifference = fabs(numbers[i] - average);
    }
  }
  printf("The entered number closest to it is %lf.\n", numbers[bestIndex]);
}

/*----------------------------------------------------------------------------*/

void printInReverse(const int numbers[], unsigned count)
{
  for (int i = count - 1; i >= 0; --i) {
    printf("%d ", numbers[i]);
  }
  printf("\n");
}

void printEven(const int numbers[], unsigned count)
{
  for (unsigned i = 0; i < count; ++i) {
    if (numbers[i] % 2 == 0) {
      printf("%d ", numbers[i]);
    }
  }
  printf("\n");
}

const unsigned NOT_FOUND = -1;
// Returns the index of the smallest of the first `count` elements of `numbers`.
// Returns `NOT_FOUND` if `count == 0`.
unsigned findSmallest(const int numbers[], unsigned count)
{
  if (count == 0) {
    return NOT_FOUND;
  }

  unsigned indexOfSmallest = 0;
  for (unsigned i = 1; i < count; ++i) {
    if (numbers[i] < numbers[indexOfSmallest]) {
      indexOfSmallest = i;
    }
  }
  return indexOfSmallest;
}

void task3(void)
{
  int numbers[MAX_ARRAY_SIZE] = {0};
  unsigned n = readNUpTo(MAX_ARRAY_SIZE);
  inputIntArray(numbers, n);

  printf("The numbers in reverse order are:\n");
  printInReverse(numbers, n);

  printf("The even numbers are:\n");
  printEven(numbers, n);

  unsigned indexOfSmallest = findSmallest(numbers, n);
  if (indexOfSmallest != NOT_FOUND) {
    printf(
      "The smallest of them is %d. Its index is %u.\n",
      numbers[indexOfSmallest], indexOfSmallest
    );
  }
}

/*----------------------------------------------------------------------------*/

unsigned countIn(double what, double where[], unsigned size, double precision)
{
  unsigned result = 0;
  for (unsigned i = 0; i < size; ++i) {
    if (fabs(where[i] - what) < precision) {
      ++result;
    }
  }
  return result;
}

void task4(void)
{
  double numbers[MAX_ARRAY_SIZE] = {0.0};
  unsigned n = readNUpTo(MAX_ARRAY_SIZE);
  inputDoubleArray(numbers, n);

  printf("Enter the number you're looking for:\t");
  double r = 0.0;
  scanf("%lf", &r);

  const double EPSILON = 0.001;
  unsigned count = countIn(r, numbers, n, EPSILON);
  printf("%lf can be found %u times in the array.\n", r, count);
}

/*----------------------------------------------------------------------------*/

// Returns 0 if `sequence` is zigzag-growing.
// Otherwise, returns the index of the first member of `sequence`
// that breaks its "zigzag-growing" property.
unsigned checkZigzagGrowing(int sequence[], unsigned size)
{
  for (unsigned i = 0; i < size; ++i) {
    if (i % 2 == 1) {
      if (sequence[i] <= sequence[i - 1] ||
          i > 1 && sequence[i] <= sequence[i - 2]) {
        return i;
      }
    } else { // (i % 2 == 0)
      if (i > 0 && sequence[i] >= sequence[i - 1]) {
        return i;
      }
    }
  }
  return 0;
}

void task5(void)
{
  int numbers[MAX_ARRAY_SIZE] = {0};
  unsigned n = readNUpTo(MAX_ARRAY_SIZE);
  inputIntArray(numbers, n);

  unsigned potentiallyBreakingIndex = checkZigzagGrowing(numbers, n);
  if (potentiallyBreakingIndex == 0) {
    printf("The sequence is zigzag-growing.\n");
  } else {
    printf("The sequence is not zigzag-growing; the first index that breaks ");
    printf("the property is %u.\n", potentiallyBreakingIndex);
  }
}

/*----------------------------------------------------------------------------*/

void constructPrimesTable(bool primesTable[], unsigned size)
{
  primesTable[0] = primesTable[1] = false;
  for (unsigned i = 2; i < size; ++i) {
    // Assume every other number is prime until proven otherwise.
    primesTable[i] = true;
  }

  for (unsigned i = 2; i < sqrt(size); ++i) {
    if (primesTable[i]) {
      // Mark all multiples of i as not prime.
      for (unsigned j = i * i; j < size; j += i) {
        primesTable[j] = false;
      }
    }
  }
}

#define PRIMES_TABLE_SIZE 10001

void task6(void)
{
  bool primesTable[PRIMES_TABLE_SIZE] = {false};
  constructPrimesTable(primesTable, PRIMES_TABLE_SIZE);

  unsigned n = readNUpTo(PRIMES_TABLE_SIZE - 1);
  unsigned m = readNUpTo(PRIMES_TABLE_SIZE - 1);

  printf("%u is %sprime.\n", n, (primesTable[n] ? "" : "not "));
  printf("%u is %sprime.\n", m, (primesTable[m] ? "" : "not "));
}

/*----------------------------------------------------------------------------*/

void task7(void)
{
  unsigned numbers[MAX_ARRAY_SIZE] = {0};
  unsigned n = readNUpTo(MAX_ARRAY_SIZE);

  printf("Now enter %u natural numbers < %u:\n",n, PRIMES_TABLE_SIZE);
  for (unsigned i = 0; i < n; ++i) {
    scanf("%u", numbers+i);
  }

  bool primesTable[PRIMES_TABLE_SIZE] = {false};
  constructPrimesTable(primesTable, PRIMES_TABLE_SIZE);

  for (unsigned i = 0; i < n; ++i) {
    unsigned element = numbers[i];
    printf("%u is %sprime.\n", element, (primesTable[element] ? "" : "not "));
  }
}

/*----------------------------------------------------------------------------*/

int main(void)
{
  printf("\nTask 2\n");
  task2();

  printf("\nTask 3\n");
  task3();

  printf("\nTask 4\n");
  task4();

  printf("\nTask 5\n");
  task5();

  printf("\nTask 6\n");
  task6();

  printf("\nTask 7\n");
  task7();

  return 0;
}
