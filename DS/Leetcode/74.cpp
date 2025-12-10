#include"hf.hpp"

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int size=matrix[0].size()-1;
        int h=0,t=matrix.size()-1;
        int line,row;
        while(h<=t){
            int mid=(h+t)/2;
            if(target == matrix[mid][0]){
                t=mid;
                break;
            }
            if(target < matrix[mid][0]){
                t=mid-1;
            }else{
                h=mid+1;
            }
        }
        
        //overflow
        if (t<0)
        {
            return false;
        }
        
        line=t;
        
        
        //cout<<"line: "<<line<<endl;



        int h2=0,t2=size;
        while(h2<=t2){
            int m=(h2+t2)/2;
            
            if (target == matrix[line][m])
            {
                t2=m;
                break;
            }
            
            if(target <= matrix[line][m]){
                t2=m-1;
            }else{
                h2=m+1;
            }
        }
        if (t2<0)
        {
            return false;
        }
        
        row=t2;


        //cout<<"row: "<<row<<endl;
        if(matrix[line][row]==target){
            return true;
        }
        else{
            return false;
        }


    
        
}

/*
int in;
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    while (cin>>in)
    {
        bool a=searchMatrix(matrix,in);
        cout<<"answer: "<<a<<endl;
    }
*/