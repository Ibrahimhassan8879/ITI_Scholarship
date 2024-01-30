#include <stdio.h>
#include <stdlib.h>


int Task_1();
int Task_2();
int Task_3();

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
            printf("\n\n  Good bye\n All rights reserved © by Ibrahim Hassan since 10\31\2023 \n\n");
            return 0;
        }
        c = get_continue();
        if ( c == 'n' || c == 'N')
        {
            printf("\n\n  Good bye\n All rights reserved © by Ibrahim Hassan since 10\31\2023 \n\n");
            return 0;
        }
    }


}


int Task_1()
{
    // TO DO: Get max and min number of arrays
    int size;
    printf("\n\n Enter the size of array : ");
    scanf("%i", &size);
    int Array[size];
    printf("\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("  Enter Array element number %i : ",i + 1);
        scanf("%i",&Array[i]);
    }

    //Getting Max
    int Max = Array[0];
    for (int i = 0; i < size; i++)
    {
        if ( Array[i] > Max)
        {
            Max = Array[i];
        }
    }

    printf("\n\n  The Maximum number in array is: %i \n",Max);

    int Min = Array[0];
    // Getting Min
        for (int i = 0; i < size; i++)
    {
        if ( Array[i] < Min)
        {
            Min = Array[i];
        }
    }

    printf("  The Minimum number in array is: %i \n",Min);

}

int Task_2()
{
    int Rows;
    int Columns;

    printf("\n\n Enter the number of Rows and Columns: ");
    scanf("%i", &Rows);
    scanf("%i", &Columns);

    int Array[Rows][Columns];

    int *Sum = (int *)malloc(Rows * sizeof(int));
    int *Average = (int *)malloc(Columns * sizeof(int));

    if (Sum == NULL || Average == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < Rows; i++)
    {
        Sum[i] = 0;
    }
    for (int i = 0; i < Columns; i++)
    {
        Average[i] = 0;
    }
    printf("\n\n");
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++)
        {
            printf("  Enter the value of student %i subject %i: ", i + 1, j + 1);
            scanf("%i", &Array[i][j]);
            Sum[i] += Array[i][j];
            Average[j] += Array[i][j];
        }
        printf("\n");
    }

    printf("  The Sum for each student     : { ");
    for (int i = 0; i < Rows; i++)
    {
        if ( i != Rows - 1)
        {
            printf("%i, ", Sum[i]);
        }
        else
        {
            printf("%i ", Sum[i]);
        }

    }
    printf("}\n");
    printf("  The Average for each subject : { ");
    for (int i = 0; i < Columns; i++)
    {
        if ( i != Columns - 1)
        {
            printf("%i, ", Average[i]);
        }
        else
        {
            printf("%i ", Average[i]);
        }
    }
    printf("}\n");

    free(Sum);
    free(Average);

    return 0;
}

int Task_3()
{
    // Multiplication of two arrays
    int Rows1,Columns1, Rows2, Columns2;
    printf("\n\n Enter the Array 1 Size in (Rows,Columns) : ");
    scanf("%i",&Rows1);
    scanf("%i",&Columns1);

    printf(" Enter the Array 2 Size in (Rows,Columns) : ");
    scanf("%i",&Rows2);
    scanf("%i",&Columns2);

    if (Columns1 != Rows2)
    {
        printf("\n\n  These two Matrix cannot be multiplied");
        return 0;
    }

    int Array1[Rows1][Columns1];
    int Array2[Rows2][Columns2];

    printf("\n\n");
    for (int i = 0; i < Rows1; i++)
    {
        for (int j = 0; j < Columns1; j++)
        {
            printf("  Enter the value of Array 1 [%i][%i] : ",i + 1 ,j + 1);
            scanf("%i",&Array1[i][j]);
        }
    }
    printf("\n\n");
    for (int i = 0; i < Rows2; i++)
    {
        for (int j = 0; j < Columns2; j++)
        {
            printf("  Enter the value of Array 2 [%i][%i] : ",i + 1 ,j + 1);
            scanf("%i",&Array2[i][j]);
        }
    }

    int Result_Array[Rows1][Columns2];
    for (int i = 0; i < Rows1; i++)
    {
        for (int j = 0; j < Columns2; j++)
        {
        Result_Array[i][j] = 0; // Initialize each element to 0
        }
    }


    for (int i = 0; i < Rows1; i++)
    {
        for (int j = 0 ; j < Columns2; j++)
        {
            for (int k = 0 ; k < Columns1; k++)
            {

                Result_Array[i][j] += Array1[i][k] * Array2[k][j];
            }
        }
    }

    printf("\n\n  The Result Multiplication Array is : [ ");
    for (int i = 0; i < Rows1 ; i ++)
    {
        for (int j = 0; j < Columns2 ; j++)
        {
            if ( (i == Rows1 - 1) && ( j == Columns2 - 1 ) )
            {
                printf("%i ",Result_Array[i][j]);
            }
            else
            {
                printf("%i, ",Result_Array[i][j]);
            }

        }
    }
    printf("] \n");
    return 0;


}

int Operations()
{
    int x;
    do
    {
    printf("\n Select Task to execute \n\n  1 : Getting Max number of array \n  2 : Calculate Sum & Average of Array \n  3 : Multiplication the Arrays \n  4 : Exit Program \n \n");
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




