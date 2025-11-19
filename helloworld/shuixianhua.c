#include<stdio.h>
void shuixianhua();
int triple_x(int x);
int triple_x(int x){
    return x*x*x;
}
void shuixianhua(){

    for(int n=0;n<1000;n++)
    {int a1=n/100;
    int a2=(n/10)%10;
    int a3=n%10;
    int sum=triple_x(a1)+triple_x(a2)+triple_x(a3);

    if (sum==n)
    {
        printf("%d\n",n);
    }}
    
}
int main(){
    shuixianhua();
}