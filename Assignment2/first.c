#include <stdio.h>

int main() {
    int rno;
    char name[20];
    char cd;
    printf("\n Enter your name");
    scanf("%s",name);
    printf("\n Enter Roll Number");
    scanf("%d",&rno);
    printf("\n Enter class division");
    scanf(" %c",&cd);
    printf("\n ------Details----");
    printf("\nName:%s",name);
    printf("\nRoll No:%d",rno);
    printf("\nClass division:%c",cd);

    return 0;
}
