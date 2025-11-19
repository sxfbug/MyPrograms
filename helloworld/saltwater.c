#include<stdio.h>
int main(){
    int vul,d;
    while (scanf("%d %d",&vul,&d)!=EOF)
    {   int count=0;
        int times=1;
		int mark=0;
        while (vul>0)
        {
        //drop
        for (int i= 0; i < times; i++)
        {
            vul-=d;
            count++;
            //当前不是这一波的最后一滴,不用停直接结束
            if (vul<=d&& i<times-1)
            {
                count++;
                vul=0;
              	mark=1;
                break;
            }
            //是这一波的最后一滴,要再停一下
            else if(vul<=d&& i==times-1){
                count++;
                vul=0;
              	mark=2;
                break;
            }
            
            
        }
        //下一次多一滴
        times++;

        if(mark==1){
          break;
        } 


        //停顿的时间
        count++;
        
        
        

        
        }
        printf("%d\n",count);
        

    }
    
}