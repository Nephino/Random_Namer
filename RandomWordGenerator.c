#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

char vovel[] = {'a', 'e', 'i', 'o', 'u'};
int range[2] = {97, 122};  // a - z

bool isVovel(char letter)
{   
    for(int i = 0; i < 5; i++)
    {
        if (letter == vovel[i])
            return 1;
    }
    return 0;
}

char getLetter(void)
{
    return (char)(rand() % (range[1] - range[0]) + range[0]);
}

char getConsonant(void)
{
    char letter = getLetter();
    while( isVovel(letter) )
    {
        letter = getLetter();
    }
    return letter;
}

char getVovel(void)
{
    return vovel[ (char)(rand() % 5) ];
}

void printWord(int length)
{
    for(int i = 0; i < length; i++)
    {
        if(i % 2)
        {
            printf("%c",getVovel());
        }else{
            printf("%c",getConsonant());
        }
    }
}

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));

    while(getchar() == '\n')
    {
        char length = (rand() % 5) + 5;  //[5,10]
        printWord(length);
        printf("\n");
    }

    return 0;
}
/**
 * nephino
**/