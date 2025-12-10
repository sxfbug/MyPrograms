#include"headfile.hpp"

int Bin(vector<int>&x,int y)
{
    int head=0,tail=x.size()-1;

    while (head<=tail)
    {
        int mid=(head+tail)/2;
        if (y>x[mid])
        {
            head=mid+1;
        }
        else if(y<x[mid]){
            tail=mid-1;
        }else{
            return mid;
        }
        
    }
    return -1;
    
}