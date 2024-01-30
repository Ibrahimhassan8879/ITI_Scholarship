#include <iostream>


//Create Template of this class

using namespace std;

template<class Mytype>
class Mystack
{
    Mytype *stk;
    int Tos;
    int Size;
    static int Counter;

public:
    //Constructors
    Mystack(int S = 4)
    {
        Size = S;
        Tos = 0;
        stk = new Mytype[Size];
        Counter++;
    }
    //Copy constructor
    Mystack (Mystack &S1)
    {
        Size = S1.Size;
        Tos = S1.Tos;
        stk = new Mytype[Size];
        for (int i = 0; i < Tos; i++)
        {
            stk[i] = S1.stk[i];
        }
        Counter++;
    }
    // Destructor
    ~Mystack()
    {
        /*
        for (int i = 0; i < Tos; i++)
        {
            stk[i] = -1;
        }
        */
        delete []stk;
        cout<< "Destructor"<<endl;
        Counter--;
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
    void Push(Mytype N)
    {
        if (!Isnull())
        {
            stk[Tos++] = N;
        }
    }
    Mytype Pop()
    {
        if (!Isempty())
        {
            cout << "\nPop is declared\n";
            return stk[--Tos];
        }
        else
        {
            cout << "Stack is Empty"<< endl;
            //return 1;
        }
    }
    void print()
    {
        cout << "The last element is : " << stk[Tos-1] << endl;
    }
    void viewContent ();

    // Operator =
    Mystack operator = (const Mystack &SecondStack)
    {
        delete [] stk;
        Tos = SecondStack.Tos;
        Size = SecondStack.Size;
        stk = new Mytype[Size];
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


    //GetCounter
    static int GetCounter()
    {
        return Counter;
    }

    int & operator [] (int index)
    {

       if ( (index >= 0) && (index < Size) )
        return stk[index];
    }
};

template<class Mytype>
void Mystack<Mytype>::viewContent()
{
    cout << "Number : ";
    for (int i = 0; i < Tos ; i++)
    {
        cout << i << ":"<< stk[i] << ", ";
    }
    cout << endl;
}



template<class Mytype>
int Mystack<Mytype>::Counter = 0;


int main()
{
    Mystack<int>S1(5),S2(4),S3, S4(2);
    Mystack<char> S5(8);
    Mystack<float>S6(8);
    Mystack<int>S7(8);
    Mystack<int>S8(4);

    cout << "The number of objects currently we have is : "<< Mystack<int>::GetCounter()<< endl;
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
    cout << "\n\n View content of S5"<< endl;
    S5.Push('a');
    S5.Push('b');
    S5.Push('c');
    S5.Push('d');

    S5.viewContent();

    cout << "============================================"<<endl;
    cout<< "The object of floats S6 of size 4 usage" << endl;
    float Num[4];
    for (int i = 0; i < 4; i++)
    {
        cout<< "Enter the element number "<< i + 1 << " to push : ";
        cin>>Num[i];
        S6.Push(Num[i]);
    }

    cout << "\n\n View content of S6"<< endl;
    S6.viewContent();

    cout << "============================================"<<endl;
    cout<< "The object of chars S7 of size 8" << endl;
    S7.Push('a');
    S7.Push('b');
    S7.Push('c');
    S7.Push('d');
    S7.Push('h');
    S7.Push('A');
    S7.Push('R');
    S7.Push('W');

    cout << "\n\n View content of S7"<< endl;
    S7.viewContent();


    cout << "============================================"<<endl;
    cout<< "The object of chars S8 of size 4" << endl;
    S8[0];
    S8[1];
    S8[2];
    S8[3];

    cout << "\n\n View content of S7"<< endl;
    S8.viewContent();

    return 0;
}
