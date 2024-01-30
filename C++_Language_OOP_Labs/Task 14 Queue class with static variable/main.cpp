#include <iostream>

using namespace std;

// Conversion to static
// Counter


class Myqueue
{
    int *Q;
    int Tail;
    int Size;
    int Head;
    static int Counter;

public:
    Myqueue(int L)
    {
        Tail = -1;
        Size = L;
        Head = 0;
        Q = new int[Size];
        Counter ++;
    }
    ~Myqueue()
    {
        delete [] Q;
        Counter --;
    }
    int Isfull()
    {
        return Tail == (Size - 1);
    }
    int Isempty()
    {
        return Tail == -1;
    }
    void Enq(int n)
    {
        if (Isfull())
        {
            cout << "The Q is full" << endl;
        }
        else
        {
            Q[++Tail] = n;
            cout << "The number " << n << "registered." << endl;
        }
    }
    void Deq()
    {
        if (Isempty())
        {
            cout << "The object is empty"<< endl;
        }
        else
        {
            for (int i = 0; i < Tail + 1; i++ )
            {
                Q[i] = Q[i + 1];
            }
            Tail--;
        }
    }
    int peak()
    {
        if (Isempty())
        {
            cout << "The object is empty." << endl;
        }
        else
        {
            cout << "The peak number is : " << Q[Head]<< endl;
        }
    }
    static int GetCounter()
    {
        return Counter;
    }
};


int Myqueue::Counter = 0;

int main()
{
    int Size;
    cout<< "Enter the array size that you want : ";
    cin >> Size;

    cout << "The object c1 created" << endl;
    Myqueue c1(Size);
    int Selection;
    int EnQ_Number;

    cout <<"The total number of objects created is : "<<Myqueue::GetCounter() <<endl;

    cout << "The object c2 created" << endl;
    Myqueue c2(10);

    cout << "The object c3 created" << endl;
    cout <<"The total number of objects created is : "<<Myqueue::GetCounter() <<endl;

    Myqueue c3(5);
    cout <<"The total number of objects created is : "<<Myqueue::GetCounter() <<endl;


    do
    {
        cout<< "  Select options\n  1: EnQ\n  2: DeQ\n  3: Peak" << endl;
        cin >> Selection;

        switch (Selection)
        {
        case 1:
            cout << "Enter the number that you want to EnQ : ";
            cin >> EnQ_Number;
            c3.Enq(EnQ_Number);
            break;
        case 2:
            c3.Deq();
            break;
        case 3:
            c3.peak();
        }
    }while (Selection != 1 || Selection != 2 || Selection != 3);

    cout <<"The total number of objects created is : "<<Myqueue::GetCounter() <<endl;

return 1;
}
