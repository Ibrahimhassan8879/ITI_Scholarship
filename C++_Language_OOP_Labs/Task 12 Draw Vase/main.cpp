#include "graphics.h"
//#include "winbgim.h"
#include <iostream>


using namespace std;

class Point
{
    int X,Y;

public:
    //Constructor
    Point(int x = 0, int y = 0)
    {
        X = x;
        Y = y;
        //cout << "Point cTor\n";
    }
    //Destructor
    ~Point()
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

    //Setters
    void SetX(int x)
    {
        X = x;
    }
    void SetY(int y)
    {
        Y = y;
    }

    //Show function
    void Show()
    {
        cout << "(" << X << "," << Y << ")"<< endl;
    }

};

//Association Class
class Rect
{
    Point UL;
    Point LR;
    int Color;

    public:

    // Default Constructor
    Rect()
    {
        //cout << "Rect cTor\n";
        Color = 0;
    }

    // Parametrized Constructor
    Rect(int X1, int Y1, int X2, int Y2, int C):UL(X1,Y1), LR(X2,Y2)
    {
        //cout << "Parametrized cTor\n";
        Color = C;
    }

    //Draw method
    void Draw()
    {
        setcolor(Color);
        rectangle(UL.GetX(), UL.GetY(), LR.GetX(), LR.GetY());
    }
};

class Line
{
    Point P1;
    Point P2;
    int Color;

public:

    // Default Constructor
    Line()
    {
        int Color = 0;
    }
    // Parametrized Constructor
    Line(int X1, int Y1, int X2, int Y2, int C): P1(X1, Y1), P2(X2, Y2)
    {
        Color = C;
    }

    //Draw method
    void Draw()
    {
        setcolor(Color);
        line(P1.GetX(), P1.GetY(), P2.GetX(), P2.GetY());
    }
};

class Tri
{
    Point P1;
    Point P2;
    Point P3;
    int Color;

public:

    // Default Constructor
    Tri()
    {
        int Color = 0;
    }

    // Parametrized Constructor
    Tri(int X1, int Y1, int X2, int Y2, int X3, int Y3, int C):P1(X1, Y1), P2(X2, Y2), P3(X3, Y3)
    {
        Color = C;
    }

    // Draw method
    void Draw()
    {
        setcolor(Color);
        cout << P1.GetX() << ": "<<P1.GetY() << " : " << P2.GetX() << ": " << P2.GetY()<< endl;
        line(P1.GetX(), P1.GetY(), P2.GetX(), P2.GetY());
        line(P2.GetX(), P2.GetY(), P3.GetX(), P3.GetY());
        line(P3.GetX(), P3.GetY(), P1.GetX(), P1.GetY());
    }

};

class Cir
{
    Point P1;
    int Rad;
    int Color;

public:

    // Default Constructor
    Cir()
    {
        int Color = 0;
    }

    // Parametrized Constructor
    Cir(int X1, int Y1, int R, int C): P1(X1, Y1)
    {
        Rad = R;
        Color = C;
    }

    // Draw method
    void Draw()
    {
        setcolor(Color);
        circle(P1.GetX(), P1.GetY(), Rad);
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
