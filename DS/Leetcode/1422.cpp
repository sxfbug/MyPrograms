#include"hf.hpp"

int maxScore(string s) 
{
    //尝试一下前后缀数组？
    int size=s.length();
    //前后缀数组a[i]的含义是，在i的右侧分割，得到的总分
    vector<int> front(size,0);
    vector<int> back=front;

    //划分是非空的子字符串
    for(int i=0;i<size;i++){
        
        if(s[i]=='0'){

            if(i==0){
                front[0]=1;
            }else{
                front[i]=front[i-1]+1;
            }
            
        }else{
            front[i]=i>0 ? front[i-1] : 0;
        }
    }


    for(int i=size-1;i>=0;i--){
        if(s[i]=='1'){

            if(i==size-1){
                back[i]=1;
            }else{
                back[i]=back[i+1]+1;
            }
            
        }else{
            back[i]= i<size-1 ? back[i+1] : 0;
        }
    }
    // vsivec(front);
    // vsivec(back);

    vector<int> sum(size-1,0);
    for (int i = 1; i < size; i++)
    {
        sum[i-1]=back[i]+front[i-1];
    }
    // vsivec(sum);
    int b=0;
    for (int i = 0; i < sum.size(); i++)
    {
        b= b<sum[i] ? sum[i] : b;
    }
    
    return b;
}
