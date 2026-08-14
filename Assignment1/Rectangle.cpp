#include<iostream>
using namespace std;
int main()
{
  float length, breadth, area, perimeter;
  cout<<"Enter length:";
  cin>>length;
 
  cout<<"Enter breadth:";
  cin>>breadth;
  
  area=length*breadth;
  perimeter=2*(length+breadth);
 
  cout<<"Area of rectangle="<<area<<endl;
  cout<<"Perimeter of rectangle="<<perimeter;
  
  return 0;
}
