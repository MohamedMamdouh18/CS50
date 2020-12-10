#include <stdio.h>
#include <stdlib.h>
#include <cs50.c>

int main(void)
{
    int count ;
    long long credit ;

    do     //do while to avoid negative numbers
    {
        credit = get_long_long("credit card:");
    }
    while (credit <= 0);

    long long cnum = credit;

    while (credit > 0) //to count how many digits
    {
        credit = credit / 10;
        count = count + 1;
    }
// the start of luhn's algorithm
    int num1 = cnum % 10;
    int num2 = ((cnum % 100) / 10) * 2;
    int num3 = (cnum % 1000) / 100;
    int num4 = ((cnum % 10000) / 1000) * 2;
    int num5 = (cnum % 100000) / 10000;
    int num6 = ((cnum % 1000000) / 100000) * 2;
    int num7 = (cnum % 10000000) / 1000000;
    int num8 = ((cnum % 100000000) / 10000000) * 2;
    int num9 = (cnum % 1000000000) / 100000000;
    int num10 = ((cnum % 10000000000) / 1000000000) * 2;
    int num11 = (cnum % 100000000000) / 10000000000;
    int num12 = ((cnum % 1000000000000) / 100000000000) * 2;
    int num13 = (cnum % 10000000000000) / 1000000000000;
    int num14 = ((cnum % 100000000000000) / 10000000000000) * 2;
    int num15 = (cnum % 1000000000000000) / 100000000000000;
    int num16 = ((cnum % 10000000000000000) / 1000000000000000) * 2;
    int num17 = num16 / 2 ;
    int num18 = num14 / 2;
//we split the digits that we doubled
    int double1 = (num2 % 10);
    int double2 = (num2 % 100) / 10;
    int double3 = (num4 % 10);
    int double4 = (num4 % 100) / 10;
    int double5 = (num6 % 10);
    int double6 = (num6 % 100) / 10;
    int double7 = (num8 % 10);
    int double8 = (num8 % 100) / 10;
    int double9 = (num10 % 10);
    int double10 = (num10 % 100) / 10;
    int double11 = (num12 % 10);
    int double12 = (num12 % 100) / 10;
    int double13 = (num14 % 10);
    int double14 = (num14 % 100) / 10;
    int double15 = (num16 % 10);
    int double16 = (num16 % 100) / 10;
//we sum all the digits
    int sum = double1 + double2 + double3 + double4 + double5 + double6 + double7 + double8 + double9 + double10 + double11 + double12 +
              double13 + double14 + double15 + double16 + num1 + num3 + num5 + num7 + num9 + num11 + num13 + num15;


    if ((sum % 10 == 0) && (count == 15) && (num15 == 3) && ((num18 == 4) || (num18 == 7)))//this is AMEX
    {
        printf("AMEX\n");
    }
    else if ((sum % 10 == 0) && (count == 16) && (num17 == 5) && ((num15 == 1) || (num15 == 2)
             || (num15 == 3)                            || (num15 == 4) || (num15 == 5)))//this for mastercard
    {
        printf("MASTERCARD\n");
    }
    else if ((sum % 10 == 0) && ((count == 13) || (count = 16)) && ((num13 == 4) || (num17 == 4)))//this for visa
    {
        printf("VISA\n");
    }
    else //else is invalid
    {
        printf("INVALID\n");
    }

}

