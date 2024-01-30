#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "F:\ITI_Work\Sync_Files\6-C\Labs\Day_4\MyLibrary.h"


int Task_1();
int Task_2();
int Task_3();
int Task_4();
int Task_5();
int Task_6();
int Task_7();
int Task_8();
int Task_9();



int Operations();
char get_continue();


int main()
{
    int x;
    char c;

    while (1)
    {
        x = Operations();
        switch(x)
        {
        case 1:
            Task_1();
            break;
        case 2:
            Task_2();
            break;
        case 3:
            Task_3();
            break;
        case 4:
            Task_4();
            break;
        case 5:
            Task_5();
            break;
        case 6:
            Task_6();
            break;
        case 7:
            Task_7();
            break;
        case 8:
            Task_8();
            break;
        case 9:
            Task_9();
            break;
        case 10:
            printf("\n\n  Good bye\n ");
            return 0;
        }
        c = get_continue();
        if ( c == 'n' || c == 'N')
        {
            printf("\n\n  Good bye\n");
            return 0;
        }
    }


}


int Task_1()
{
    char str[10], ch;
    printf("\n\n  Enter characters : ");

    for (int i = 0; i < 10; i++)
    {
        str[i] = NULL;
    }
    _flushall();
    for (int i = 0; i < 10; i++)
    {
        ch = getche();
        if ( ch == 13 )
        {
            str[i] == '\0';
            break;
        }
        else
        {
            str[i] = ch;
        }
    }

    printf("\n  The letter that you've entered is : ");
    int i = 0;
    while( str[i] != '\0')
    {
        printf("%c", str[i++]);
    }
    return 0;

}

int Task_2()
{
    char ch;
    printf("\n\n  Enter character : ");

    ch = getche();

    if (ch == 0 || ch == -32 || ch == 224)
    {
        ch = getche();
        _flushall();
        printf("\n  The key you've entered is a Extended key and it's ASCII value is : %i \n\n", ch);
    }
    else
    {
        printf("\n  The key you've entered is a Normal key and it's ASCII value is : %i \n\n", ch);
    }

    return 0;
}

int Task_3()
{
    char Fname[10], Lname[10], Fullname[22];
    printf("\n\n  Enter your first name : ");
    scanf("%s", Fname);

    printf("\n\n  Enter your last name : ");
    scanf("%s", Lname);

    strcpy(Fullname, Fname);
    strcat(Fullname, " ");
    strcat(Fullname, Lname);


    printf("\n\n  Your Full name is : %s", Fullname);
    return 0;


}

int Task_4()
{

    char ch;
    int i, cur = 0, Flag = 0;
    char Menu[3][8] = {"NEW", "DISPLAY", "EXIT"};

do
{

textattr(0X07); ///Normal
clrscr();

    for(i=0; i<3; i++)
    {
        if(cur == i)
        {
            textattr(0X50);
            //textattr(0X70); ///Highlight
        }
        else
        {
            textattr(0X07); ///Normal
        }
        gotoxy(60, 7+i*3);
        printf("%s", Menu[i]);
    }

    ch = getche();
    switch(ch)
    {
    case 224:///Extended
    case -32:
    case 0:
            ch = getche();
            switch(ch)
            {
                case 72:   ///Up
                case 73:  /// page Up
                    cur--;
                    if(cur<0)
                        cur = 2;
                break;

                case 80:   ///Down
                case 81:   ///page Down
                    cur++;
                    if(cur>2)
                        cur = 0;
                break;

                case 71: ///Home
                    cur = 0;
                break;

                case 79: ///End
                    cur = 2;
                break;
            }
     break;

    case 13: ///Enter
        if(cur == 0) ///New
        {
            clrscr();
            printf("\n This is Ibrahim Page");
            getche();
        }
        else if(cur == 1) ///Display
        {
            clrscr();
            printf("\n This is Display Page");
            getche();
        }
        else  ///Exit
        {
            Flag = 1;
        }
    break;

    case 9: ///Tab
         cur++;
            if(cur>2)
              cur = 0;
    break;

    case 27: ///Esc
        Flag = 1;
    break;
    }

}///End of While
while(Flag == 0);
    textattr(0X07);
}

int Task_5()
{
    int Num1,Num2,Num3;
    printf("\n\n  Enter number 1 : ");
    scanf("%i", &Num1);

    printf("\n\n  Enter number 2 : ");
    scanf("%i", &Num2);

    printf("\n\n  Enter number 3 : ");
    scanf("%i", &Num3);

    if ( Num1 >= Num2 && Num1 >= Num3)
    {
        printf("\n\n  The biggest number number 1  : %i", Num1);
    }
    else if ( Num2 >= Num1 && Num2 >= Num3)
    {
        printf("\n\n  The biggest number number 2  : %i", Num2);
    }
    else
    {
        printf("\n\n  The biggest number number 3  : %i", Num3);
    }
    printf("\n\n");
    return 0;
}


int Task_6()
{
    char ch;
    char Word[10] = {0};
    char Frequency[200] = {0};
    printf("\n\n  Enter the word to check it's frequency : ");
    for (int i = 0; i < 10; i++)
    {
        ch = getche();
        if ( ch == 13 )
        {
            Word[i] = '\0';   /// Null terminator
            break;
        }
        else
        {
            Word[i] = ch;
        }
    }

    for (int i = 0;i < 10;i++)
    {
        if ( (Word[i] >= 65 && Word[i <= 90]) || (Word[i] >= 97 && Word[i <= 122]))
        {
            Frequency[Word[i]]++;
        }
    }
    printf("\n\n  The letters with it's frequencies is : ");
    for (int i = 0; i < 200;i++)
    {
        if (Frequency[i] != 0)
        {
            printf("%c %i, ", i, Frequency[i]);
        }
    }
    return 0;
}

int Task_7()
{
    char ch;
    char Word[10] = {0};
    char CpyWord[10] = {0};
    printf("\n\n  Enter the word that you want to copy : ");
    for (int i = 0; i < 10;i++)
    {
        ch = getche();
        if ( ch == 13 )
        {
            Word[i] = '\0';
            break;
        }
        else
        {
            Word[i] = ch;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (Word[i] == '\0')
        {
            CpyWord[i] = '\0';
            break;
        }
        else
        {
            CpyWord[i] = Word[i];
        }
    }
    printf("\n\n  The copied word is : '");
    for (int i = 0; i < 10; i++)
    {
        if (CpyWord[i] == '\0')
        {
            break;
        }
        else
        {
            printf("%c", CpyWord[i]);
        }
    }
    printf("'");
    return 0;
}

int Task_8()
{
    char ch;
    char Word[100];
    printf("\n\n  Enter the word that you want to calculate length : ");
    for (int i = 0; i < 100;i++)
    {
        ch = getche();
        if ( ch == 13 )
        {
            Word[i] = '\0';
            break;
        }
        else
        {
            Word[i] = ch;
        }
    }
    int counter = 0;
    int i = 0;
    for (int i = 0; i < 100;i++)
    {
        if ( Word[i] == '\0' )
        {
            break;
        }
        else
        {
            counter++;
        }
    }
    printf("\n\n  The length of the word you have entered is : %i \n\n", counter);
    return 0;
}

int Task_9()
{
    char ch;
    char Word[100] = {0};
    printf("\n\n  Enter the word that you want to remove all characters except alphabet : ");
    for (int i = 0; i < 100;i++)
    {
        ch = getche();
        if ( ch == 13 )
        {
            Word[i] = '\0';
            break;
        }
        else
        {
            Word[i] = ch;
        }
    }
    for (int i = 0; i < 100; i++)
    {
        if ((Word[i] >= 65 && Word[i] <= 90) || (Word[i] >= 97 && Word[i] <= 122))
        {
            Word[i];
        }
        else
        {
            Word[i] = '0';
        }
    }
    printf("\n\n The word without non-alphabetic characters is : ");
    for (int i = 0; i < 100; i++)
    {
        if (Word[i] != '0')
        {
            printf("%c", Word[i]);
        }
        if (Word[i] == '\0')
        {
            break;
        }
    }
    printf("\n\n");
    return 0;
}

int Operations()
{
    int x;
    do
    {
    printf("\n Select Task to execute \n\n  1 : Receive character by character \n  2 : C program take char and displays if it's normal or extended key \n  3 : Take First name and Last name and display Fullname \n  4:  Highlight Menu Task \n  5 : Task to Select the big number between 3 numbers \n  6 : C program to find the frequency of Characters \n  7 : C program to Copy String Without Using strcpy() \n  8 : C Program to find the Length of a String without Using strlen() \n  9 : C program to Remove all Characters in a String Except Alphabet \n  10 : Exit Program \n \n");
    if (scanf(" %i", &x) != 1)
    {
        // Clear the input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    }while( x < 1 || x > 10);
    return x;
}

char get_continue()
{
    char e;
    printf("\n  Do you want to continue the program (Y/N) ? ");
    do
    {
        scanf(" %c",&e);
    }while(e != 'Y' && e != 'y' && e != 'N' && e != 'n');
    return e;
}
