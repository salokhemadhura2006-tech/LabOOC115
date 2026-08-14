#include<iostream>
using namespace std;
int main()
{
  int r, area, crf;
  const float PI=3.14;
  cout<<"Enter radius of circle:";
  cin>>r;
  area=PI*r*r;
  crf=2*PI*r;

 cout<<"Area of circle="<<area<<endl;
 cout<<"Circumference of circle="<<crf;
  return 0;
}

