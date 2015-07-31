/*==========================================================================
#    > File Name:     hihoweek49.cpp
#    > Version:       v0.0.1
#    > Author:        Jiang Wei
#    > Mail:          jiangwei@pmo.ac.cn 
#    > Created Time:  2015-06-23  03:21:09
----------------------------------------------------------------------------
#    > Description :
#        
----------------------------------------------------------------------------
#    > History :
#
==========================================================================*/

#include<iostream>
using namespace std;
int main(){
    int n,m;
    int* s=new int[n];
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        s[a]++;
        s[b]++;
    }
    int r=0;
    for(int i=0;i<n;++i)
        if(s[i]%2==1)r++;
    cout<<(r==2?"Full":"Part")<<endl;
    delete[] s;
    return 0;
}
