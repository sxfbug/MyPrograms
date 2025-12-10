#include"headfile.hpp"

//返回的是索引，如果找不到返回-1
int Seq(vector<int> &x,int y)
{
    for (auto i = 0; i < x.size(); i++)
    {
        if (x[i]==y)
        {
            return i;
        }
        
    }
    return -1;
}