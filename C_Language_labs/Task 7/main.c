#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "F:\ITI_Work\Sync_Files\6-C\Labs\Day_4\MyLibrary.h"
#define NotFound "\nThis employee wasn't found.\n"

///Define Constants
#define Menu_Content 6
#define Menu_Header_Items 3
#define Menu_Horizontal_Spacing 40
#define Menu_Vertical_Spacing 5
#define Menu_Horizontal_Initial_Spacing 2
#define Menu_Vertical_Initial_Spacing 2
#define Line_Size 15

#define Employee_Items 8
#define Employee_Header_Items 4
#define Employee_Horizontal_Spacing 40
#define Employee_Vertical_Spacing 5
#define Employee_Horizontal_Initial_Spacing 2
#define Employee_Vertical_Initial_Spacing 2

#define Max_Employee 10
#define Max_Characters 30
#define Max_Name 30
#define WhiteTextBlueBackground 0x1E
#define YellowTextRedBackground 0x4F


#define Extended_Key_1 0
#define Extended_Key_2 -32
#define Extended_Key_3 224

#define Up_Arrow_Key 72
#define Down_Arrow_Key 80
#define Right_Arrow_Key 77
#define Left_Arrow_Key 75
#define Home_Key 71
#define End_Key 79
#define Enter_Key 13
#define Esc_Key 27
#define BackSpace_Key 8



typedef struct Employee
{
  int ID;
  char Name[Max_Name];
  char Address[Max_Characters];
  char Gender;
  int Age;
  int Salary;
  int Bonus;
  int Deduction;
  int Flag;
  int Net_salary;
}Employee;

/// Functions Prototypes
int Getx(int i);
int Gety(int i);
void gotoInput(int i);
void printSpaces(int i);
void highlightInput(int i);
void lowlightInput(int i,char *line);
void lineEditor(int x, int y, char Fchar, char Lchar, char *line);
int GetInt(int i);
int GetDouble(int i);
void GetString(int i, char *line);
Employee GetEmployee();
int EmployeeFound(Employee *Emp, int ID)
{
  return 0;
}
void displayEmployeeID(Employee *emp, int id);
void displayEmployeeIndex(Employee *emp, int i);
void waitKey();
void displayEmployees(Employee *emp);
void deleteEmployeeIndex(Employee *emp, int index, int currentEmp);
int areYouSureDelete(Employee *emp, int index, int currentEmp);
int deleteEmployeeID(Employee *emp, int id, int currentEmp);
int deleteEmployeeName(Employee *emp, char name[100], int currentEmp);




int main()
{
  //Define Local variables
  char Menu_Items[Menu_Content][Max_Characters] = { "Register New Employee", "Display Employee by ID", "Display All", "Delete By Id", "Delete ALL", "Exit"};
  Employee Emp[Max_Employee] = {};
  int Key_Entered;
  int Employee_Index = 0;
  int cursour = 0;
  int Exit_Flag = 1;
  Employee Emp_Temp = {};
  int ID;
  char nameTemp[100];

  do
  {
    /// Initiate Blue Screen with White text bold
    textattr(WhiteTextBlueBackground);
    clrscr();

    for (int i = 0; i < Menu_Content; i++)
    {
      if ( cursour == i )
      {
        textattr(YellowTextRedBackground);
      }

      /// Writing the Menu Content
      gotoxy(Menu_Horizontal_Initial_Spacing + (i/Menu_Header_Items)*Menu_Horizontal_Spacing, Menu_Vertical_Initial_Spacing + ((i%Menu_Header_Items - 1)+ 1)*Menu_Vertical_Spacing);
      puts(Menu_Items[i]);
      textattr(WhiteTextBlueBackground);
    }

    Key_Entered = getch();

    ///Switch Keys cases with first switch for Extended Keys
    switch(Key_Entered)
    {
      case Esc_Key:
        Exit_Flag = 0;
        break;
      case Enter_Key:
        switch(cursour)
        {
          case 0:
            clrscr();
            if (Employee_Index < Max_Employee)
            {
              Emp_Temp = GetEmployee();


              if (!EmployeeFound(Emp, Emp_Temp.ID))
              {
                Emp[Employee_Index++] = Emp_Temp;
              }
              else
              {
                printf("\n\n  You have already Employee at This ID Exists !");
                getch();
              }
            }
            else
            {
              printf("\n\n  You have the Maximum amount of Employees Registered");
              getch();
            }
            break;
        case 1: //Display by ID page
              clrscr();
              _flushall();
              printf(" Please Enter the employee ID to be displayed: ");
              scanf("%i", &ID);
              _flushall();
              displayEmployeeID(Emp, ID);
              waitKey();
              break;
        case 2: //Display all employees
              clrscr();
              displayEmployees(Emp);
              waitKey();
              break;
        case 3:
            clrscr();
            printf("Please enter the employee Name to be DELETED: ");
            _flushall();
            gets(nameTemp);
            if (deleteEmployeeName(Emp, nameTemp, Employee_Index))
                Employee_Index--;
            waitKey();
            break;
        case 5:
            Exit_Flag = 1;
            break;
        }
        break;

      case Extended_Key_1:
      case Extended_Key_2:
      case Extended_Key_3:

        Key_Entered = getch();
        switch(Key_Entered)
        {
        case Up_Arrow_Key:
          cursour = cursour <= 0 ? Menu_Content - 1 : cursour - 1;
          break;
        case Down_Arrow_Key:
          cursour = cursour >= Menu_Content - 1 ? 0 : cursour + 1;
          break;
        case Left_Arrow_Key:
          cursour = cursour <= Menu_Header_Items - 1 ? cursour + Menu_Header_Items : cursour - Menu_Header_Items;
          break;
        case Right_Arrow_Key:
          cursour = cursour >= Menu_Header_Items ? cursour - Menu_Header_Items : cursour + Menu_Header_Items;
          break;
        case Home_Key:
          cursour = 0;
          break;
        case End_Key:
          cursour = Menu_Items - 1;
          break;
        }
    break;
    }

  }while( Exit_Flag != 0 );
  return 0;
}


int Getx(int i)
{
  int location = (i/Employee_Header_Items)*Employee_Horizontal_Spacing + 22;
  return location;
}

int Gety(int i)
{
  int location = (i%Employee_Header_Items)*Employee_Vertical_Spacing + Employee_Vertical_Initial_Spacing;
  return location;
}

void gotoInput(int i)
{
  gotoxy(Getx(i), Gety(i));
}

void printSpaces(int i)
{
  gotoInput(i);
  for (int i = 0; i < Line_Size; i++)
  {
    printf(" ");
  }
  gotoInput(i);
}

void highlightInput(int i)
{
  textattr(YellowTextRedBackground);
  printSpaces(i);
}

void lowlightInput(int i,char *line)
{
  textattr(WhiteTextBlueBackground);
  gotoInput(i);

  printf("%s", line);

  int len = strlen(line);
  for (int j = 0; j < Line_Size - len; j++)
  {
    printf(" ");
  }
}

void lineEditor(int x, int y, char Fchar, char Lchar, char *line)
{
  int StartColumn = x, CurrentColumn = x, EndColumn = x, MaxColumn = x + Line_Size, Exit_Flag = 1;
  char Key;

  do
  {
    gotoxy(CurrentColumn, y);
    Key = getch();

    switch (Key)
    {
      case Extended_Key_1:
      case Extended_Key_2:
      case Extended_Key_3:
        Key = getch();
        switch(Key)
        {
        case Left_Arrow_Key:
          CurrentColumn = CurrentColumn > StartColumn ? CurrentColumn - 1 : CurrentColumn;
          break;
        case Right_Arrow_Key:
          CurrentColumn = CurrentColumn < EndColumn ? CurrentColumn + 1 : CurrentColumn;
          break;
        case Home_Key:
          CurrentColumn = StartColumn;
          break;
        case End_Key:
          CurrentColumn = EndColumn;
          break;
        }
        break;

      case Enter_Key:
        Exit_Flag = 0;
        break;
      case BackSpace_Key:
        line[CurrentColumn - x ] = " ";
        CurrentColumn = CurrentColumn > StartColumn ? CurrentColumn - 1 : CurrentColumn;
        printf(" ");
        break;
      case Esc_Key:
        textattr(WhiteTextBlueBackground);
        clrscr();
        _Exit(0);
        break;
      default:

        if ( CurrentColumn < MaxColumn && ((Key >= Fchar && Key <= Lchar) || Key == ' '))
        {
          line[CurrentColumn - x] = Key;
          printf("%c", Key);
          if (CurrentColumn == EndColumn)
          {
            EndColumn++;
          }
          CurrentColumn++;
        }
    }
  }while(Exit_Flag != 0);
}

int GetInt(int i)
{
  char line[Line_Size + 1] = {};
  do
  {
    highlightInput(i);
    lineEditor(Getx(i), Gety(i), 48 , 57 , line);
  }while ( strcmp(line,"") == 0);

  lowlightInput(i,line);

  return atoi(line);
}

int GetDouble(int i)
{
  char line[Line_Size + 1] = {};
  do
  {
    highlightInput(i);
    lineEditor(Getx(i),Gety(i),48,57,line);
  }while( strcmp(line,"") == 0);
  lowlightInput(i,line);
  char *tempChar;

  return strtod(line, &tempChar);
}

void GetString(int i, char *line)
{
  do
  {
    highlightInput(i);
    lineEditor(Getx(i), Gety(i), 65, 122, line);
  }while ( strcmp(line,"") == 0);
  lowlightInput(i, line);
}


Employee GetEmployee()
{
    int cursour = 0;
    int Key_Entered;
    char Name[Line_Size + 1] = {};
    char Address[Line_Size + 1]= {};
    textattr(WhiteTextBlueBackground);
    char Employee_Menu[Employee_Items][Max_Characters] = { "Employee ID      :  ", "Employee Age     :  ", "Employee Gender  :  ", "Employee Name    :  ","Employee Address   :  ", "Employee Salary    :  " , "Employee Bonus     :  " , "Employee Deduction :  "};
    Employee Emp;
    int i = 0;

  for (int i = 0; i < Employee_Items; i++)
  {

    gotoxy( Employee_Horizontal_Initial_Spacing + (i/Employee_Header_Items)*Employee_Horizontal_Spacing, Employee_Vertical_Initial_Spacing + (i%Employee_Header_Items)*Employee_Vertical_Spacing);
    puts(Employee_Menu[i]);
    textattr(WhiteTextBlueBackground);
  }
      _flushall();

      i = 0;

      Emp.ID = GetInt(i++);

      Emp.Age = GetInt(i++);

      highlightInput(i);
      do
      {
        gotoInput(i);
        for (int i = 0; i < Line_Size; i++)
        {
          printf(" ");
        }
        gotoInput(i);
        scanf("%c", &Emp.Gender);
      }while( Emp.Gender != 'M' && Emp.Gender != 'F' && Emp.Gender != 'm' && Emp.Gender != 'f');
      lowlightInput(i++, &Emp.Gender);

      _flushall();


      GetString(i++, Name);
      strcpy(Emp.Name,Name);

      GetString(i++, Address);
      strcpy(Emp.Address, Address);

      Emp.Salary = GetDouble(i++);

      Emp.Bonus = GetDouble(i++);

      Emp.Deduction = GetDouble(i++);


  _flushall();
  return Emp;
}


// Display by ID function
void displayEmployeeID(Employee *emp, int id)
{
    for (int i = 0; i < Max_Employee; i++)
    {
        // display Employee info if the ID matches
        if (id == emp[i].ID && strcmp("", emp[i].Name) != 0)
        {
            displayEmployeeIndex(emp, i);
            return;
        }
    }

    printf(NotFound);
}

void displayEmployeeIndex(Employee *emp, int i)
{
    printf("\n Employee ID: %i. Employee Name : %s, Employee Net Salary :$%.2lf\n\n", emp[i].ID, emp[i].Name, emp[i].Salary + emp[i].Bonus - emp[i].Deduction);
}

void waitKey()
{
    _flushall();
    printf("\n\n\n(press any key to continue)");
    _getch();
    _flushall();
}

/*
    displays all employees from emp array
*/
void displayEmployees(Employee *emp)
{
    // records if the list empty or not
    int empty = 0;
    for (int i = 0; i < Max_Employee; i++)
    {
        // display Employee info if exists
        if (strcmp("", emp[i].Name) != 0)
        {
            empty++;
            displayEmployeeIndex(emp, i);
        }
    }

    if (!empty)
        printf("There are no employees, yet");
}

/*
    delete an employee from the emp Arr using its index, and shift all other elements left
    up to currentEmp
*/
void deleteEmployeeIndex(Employee *emp, int index, int currentEmp)
{
    currentEmp = currentEmp == Max_Employee ? currentEmp - 1 : currentEmp;

    for (int i = index; i < currentEmp - 1; i++)
    {
        emp[i] = emp[i+1];
    }

    emp[currentEmp - 1].ID = -1;
    strcpy(emp[currentEmp - 1].Name, "");
}

/*
    confirms from the user to delete an employee from the emp Arr using its index,
    and shift all other elements left up to currentEmp
*/
int areYouSureDelete(Employee *emp, int index, int currentEmp)
{
    displayEmployeeIndex(emp, index);
    char sure;
    do
    {
        printf("Are you sure you want to delete this employee? (y/n)\n");
        scanf("%c", &sure);
    }
    while (sure != 'y' && sure != 'n');

    if (sure == 'y')
    {
        deleteEmployeeIndex(emp, index, currentEmp);
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
    delete an employee from the emp Arr using its ID, and shift all other elements left
    up to currentEmp
*/
int deleteEmployeeID(Employee *emp, int id, int currentEmp)
{
    for (int i = 0; i < Max_Employee; i++)
    {
        // delete Employee info if the ID matches
        if (id == emp[i].ID && strcmp("", emp[i].Name) != 0)
        {
            // ask the user if he is sure to delete this emp
            return areYouSureDelete(emp, i, currentEmp);
        }
    }

    printf(NotFound);

    return 0;
}

/*
    delete an employee from the emp Arr using its Name, and shift all other elements left
    up to currentEmp
*/
int deleteEmployeeName(Employee *emp, char name[100], int currentEmp)
{
    for (int i = 0; i < Max_Employee; i++)
    {
        // delete Employee info if the name matches
        if (strcmp(name, emp[i].Name) == 0 && strcmp("", emp[i].Name) != 0)
        {
            // ask the user if he is sure to delete this emp
            return areYouSureDelete(emp, i, currentEmp);
        }
    }

    printf(NotFound);

    return 0;
}
