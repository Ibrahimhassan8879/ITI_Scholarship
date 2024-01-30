#include <iostream>

using namespace std;


//Class Geoshape

class Geoshape
{
protected:

    double Dimm1,Dimm2;

public:

    // Constructor
    Geoshape(double x = 0,double y = 0)
    {
        Dimm1 = x;
        Dimm2 = y;
    }

    //Setters
    void SetDim1(double x)
    {
        Dimm1 = x;
    }
    void SetDim2(double y)
    {
        Dimm2 = y;
    }

    //Getters
    double GetDim1()
    {
        return Dimm1;
    }
    double GetDim2()
    {
        return Dimm2;
    }
};

/*
//Rectangle class

class Rect : public Geoshape
{
public:

    //Constructor
    Rect(double x, double y):Geoshape(x,y)
    {}

    //Area calculation
    double GetArea()
    {
        return Dimm1*Dimm2;
    }
};


//Square class

class Square : protected Rect
{
public:

    //Constructor
    Square(double x):Rect(x,x)
    {}

    //Area calculation
    double GetArea()
    {
        return Dimm1*Dimm2;
    }

};

*/
/*
//Rectangle class

class Rect : protected Geoshape
{
public:

    //Constructor
    Rect(double x, double y):Geoshape(x,y)
    {}

    //Area calculation
    double GetArea()
    {
        return Dimm1*Dimm2;
    }
};


//Square class

class Square : private Rect
{
public:

    //Constructor
    Square(double x):Rect(x,x)
    {}

    //Area calculation
    double GetArea()
    {
        return Dimm1*Dimm2;
    }

};
*/

/*
//Rectangle class

class Rect : private Geoshape
{
public:

    //Constructor
    Rect(double x, double y):Geoshape(x,y)
    {}

    //Area calculation
    double GetArea()
    {
        return Dimm1*Dimm2;
    }
};


//Square class

class Square : protected Rect
{
public:

    //Constructor
    Square(double x):Rect(x,x)
    {}

    //Area calculation
    double GetArea()
    {
        return Dimm1*Dimm2;
    }

};

*/


//Rectangle class

class Rect : private Geoshape
{
public:

    //Constructor
    Rect(double x, double y):Geoshape(x,y)
    {}

    //Area calculation
    double GetArea()
    {
        return Dimm1*Dimm2;
    }
};


//Square class

class Square : public Rect
{
public:

    //Constructor
    Square(double x):Rect(x,x)
    {}

    //Area calculation
    double GetArea()
    {
        return Dimm1*Dimm2;
    }

};


//Circle class

class Circle : protected Geoshape
{
public:

    //Constructor
    Circle(double R):Geoshape(R,R)
    {}

    //Area calculation
    double GetArea()
    {
        return 3.14*Dimm1*Dimm1;
    }
};

//Triangle class

class Triangle : protected Geoshape
{
public:
    //Constructor
    Triangle(double x, double y):Geoshape(x,y)
    {}

    //Area calculation
    double GetArea()
    {
        return 0.5*Dimm1*Dimm2;
    }
};

double SumArea(Rect *RArr,int RArrSize, Square *SArr, int SArrSize, Circle *CArr, int CArrSize, Triangle *TArr, int TArrSize)
{
    double Result = 0;
    int i = 0;

    for (i = 0; i < RArrSize; i ++)
    {
        Result += RArr[i].GetArea();
    }
    for (i = 0; i < SArrSize; i++)
    {
        Result += SArr[i].GetArea();
    }
    for (i = 0; i < CArrSize; i++)
    {
        Result += CArr[i].GetArea();
    }
    for (i = 0; i < TArrSize; i++)
    {
        Result += TArr[i].GetArea();
    }

    return Result;
}






int main()
{
    cout << " Testing the Area of all the shapes. \n";

    cout<< "============================================== \n" ;
    Rect R (10,15);
    cout << "  Rectangle --> " << R.GetArea() <<endl;

    Square S(20);
    cout << "  Square --> " << S.GetArea() <<endl;

    Circle C (10);
    cout << "  Circle --> " << C.GetArea() <<endl;

    Triangle T (5,6);
    cout << "  Triangle --> " << T.GetArea() <<endl;

    cout<< "============================================== \n" ;


    Rect RectArr[3] = {  Rect(10,10), Rect(10,10),Rect(10,10) } ; //300

    Square SqArr[3] = {  Square(10), Square(10),Square(10) } ;  // 300

    Circle CArr[3] = {  Circle(10),Circle(10),Circle(10) } ; // 942

    Triangle TArr[3] = {  Triangle (10,10) , Triangle (10,10) , Triangle (10,10) } ; // 150



    cout << " \n The Sum of Area is ====> " << SumArea(RectArr, 3, SqArr, 3, CArr, 3, TArr, 3) <<endl;  // 1692

}
