// MoreExamples.c : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
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

int32_t Sum(const int32_t* data, uint32_t len);

void Fill(int32_t* data, uint32_t len, int32_t value);


int32_t FirstIndexOf1(const char* text, char ch);

int32_t FirstIndexOf2(const char* text, char ch);

char* ToLowerCase1(char* text);

char* ToCamelCase(char* text);

const char* ReverseString(char* ch);

Bool ReverseAndAllocString(const char* text, char** reversed);

int32_t IndexOf(const char* text, const char* substr);


int32_t buffer[100];
int main(int nrOfArgs, const char* args[], const char* env[])
{

    if (nrOfArgs > 1)
    {
        if ( strcmp(args[1], "sum") == 0 )
        {
            printf("got sum");
        }
        else if (strcmp(args[1], "fill") == 0)
        {
            printf("got fill");
            Fill(buffer, 100, 0xDEADBEAF);
        }
    }
    else
    {
        uint64_t a = 0;
        char* b = (char*)&a;
        b[1] = 1;

        printf("hello world\n");
        uint8_t isPalindrom = CheckIfPalindrom("anna");
        printf("it was a plindrom %i", isPalindrom);

        int32_t index1 = FirstIndexOf1("hello", 'l');
        int32_t index2 = FirstIndexOf2("hello", 'l');

        char buffer[128] = "ALIBABA UND DIE 40 RAEUBER";// {'A', 'L', 'I', 'B', 'A', 'B', 'A', '\0'};

        printf("to lowercase: %s\n", ToLowerCase1(buffer));

        strcpy_s(buffer, sizeof buffer, "my_dear__friend__");
        printf("to camelcase: %s\n", ToCamelCase(buffer));


        strcpy_s(buffer, sizeof buffer, "Morgen");
        printf("revese string %s\n", ReverseString(buffer));

        char* ch = 0;
        if (ReverseAndAllocString("Morgen", &ch))
        {
            printf("revers and alloc %s", ch);
        }

        int32_t indexOf1 = IndexOf("Morgen kommt der Weihnachtsmann", "Morgen");
        int32_t indexOf2 = IndexOf("Morgen kommt der Weihnachtsmann", "kommt");
        int32_t indexOf3 = IndexOf("Morgen kommt der Weihnachtsmann", "mann");
        int32_t indexOf4 = IndexOf("Morgen kommt der Weihnachtsmann", "eih");
        int32_t indexOf5 = IndexOf("Morgen kommt der Weihnachtsmann", "koomt");
    }
}

void Fill(int32_t* data, uint32_t len, int32_t value)
{
    uint32_t i = 0;
    for (; i < len; i++)
    {
        data[i] = value;
    }
}

int32_t Sum(const int32_t* data, uint32_t len)
{
    uint32_t i = 0;
    int32_t sum = 0;
    for (; i < len; i++)
    {
        sum += data[i];
    }
    return sum;
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


char* ToLowerCase1(char* text)
{
    uint32_t i = 0;
    for (; text[i]!='\0'; i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z'))
        {
            //text[i] |= 0x20;
            text[i] += 32;
        }
    }
    return text;
}

char *ToLowerCase2(char* text)
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

char* ToCamelCase(char* text)
{
    int32_t i = 0;
    int32_t w = 0;
    Bool underscore = False;
    for(; text[i]; i++)
    {
        if (text[i] != '_')
        {
            char newChar = text[i];
            if (underscore)
            {
                if (newChar >= 'a' && newChar <= 'z') // it's a lower case character
                {
                    newChar -= 0x20; // to uppercase
                }
                underscore = False;
            }
            text[w++] = newChar;
        }
        else
        {
            underscore = True;
        }
    }
    text[w] = '\0';
    return text;
}

const char* ReverseString(char* ch)
{
    uint32_t last = strnlen_s(ch, 1024) - 1;
    uint32_t mid = last / 2;
    uint32_t i = 0;
    for (; i <= mid; i++)
    {
        char tmp = ch[i]; ch[i] = ch[last - i]; ch[last - i] = tmp;
    }
    return ch;
}

Bool ReverseAndAllocString(const char* text, char** reversed)
{
    uint32_t len = strnlen_s(text, 1024);
    assert(len > 0);
    char* buffer = (char*)malloc(len+1); // needs to hold the string termination.
    if (buffer == 0) return False;
    uint32_t i = 0;
    for (; i < len; i++)
    {
        
        buffer[i] = text[len - i - 1 ];
    }
    buffer[i] = '\0';
    *reversed = buffer;
    return True;
}

int32_t IndexOf(const char* text, const char* substr)
{
    const char *pText = text;
    
    for (; *pText; pText++)
    {
        const char* ch = substr;
        const char* txt = pText;
        while (*txt && *ch)
        {
            if (*txt++ != *ch++) break;
        }
        if (!*ch) return pText - text;
    }
    return -1;
}

