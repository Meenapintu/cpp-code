#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//string match()
int match(string *str,string qtr,int sn){
        int count=0;
    bool m =true;
     for(int i=0;i<sn;++i){
         if(str[i].size()!=qtr.size())continue;
         else{
             
             m=true;
             for(int j=0;j<qtr.size();++j){
                 if(str[i][j]!=qtr[j]){m=false;break;}
             }
             if(m)count++;
         }
     }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    string str[n];
      for(int i=0;i<n;++i){
        cin>>str[i];
    }
    int q;
    cin>>q;
    string qtr[q];
    for(int i=0;i<q;++i){
        cin>>qtr[i];
    }
    
    
    for(int i=0;i<q;++i){
        cout<<match(str,qtr[i],n)<<'\n';
    }
    
    return 0;
}

