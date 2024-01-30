#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "MyLibrary.h"
#define NotFound "\n  This employee wasn't found.\n"

///Define Constants
#define Menu_Content 8
#define Menu_Header_Items 4
#define Menu_Horizontal_Spacing 62
#define Menu_Vertical_Spacing 5
#define Menu_Horizontal_Initial_Spacing 15
#define Menu_Vertical_Initial_Spacing 8
#define Line_Size 15

#define MenuBorder_Initial_Horizontal 1
#define MenuBorder_Initial_Vertical 2
#define MenuBorder_Horizontal_Lines_spacing 20
#define MenuBorder_Vertical_Lines_spacing 116
#define MenuBorder_Vertical_OutLine_Length 25
#define MenuBorder_MiddleLine_Horizontal 55
#define MenuBorder_MiddleLine_Vertical 5
#define MenuBorder_MiddleLine_Length 22

#define Employee_Items 8
#define Employee_Header_Items 4
#define Employee_Horizontal_Spacing 55
#define Employee_Vertical_Spacing 5
#define Employee_Horizontal_Initial_Spacing 10
#define Employee_Vertical_Initial_Spacing 8

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
#define Del_Key 83
#define Tab_Key 9

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
int EmployeeFound(Employee *Emp, int ID);
bool displayEmployeeID(Employee *emp, int id);
bool displayEmployeeName(Employee *emp, char *Name);
void displayEmployeeIndex(Employee *emp, int i);
void waitKey();
void displayEmployees(Employee *emp);
void deleteEmployeeIndex(Employee *emp, int index, int currentEmp);
int areYouSureDelete(Employee *emp, int index, int currentEmp);
int deleteEmployeeID(Employee *emp, int id, int currentEmp);
int deleteEmployeeName(Employee *emp, char name[100], int currentEmp);
int Menu_Borders();
int Display_One_Employee();
int Display_Employees();




int main()
{
  //Define Local variables
  char Menu_Items[Menu_Content][Max_Characters] = { "1. Register New Employee", "2. Display Employee by ID", "3. Display Employee by Name", "4. Display All", "5. Delete By ID", "6. Delete By Name", "7. Delete All", "8. Exit"};
  Employee Emp[Max_Employee] = {};
  int Key_Entered;
  int Employee_Index = 0;
  int cursour = 0;
  int Exit_Flag = 1;
  Employee Emp_Temp = {};
  int ID;
  char nameTemp[100];
  char Del;

  do
  {
    /// Initiate Blue Screen with White text bold
    textattr(WhiteTextBlueBackground);
    clrscr();
    Menu_Borders();

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
          case 0: //Register page
            clrscr();
            Menu_Borders();
            if (Employee_Index < Max_Employee)
            {
              Emp_Temp = GetEmployee();


              if (!EmployeeFound(Emp, Emp_Temp.ID))
              {
                Emp[Employee_Index++] = Emp_Temp;
              }
              else
              {
                printf("\n  You have already Employee at This ID Exists !");
                getch();
              }
            }
            else
            {
              printf("\n  You have the Maximum amount of Employees Registered");
              getch();
            }
            break;
        case 1: //Display by ID page
              clrscr();
              _flushall();
              printf("\n\n  Please Enter the employee ID to be displayed: ");
              _flushall();
              scanf("%i", &ID);
              _flushall();
              if (displayEmployeeID(Emp, ID))
              {
                clrscr();
                displayEmployeeID(Emp, ID);
                Display_One_Employee();
              }
              waitKey();
              break;
        case 2: //Display by Name
              clrscr();
              printf("\n\n  Please Enter the Employee Name to be displayed: ");
              _flushall();
              gets(nameTemp);
              _flushall();
              if (displayEmployeeName(Emp, nameTemp))
              {
                clrscr();
                displayEmployeeName(Emp, nameTemp);
                Display_One_Employee();
              }
              waitKey();
              break;
        case 3: //Display All
              clrscr();
              displayEmployees(Emp);
              Display_Employees();
              waitKey();
              break;
        case 4: //Delete by ID
            clrscr();
            printf("\n\n  Please enter the employee ID to be DELETED: ");
            _flushall();
            scanf("%i", &ID);
            _flushall();
            if (deleteEmployeeID(Emp, ID, Employee_Index))
                Employee_Index--;
            waitKey();
            break;
        case 5: //Delete by Name
            clrscr();
            printf("\n\n  Please enter the employee Name to be DELETED: ");
            _flushall();
            gets(nameTemp);
            if (deleteEmployeeName(Emp, nameTemp, Employee_Index))
                Employee_Index--;
            waitKey();
            break;
        case 6: //Delete All
            clrscr();
            printf("\n\n  Are you sure that you want to Delete all Employees ? (Y/N)");
            scanf("%c",&Del);
            if (Del == 'Y' || Del == 'y')
            {
                for (int i = Employee_Index; i >= 0;i--)
                {
                    deleteEmployeeIndex(Emp, i, Employee_Index);
                }
            }
            else
            {
                break;
            }
            break;
        case 7: //Exit
            Exit_Flag = 0;
            printf("\n\n\n");
            break;
        }
        break;
      case Tab_Key:
          cursour = cursour >= Menu_Content - 1 ? 0 : cursour + 1;
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
          cursour = Menu_Content - 1;
          break;
        }
    break;
    }

  }while( Exit_Flag != 0 );
  return 0;
}


int Getx(int i)
{
  int location = Employee_Horizontal_Initial_Spacing + (i/Employee_Header_Items)*Employee_Horizontal_Spacing + 22;
  return location;
}

int Gety(int i)
{
  int location =  Employee_Vertical_Initial_Spacing + (i%Employee_Header_Items)*Employee_Vertical_Spacing ;
  return location;
}

void gotoInput(int i)
{
  gotoxy(Getx(i), Gety(i));
}

void printSpaces(int index)
{
  gotoInput(index);
  for (int i = 0; i < Line_Size; i++)
  {
    printf(" ");
  }
  gotoInput(index);
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
        case Del_Key:
            line[CurrentColumn - x] = ' ';
            CurrentColumn = CurrentColumn > StartColumn ? CurrentColumn - 1 : CurrentColumn;
             for (int i = StartColumn; i < EndColumn; i++)
             {
                 printf(" ");
             }
        }
        break;

      case Enter_Key:
        Exit_Flag = 0;
        break;
      case BackSpace_Key:
        line[CurrentColumn - x ] = ' ';
        for (int i = 0; i < (EndColumn - CurrentColumn); i++)
        {
            line[CurrentColumn - x + i] = line[CurrentColumn - x + i + 1];
            printf("%c", line[CurrentColumn - x + i]);
        }
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
      printf("\n\n");
      waitKey();


  _flushall();
  return Emp;
}


// Display by ID function
bool displayEmployeeID(Employee *emp, int id)
{
    for (int i = 0; i < Max_Employee; i++)
    {
        // display Employee info if the ID matches
        if (id == emp[i].ID && strcmp("", emp[i].Name) != 0)
        {
            gotoxy(4,10 + i);
            displayEmployeeIndex(emp, i);
            return true;
        }
    }

    printf(NotFound);
    return false;
}

bool displayEmployeeName(Employee *emp, char *Name)
{
    for (int i = 0; i < Max_Employee; i++)
    {
        if (strcmp(Name, emp[i].Name) == 0)
        {
            gotoxy(4,10 + i);
            displayEmployeeIndex(emp, i);
            return true;
        }
    }
    printf(NotFound);
    return false;
}

void displayEmployeeIndex(Employee *emp, int i)
{
  printf("  %-2i        %-2i        %-1c      %-18s  %-49s     %-5d\n", emp[i].ID, emp[i].Age, emp[i].Gender, emp[i].Name, emp[i].Address, emp[i].Salary + emp[i].Bonus - emp[i].Deduction);
}


void waitKey()
{
    _flushall();
    printf("\n\n  (press any key to continue)");
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
            gotoxy(4,10 + i);
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
    clrscr();
    gotoxy(4, 10);
    displayEmployeeIndex(emp, index);
    Display_One_Employee();
    char sure;
    do
    {
        printf("\n\n\n  Are you sure you want to delete this employee? (y/n)\n");
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
  return 0; // Add this line to handle cases where the loop does not find a match
}

int EmployeeFound(Employee *Emp, int ID)
{
    int i;

    for (i = 0; i< Max_Employee; i++)
    {
        if ( ID == Emp[i].ID)
        {
            return true;
        }
    }
    return false;
}

int Menu_Borders()
{
    gotoxy(1, 1);
    printf("______________________________________________________________________________________________________________________");
    printf("\n\n");
    printf("                   Employees Menu Task  -  By Ibrahim Hassan Ibrahim - Static Line Editor version ");
    printf("\n");
    printf("  ___________________________________________________________________________________________________________________");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf(" _____________________________________________________________________________________________________________________");

    for (int i = 0; i < 2*MenuBorder_Vertical_OutLine_Length; i++)
    {
        gotoxy(MenuBorder_Initial_Horizontal + (i/MenuBorder_Vertical_OutLine_Length)*MenuBorder_Vertical_Lines_spacing, MenuBorder_Initial_Vertical + ((i%MenuBorder_Vertical_OutLine_Length - 1)+ 1)*1);
        puts("||");
    }
    for (int i = 0; i < MenuBorder_MiddleLine_Length; i++)
    {
        gotoxy(MenuBorder_MiddleLine_Horizontal + (i/MenuBorder_MiddleLine_Length)*MenuBorder_Vertical_Lines_spacing, MenuBorder_MiddleLine_Vertical + ((i%MenuBorder_MiddleLine_Length - 1)+ 1)*1);
        puts("||");
    }
    return 1;
}

int Display_Employees()
{
    gotoxy(1, 1);
    printf("______________________________________________________________________________________________________________________");
    printf("\n\n");
    printf("                   Employees Menu Task  -  By Ibrahim Hassan Ibrahim - Static Line Editor version ");
    printf("\n");
    printf("                                              Employees Data Table                                                   ");
    printf("    ____________________________________________________________________________________________________________________");
    printf("\n\n");
    printf("      ID       Age     Gender    Name                Address                                             Net Salary  ");
    printf("    ____________________________________________________________________________________________________________________");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf(" _____________________________________________________________________________________________________________________");

    for (int i = 0; i < 2*MenuBorder_Vertical_OutLine_Length; i++)
    {
        gotoxy(MenuBorder_Initial_Horizontal + (i/MenuBorder_Vertical_OutLine_Length)*MenuBorder_Vertical_Lines_spacing, MenuBorder_Initial_Vertical + ((i%MenuBorder_Vertical_OutLine_Length - 1)+ 1)*1);
        puts("||");
    }
    for (int i = 0; i < 3*21; i++)
    {
        gotoxy(11 + (i/21)*10, 6 + ((i%21 - 1)+ 1)*1);
        puts("|");
    }
    for (int i = 0; i < 1*21; i++)
    {
        gotoxy(51 + (i/21)*22, 6 + ((i%21 - 1)+ 1)*1);
        puts("|");
    }
    for (int i = 0; i < 1*21; i++)
    {
        gotoxy(101 + (i/21)*15, 6 + ((i%21 - 1)+ 1)*1);
        puts("|");
    }
    return 1;
}

int Display_One_Employee()
{
    gotoxy(1, 1);
    printf("______________________________________________________________________________________________________________________");
    printf("\n\n");
    printf("                   Employees Menu Task  -  By Ibrahim Hassan Ibrahim - Static Line Editor version ");
    printf("\n");
    printf("                                              Employees Data Table                                                   ");
    printf("    ____________________________________________________________________________________________________________________");
    printf("\n\n");
    printf("      ID       Age     Gender    Name                Address                                             Net Salary  ");
    printf("    ____________________________________________________________________________________________________________________");
    printf("\n\n\n");
    printf(" _____________________________________________________________________________________________________________________");

    for (int i = 0; i < 2*10; i++)
    {
        gotoxy(MenuBorder_Initial_Horizontal + (i/10)*MenuBorder_Vertical_Lines_spacing, MenuBorder_Initial_Vertical + ((i%10 - 1)+ 1)*1);
        puts("||");
    }
    for (int i = 0; i < 3*6; i++)
    {
        gotoxy(11 + (i/6)*10, 6 + ((i%6 - 1)+ 1)*1);
        puts("|");
    }
    for (int i = 0; i < 1*6; i++)
    {
        gotoxy(51 + (i/6)*22, 6 + ((i%6 - 1)+ 1)*1);
        puts("|");
    }
    for (int i = 0; i < 1*6; i++)
    {
        gotoxy(101 + (i/6)*15, 6 + ((i%6 - 1)+ 1)*1);
        puts("|");
    }
    return 1;
}

