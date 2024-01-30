#include <iostream>
#include <conio.h>

using namespace std;

class complex
{
private:
    int real;
    int imaginary;
public:
    void setReal(int r)
    {
        real = r;
    }
    int getReal()
    {
        return real;
    }

    void setImaginary(int i)
    {
        imaginary = i;
    }
    int getImaginary()
    {
        return imaginary;
    }

            /* this means:
            1) R: 4  I:3 --> 4 + 3i
            2) R: 4  I:-3 --> 4 - 3i
            3) R: 4  I: 0 --> 4
            4) R: 0  I: 3 --> 3i
            5) R: 0  I: 0 --> 0
            */
    void print()
    {
        if ( real != 0 && imaginary > 0)
        {
            cout << "The complex number is : "<< real <<"+"<<imaginary<<"I"<< endl;
        }
        else if ( real != 0 && imaginary < 0)
        {
            cout << "The complex number is : "<< real <<imaginary<<"I"<< endl;
        }
        else if ( real != 0 && imaginary == 0)
        {
            cout << "The complex number is : "<< real<< endl;
        }
        else if ( real == 0 && imaginary != 0)
        {
            cout << "The complex number is : "<< imaginary<<"I"<<endl;
        }
        else if ( real == 0 && imaginary == 0)
        {
            cout << "The complex number is : "<< real<<endl;
        }
    }

    // sum function
    complex sum(complex c2)
    {
        complex c3;
        c3.setReal(getReal() + c2.getReal());
        c3.setImaginary(getImaginary() + c2.getImaginary());
        return c3;
    }

};

complex sub( complex c1, complex c2)
{
    complex c3;
    c3.setReal(c1.getReal() - c2.getReal());
    c3.setImaginary(c1.getImaginary() - c2.getImaginary());
    return c3;
}
int main()
{
    int Flag = 0;
    int x,y;
    complex c1,c2,c3;

    do
    {

        cout<< "  Enter the Element 1 real number      : ";
        cin>>x;
        c1.setReal(x);

        cout<< "  Enter the Element 1 imaginary number : ";
        cin>>y;
        c1.setImaginary(y);

        cout<<"---------------------------------" <<endl;
        cout<< "  Enter the Element 2 real number      : ";
        cin>>x;
        c2.setReal(x);

        cout<< "  Enter the Element 2 imaginary number : ";
        cin>>y;
        c2.setImaginary(y);

        cout<<"---------------------------------" <<endl;
        cout<< " The Element 1"<<endl;
        c1.print();
        cout<<"---------------------------------" <<endl;
        cout<< " The Element 2"<<endl;
        c2.print();
        cout<<"---------------------------------" <<endl;
        cout<<" The submission of two numbers"<<endl;
        c3 = c1.sum(c2);
        c3.print();
        cout<<"---------------------------------" <<endl;
        cout<<" The subtraction of two numbers"<<endl;
        c3 = sub(c1,c2);
        c3.print();
        cout<<"---------------------------------" <<endl;
        cout<<" Exit? press (1) else press any key" <<endl;

        Flag = _getch();

        cout<<"---------------------------------" <<endl;

    }while(Flag == 0);
}
