#include<iostream>
using namespace std;
class A{
    private:
      int a;
      int b;
    friend void sum(A a);

};
void sum(A,a){
    cout<<"Addition"<<a.a+a.b;
}
int main()
{
    A a;
    cout<<sum(a);
}