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
int swap(int* x, int* y);
float power_result(float base, float power);

typedef struct Employee
{
    int ID;
    char Name[20];
    int Salary;
    int Bonus;
    int Deduction;
    int Net_salary;
}Employee;

Employee Addnewemployee(int i);
void DisplayEmployee(Employee);
void DisplayEmployeebyID(Employee *E, int id);
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

/// C Program to take single Employee's information (ID, Name, Salary, Bonus, Deduction)
int Task_1()
{
    int Net_salary = 0;
    printf("\n\n  Enter the Employee Data inlcude (ID, Name, Salary, Bonus, Deduction) : ");
    struct Employee E;

    scanf("%i %s %i %i %i", &E.ID, E.Name, &E.Salary, &E.Bonus, &E.Deduction);

    Net_salary = E.Salary + E.Bonus - E.Deduction;

    printf("\n\n  The Employee code %i, Name %s, Net Salary %i", E.ID, E.Name, Net_salary);
    return 0;

}

int Task_2()
{
    struct Employee E[5];
    int Net_salary[5] = {0};

    for (int i = 0; i < 5 ; i++)
    {
        char ch[10] = {0};
        printf("\n\n  Enter the Employee [%i] Data Include (ID, Name, Salary, Bonus, Deduction) : ", i + 1);
        scanf("%i %s %i %i %i", &E[i].ID, E[i].Name, &E[i].Salary, &E[i].Bonus, &E[i].Deduction);
        E[i].Net_salary = E[i].Salary + E[i].Bonus - E[i].Deduction;
    }

    printf("\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\n  The Employee [%i] Code %i, Name %s, Net Salary %i",i+1, E[i].ID, E[i].Name, E[i].Net_salary);
    }
    printf("\n\n");
    return 0;
}

int Task_3()
{
    Employee E;
    E = Addnewemployee(1);
    DisplayEmployee(E);
    return 0;
}

Employee Addnewemployee(int i)
{
    Employee E;
    printf("\n\n  Enter the Employee Data inlcude (ID, Name, Salary, Bonus, Deduction) : ");
    scanf("%i %s %i %i %i", &E.ID, E.Name, &E.Salary, &E.Bonus, &E.Deduction);
    int Net_salary = 0;
    E.Net_salary = E.Salary + E.Bonus - E.Deduction;

    return E;
}

void DisplayEmployee(Employee E)
{
    printf("\n\n  The Employee code %i, Name %s, Net Salary %i", E.ID, E.Name, E.Net_salary);
    return 0;
}

void DisplayEmployeebyID(Employee *E, int id)
{
    int flag_found = 0;

    for (int i = 0; i < 5; i++)
    {
        if (E[i].ID == id)
        {
            flag_found = 1;
            printf("Employee code %i, Name %s, Net Salary %i\n", E[i].ID, E[i].Name, E[i].Net_salary);
            break;
        }

    }
    if (!flag_found)
    {
        printf("\nEmployee with ID %d not found.\n", id);
    }
    return 0;
}

int Task_4()
{
    Employee E[5];
    char ch;
    int i, cur = 0, Flag = 0;
    char Menu[6][15] = {"NEW", "DISPLAY","Display All","Delete", "Delete All", "EXIT"};
    int Employeeindex = 0;
do
{

textattr(0X07); ///Normal
clrscr();

    for(i=0; i<6; i++)
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
                        cur = 5;
                break;

                case 80:   ///Down
                case 81:   ///page Down
                    cur++;
                    if(cur>5)
                        cur = 0;
                break;

                case 71: ///Home
                    cur = 0;
                break;

                case 79: ///End
                    cur = 5;
                break;
            }
     break;

    case 13: ///Enter
        if(cur == 0) ///New
        {
            clrscr();
            printf("\n This is New Employee Page");
            if ( Employeeindex < 5)
            {
                E[Employeeindex] = Addnewemployee(Employeeindex);
                Employeeindex++;
            }
            else
            {
                printf("\n\n You have reached the Maximum amount of employees");
            }

            getche();
        }
        else if(cur == 1) ///Display
        {
            clrscr();
            int x = 0 ;
            printf("\n This is Display Page");
            printf("\n  Enter the employee ID to Display : ");
            scanf("%i", &x);
            DisplayEmployeebyID(E, x);
            getche();
        }
        else if(cur == 2) ///Display all
        {
            clrscr();
            printf("\n This is Display all Page");
            for (int i = 1; i <= Employeeindex; i++)
            {
                DisplayEmployeebyID(E, i);
            }
            getche();
        }
        else if(cur == 3) ///Delete
        {
            clrscr();
            int x = 0;
            printf("\n This is Delete Page");
            printf("\n  Enter the employee ID to Delete : ");
            scanf("%i", &x);
            E[x].ID = 0;
            E[x].Name[0] = '\0';
            E[x].Salary = 0;
            E[x].Net_salary = 0;
            E[x].Bonus = 0;
            E[x].Deduction = 0;
            printf("\n\n  The Employee Deleted");
            getche();
        }
        else if(cur == 4) ///Delete all
        {
            clrscr();
            printf("\n This is Delete all Page");
            for (int i = 0 ; i < Employeeindex;i++)
            {
                E[i].ID = 0;
                E[i].Name[0] = '\0';
                E[i].Salary = 0;
                E[i].Net_salary = 0;
                E[i].Bonus = 0;
                E[i].Deduction = 0;
                printf("\n\n  All Employees Deleted");
            }
            getche();
        }
        else  ///Exit
        {
            Flag = 1;
            textattr(0X07);
            clrscr();
        }
    break;

    case 9: ///Tab
         cur++;
            if(cur>5)
              cur = 0;
    break;

    case 27: ///Esc
        Flag = 1;
    break;
    }

}///End of While
while(Flag == 0);
}

int Task_5()
{
    int x,y;
    printf("\n\n Enter Number 1 : ");
    scanf("%i", &x);

    printf("\n\n Enter Number 2 : ");
    scanf("%i", &y);

    printf("\n  The x value : %i  The y value : %i", x, y);
    swap(&x, &y);
    printf("\n  The x value : %i  The y value : %i", x, y);

    return 0;
}

int swap(int* x, int* y)
{
    int Temp;
    Temp = *x;
    *x = *y;
    *y = Temp;
}

int Task_6()
{
    int base = 0;
    int power = 0;
    printf("\n\n  Enter base : ");
    scanf("%i", &base);
    printf("\n\n  Enter power : ");
    scanf("%i", &power);
    printf("\n\n  The result is : %f", power_result(base, power));
    return 0;
}

float power_result(float base, float power)
{
    if (power < 0)
    {
        return (1.0 / base) * power_result(base, power + 1);
    }
    else if (power == 0)
    {
        return 1;
    }
    else
    {
        return base * power_result(base, power - 1);
    }
}


int Operations()
{
    int x;
    do
    {
    printf("\n Select Task to execute \n\n  1 : C program to take single Employee's information \n  2 : C Program to take information of Array of 5 Employees \n  3 : Employee with Functions (try to divide Ass#2 into 2 functions) \n  4 : Employee with functions and Highlight Menu: Menu of Array_Of_Struct \n  5 : C Program to swap 2 integer values \n  6 : Recursive Powers \n  7 : Exit Program \n \n");
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
