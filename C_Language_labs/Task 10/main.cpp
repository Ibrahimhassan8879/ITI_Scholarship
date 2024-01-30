#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "MyLibrary.h"
#include <unistd.h>
#define normalpen 0x0f
#define highlightpen 224
#define yellowpen 192
#define bluepen 176


///Define Constants
#define Menu_Content 6
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
#define Max_Name 100
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
#define Esc_Key2 27
#define BackSpace_Key 8
#define Del_Key 83
#define Tab_Key 9


//Functions declartions
int Display_One_Employee();
int Display_Employees();
int Menu_Borders();
void waitKey();



typedef struct employee
{int id,age;
    char gender[3], name[100],city[200];
    double salary, bonus, deduct;
}employee;

employee e [Max_Employee] = {0};


char** Multi_LineEditor(int c, int *size, int* xPos, int* yPos,char* sChar, char* eChar)
{
    // c -- number of lines ( also means no. of rows )
    // int *size --- pointer to an array that hold char array sizes in order.

     /*  Very impotrant !!!

            ptr : int** --> pointer to a pointer

            ptr[i]: int* --> pointer to a start of an array

            ptr[i][j]: int --> the value of an element inside the array.

     */


    int i , k = 0 , exitFlag = 0;
    char ch;

    // 1- creating the array of pointers
    char** ptr = (char**) malloc(c * sizeof(char*));

    // array of pointers to just point at the char arrays allocated by ptr in the for loop.
    char** pCurrent = (char**) malloc(c * sizeof(char*));
    char** pEnd = (char**) malloc(c * sizeof(char*));

    for(i = 0; i < c; i++)
    {
        // 2- creating an array linked to each of the pointers array.
        ptr[i] = (char*) malloc(size[i] *sizeof(char));

        //intilizing the pointers.
        pCurrent[i] = ptr[i];
        pEnd[i] = ptr[i];
    }



   /*  inside this function we still have :

                    1- array of xpos
                    2- array of ypos
                    3- array of start char
                    4- array of end char*/
    do{

            gotoxy(xPos[k],yPos[k]); // this is important for the movement of cursor
            ch = _getch();


            switch (ch)
            {
                case Down_Arrow_Key:

                    if (k < 7)
                    {
                        k++;
                    }
                    else{ k = 0;}
                    break;

                case Up_Arrow_Key:
                   if (k > 0)
                    {
                        k--;
                    }
                    else{ k = 7;}
                    break;

                case Tab_Key:
                    if (k < 7)
                    {
                        k++;
                    }
                    else{ k = 0;}
                    break;

                case Enter_Key: // we want to end the text and return it
                    for(int i = 0; i < c; i++)
                    {
                        *(pEnd[i]) = '\0';
                    }

                    // this (return statement) is how i get out of the while loop.
                    return ptr;
                    break;

                case Left_Arrow_Key:
                    if(pCurrent[k] > ptr[k])
                    {
                        --pCurrent[k];
                        --xPos[k];
                    }
                    break;

                case Right_Arrow_Key:
                    if(pCurrent[k] < pEnd[k])
                    {
                        ++pCurrent[k];
                        ++xPos[k];
                    }
                    break;
                case Home_Key:
                      // order of lines is IMPORTANT
                    xPos[k] = xPos[k] - (pCurrent[k] - ptr[k]);
                    pCurrent[k] = ptr[k];
                    break;

                case End_Key:
                    xPos[k] = xPos[k] + (pEnd[k] - pCurrent[k]);
                    pCurrent[k] = pEnd[k];
                    break;

                case Esc_Key:
                    gotoxy(0,30);
                    exit(1);


                default:  // the default makes it like we don't have a switch statement
                          // but if the switch cases are met "sometimes" then they are useful.

                    if (ch >= sChar[k] && ch <= eChar[k]  || ch =='.' || ch == ' ')
                    {


                            printf("%c",ch);
                            *(pCurrent[k]) = ch ;



                            if(pCurrent[k] == pEnd[k])
                            {
                                pEnd[k]++;
                            }

                            pCurrent[k]++;

                            xPos[k]++ ; // this will move the cursor in the horitzonatl postion.
                    }
            }
    }while (exitFlag == 0);

    free(pCurrent);
    free(pEnd);

}

add_employee()
{
    textattr(WhiteTextBlueBackground);
    // 8 data about each employee...
    char add_menu [Employee_Items][Max_Characters] = { "Employee ID      :  ", "Employee Age     :  ", "Employee Gender  :  ", "Employee Name    :  ","Employee Address   :  ", "Employee Salary    :  " , "Employee Bonus     :  " , "Employee Deduction :  "};

    int i , current = 0 , exitflag = 0, ch ;



    for (int i = 0; i < Employee_Items; i++)
        {

        gotoxy( Employee_Horizontal_Initial_Spacing + (i/Employee_Header_Items)*Employee_Horizontal_Spacing, Employee_Vertical_Initial_Spacing + (i%Employee_Header_Items)*Employee_Vertical_Spacing);
        puts(add_menu[i]);
        textattr(WhiteTextBlueBackground);
        }
        _flushall();

        // defining input arrays

        int c = 8;

        int size[]={3,3,2,20,20,10,10,10};

        int x []={30,30,30,30,85,85,85,85};
        int y []={8,13,18,23,8,13,18,23};

        char sChar[] ={'0','0','a','a','a','0','0','0'};
        char eChar[] ={'9','9','z','z','z','9','9','9'};

        char ** Data;

        Data = Multi_LineEditor(c, size, x, y, sChar, eChar);

        int id_temp = 0 , id_flag = 0;

    id_temp = atoi(Data[0]) ;



//     this is to be able to use the number inside arrays from 0 to 9
//     to represent 1 to 10.
    id_temp = id_temp -1;



        // memory storing.

        // 1- ID
    e[id_temp].id = atoi(Data[0]);

    // 2- AGE
    e[id_temp].age = atoi(Data[1]);


    // 3-storing Gender !! (special case) -- because we only want one char.

    // note: I forget to make the gender as  ( char gender[3]) and had it like ( char gender)
    //          which cannot be used with strcpy.... that's why I was getting that error.
    strcpy(e[id_temp].gender,Data[2]);


    // 4- Name

    strcpy(e[id_temp].name,Data[3]);


    // 5- city

   strcpy(e[id_temp].city,Data[4]);

    // 6- salary

    e[id_temp].salary = atof(Data[5]);

    // 7- overtime


    e[id_temp].bonus = atof(Data[6]);

    // 8- deduct

    e[id_temp].deduct = atof(Data[7]);


//        sleep(10);

    for(int i = 0; i < c; i++)
    {
        free(Data[i]);
    }

    free(Data);

    system("cls");



}

 void disp_id()
 {
    int id_temp = 0 , id_flag = 0;
    system("cls");

    printf("Please enter an Empolyee ID betweeen 1 and 10 \n");
    printf("Note: Be sure that you already registered it..... \n");
    printf(" ID is #  ");
    scanf("%i",&id_temp);

    // this is to be able to use the number inside arrays from 0 to 9
    // to represent 1 to 10.
    id_temp = id_temp -1;

    // this part to check if the number is correct
    // and if it's already stored or not

        if (id_temp < 0 || id_temp > 9)
        {
        system("cls");
        return;
        }

     for (int i = 0 ; i < 10; i++)
    {
        // if  the person with that index has age stored
        // then the values will be equaled.


        // note we have nested if's
        if (e[id_temp].age == 0)
        {
            system("cls");
            // gotoxy (position horizontally, position vertically )

//            gotoxy(40,12);
//            printf(" The ID has no data !!! Want to register it ? \n");

            gotoxy(35,15);
            textattr(bluepen);
            printf(" The ID # %i has no data !!! Want to register it ? ", id_temp+1);
            textattr(normalpen);
            gotoxy(40,18);
            printf(" if yes press 'y' else press 'n' ");

            int ch = _getche();

            // override check.
            if (ch == 'n')
                {
                    system("cls");

                    gotoxy(18,15);
                    textattr(yellowpen);
                    printf(" ***** You will get redirected to the (main menu) again in 5 seconds *** ");
                    textattr(normalpen);

                    // usleep( millli-second)

                    system("cls");

                    return;
                }
            else if ( ch == 'y')
                { add_employee();}



            }
        }

        system("cls");

        e[id_temp].id = id_temp +1;

        double net = e[id_temp].salary + e[id_temp].bonus - e[id_temp].deduct;

        gotoxy(4, 10);
        printf("  %-2i        %-2i        %c      %-18s  %-49s     %0.02lf\n", e[id_temp].id, e[id_temp].age, e[id_temp].gender[0], e[id_temp].name, e[id_temp].city, net);
        Display_One_Employee();
        waitKey();
    system("cls");


 }



disp_all()
{
    // now we will need the flag..
    // to check for the case that we don't have any data to show.
    int id_flag = 0 ;




     for (int i = 0 ; i < 10; i++)
    {
        // if  the person with that index has age stored
        // then the values will be equaled.


        // note we have nested if's
        if (e[i].age != 0)
        {
            double net = e[i].salary + e[i].bonus - e[i].deduct;
            gotoxy(4, 10 + i);
            printf("  %-2i        %-2i        %c      %-18s  %-49s     %0.02lf\n", e[i].id, e[i].age, e[i].gender[0], e[i].name, e[i].city, net);
            Display_Employees();

            // becuase this mean we found at least one employee.
            id_flag = 1;
        }
    }
    waitKey();
       if (id_flag == 0)
       {
           printf("no empolyee data has been entered previously.... \n");
           waitKey();
       }
       else{
        system("cls");
       }
}

void delete_id()
{

    int id_temp = 0 , id_flag = 0;
    system("cls");

    printf("Please enter an Empolyee ID betweeen 1 and 10 \n");
    printf("Note: Be sure that you already registered it..... \n");
    printf(" ID is #  ");
    scanf("%i",&id_temp);

    // this is to be able to use the number inside arrays from 0 to 9
    // to represent 1 to 10.
    id_temp = id_temp -1;

    // this part to check if the number is correct
    // and if it's already stored or not

        if (id_temp < 0 || id_temp > 9)
        {
        system("cls");
        return;
        }

        for (int i = 0 ; i < 10; i++)
        {
        // if  the person with that index has age stored
        // then the values will be equaled.


        // note we have nested if's
            if (e[id_temp].age != 0)
            {
                e[id_temp].age = 0;

                printf(" \n ID #%i has been deleted. \n", id_temp+1);
                printf("------------------------------------ \n");

            // becuase this mean we found at least one employee.
            id_flag = 1;

            }

        }

       if (id_flag == 0)
       {
           printf("no empolyee data with this id.... \n");
          printf("press any key to go back");

            _getch();

            system("cls");

       }
       else{

        printf("press any key to go back");

        _getch();
        system("cls");

       }



}







delete_name()
{
     char name[50];

    int id_flag = 0;

    system("cls");

    printf("Please enter an Empolyee name to be deleted \n");
    printf("Note: Be sure that you already registered it..... \n");
    printf(" Enter employee name:   ");

    _flushall();
    gets(name);

    // this is to be able to use the number inside arrays from 0 to 9
    // to represent 1 to 10.


    // this part to check if the number is correct
    // and if it's already stored or not



    for(int i = 0; i < 10; i++)
    {


        if( strcmp(name,e[i].name) == 0)
        {
            e[i].age = 0 ;
            id_flag = 1;

            printf("the user %s with id %i has been deleted",e[i].name,e[i].id);

        }


    }




       if (id_flag == 0)
       {
           printf("no data found to be deleted..... \n");
          printf("press any key to go back");

        _getch();
        system("cls");

       }
       else{

         printf("\n press any key to go back");

        _getch();
        system("cls");

       }
}


int main()
{

    // 6 options
    char Menu_Items [6][30] = { "1. Register New Employee", "2. Display Employee by ID",  "3. Display All", "4. Delete By ID", "5. Delete By Name","6. Exit"};

    int i , current = 0 , exitflag = 0, ch ;

//    char line [11] = malloc(sizeof(char)*11);

    // We will have everything inside a do- while
    // that will exit when the flag is met.

                //1- creating an array of 10 employees
                //and intializing every input to (zero)

    // we don't need struct, because we used (typedef)





// printf("test array : %i ", e[5].id);



do{
    // check this part.
    textattr(WhiteTextBlueBackground);
    clrscr();
    Menu_Borders();

    for (int i = 0; i < Menu_Content; i++)
    {
      if ( current == i )
      {
        textattr(YellowTextRedBackground);
      }

      /// Writing the Menu Content
      gotoxy(Menu_Horizontal_Initial_Spacing + (i/Menu_Header_Items)*Menu_Horizontal_Spacing, Menu_Vertical_Initial_Spacing + ((i%Menu_Header_Items - 1)+ 1)*Menu_Vertical_Spacing);
      puts(Menu_Items[i]);
      textattr(WhiteTextBlueBackground);
    }

    // we take a user input from _getch()
    // store it in ch
    // input ch to a switch st

    // put a break point here for tracing.

    // 2-  THIS PART: Where we start analysing (user input) and changing the highlighted
    //                based on it.  and based on currently highligted we will do an option.
    ch = _getch();

    switch (ch)
    {
        case Enter_Key:
            switch (current)
            {
                /*if currennt is 0 , it means it's highlighting (new)
                 and by pressing enter, we want a function to be done.

                 1- so new will clear the screen as if you you have a new window
                 2- then you can enter the name of your project before breaking out
                 */
                case 0: // new

                    // this clear, clears the window from the main menu
                    // before writing something related to (new)
                     clrscr();
                     Menu_Borders();
                     add_employee();
                break;

                case 1: // Display by id
                    disp_id();
                break;

                case 2: // Display all
                    clrscr();
                    disp_all();
                break;

                case 3: // delete by id
                    delete_id();
                break;

                case 4: // delete by name
                    delete_name();
                break;

                case 5: // exit
                    exitflag = 1 ;
                break;
            }
            break;

        case Esc_Key:
            exitflag = 1;
            break;

        // if it's not (enter ) or (esc), check the following

        case 224 : // extended key   //0xfffffeo I wrote it wrong, search for it.



            // we look for the second byte after finding the an extended key.

            ch = _getch();
            switch(ch)
            {
                case Up_Arrow_Key : //up

                    // as the current number increase going down for the menu
                    // if we want to go up we have to decrease it.
                    current --;

                    // this if condition to make sure if we go out of limit
                    // it loops the selection to the highest in the menu
                    if (current < 0) current = 5;
                    break;


                case Down_Arrow_Key : // down
                    current ++;
                    if(current >5) current = 0;
                    break;


                case Home_Key: //home

                    // (home) takes u to the most upper value.
                    current = 0;
                    break;

                case End_Key: // end

                    // (end) takes u to the most lower value.
                    current = 5;
                    break;
            }
            break;
    }

}
while(exitflag == 0);



}

int Menu_Borders()
{
    gotoxy(1, 1);
    printf("______________________________________________________________________________________________________________________");
    printf("\n\n");
    printf("                Employees Menu Task  -  By Ibrahim Hassan Ibrahim - Dynamic Multi Line Editor version ");
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
    printf("                Employees Menu Task  -  By Ibrahim Hassan Ibrahim - Dynamic Multi Line Editor version ");
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
    printf("                Employees Menu Task  -  By Ibrahim Hassan Ibrahim - Dynamic Multi Line Editor version ");
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

void waitKey()
{
    _flushall();
    printf("\n\n  (press any key to continue)");
    _getch();
    _flushall();
}
