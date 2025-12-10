#include"hf.hpp"

int vowelStrings(vector<string>& words, int left, int right) 
{
    int c=0;
    for(string i : words){
        int t=i.length()-1;
        if(i[0]=='a' || i[0]=='e' ||i[0]=='i' ||i[0]=='o' ||i[0]=='u' ){
            if(i[t]=='a' || i[t]=='e' ||i[t]=='i' ||i[t]=='o' ||i[t]=='u'){
                c++;
            }
        }
    }
    return c;
}
