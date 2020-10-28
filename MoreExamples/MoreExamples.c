// MoreExamples.c : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdint.h>
#include <string.h>

//
// enums are integer values that are used with a name
// in c the enums-values are treated as compile time constants with global scope
//

typedef enum
{
    False=0,
    True=1
}Bool;

/**
* Prototype of a function; a prototype is required if
* the function definition is written after its first use. 
* There are cases, where we could do without by just moving the the definition to the beginning of a file.
* But there are also cases, where we cannot order the functions properly.
* - This is the case when we use libraries
* - This may be the case when we have recursive calls A() -> B() and B() -> A()
* 
* Therefore its common practice to place the prototype of the functions separate to a header (for public functions)
* or to the beginning of a c-Source
*/
 
Bool CheckIfPalindrom(const char* palindrom);

int32_t FirstIndexOf1(const char* text, char ch);
int32_t FirstIndexOf2(const char* text, char ch);

char* ToLowerCase(char* text);

int main()
{
    printf("hello world\n");
    uint8_t isPalindrom = CheckIfPalindrom("anna");
    printf("it was a plindrom %i", isPalindrom);

    int32_t index1 = FirstIndexOf1("hello", 'l');
    int32_t index2 = FirstIndexOf2("hello", 'l');

    char buffer[128];
    strcpy_s(buffer, sizeof buffer, "ALIBABA UND DIE 40 RAEUBER");

    printf("to lowercase: %s", ToLowerCase(buffer));
}

Bool CheckIfPalindrom(const char* palindrom)
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

/**
* 
*/
int32_t FirstIndexOf1(const char* text, char ch)
{
    int32_t i = 0;
    char curChar = text[i];
    while (curChar != '\0' )
    {
        if (curChar == ch) return i;
        i++;
        curChar = text[i];
    }
    return -1;
}

/**
* hantieren mit Zeigern
*/
int32_t FirstIndexOf2(const char* text, char ch)
{
    const char* p = text;
    while (*p != '\0')
    {
        if (*p == ch) return (p - text);
        p++;
    }
    return -1;
}


char *ToLowerCase(char* text)
{
    char* p = text;
    for (; *p; p++)
    {
        if ((*p >= 'A' && *p <= 'Z' ))
        {
            *p |= 0x20;
        }
    }
    return text;
}

