#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int Task_1();
int Task_2();
int Task_3();
void gotoxy (int column, int line);
char get_continue();


int main()
{
    int x;
    char e;

    while(1)
    {
        int x = Operations();
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
            return 0;
        }
        e = get_continue();
        if ( e == 'n' || e == 'N')
        {
            return 0;
        }
    }
    return 0;
}

int Task_1()
{
    int size;
    do
    {
        printf("\n\n  Enter the Magic box size in odd numbers : ");
        scanf("%i",&size);
    }while( ( size % 2) == 0 || size < 3);

    int size_multiplied = size * size;
    int Row = 1;
    int Column = (size + 1) / 2;

    for (int i = 1; i <= size_multiplied ; i++)
    {
        gotoxy((Column + 20 )*4, (Row + 6 )*2);
        printf("%i", i);
        if ( (i % size) != 0 )
        {
            Row = ( Row - 1 - size ) % size + size;
            Column = (Column - 1 - size) % size + size;
        }
        else
        {
            Row = ( Row + 1 - size ) % size + size;
        }
    }
    for (int i = 0; i < size ; i++)
    {
        printf("\n\n\n\n\n");
    }
    return 0;
}

void gotoxy(int column, int line) {
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int Task_2()
{
    int x;
    int entry;
    int sum = 0;
    do
    {
        printf("\n\n  Enter the amount of numbers to sum : ");
        scanf("%i",&x);
    } while( x > 100  || x <= 0 );

    printf("\n\n");
    for (int i = 0; i < x ; i++)
    {
        printf("  Enter the Number (%i) : ", i + 1);
        scanf("%i", &entry);
        sum += entry;
    }

    printf("\n\n");
    printf("  The Sum is : %i\n\n",sum);
    return 0;
}

int Task_3()
{
    int x;
    do
    {
        printf("\n\n  Enter the choice number 1, 2, 3 : ");
        scanf("%i",&x);
    }while( x <= 0 || x > 3);

    printf("\n\n  You have selected the choice number %i \n\n",x);
    return 0;
}

int Operations()
{
    int x;
    do
    {
    printf("\n Select type of program to run\n\n  1 : Magic box\n  2 : Read numbers to sum\n  3 : Menu 3 choices to select\n  4 : Exit program \n");
    if (scanf(" %i", &x) != 1)
    {
        // Clear the input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    }while( x < 1 || x > 4);
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

