/*PAT Advance 1058. A+B in Hogwarts (20)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>

int main(){
	int g,s,k,tmp1,tmp2;
	int a[3];
	scanf("%d.%d.%d",&a[0],&a[1],&a[2]);
	scanf("%d.%d.%d",&g,&s,&k);
	tmp1 = (a[2] + k)/29;
	a[2] = (a[2] + k)%29;
	tmp2 = (tmp1 + a[1] + s)/17;
	a[1] = (tmp1 + a[1] + s)%17;
	a[0] = a[0] + g + tmp2;
	printf("%d.%d.%d\n",a[0],a[1],a[2]);
	return 0;
}