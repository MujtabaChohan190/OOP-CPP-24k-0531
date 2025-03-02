#include <iostream>
#include <windows.h>
using namespace std;
class Blend
{
    public:
    void blendJuice()
    {
        for(int i=1;i<=5;i++)
        {
            cout<<"Blending.... ("<<i<<" seconds)"<<endl;
            Sleep(1000);
            system("cls");
        }
        cout<<endl;
    }
};
class Grind
{
    public:
    void GrindJuice()
    {
        for(int i=1;i<=5;i++)
        {
            cout<<"Grinding.... ("<<i<<" seconds)"<<endl;
            Sleep(1000);
            system("cls");
        }
    }
};
class JuiceMaker
{
    Blend b;
    Grind g;
    public:
    void makeJuice()
    {
        b.blendJuice();
        g.GrindJuice();
        cout<<"Juice is ready!";
    }
};
int main()
{
    JuiceMaker JM;
    JM.makeJuice();
}
