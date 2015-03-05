/*PAT Advance 1007. Maximum Subsequence Sum (25)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n,sum,maxsum,maxbegin,maxend,sumbegin,sumend,i;
	int *num;
	scanf("%d",&n);
	sum = 0;
	maxsum = -1;
	i = 0;
	sumbegin = sumend = 0;
	num = (int *)malloc(sizeof(int)*n);
	while(n--){
		scanf("%d",&num[i]);
		sum += num[i];
		sumend = i;
		if(sum <0){
		sum = 0;
		sumbegin = sumend = i+1;
	}
		else if(sum>maxsum){
		maxsum = sum;
	    maxbegin = sumbegin;
	    maxend = sumend;
	}
		i++;
	}
    if(maxsum<0){
    	maxsum = 0;
    	maxend = i-1;
    }
	printf("%d %d %d\n",maxsum,num[maxbegin],num[maxend]);
    free(num);
	return 0;
}