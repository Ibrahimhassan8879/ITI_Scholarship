#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "F:\ITI_Work\Sync_Files\6-C\Labs\Day_4\MyLibrary.h"


typedef struct Employee
{
    int ID;
    char Name[10];
    int Salary;
    int Bonus;
    int Deduction;
    int Flag;
    int Net_salary;
}Employee;

Employee Addnewemployee()
{
    Employee E;
    printf("\n\n  Enter the Employee Data : (ID, Name, Salary, Bonus, Deduction)");
    scanf("%i %s %i %i %i", &E.ID, &E.Name, &E.Salary, &E.Bonus, &E.Deduction);
    E.Net_salary = E.Salary + E.Bonus - E.Deduction;
    E.Flag = 1;
    return E;
}

int DisplayEmployee(Employee E)
{
    E.Net_salary = E.Salary + E.Bonus - E.Deduction;
    if ( E.Flag == 1)
    {
        printf("\n\n  The Employee Data \n\n  ID       : %6d     Name         : %-20s\n  Salary   : %6d     Bonus        : %6d\n  Deduction: %6d     Net_Salary   : %6d\n ==============================================",
    E.ID, E.Name, E.Salary, E.Bonus, E.Deduction, E.Net_salary);
    }
    else
    {
        printf("\n\n  Employee Not found");
    }
    return 0;

}

int main()
{
    char ch;
    Employee E[10];
    int cursour = 1;
    int Menu_Flag = 0;
    int Max_Employee = 0;
    char Menu[6][15] = {"NEW", "DISPLAY","Display All","Delete", "Delete All", "EXIT"};
    do
    {
        /// Setting default background color
        textattr(0x1E);
        clrscr();
        for (int i = 0; i < 6;i++)
        {
            if ( cursour == i )
            {
                textattr(0x4F); /// RED WITH BLUE BACKGROUND WITH BOLD
            }
            else
            {
                textattr(0x1E);
            }
            gotoxy(5, 2 + i*5);
            printf("%s", Menu[i]);
        }

        /// Getting user selection
        ch = getche();
        switch(ch)
        {
            /// if extended keys
            case 0:
            case -32:
            case 224:

            ch = getche();
            switch(ch)
            {
                case 72:   ///Up
                case 73:  /// page Up
                    cursour--;
                    if(cursour<0)
                        cursour = 5;
                break;

                case 80:   ///Down
                case 81:   ///page Down
                    cursour++;
                    if(cursour>5)
                        cursour = 0;
                break;

                case 71: ///Home
                    cursour = 0;
                break;

                case 79: ///End
                    cursour = 5;
                break;
            }
            break;

            case 13:    ///Enter
                if ( cursour == 0 )
                {
                    clrscr();
                    printf("\n\n    This is New page");
                    if ( Max_Employee < 10 )
                    {
                        E[Max_Employee] = Addnewemployee();
                        Max_Employee++;
                    }
                    else
                    {
                        printf("\n\n You Have reached the max amount of Employees");
                    }
                    getche();
                }

                else if ( cursour == 1 )
                {
                    clrscr();
                    int x;
                    printf("\n\n    This is Display Screen");
                    printf("\n\n    Select Employee to show by ID : ");
                    scanf("%i", &x);
                    for (int i = 0; i < Max_Employee; i++)
                    {
                        if (E[i].ID == x)
                        {
                            DisplayEmployee(E[i]);
                        }
                    }
                    getche();
                }
                else if ( cursour == 2 )
                {
                    clrscr();
                    printf("\n\n   This is Display all Screen");
                    for (int i = 0; i < Max_Employee; i++)
                    {
                        if (E[i].Flag == 1)
                        {
                            DisplayEmployee(E[i]);
                        }
                    }
                    getche();
                }
                else if ( cursour == 3)
                {
                    clrscr();
                    int x;
                    printf("\n\n   This is Delete Employee Screen");
                    printf("\n\n   Enter the Employee ID to DELETE :  ");
                    scanf("%i", &x);
                    for (int i = 0; i < Max_Employee; i++)
                    {
                        if (E[i].ID == x && E[i].Flag == 1)
                        {
                            E[i].Flag = 0;
                            printf("\n\n   Employee ID : %i Has been Deleted", E[i].ID);
                        }
                    }
                    getche();
                }
                else if ( cursour == 4)
                {
                    clrscr();
                    char x;
                    printf("\n\n   This is Delete ALL screen ....");
                    printf("\n\n   Are you sure that you want to Delete all Employees (Y/N) : ");
                    scanf("%c", &x);
                    if ( x == 'Y' || x == 'y')
                    {
                        for (int i = 0; i < Max_Employee ; i++)
                        {
                            E[i].Flag = 0;
                        }
                        printf("\n\n   All Employees Has been Deleted Successfully ....");
                    }
                    else if ( x == 'N' || x == 'n')
                    {
                        getche();
                    }
                    getche();
                }
                else
                {
                    clrscr();
                    char x;
                    printf("\n\n   Are you sure that you want to Exit ? (Y/N) : ");
                    scanf("%c", &x);
                    if ( x == 'Y' || x == 'y')
                    {
                        Menu_Flag = 1;
                        textattr(0X07);
                        clrscr();
                    }
                    else if ( x == 'N' || x == 'n')
                    {
                        break;
                    }
                }
            break;
            case 9:    ///Tab
                (cursour > 5)?0:cursour++;
                break;
            case 27:   ///Esc
                Menu_Flag = 1;
                break;
        }
    }while (Menu_Flag == 0);
}
