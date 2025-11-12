#include <math.h>
#include <stdbool.h>
#include <stdio.h>


void task1(void)
{
  printf("Enter the lake's radius:\t");
  double r = 0.0;
  scanf("%lf", &r);

  printf("Enter an octarine lily's area:\t");
  double lilyArea = 0.0;
  scanf("%lf", &lilyArea);

  const double PI = 3.141592;
  const unsigned maximumLilyCount = floor(PI * r * r / lilyArea);

  unsigned currentDayN = 2u;
  unsigned lilyCountN = 1u;
  unsigned lilyCountNMinus1 = 1u;

  while (lilyCountN < maximumLilyCount) {
    ++currentDayN;

    const unsigned newLilyCount = lilyCountNMinus1 + lilyCountN;
    lilyCountNMinus1 = lilyCountN;
    lilyCountN = newLilyCount;
  }

  printf("The Lily lake will be full on Sectober %u\n", currentDayN);
}

/*----------------------------------------------------------------------------*/

bool isPrime(unsigned n)
{
  for (unsigned i = 2u; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void task2(void)
{
  printf("Enter a natural number:\t");
  unsigned n = 0u;
  scanf("%u", &n);

  for (unsigned candidate = 2u; candidate <= n; ++candidate) {
    if (isPrime(candidate)) {
      printf("%u is prime\n", candidate);
    }
  }
}

/*----------------------------------------------------------------------------*/

int findGCD(const int a, const int b)
{
  // Започваме от по-малкото от двете числа.
  int gcd = (a < b) ? a : b;

  while (gcd > 0) {
    // Ако намерим общ делител на двете, спираме и директно го връщаме.
    if (a % gcd == 0 && b % gcd == 0) {
      return gcd;
    }
    gcd--;
  }

  // Иначе единственият им общ делител е 1.
  return 1;
}

void task3(void)
{
  printf("Enter two integers:\t");
  int x = 0, y = 0;
  scanf("%d %d", &x, &y);

  printf("The greatest common denominator of %d and %d is %d\n", x, y, findGCD(x, y));
}

/*----------------------------------------------------------------------------*/

unsigned subBits(unsigned n, unsigned firstBit, unsigned bitsCount)
{
  const unsigned bitMask = (1u << bitsCount) - 1;
  const unsigned bitsToShift = 32 - firstBit - bitsCount;
  return (n >> bitsToShift) & bitMask;
}

bool isPalindrome(unsigned n, unsigned bitGroupSize)
{
  unsigned i = 0;
  unsigned j = 32 - bitGroupSize;
  
  while (i < j) {
    if (subBits(n, i, bitGroupSize) != subBits(n, j, bitGroupSize)) {
      return false;
    }
    i += bitGroupSize;
    j -= bitGroupSize;
  }
  
  return true;
}

void task4(void)
{
  printf("Enter n:\t");
  unsigned n = 0u;
  scanf("%u", &n);

  const bool isPalindromeHex = isPalindrome(n, 4);
  const bool isPalindromeQuad = isPalindrome(n, 2);

  printf("%u is %sa hexadecimal palindrome. It is %sa quaternary palindrome.\n",
    n, (isPalindromeHex? "" : "not "), (isPalindromeQuad? "" : "not "));
}

/*----------------------------------------------------------------------------*/

void printQuaternary(unsigned n)
{
  for (unsigned i = 0; i < 32; i += 2) {
    printf("%u", subBits(n, i, 2));
  }
}

void printHex(unsigned n)
{
  for (unsigned i = 0; i < 32; i += 4) {
    const unsigned currentBits = subBits(n, i, 4);
    switch(currentBits) {
      case 15:
        printf("F");
        break;
      case 14:
        printf("E");
        break;
      case 13:
        printf("D");
        break;
      case 12:
        printf("C");
        break;
      case 11:
        printf("B");
        break;
      case 10:
        printf("A");
        break;
      default:
        printf("%u", currentBits);
    }
  }
}

void task5(void)
{
  printf("Enter n:\t");
  unsigned n = 0u;
  scanf("%u", &n);

  const bool isPalindromeHex = isPalindrome(n, 4);
  const bool isPalindromeQuad = isPalindrome(n, 2);

  printHex(n);
  printf(" is %sa hexadecimal palindrome. ", (isPalindromeHex? "" : "not "));
  printQuaternary(n);
  printf(" is %sa quaternary palindrome.\n", (isPalindromeQuad? "" : "not "));
}

/*----------------------------------------------------------------------------*/

void printNSpaces(unsigned nSpaces)
{
  for (unsigned i = 0; i < nSpaces; ++i) {
    printf(" ");
  }
}

void printHorizontal(unsigned nSpaces, unsigned nStars)
{
  printNSpaces(nSpaces);

  for (unsigned i = 0; i < nStars; ++i) {
    printf("* ");
  }
  printf("\n");
}

void printMidRow(unsigned i, unsigned n)
{
  printNSpaces(n - i - 2);
  printf("*");
  printNSpaces(i);
  printf("*");

  printNSpaces(3 * n - 2);

  printf("*");
  printNSpaces(n - i - 3);
  printf("*\n");
}

void printParallelogram(unsigned n)
{
  // Първи ред.
  printHorizontal(n - 1, 2 * n);

  // Междинни редове.
  for (unsigned i = 0; i < n - 2; ++i) {
    printMidRow(i, n);
  }

  // Последен ред.
  printHorizontal(0, 2 * n);
}

void task6(void)
{
  printf("Enter the size of the parallelogram:\t");
  unsigned n = 0u;
  scanf("%u", &n);

  printParallelogram(n);
}

/*----------------------------------------------------------------------------*/

int main(void)
{
  printf("Task 1\n");
  task1();

  printf("Task 2\n");
  task2();

  printf("Task 3\n");
  task3();

  printf("Task 4\n");
  task4();

  printf("Task 5\n");
  task5();

  printf("Task6\n");
  task6();

  return 0;
}
