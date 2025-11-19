#include<stdio.h>
int main(){
	int y,m;
    scanf("%d %d",&y,&m);
  	switch (m){
      case 1:case 3 :case 5:case 7:case 8:case 10:case 12:{
        printf("%d-%d-%d",y,m,31);
        break;
      }
      case 2:{
      if((y%4==0&&y%100!=0)||y%400==0){
      	printf("%d-%d-%d",y,2,29);
      }else{
        printf("%d-%d-%d",y,2,28);
      }
        break;
    }
      default:{
        printf("%d-%d-%d",y,m,30);
      }
        
    }
        
}