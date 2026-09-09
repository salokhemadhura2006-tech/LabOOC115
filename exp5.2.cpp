#include<iostream>
using namespace std;
class construct
{
    protected:
    float area;

    construct(){
        area=0;
    }

    construct(int a,int b)
    {
        area=a*b;
    }
    void display()
    {
        cout<<area<<endl;

    }

};
int main()
{
    construct c;
    construct c1(5,3);
    c.display();
    c1.display();
    cout<<"Area is:"<<c1.area;
    return 0;

}
