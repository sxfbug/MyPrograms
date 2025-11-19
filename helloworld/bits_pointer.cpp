#include<stdio.h>
#include<iostream>
#include<cstring>
#include<bitset>
#include<limits.h>

using namespace std;
typedef unsigned char* bite;
void show_bit(const bite &x,int y){
        for(int i=0;i<y;i++){
            printf("%.2x",x[i]);
            // cout<<"(add=0x";
            // printf("%.10x",&x[i]);
            // cout<<")";
            std::cout<<"\t";
        }
    }


int tadd_ok(int x,int y){
    //64 bit machine,but the size of int is 32bit
        //return !(x>>31 ^ (x+y)>>31);错误原因是，只判断了符号位，
        //只能处理x和y同号的情况，不能处理异号情况
        int pos_overflow= (x>>31) & (y>>31) & !(x+y>>31);
        int neg_overflow= !(x>>31) & !(y>>31) & (x+y>>31);
        return !(pos_overflow|neg_overflow);
    }

int allOddBits(int x) {
  //移位，问题是  
  //我能不能人工制造一个大常量,不行
  int t2 = x;
  int t4 = (x>>8);
  int t6 = (x>>16);
  int t8 = (x>>24);
  
  
  printf("%x\n,%x\n,%x\n,%x\n",t2,t4,t6,t8);
  int tem=((t2&t4&t6&t8)|0x55);
  printf("%x\n",tem);
  int tem2=tem^0xff;
  printf("%x\n",tem2);
    return  !(tem2);   
}

void ii(int x){
    printf("%x\n",!(!x));
    printf("%x\n",~(!(!x))+1);
}

int cond(int x, int y, int z) {
  //用两次！，把正数和0映射到1和0
  //通过求负数，可以把0和1映射成0x0000和0xffff
  int cond = !(!x);
  printf("%x\n",cond);
  int mark = ~cond+1;
  printf("mark:%x\n",mark);
  printf("mark&y:%x\n",mark&y);
  printf("mark&z:%x\n",mark&z);

  return (mark&y) | (~mark&z);
}

int Myabs(int x){
  int is_neg= x>>31;//0 and 1
  int is_neg_allbit=~is_neg+1;//pos:0x0000 /neg:0xffff
  
  //问题：对于0x8000,操作后仍得到原value

  //两种情况时，当前序列都不需要判断：1.当前序列为0 2.前序序列非0
  //是的情况：1.前序都没有出现过非0序列,都是0 2.当前序列非0
  //需要记录前序情况，用&传递
  int num1=x>>24;//front 1-8bits
  int num1_abs=(is_neg_allbit&(~num1+1))|(~is_neg_allbit&num1);

  int front_8bit_is0=!(num1_abs^0);//1->full 0; 0->not full 0
  //check which bit is 1
  int mark1=~(!((0x0f|num1_abs)^0x0f))+1;//front 1-4bits,(0000 1111 | x)^0000 1111,if 0x0000, 1-4bit is 0000
  //with !, 1->1-4bit is 0000,0->not 0000
  //with ~+1,ffff->1-4bit is 0000,  0->not 0000
  int m1_up_edge=0x08;
  int m1_down_edge=0x00;

  
  //如果我可以把所有结果都映射到0x0和0xf上，就可以用|的串联，实现寻找到唯一的结果
  //这样想不行，因为有先后的逻辑关系，必须是从高往低位检验
  //divided in two with sub

  int mark2=2;//front 5-8bits,(1111 0000 |x)^1111 0000, if 0x0000, 5-8bit is 0000

   
  int num2=(x>>16)-(num1<<8);//9-16bits
  int num2_abs=(is_neg_allbit&(~num2+1))|(~is_neg_allbit&num2);
  int front_9to16bit_is0=!front_8bit_is0 | (!(num2_abs^0));//1->full 0; 0->not full 0

  int num3=(x>>8)-((x>>16)<<8);//17-24bits
  int num3_abs=(is_neg_allbit&(~num3+1))|(~is_neg_allbit&num3);
  int front_17to24bit_is0=!front_9to16bit_is0 | (!(num3_abs^0));//1->full 0; 0->not full 0

  int num4=x-((x>>8)<<8);//25-32bits
  int num4_abs=(is_neg_allbit&(~num4+1))|(~is_neg_allbit&num4);
  int front_25to32bit_is0=!front_17to24bit_is0 | (!(num3_abs^0));//1->full 0; 0->not full 0
  
  //如果front系列的数都是0,那意味着1-8bit是有最高位的
  printf("num1 abs=%x\n",num1_abs);
  printf("num2 abs=%x\n",num2_abs);
  printf("num3 abs=%x\n",num3_abs);
  printf("num4 abs=%x\n",num4_abs);

  printf("1-8:%x\n",front_8bit_is0);
  printf("9-16:%x\n",front_9to16bit_is0);
  printf("17-24:%x\n",front_17to24bit_is0);
  printf("25-32:%x\n",front_25to32bit_is0);
  return 0;
}

int main(){
    printf("%x\n",Myabs(0x80000000));
    printf("%x\n",Myabs(0x7fffffff));
    printf("%x\n",Myabs(0x12345678));
    printf("%x\n",Myabs(0x00000678));
    printf("%x\n",Myabs(0x00305678));
   
    
}

//cout<<allOddBits(0xffffffff);

    
    //cout<<sizeof(int);
// int result=tadd_ok(3,-4);
    // printf("%d\n",result);
    // result=tadd_ok(2147483647,2147483647);
    // printf("%d\n",result);
    // result=tadd_ok(-2147483647,-2147483647);
    // printf("%d\n",result);

// char* num="abcdef";
    // cout<<"num as parameter: ";
    // cout<<endl;
    // show_bit((bite)num,strlen(num)+1);
    // cout<<endl;
    // cout<<"value of num: "<<(void*)num;
    // cout<<endl;
    // cout<<"address of num:"<<&num;
    // cout<<endl;
    // cout<<"&num as parameter: ";
    // cout<<endl;
    // show_bit((bite)&num,sizeof(num));


    // int x=1,mx=-1;
    // show_bit((bite)&x,sizeof(x));
    // cout<<endl;
    // cout<<bitset<32>(x);
    // cout<<endl;
        

    // cout<<bitset<32>(mx);
    // cout<<endl;
    // show_bit((bite)&mx,sizeof(x));

    // cout<<"transfer int mx to unsigned: "<<(unsigned)mx;


    // int i;
    // float result=0;
    // unsigned length=0;

    // for(i=0;i<=length-1;i++){
    //     result++;
    // }
    // cout<<result;


    //思路：先找到这个数的符号位（最高位），再进行计算位数
  //对于正数，从左到右找到第一个非0位，就是次高位
  //负数和正数所需的位数是一样的，能不能把负数变成正数来一起计算
  //一次最多同时比较8bit
//   int is_neg= x>>31;//0 and 1
//   int is_neg_allbit=~is_neg+1;//pos:0x0000 /neg:0xffff
//   int abs=(is_neg_allbit&(~x+1))|(~is_neg_allbit&x);//对负数取相反数，对正数保留原值
//   //问题：对于0x8000,操作后仍得到原value

//   int num1=abs>>24;//front 1-8bits
//   int front_8bit_is0=!(num1^0);//1->full 0; 0->not full 0
//   //check which bit is 1
//   int mark1=~(!((0x0f|x)^0x0f))+1;//front 1-4bits,(0000 1111 | x)^0000 1111,if 0x0000, 1-4bit is 0000
//   //with !, 1->1-4bit is 0000,0->not 0000
//   //with ~+1,ffff->1-4bit is 0000,0->not 0000

  
//   //如果我可以把所有结果都映射到0x0和0xf上，就可以用|的串联，实现寻找到唯一的结果
//   //这样想不行，因为有先后的逻辑关系，必须是从高往低位检验
//   //divided in two with sub

//   int mark2=//front 5-8bits,(1111 0000 |x)^1111 0000, if 0x0000, 5-8bit is 0000


//   int num2=(abs>>16)-(num1<<8);//9-16bits
//   int front_9to16bit_is0=!(num2^0);//1->full 0; 0->not full 0

//   int num3=(abs>>8)-((abs>>16)<<8);//17-24bits
//   int front_17to24bit_is0=!(num3^0);//1->full 0; 0->not full 0

//   int num4=abs-((abs>>8)<<8);//25-32bits
//   int front_25to32bit_is0=!(num4^0);//1->full 0; 0->not full 0
