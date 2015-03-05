/*PAT Advance 1031. Hello World for U (20)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
#include<string.h>
int main(){
	char str[90];
	int len,n1,n2,n3,i,j,k;
	scanf("%s",str);
	len = strlen(str);
	if((len + 2)%3 == 0){
		n1 = n2 = n3 = (len + 2)/3;
	}
	else if((len +2)%3){
		n2 = (len + 2) %3 + (len + 2)/3;
		n1 = n3 = (len +2)/3;
	}
	for(i = 0,j = len-1;i<n1-1;i++,j--){
		printf("%c",str[i]);
		for(k = 1;k<=n2 - 2;k++)
			printf(" ");
		printf("%c\n",str[j]);
	}
	for(;i<=j;i++)
		printf("%c",str[i]);
	printf("\n");
	return 0;
}