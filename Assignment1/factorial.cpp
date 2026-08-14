#include<iostream>
using namespace std;
int main()
{
  int n,i,f=1;
  cout<<"Enter number";
  cin>>n;
  for(i=1;i<=n;i++)
     {
           f=f*i;
     }
  
  cout<<" Factorial of Number:"<<f;
  
    
  return 0;
}

