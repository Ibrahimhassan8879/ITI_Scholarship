#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int Task_1();
int Task_2();
int Task_3();
int Task_4();
int Task_5();
int Operations();
char get_continue();
int get_binary();

int main()
{
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
                Task_4();
                break;
            case 5:
                Task_5();
                break;
            case 6:
                return 0;
        }

        e = get_continue();
        if ( e == 'n' || e == 'N' )
        {
            return 0;
        }
    }
    return 0;
}

int Task_1()
{
    printf("\n \n  Hello, world.c \n\n");
}

int Task_2()
{
    int y;
    char H;

    do
    {
        printf("\n Select the function to convert character to integer\n\n  1: getch() \n  2: getche() \n  3: getchar() \n  4: getc()\n  5: scanf() \n \n");
        scanf(" %i",&y);
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }while( y < 1 || y > 5);
    printf("\n  Enter the character : ");
    switch(y)
    {
    case 1:
        H = getch();
        break;
    case 2:
        H = getche();
        break;
    case 3:
        H = getchar();
        break;
    case 4:
        H = getc(stdin);
        break;
    case 5:
        scanf(" %c",&H);
        break;
    }
    printf("\n  The corresponding value in ASCII number is : %i\n\n",H);
}

int Task_3()
{
    int y;
    printf("\n  Enter the integer : ");
    _flushall();
    scanf(" %i",&y);
    printf("\n  The corresponding value in ASCII character is : %c\n\n",y);
}

int Task_4()
{
    int y, a, b, c;
    int binary_input_1, binary_input_2, binary_output;

    do
    {
        printf("\n Select the bitwise operation that you want \n\n  1 : AND Operator   & \n  2 : OR Operator    | \n  3 : XOR Operator   ^ \n  4 : Telda Operator ~ \n \n");
        scanf(" %i",&y);
    }while ( y != 1 && y != 2 && y != 3 && y != 4);

    if ( y == 4 )
    {
        printf("\n  Enter the integer value in operation : ");
        scanf(" %i", &a);
        binary_input_1 = get_binary(a);
    }
    else if ( y == 1 || y == 2 || y == 3)
    {
        printf("\n  Enter the two integer values in operation (Integer 1, Integer 2) : ");
        scanf(" %i %i", &a , &b);
        binary_input_1 = get_binary(a);
        binary_input_2 = get_binary(b);
    }

    switch(y)
    {
    case 1:
        c = a & b;
        binary_output = get_binary(c);
        printf("\n  The value of the bitwise AND Operator is  : %i", c);
        printf("\n  The binary integer 1                      : %i \n  The binary integer 2                      : %i \n  The binary result                         : %i\n\n", binary_input_1, binary_input_2, binary_output);
        break;
    case 2:
        c = a | b;
        binary_output = get_binary(c);
        printf("\n  The value of the bitwise OR Operator is  : %i", c);
        printf("\n  The binary integer 1                     : %i \n  The binary integer 2                     : %i \n  The binary result                        : %i\n\n", binary_input_1, binary_input_2, binary_output);
        break;
    case 3:
        c = a ^ b;
        binary_output = get_binary(c);
        printf("\n  The value of the bitwise XOR Operator is  : %i", c);
        printf("\n  The binary integer 1                      : %i \n  The binary integer 2                      : %i \n  The binary result                         : %i\n\n", binary_input_1, binary_input_2, binary_output);
        break;
    case 4:
        c =  ~a;
        binary_output = get_binary(c);
        printf("\n  The value of the bitwise Telda Operator is  : %i", c);
        printf("\n  The binary integer                          :  %i \n  The binary result                           : %i\n\n", binary_input_1, binary_output);
        break;
    }
}

int Task_5()
{
    int y, a,b, Result;
    int binary_input, binary_output;

    do
    {
        printf("\n Select Operation that you want \n \n  1 : Left Shifting << \n  2 : Right Shifting >> \n \n");
        scanf(" %i",&y);
    }while(y != 1 && y != 2);

    printf("\n  Enter the integer value in operation : ");
    scanf(" %i", &a);
    binary_input = get_binary(a);

    printf("\n  Enter the amount of Shifting         : ");
    scanf(" %i", &b);

    switch(y)
    {
    case 1:
        Result = a << b;
        printf("\n  The result of Left Shifting is       : %i \n", Result);
        binary_output = get_binary(Result);
        break;
    case 2:
        Result = a >> b;
        printf("\n  The result of Right Shifting is      : %i \n", Result);
        binary_output = get_binary(Result);
        break;
    }
    printf("  The binary integer                   : %i \n  The binary result                    : %i\n\n", binary_input, binary_output);
}

int get_binary(int x)
{
    int binary = 0;
    int temp;
    int base = 2;
    int increment = 1;

    while ( x != 0)
    {
        temp = x % 2;
        binary += temp*increment;
        increment *= 10;
        x /= 2;
    }
    return binary;
}

int Operations()
{
    int x;
    do
    {
        printf("\n Enter the Task number to operate\n \n  1: Program say Hello, world.c \n  2: Program converts character to the corresponding integer value in ASCII Code \n  3: Program converts integer to the corresponding value in ASCII Code\n  4: Program using bitwise operators &, ~, |, ^ \n  5: Program applies right & left shifting of an integer\n  6: Exit Program\n \n");
        if (scanf(" %i", &x) != 1)
        {
            // Clear the input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
    }while(x < 1 || x > 6);

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
