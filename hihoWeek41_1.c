/*==========================================================================
#    > File Name:     hihoWeek41.c
#    > Version:       v0.0.1
#    > Author:        Jiang Wei
#    > Mail:          jiangwei@pmo.ac.cn
#    > Created Time:  2015-04-15  02:37:17
----------------------------------------------------------------------------
#    > Description :
#
----------------------------------------------------------------------------
#    > History :
#
==========================================================================*/

#include<stdio.h>
void assignment(long  a[][2], long  b[][2])
{

	int i, j;
	for (i = 0; i<2; i++)
	{
		for (j = 0; j<2; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}
void multMat2(long   a[][2], long  b[][2], long  result[][2])
{
	int i, j, k;
	for (i = 0; i<2; i++)
	{
		for (j = 0; j<2; j++)
		{
			result[i][j] = 0;
			for (k = 0; k < 2; k++)
			{
				result[i][j] += a[i][k] * b[k][j];
				result[i][j] %= 19999997;
			}
		}
	}
}
void quickPow(long  a[][2], long  n, long  result[][2])
{
	long  i = 1;
	long  swap[2][2], pow1[2][2], pow2[2][2];
	assignment(pow2, a);
	if (n>0)
	{
		while (i <= n)
		{
			if ((i&n) != 0)
			{
				multMat2(result, pow2, swap);
				assignment(result, swap);
			}
			i <<= 1;
			multMat2(pow2, pow2, pow1);
			assignment(pow2, pow1);
		}
	}
}

int main()
{
	long  n;
	long  mat[2][2] = { 1, 0, 0, 1 };
	long  a[2][2] = { 0, 1, 1, 1 };
	scanf("%ld", &n);
	if (n > 100000000)
	{
		return 1;
	}
	if (n < 1)
	{
		printf("0\n");
		return 0;
	}
	quickPow(a, n, mat);
	printf("%ld\n", mat[1][1]);
	return 0;
}
