#include<iostream>
using namespace std;
int main()
{
  int a,b,ch;
  cout<<"Enter two numbers:";
  cin>>a>>b;

  cout<<"\n--MENU--";
  cout<<"\n1.Addition";
  cout<<"\n2.Subtraction";
  cout<<"\n3.Multiplication";
  cout<<"\n4.Division";
  cout<<"\n5.Moduls";
 

  cout<<"\nEnter your choice: ";
  cin>>ch;

  switch(ch)
   {
      case 1:
           cout<<"Addition="<<a+b;
           break;

      case 2:
           cout<<"Subtraction="<<a-b;
           break;


      case 3:
           cout<<"Multiplication="<<a*b;
           break;

     
      case 4:
           cout<<"Division="<<a/b;
           break;

      case 5:
           cout<<"Modulus="<<a%b;
           break;
      default:
           cout<<"Invalid choice";
    }
return 0;
}

