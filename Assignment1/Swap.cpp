#include<iostream>
using namespace std;
int main()
{
  int a,b,temp;
  cout<<"Enter value of two numbers";
  cin>>a>>b;
  cout<<"Numbers before swapping: a ="<<a <<" b ="<<b <<endl;
  temp=a;
  a=b;
  b=temp;
  cout<<"Numbers after swapping: a ="<<a <<" b ="<<b <<endl;
  return 0;
}
