#include <iostream>

using namespace std;

class intArray
{
    int *Arr;
    int Size;

    public:
    //Constructors

    //Default constructor
    //Parameterized constructor
    intArray(int i = 5)
    {
        Size = i;
        Arr = new int[Size];
    }

    //Copy constructor
    intArray(const intArray &OldArr)
    {
        Size = OldArr.Size;
        Arr = new int[Size];
        for (int i = 0; i < Size; i++)
        {
            Arr[i] = OldArr.Arr[i];
        }
    }

    //Destructor
    ~intArray()
    {
        for (int i = 0; i < Size; i++)
        {
            Arr[i] = -1;
        }
        delete [] Arr;
    }

    //Assignment Operator overloading
    intArray operator = (const intArray &Assigned)
    {
        delete [] Arr;
        Size = Assigned.Size;
        Arr = new int[Size];
        for (int i = 0; i < Size; i++)
        {
            Arr[i] = Assigned.Arr[i];
        }
        return *this;
    }

    //Getter function
    int GetArrayValue(int x)
    {
        if ( x < 0 || x > Size)
        {
            cout << "Invalid index location"<< endl;
            return 0;
        }
        else
        {
            return Arr[x];
        }
    }

    //Setter function
    void SetArrayValue(int index, int value)
    {
        if ( index < 0 || index > Size)
        {
            cout << "Invalid index location" << endl;
            return;
        }
        else
        {
            Arr[index] = value;
        }
    }

    //Getter function
    int GetSize()
    {
        return Size;
    }
    intArray operator +(const intArray &SecondArray)
    {
        if ( Size > SecondArray.Size )
        {
            for (int i = 0; i < SecondArray.Size;i++)
            {
                Arr[i] += SecondArray.Arr[i];
            }
        }
        else
        {
            Size = SecondArray.Size;
            for (int i = 0; i < Size;i++)
            {
                Arr[i] += SecondArray.Arr[i];
            }
        }
        return *this;
    }
};

int main()
{
    intArray MyA(7) , MyB, MyC(5);

    cout << "Numbers in Array A : [ ";
    for (int i = 0; i < MyA.GetSize(); i++)
    {
        MyA.SetArrayValue(i, 3*i);
        if (i == MyA.GetSize() - 1)
        {
            cout << MyA.GetArrayValue(i) << " ]"<<endl;
        }
        else
        {
            cout << MyA.GetArrayValue(i) << ", ";
        }

    }

    cout << "Numbers in Array B : [ ";
    for (int i = 0; i < MyB.GetSize(); i++)
    {
        MyB.SetArrayValue(i, 5*i);
        if (i == MyB.GetSize() - 1)
        {
            cout << MyB.GetArrayValue(i) << " ]"<<endl;
        }
        else
        {
            cout << MyB.GetArrayValue(i) << ", ";
        }
    }

    cout << "Numbers in Array C : [ ";
    for (int i = 0; i < MyC.GetSize(); i++)
    {
        MyC.SetArrayValue(i, 7*i);
        if (i == MyC.GetSize() - 1)
        {
            cout << MyC.GetArrayValue(i) << " ]"<<endl;
        }
        else
        {
            cout << MyC.GetArrayValue(i) << ", ";
        }
    }

    cout << "Array C = A + B" << endl;
    MyC = MyA + MyB;
    cout << "Numbers in Array C : [ ";
    for (int i = 0; i < MyC.GetSize(); i++)
    {
        if (i == MyC.GetSize() - 1)
        {
            cout << MyC.GetArrayValue(i) << " ]"<<endl;
        }
        else
        {
            cout << MyC.GetArrayValue(i) << ", ";
        }
    }


}
