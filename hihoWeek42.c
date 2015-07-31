/*==========================================================================
#    > File Name:     hihoWeek42.c
#    > Version:       v0.0.1
#    > Author:        Jiang Wei
#    > Mail:          jiangwei@pmo.ac.cn 
#    > Created Time:  2015-04-21  11:23:06
----------------------------------------------------------------------------
#    > Description :
#        
----------------------------------------------------------------------------
#    > History :
#
==========================================================================*/

#include<stdio.h>
#define mod 12357





void assignment(long a[8][8], long b[8][8], int n)
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
void multMat(long a[8][8], long b[8][8], long result[8][8], int n)
{
    
	int i, j, k;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			result[i][j] = 0;
			for (k = 0; k < n; k++)
			{
				result[i][j] += (a[i][k] * b[k][j]) % mod;
				result[i][j] = result[i][j] % mod;
                
			}
		}
	}
}
void quickPow(long a[8][8], int div, long n, long  result[8][8])
{
	long i = 1;
	long swap[8][8], pow1[8][8], pow2[8][8];
	assignment(pow2, a, div);
	if (n>0)
	{
		while (i <= n)
		{
			if ((i&n) != 0)
			{
				multMat(result, pow2, swap, div);
				assignment(result, swap, div);
			}
			i <<= 1;
			multMat(pow2, pow2, pow1, div);
			assignment(pow2, pow1, div);
		}
	}
}
int main(){
    int i, j, k ;
    long  n, t = 0;
    long aa[100000];
    long  mat[8][8] = { 0 };
    long  a[8][8] = { 0 };
    aa[0]=1;
    aa[1]=3;
    for(i=0;i<4122;i++){
        aa[i+2]=(4*aa[i+1]-aa[i]+12357)%12357;
    }

    printf("%ld\n",aa[4121]);
    
   // long t=aa[k%4122];
    
    for (i = 0; i < 8; i++){
        mat[i][i] = 1;
        a[i][7 - i] = 1;
    }
    a[3][7] = a[6][7] = a[7][3] = a[7][6] = 1;
  //  scanf("%ld", &n);
    for(n=2;n<5;n++){
        k=n/2;
        t=aa[k%4122];

        for (i = 0; i < 8; i++){
            for(i=0;j<8;j++){
                mat[i][j]=0;
            }
            mat[i][i] = 1;
        }
      //  quickPow(a, 8, n, mat);
     //   if(t!=mat[7][7]){
            printf("t=%ld, mat=%ld\n",t, mat[7][7]);
      //  }
    }

    return 0;
}
