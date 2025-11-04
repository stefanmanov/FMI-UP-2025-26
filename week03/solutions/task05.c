#include <stdio.h>


int main(void)
{
  printf("Enter month and year:\t");
  int month = 0, year = 0;
  scanf("%d %d", &month, &year);

  int isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

  {
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      printf("31\n");
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      printf("30\n");
      break;
    case 2:
      printf("%s\n", (isLeapYear ? "29" : "28"));
      break;
    default:
      printf("Invalid data!\n");
    }
  }

  /* --------------------------------------------------------------------------*/

  {
    if (month < 1 || month > 12) {
      printf("Invalid data!\n");
    }
    else if (month == 2) {
      printf("%s\n", (isLeapYear ? "29" : "28"));
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
      printf("30\n");
    }
    else {
      printf("31\n");
    }
  }

  return 0;
}
