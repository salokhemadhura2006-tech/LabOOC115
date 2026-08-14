#include<iostream>
using namespace std;
int main()
{
  int a,b;
  cout<<"Enter value of two numbers";
  cin>>a>>b;
  cout<<"Numbers before swapping: a = "<<a << " b ="<<b <<endl;
  a=a+b;
  b=a-b;
  a=a-b;
  cout<<"Numbers after swapping: a ="<<a << " b =" <<b <<endl;
  return 0;
}
