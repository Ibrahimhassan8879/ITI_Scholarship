#include <iostream>

using namespace std;


class Mystack
{
    int *stk;
    int Tos;
    int Size;

public:
    //Constructors
    Mystack(int S = 4)
    {
        Size = S;
        Tos = 0;
        stk = new int[Size];
    }
    //Copy constructor
    Mystack (Mystack &S1)
    {
        Size = S1.Size;
        Tos = S1.Tos;
        stk = new int[Size];
        for (int i = 0; i < Tos; i++)
        {
            stk[i] = S1.stk[i];
        }
    }
    // Destructor
    ~Mystack()
    {
        for (int i = 0; i < Tos; i++)
        {
            stk[i] = -1;
        }
        delete []stk;

    }

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
    void viewContent ()
    {
        cout << "Number : ";
        for (int i = 0; i < Tos ; i++)
        {
            cout << i << ":"<< stk[i] << ", ";
        }
        cout << endl;
    }
    // Operator =
    Mystack operator = (const Mystack &SecondStack)
    {
        Tos = SecondStack.Tos;
        Size = SecondStack.Size;
        delete [] stk;
        stk = new int[Size];
        for (int i = 0; i < Size; i++)
        {
            stk[i] = SecondStack.stk[i];
        }
        return *this;
    }
    //Operator + append
    Mystack operator + (const Mystack &SecondStack)
    {

        Mystack C(Size + SecondStack.Size);
        C.Tos = Tos + SecondStack.Tos;
        int k = 0;
        for (int i = 0; i < Tos; i++)
        {
            C.stk[i] = stk[i];
        }
        for (int i = Tos; i < C.Tos; i++)
        {
            C.stk[i] = SecondStack.stk[k];
            k++;
        }
        return C;
    }
};



int main()
{
    Mystack S1(5),S2(4),S3, S4(2);

    S1.Push(2);
    S1.Push(4);
    S1.Push(6);
    S1.Push(8);

    cout << "\n\n View content of S1"<< endl;
    S1.viewContent();

    cout << "============================================"<<endl;
    S2.Push(4);
    S2.Push(5);
    S2.Push(6);
    S2.Push(7);

    cout << "\n\n View content of S2"<< endl;
    S2.viewContent();
    cout << "============================================"<<endl;

    cout << "\n\n View content of S4 = S1"<< endl;
    S4 = S1;
    S4.viewContent();

    cout << "============================================"<<endl;

    cout << "\n\n View content of S3 = S1 + S2"<< endl;
    S3 = S1 + S2;
    S3.viewContent();

    cout << "============================================"<<endl;

    return 0;
}
