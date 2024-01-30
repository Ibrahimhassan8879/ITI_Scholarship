#include <iostream>
#include "graphics.h"
//#include "winbgim.h"
#include <iostream>

using namespace std;

class Shape
{
    int X,X2;
    int Y,Y2;
    int Z,Z2;

protected:

    int Color;

public:
    //Constructor
    Shape(int x = 0, int y = 0)
    {
        X = x;
        Y = y;
        //cout << "Point cTor\n";
    }
    //Destructor
    ~Shape()
    {
        //cout << "Point desTor\n";
    }

    //Getters
    int GetX()
    {
        return X;
    }
    int GetY()
    {
        return Y;
    }
    int GetX2()
    {
        return X2;
    }
    int GetY2()
    {
        return Y2;
    }
    int GetZ()
    {
        return Z;
    }
    int GetZ2()
    {
        return Z2;
    }

    //Setters
    void SetX(int x)
    {
        X = x;
    }
    void SetY(int y)
    {
        Y = y;
    }
    void SetX2(int x2)
    {
        X2 = x2;
    }
    void SetY2(int y2)
    {
        Y2 = y2;
    }
    void SetZ(int z)
    {
        Z = z;
    }
    void SetZ2(int z2)
    {
        Z2 = z2;
    }

    //Show function
    void Show()
    {
        cout << "Point 1 : (" << X << "," << Y << ")"<< endl;
        cout << "Point 2 : (" << X2 << "," << Y2 << ")"<< endl;
    }

};

//Association Class
class Rect : public Shape
{
    public:

    // Default Constructor
    Rect()
    {
        //cout << "Rect cTor\n";
        Color = 0;
    }

    // Parametrized Constructor
    Rect(int Point1X, int Point1Y, int Point2X, int Point2Y, int C)
    {
        SetX(Point1X);
        SetY(Point1Y);
        SetX2(Point2X);
        SetY2(Point2Y);
        Color = C;
        //cout << "Parametrized cTor\n";
    }

    //Draw method
    void Draw()
    {
        setcolor(Color);
        rectangle(GetX(), GetY(), GetX2(), GetY2());
    }
};

class Line : protected Shape
{
public:

    // Default Constructor
    Line()
    {
        Color = 0;
    }
    // Parametrized Constructor
    Line(int Point1X, int Point1Y, int Point2X, int Point2Y, int C)
    {
        SetX(Point1X);
        SetY(Point1Y);
        SetX2(Point2X);
        SetY2(Point2Y);
        Color = C;
    }

    //Draw method
    void Draw()
    {
        setcolor(Color);
        line(GetX(), GetY(), GetX2(), GetY2());
    }
};

class Tri : public Shape
{

public:

    // Default Constructor
    Tri()
    {
        Color = 0;
    }

    // Parametrized Constructor
    Tri(int Point1X, int Point1Y, int Point2X, int Point2Y, int Point1Z, int Point2Z, int C)
    {
        SetX(Point1X);
        SetY(Point1Y);
        SetZ(Point1Z);
        SetX2(Point2X);
        SetY2(Point2Y);
        SetZ2(Point2Z);
        Color = C;
    }

    // Draw method
    void Draw()
    {
        setcolor(Color);
        line(GetX(), GetY(), GetX2(), GetY2());
        line(GetX2(), GetY2(), GetZ(), GetZ2());
        line(GetZ(), GetZ2(), GetX(), GetY());
    }

};

class Cir : public Shape
{

public:

    // Default Constructor
    Cir()
    {
        int Color = 0;
    }

    // Parametrized Constructor
    Cir(int X1, int Y1, int R, int C)
    {
        SetX(X1);
        SetY(Y1);
        SetZ(R);
        Color = C;
    }

    // Draw method
    void Draw()
    {
        setcolor(Color);
        circle(GetX(),GetY(),GetZ());
    }
};

int main()
{

    initgraph();
    Rect R1 (294,340,529,409,7);
    R1.Draw();


    Line L1 (376,340,378,278,7);
    L1.Draw();

    Line L2 (439,341,437,260,7);
    L2.Draw();

    Line L3 (461,232,445,117,8);
    L3.Draw();

    Line L4 (351,233,367,113,8);
    L4.Draw();

    Cir C1(405,117,80,5);
    C1.Draw();

    Cir C2(405,233,120,5);
    C2.Draw();

    Tri T1(315,391,333,356,348,393,3);
    T1.Draw();


}
