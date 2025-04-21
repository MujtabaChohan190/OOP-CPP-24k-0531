#include<iostream>
#include<string>
using namespace std;
class Car
{
    protected:
    string model;
    double price;
    public:
    Car(string m,double p):model(m),price(p){}
    virtual void setprice()=0;
};
class color:public Car
{
    public:
    color(string m,double p):Car(m,p){}
    void setprice()
    {
        price*=0.1;//color has 10 percent price of the car
        cout<<"Price of "<<model<<" is: "<<price<<endl;
    }    
};
class company:public Car
{
    public:
    company(string m,double p):Car(m,p){}
    void setprice()
    {
        price*=0.15;//company has 20 percent price of the car
        cout<<"Price of "<<model<<" is: "<<price<<endl;
    } 
};
int main()
{
    Car* c1=new color("Corolla",100000);
    Car* c2=new company("Github",500000);
    c1->setprice();
    c2->setprice();
}
