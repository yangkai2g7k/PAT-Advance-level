/*PAT Advance 1019. General Palindromic Number (20)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>

int main(){
	int num[1000],i,digit,j,flag;
	long long n,radix;
	scanf("%Ld%Ld",&n,&radix);
	i = 0;
	while(n){
		num[i++] = n % radix;
		n = n/radix;
	}
	digit = i-1;
	flag =0;
	for(i = 0,j = digit;i<j;i++,j--)
		if(num[i]!= num[j]){
			flag = 1;
			break;
		}
	if(flag)
		printf("No\n");
	else printf("Yes\n");
	for(i = digit;i>0;i--){  
		printf("%d ",num[i]);
	}
	printf("%d\n",num[0]);
	return 0;
}