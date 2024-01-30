#include <iostream>
#include <cstring>
using namespace std;

class Mycomplex
{
    int real;
    int img;

public:
    void setreal(int r)
    {
        real = r;
    }
    int getreal()
    {
        return real;
    }
    void setimg(int i)
    {
        img = i;
    }
    int getimg()
    {
        return img;
    }
    // Copy Constructor
    Mycomplex( Mycomplex &C1)
    {
        real = C1.real;
        img = C1.img;
    }
    // Constructors
        Mycomplex()
    {
        real = img = 0;
    }
        Mycomplex(int i)
    {
        real = img = i;
    }
    Mycomplex(int i,int g)
    {
        real = i;
        img = g;
    }
    // Destructor
    ~Mycomplex()
    {
    }
    void print()
    {
        if ( real != 0 && img > 0)
        {
            cout << "The complex number is : "<< real <<"+"<<img<<"I"<< endl;
        }
        else if ( real != 0 && img < 0)
        {
            cout << "The complex number is : "<< real <<img<<"I"<< endl;
        }
        else if ( real != 0 && img == 0)
        {
            cout << "The complex number is : "<< img<< endl;
        }
        else if ( real == 0 && img != 0)
        {
            cout << "The complex number is : "<< img<<"I"<<endl;
        }
        else if ( real == 0 && img == 0)
        {
            cout << "The complex number is : "<< real<<endl;
        }
    }
    Mycomplex Sum(Mycomplex C)
    {
        Mycomplex Result;
        Result.real = real + C.real;
        Result.img = img + C.img;
        return Result;
    }
    Mycomplex Sub(Mycomplex C)
    {
        Mycomplex Result;
        Result.real = real - C.real;
        Result.img = img - C.img;
        return Result;
    }
    Mycomplex operator +(Mycomplex &C1)
    {
        Mycomplex Result;
        Result.real = real + C1.real;
        Result.img = img + C1.img;
        return Result;
    }
    Mycomplex operator +(int Right)
    {
        Mycomplex Result;
        Result.real = Right + real;
        return Result;
    }
    Mycomplex operator +=(const Mycomplex &Right)
    {
        real += Right.real;
        img += Right.img;
        return *this;
    }
    Mycomplex operator ++()
    {
        real++;
        return *this;
    }
    Mycomplex operator ++(int)
    {
        Mycomplex Temp(real,img);
        real++;
        return Temp;
    }

    //Operator 1:  C3 = C1 - C2
    Mycomplex operator -(const Mycomplex &C1)
    {
        Mycomplex Result( real - C1.real, img - C1.img);
        return Result;
    }
    //Operator 3:  C3 = C2 - 7
    Mycomplex operator -(int Left)
    {
        Mycomplex Result(real - Left, img);
        return Result;
    }
    //Operator 4:  C1 -= C2
    Mycomplex operator -=(const Mycomplex &C)
    {
        real = real - C.real;
        img = img - C.img;
        return *this;
    }
    //Operator 5:  C1 -= 7
    Mycomplex operator -=(int i)
    {
        real = real - i;
        return *this;
    }
    //Operator 7:  --C10
    Mycomplex operator --()
    {
        real--;
        return *this;
    }
    //Operator 8:  C11--
    Mycomplex operator --(int)
    {
        Mycomplex Temp(real,img);
        real--;
        return Temp;
    }
    //Operator 9:  ==   C4 == C5   C4 == C6
    bool operator ==(const Mycomplex &Right)
    {
        return (real == Right.real)&&(img == Right.img);
    }
    //Operator 10:  !=   C4 != C5   C4 != C6
    bool operator !=(const Mycomplex &Right)
    {
        return (real != Right.real) || (img != Right.img);
    }
    //Operator 11:  C15 > C14 C14 >= C16
    bool operator > (const Mycomplex &Right)
    {
        return (real > Right.real);
    }
    bool operator >= (const Mycomplex &Right)
    {
        return (real >= Right.real);
    }
    //Operator 12:  C15 < C17 C16 <= C14
    bool operator < (const Mycomplex &Right)
    {
        return (real < Right.real);
    }
    bool operator <= (const Mycomplex &Right)
    {
        return (real <= Right.real);
    }
    //Operator 13:  int(C16)
    operator int()
    {
        return real;
    }

    operator char*()
    {
        string s = to_string(real);
        s += " + " + to_string(img) + "i";
        int n = s.length();
        char* Array = new char[n];
        strcpy(Array, s.c_str());
        return Array;
    }

};
using namespace std;

//Operator 2 C3 = 7 - C2
Mycomplex operator-(int Left, const Mycomplex &C1) {
  Mycomplex Result(Left - C1.getreal(), C1.getimg());
  return Result;
}


int operator -= (int a, const Mycomplex &C)
{
    a = a - C.getreal();
    return a;
}
int main()
{
    Mycomplex C1(7,8),C2(12),C3;
    Mycomplex C4(4,5);
    Mycomplex C5(20,3);
    Mycomplex C6(4,5);


    cout << "\n===============================================\n"<<endl;
    cout << "C1 Object values : ";
    C1.print();
    cout << "C2 Object values : ";
    C2.print();

    cout << "\n===============================================\n"<<endl;
    cout << "Operator 1:  C3 = C1 - C2"<< endl;
    C3 = C1 - C2;
    C3.print();
    cout << "\n===============================================\n"<<endl;

    cout << "Operator 2:  C3 = 7 - C2"<<endl;
    C3 = 7 - C2;
    C3.print();
    cout << "\n===============================================\n"<<endl;

    cout << "Operator 3:  C3 = C2 - 7"<< endl;
    C3 = C2 - 7;
    C3.print();
    cout << "\n===============================================\n"<<endl;

    cout << "Operator 4:  C1 -= C2" <<endl;
    C1 -= C2;
    C1.print();
    cout << "\n===============================================\n"<<endl;

    cout << "Operator 5:  C1 -= 7" <<endl;
    C1 -= 7;
    C1.print();
    cout << "\n===============================================\n"<<endl;

    cout << "Opertaor 6:  7 -= C1"<<endl;
    cout << ( 7 -= C1) << endl;
    cout << "\n===============================================\n"<<endl;

    cout << "Operator 7:  --C10"<<endl;
    Mycomplex C10(5,7);
    cout << "C10 Object values : ";
    C10.print();
    C2 = --C10;
    C2.print();
    C10.print();
    cout << "\n===============================================\n"<<endl;

    cout << "Operator 8:  C11--"<<endl;
    Mycomplex C11(5,7);
    cout << "C11 Object values : ";
    C11.print();
    C2 = C11--;
    C2.print();
    C11.print();

    cout << "\n===============================================\n"<<endl;
    cout << "C4 Object values : ";
    C4.print();
    cout << "C5 Object values : ";
    C5.print();
    cout << "C6 Object values : ";
    C6.print();


    cout << "\n===============================================\n"<<endl;
    cout << "Operator 9:  ==   C4 == C5   C4 == C6"<<endl;
    if ( C4 == C5 )
    {
        cout << "\n Equal "<<endl;
    }
    else
    {
        cout << "\n Not Equal "<<endl;
    }
    if ( C4 == C6)
    {
        cout << "\n Equal" << endl;
    }
    else
    {
        cout << "\n Not Equal "<<endl;
    }
    cout << "\n===============================================\n"<<endl;
    cout<< "Operator 10:  !=   C4 != C5   C4 != C6" << endl;
    if ( C4 != C5)
    {
        cout << "\n  Not Equal"<< endl;
    }
    else
    {
        cout << "\n  Equal "<<endl;
    }
    if (C4 != C6)
    {
        cout << "\n Not Equal" << endl;
    }
    else
    {
        cout << "\n  Equal "<<endl;
    }

    cout << "\n===============================================\n"<<endl;
    Mycomplex C14(4,5);
    Mycomplex C15(20,3);
    Mycomplex C16(4,2);
    Mycomplex C17(12,3);
    cout << "C14 Object values : ";
    C14.print();
    cout << "C15 Object values : ";
    C15.print();
    cout << "C16 Object values : ";
    C16.print();
    cout << "C17 Object values : ";
    C17.print();

    cout << "\n===============================================\n"<<endl;
    cout << " Operator 11:  C15 > C14 C14 >= C16 "<< endl;
    if ( C15 > C14 )
    {
        cout<< " C15 is greater than C14"<< endl;
    }
    else
    {
        cout << "C15 is smaller than C14"<< endl;
    }
    if ( C14 >= C16 )
    {
        cout<< " C14 is greater than or equal C16"<< endl;
    }
    else
    {
        cout << "C14 is smaller than C16"<< endl;
    }

    cout << "\n===============================================\n"<<endl;
    cout << " Operator 12:  C15 < C17 C16 <= C14"<< endl;
    if ( C15 < C17 )
    {
        cout<< " C15 is smaller than C17"<< endl;
    }
    else
    {
        cout << "C15 is greater than C17"<< endl;
    }
    if ( C16 <= C14 )
    {
        cout<< " C16 is smaller than or Equal C14"<< endl;
    }
    else
    {
        cout << " C16 is greater than C14"<< endl;
    }
    cout << "\n===============================================\n"<<endl;
    cout << " Operator 13:  int(C16)"<< endl;
    cout << int(C16);

    cout << "\n===============================================\n"<<endl;
    cout << " Operator 14:  char*(C17)"<< endl;
    cout << (char*)C17;
}


