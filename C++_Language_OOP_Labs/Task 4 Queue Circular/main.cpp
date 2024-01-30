#include <iostream>

using namespace std;

class Myqueue
{
    int *Q;
    int Tail;
    int Size;
    int Head;
    int Counter;

public:
    Myqueue(int L)
    {
        Tail = -1;
        Size = L;
        Head = 0;
        Counter = 0;
        Q = new int[Size];
    }
    ~Myqueue()
    {
        delete [] Q;
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
        if (Isfull() || Counter == Size)
        {
            cout << "The Q is full" << endl;
        }
        else
        {
            Tail = Tail + 1;
            Tail = Tail%Size;
            Q[Tail] = n;
            Counter++;
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
            Head++;
            Counter--;
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
};

int main()
{
    int Size;
    cout<< "Enter the array size that you want : ";
    cin >> Size;
    Myqueue c1(Size);
    int Selection;
    int EnQ_Number;

    do
    {
        cout<< "  Select options\n  1: EnQ\n  2: DeQ\n  3: Peak" << endl;
        cin >> Selection;

        switch (Selection)
        {
        case 1:
            cout << "Enter the number that you want to EnQ : ";
            cin >> EnQ_Number;
            c1.Enq(EnQ_Number);
            break;
        case 2:
            c1.Deq();
            break;
        case 3:
            c1.peak();
        }
    }while (Selection != 1 || Selection != 2 || Selection != 3);

return 1;
}
