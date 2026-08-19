#include<stdio.h>
int main()
{
    int arr[4],i,sum=0;
    printf("\n Enter array elements:");
    for(i=0;i<4;i++)
      {
        scanf("%d",&arr[i]);
        sum=sum + arr[i];

      } 
  printf("\n Addition :%d",sum);
  return 0;
    }
