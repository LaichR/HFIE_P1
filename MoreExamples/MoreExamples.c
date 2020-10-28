// MoreExamples.c : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint8_t CheckIfPalindrom(const char* palindrom);

int main()
{
    double x = 1e-10;
    printf("hello world\n");
    uint8_t isPalindrom = CheckIfPalindrom("anna");
    printf("it was a plindrom %i", isPalindrom);
}

uint8_t CheckIfPalindrom(const char* palindrom)
{
    uint32_t low = 0;
    uint32_t high = strnlen_s(palindrom, 128)-1;
    while ((palindrom[low] == palindrom[high]) &&
        (low < high) )
    {
        low++; high--;
    }
    return low >= high;
}
