/*==========================================================================
#    > File Name:     hihoWeek43.c
#    > Version:       v0.0.1
#    > Author:        Jiang Wei
#    > Mail:          jiangwei@pmo.ac.cn 
#    > Created Time:  2015-04-27  01:04:48
----------------------------------------------------------------------------
#    > Description :
#        
----------------------------------------------------------------------------
#    > History :
#
==========================================================================*/

#include<stdio.h>
#define mod 12357
long d[200][200];
long  mat[200][200];
long swap[200][200], pow1[200][200], pow2[200][200];
int K;
void DFS(int x, int y, int col){
    if(col == K){
        d[y][x] = 1;
        return ;
    }
    DFS(x << 1, (y << 1) + 1, col + 1);
    DFS((x << 1) + 1, y << 1, col + 1);
    if( col + 2 <= K){
        DFS( (x << 2) + 3, (y << 2) + 3, col + 2 );
    }
}
void assignment(long a[200][200], long b[200][200], int n)
{
    int i, j;
    for (i = 0; i<n; i++)
    {
        for (j = 0; j<n; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}
void multMat(long a[200][200], long b[200][200], long result[200][200], int n)
{
    int i, j, k;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++) {
            result[i][j] = 0;
            for (k = 0; k < n; k++)         {
                result[i][j] += (a[i][k] * b[k][j]) % mod;
                result[i][j] = result[i][j] % mod;
            }
        }
    }
}
void quickPow(int div, long n){
    long i = 1;
    assignment(pow2, d, div);
    if (n > 0)  {
        while (i <= n)      {
            if ((i&n) != 0)         {
                multMat(mat, pow2, swap, div);
                assignment(mat, swap, div);
            }
            i <<= 1;
            multMat(pow2, pow2, pow1, div);
            assignment(pow2, pow1, div);
        }
    }
}

int main(){
    int i,j,col;
    long  n, sum=0; 
    scanf("%d %ld", &K, &n);
    col=1<<K;
    DFS(0,0,0);
    for(i=0;i<200;i++){
        mat[i][i]=1;
    }
    quickPow(col, n);
    printf("%ld\n",mat[col-1][col-1]);
    return 0;
}
