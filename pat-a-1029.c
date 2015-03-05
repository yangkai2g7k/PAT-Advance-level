/*PAT Advance 1029. Median (25)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
#include<stdlib.h>

int main(){
	int *a,*b,*c;
	int m,n,mid,i,ap,bp,cp;
	scanf("%d",&m);
	a = (int *)malloc(sizeof(int)*m);
	for(i = 0;i<m;i++)
		scanf("%d",&a[i]);
	scanf("%d",&n);
	b = (int*)malloc(sizeof(int)*n);
	for(i = 0;i<n;i++)
		scanf("%d",&b[i]);
	c = (int *)malloc(sizeof(int)*(m+n));
	ap = bp = cp = 0;
	while(ap != m&&bp!= n){
		if(a[ap]<b[bp])
			c[cp++] = a[ap++];
		else c[cp++] = b[bp++];
	}
	while(ap!=m){
		c[cp++] = a[ap++];
	}
	while(bp!=n){
		c[cp++] = b[bp++];
	}
	if((m+n)%2 == 0)
		cp = (m + n)/2 - 1;
	else cp = (m + n)/2;
	printf("%d\n",c[cp]);
	free(a);
	free(b);
	free(c);
}