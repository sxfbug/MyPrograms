#include<stdio.h>
int main(){
    char grade;
    printf("input your grade with upper letter: ");
    scanf("%c",&grade);
    switch (grade)
    {
    case 'A':
        /* code */
        printf("excellent!");
        break;
    case 'B':
        printf("good!");
    case 'C':
        printf("not bad");
    case 'D':
        printf("you can do better");
    default:
        printf("no good");
        break;
    }
}