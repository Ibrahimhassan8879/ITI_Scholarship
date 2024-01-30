#include <iostream>


// without using copy constructor
/*
    we have the the viewContent function
    1. pass by value
    2. pass by referance

    we have the reverse function
*/
using namespace std;


class Mystack
{
    int *stk;
    int Tos;
    int Size;

public:
    //Constructors
    Mystack(int S)
    {
        Size = S;
        Tos = 0;
        stk = new int[Size];
        cout << "Constuctor\n";
    }
    // Destructor
    /*

    */
    //Function passing by value
    //friend void viewContent ( Mystack S1);
    // Functions passing by referance
    friend void viewContent ( Mystack &S1);

    Mystack Reverse()
    {
        Mystack S1(Size);
        int x = Tos - 1;
        cout << " Number : ";
        for (int i = 0; i < Tos; i ++)
        {
            cout << i << ":"<<stk[x] << ", ";
            S1.stk[i] = stk[x--];
        }
        S1.Tos = Tos;
        return S1;
    }
    int Isempty()
    {
        return Tos==0;
    }
    int Isnull()
    {
        return Tos == Size;
    }
    void Push(int N)
    {
        if (!Isnull())
        {
            stk[Tos++] = N;
        }
    }
    int Pop()
    {
        if (!Isempty())
        {
            cout << "\nPop is declared\n";
            return stk[--Tos];
        }
        else
        {
            cout << "Stack is Empty"<< endl;
            return 1;
        }
    }
    void print()
    {
        cout << "The last element is : " << stk[Tos-1] << endl;
    }
    ~Mystack()
    {
        for (int i = 0; i < Tos; i++)
        {
            stk[i] = -1;
        }
        cout << "\n The distructor\n";
        delete []stk;

    }
};


void viewContent ( Mystack &S1)
{
     cout << "Number : ";
    for (int i = 0; i < S1.Tos ; i++)
    {
        cout << i << ":"<< S1.stk[i] << ", ";
    }
    cout << endl;
}
/*
void viewContent(Mystack S1)
{
    cout << " Number : ";
    for (int i = 0; i < S1.Tos; i++)
    {
        cout << i << ":" << S1.stk[i] << ", ";
    }
    cout << endl;
}
*/
int main()
{
    Mystack S1(4);

    S1.Push(2);
    S1.Push(4);
    S1.Push(6);
    S1.Push(8);
    S1.Push(15);

    cout << "\n\n View content"<< endl;
    viewContent(S1);


    cout << "\n\n Reverse content" <<endl;
    cout << S1.Reverse().Pop();
    return 0;
}
