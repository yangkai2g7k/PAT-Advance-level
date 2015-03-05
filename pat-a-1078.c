/*PAT Advance 1078. Hashing (25)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
#include<stdlib.h>
int prime(int n){
	int i;
	if(n == 1)
	return 0;
	for(i = 2;i*i<=n;i++)
		if(n%i == 0) break;
	if(i*i>n) return 1;
	else return 0;
}
int minprime(int n){
	while(!prime(n)){
		n++;
	}
	return n;
}

int main(){
	int m,n,i,num,yu,j;
	int *a,*b;
	scanf("%d%d",&m,&n);
	m = minprime(m);
	a = (int *)malloc(sizeof(int)*m);
	b = (int *)malloc(sizeof(int)*n);
	for(i = 0;i<m;i++)
		a[i] = -1;
	for(i = 0;i<n;i++)
		b[i] = -1;
	for(i = 0;i<n;i++){
		scanf("%d",&num);
	    j = 0;
	    while(j<m){
	    	yu = (j*j + num) %m;
	    	if(a[yu] == -1){
	    		b[i] = yu;
	    		a[yu] = num;
	    		break;
	    	}
	    	j++;
	    }
	}
	for(i = 0;i<n;i++)
	{
		if(b[i]!=-1)
			printf("%d",b[i]);
		else printf("-");
		if(i == n-1) printf("\n");
		else printf(" ");
	}
	return 0;
}