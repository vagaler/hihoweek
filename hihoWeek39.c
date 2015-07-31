/*==========================================================================
#    > File Name:     mergeSort.c
#    > Version:       v0.0.1
#    > Author:        Jiang Wei
#    > Mail:          jiangwei@pmo.ac.cn 
#    > Created Time:  2015-04-02  03:40:35
----------------------------------------------------------------------------
#    > Description :
#        
----------------------------------------------------------------------------
#    > History :
#
==========================================================================*/

#include<stdio.h>
#include<stdlib.h>
 
int Merge(int sourceArr[],int tempArr[],int startIndex,int midIndex,int endIndex)
{
    int i = startIndex,j=midIndex+1,k = startIndex, convertCount=0;
    while(i!=midIndex+1 && j!=endIndex+1)
    {
        if(sourceArr[j]<sourceArr[i])
        {
            tempArr[k++] = sourceArr[j++];
            convertCount+=midIndex-i+1;
        }
        else
        {
            tempArr[k++] = sourceArr[i++];
        }
    }
    while(i!=midIndex+1)
        tempArr[k++] = sourceArr[i++];
    while(j!=endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex;i<=endIndex;i++)
        sourceArr[i] = tempArr[i];
    return convertCount;
}
 
int MergeSort(int sourceArr[],int tempArr[],int startIndex,int endIndex)
{
    int midIndex;
    int pairSum=0;
    if(startIndex<endIndex)
    {
        midIndex=(startIndex+endIndex)/2;
        pairSum+=MergeSort(sourceArr,tempArr,startIndex,midIndex);
        pairSum+=MergeSort(sourceArr,tempArr,midIndex+1,endIndex);
        pairSum+=Merge(sourceArr,tempArr,startIndex,midIndex,endIndex);
    }
    return pairSum;
}
 
int main(int argc,char * argv[])
{
    int i,n,a[100000],b[100000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    printf("%d\n",MergeSort(a,b,0,n-1));
    return 0;
}
