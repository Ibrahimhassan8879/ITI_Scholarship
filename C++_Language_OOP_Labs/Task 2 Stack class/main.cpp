#include <iostream>

using namespace std;



class Mystack
{
    int *stk;
    int Tos;
    int Size;

public:
    Mystack(int S)
    {
        Size = S;
        Tos = 0;
        stk = new int[Size];
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
            return stk[--Tos];
        }
        else
        {
            return 1;
        }
    }
    void print()
    {
        cout << "The last element is : " << stk[Tos-1] << endl;
    }
    ~Mystack()
    {
        delete []stk;
        cout << "The program has ended";
    }
};


int main()
{
    int Size;
    cout<< "Enter the array size that you want : ";
    cin >> Size;
    Mystack c1(Size);
    int Selection;
    int push;

    do
    {
        cout<< "Select 1: push  2: pop 3: print : ";
        cin >> Selection;

        switch (Selection)
        {
        case 1:
            cout << "Enter the number that you want to push : ";
            cin >> push;
            c1.Push(push);
            break;
        case 2:
            c1.Pop();
            break;
        case 3:
            c1.print();
        }
    }while (Selection != 1 || Selection != 2 || Selection != 3);

return 1;
}
