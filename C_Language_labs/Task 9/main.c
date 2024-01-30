#include <stdio.h>
#include <stdlib.h>

#define Max_Student 10
#define Max_Subject 5


// Dynamic Memory Allocation Task of Students with subjects
/*
    This Task operations

    1. Allocate pointer to array of pointers
    2. Allocate arrays for the array of pointers
    3. Allocate sum array to calculate the total grades of each student
    4. Allocate avg array to calculate the average grades in each subject
    5. free the memory
*/

int main()
{
    int **Ptr;
    int Subjects_Number, Students_Number;
    int *Sum_Array, *Avg_Array;

    // Getting Students number from the user
    do
    {
        _flushall();
        printf("\n\n   Enter the total students number to be calculated : ");
        scanf("%i", &Students_Number);
    }while(Students_Number > Max_Student || Students_Number < 1);
    printf("\n");

    // Getting Subjects number from the user
    do
    {
        _flushall();
        printf("   Enter the total subjects number to be calculated : ");
        scanf("%i", &Subjects_Number);
    }while(Subjects_Number > Max_Subject || Subjects_Number < 1);
    printf("\n");

    // Allocating Pointer to array of pointers of Students
    Ptr = (int**)malloc(Students_Number * sizeof(int*));

    if (Ptr == NULL)
    {
        printf("\n\n   There is no enough memory to run the program Exiting ....\n");
        return 0;
    }

    // Allocating Array of pointers of Subjects
    for (int i = 0; i < Students_Number; i++)
    {
        Ptr[i] = (int*)malloc(Subjects_Number * sizeof(int));
    }

    for (int i = 0; i < Students_Number; i++)
    {
        if (Ptr[i] == NULL)
        {
            printf("\n\n   There is no enough memory to run the program Exiting ....\n");
            return 0;
        }
    }

    // Allocating array of sum for Students and refill with zeros
    Sum_Array = (int*)malloc(Students_Number * sizeof(int));

    if (Sum_Array == NULL)
    {
        printf("\n\n   There is no enough memory to run the program Exiting ....\n");
        for (int i = 0; i < Students_Number; i++)
        {
            free(Ptr[i]);
        }
        free(Ptr);
        return 0;
    }
    for (int i = 0; i < Students_Number; i++)
    {
        Sum_Array[i] = 0;
    }

    // Allocating array of average for subjects and refill with zeros
    Avg_Array = (int*)malloc(Subjects_Number * sizeof(int));

    if (Avg_Array == NULL)
    {
        printf("\n\n   There is no enough memory to run the program Exiting ....\n");
        free(Sum_Array);
        for (int i = 0; i < Students_Number; i++)
        {
            free(Ptr[i]);
        }
        free(Ptr);
        return 0;
    }
    for (int i = 0; i < Subjects_Number; i++)
    {
        Avg_Array[i] = 0;
    }


    // Filling the data from the user
    for (int i = 0; i < Students_Number; i++)
    {
        for (int j = 0; j < Subjects_Number; j++)
        {
            printf("   Enter the Student number %i subject number %i grade : ",i+1,j+1);
            scanf("%i", &Ptr[i][j]);
            Sum_Array[i] += Ptr[i][j];
            Avg_Array[j] += Ptr[i][j];
        }
        printf("\n");
    }

    // Calculating the average for each subject after Filling data
    for (int i = 0; i < Subjects_Number; i++)
    {
        Avg_Array[i] /= Students_Number;
    }

    // Printing the data of inputs
    for (int i = 0; i < Students_Number; i++)
    {
        printf("   The student number %i has grades : [ ", i+1);
        for (int j = 0; j < Subjects_Number; j++)
        {
            if (j == Subjects_Number - 1)
            {
                printf("%i ]", Ptr[i][j]);
            }
            else
            {
                printf("%i, ", Ptr[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");

    // Printing the Sum of each student
    for (int i = 0; i < Students_Number; i++)
    {
        printf("   The sum of student %i is : %i\n",i+1, Sum_Array[i]);
    }
    printf("\n");

    // Printing the Average of each subject
    for (int i = 0; i < Subjects_Number; i++)
    {
        printf("   The average of subject %i is : %i\n",i+1, Avg_Array[i]);
    }
    printf("\n");

    // Free the memory
    for (int i = 0; i < Students_Number; i++)
    {
        free(Ptr[i]);
    }

    free(Ptr);

    free(Sum_Array);
    free(Avg_Array);

    return 0;
}
