/*==========================================================================
#    > File Name:     hihoweek50.c
#    > Version:       v0.0.1
#    > Author:        Jiang Wei
#    > Mail:          jiangwei@pmo.ac.cn 
#    > Created Time:  2015-06-23  10:23:39
----------------------------------------------------------------------------
#    > Description :
#        
----------------------------------------------------------------------------
#    > History :
#
==========================================================================*/

#include<stdio.h>

#include<stdio.h>
int s[10001];

int main(){
    int n,m,i;
    int r=0;
    scanf("%d%d", &n, &m);
    while(m--){
        int a,b;
        scanf("%d%d", &a, &b);
        s[a]++;
        s[b]++;
    }
    for(i=0;i<n;++i)
        if(s[i]%2==1)r++;

    printf(r>2?"Part\n":"Full\n");

    return 0;
}
