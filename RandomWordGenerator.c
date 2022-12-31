#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

char vovel[5] = {'a', 'e', 'i', 'o', 'u'};
int wordLength[2] = {5, 10};

char getVovel(void)
{
    return vovel[ (rand() % 5) ];
}

char getLetter(void)
{
    return (char)(rand() % 25 + 97);  // 'a' ~ 'z'
}

bool isVovel(char letter)
{   
    for(int i = 0; i < 5; i++)
    {
        if (letter == vovel[i])
            return 1;
    }
    return 0;
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

    while(getchar() == '\n')  //input "enter" to generate a new word
    {
        printWord(rand() % (wordLength[1] - wordLength[0]) + wordLength[0]);
        printf("\n");
    }

    return 0;
}
