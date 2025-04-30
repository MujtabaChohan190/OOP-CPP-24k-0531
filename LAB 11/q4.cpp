#include<iostream>
using namespace std;
template<typename T>
class Class1
{
    protected:
    T var1;
    T var2;
    public:
    Class1(T v1,T v2):var1(v1),var2(v2){}
    
};
template<typename T>
class Class2:public Class1<T>
{
    T var3;
    T var4;
    public: 
    Class2(T v1,T v2,T v3,T v4):Class1<T>(v1,v2),var3(v3),var4(v4){}
    void multiplyValues() {
        T result = (this->var1 * this->var2) * (var3 * var4);
        cout << "Multiplication result: " << result << endl;
    }
};
int main() {
    Class2<int> obj(2, 3, 4, 5);
    obj.multiplyValues();

    return 0;
}
