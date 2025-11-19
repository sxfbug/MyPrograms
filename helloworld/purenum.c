#include<stdio.h>
int main(){
    const char y='Y',n='N';

  	int a,i,x;
    x=0;
  	scanf("%d",&a);
	for(int i=1;i<=a;i++){
    	if(a%i==0){
        x++;
        }
    }
  if(x>2){
  printf("%c",n);
  }
  else{
  printf("%c",y);
  }
}