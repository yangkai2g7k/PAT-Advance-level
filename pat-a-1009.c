/*PAT Advance 1009. Product of Polynomials (25)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	double a[2][1001],b[2001];
	int i,n,times,sum,j;
	double an;
	for(i = 0;i<=1000;i++)
		a[0][i] = a[1][i] = 0;
	for(i = 0;i<=2000;i++)
		b[i] = 0;
	for(i = 0;i<2;i++){
		scanf("%d",×);
		while(times--){
			scanf("%d%lf",&n,&an);
			a[i][n] = an;
		}
	}
	for(i = 0;i<=1000;i++)
	   	if(fabs(a[0][i])>0.00001){
	   		for(j = 0;j<=1000;j++){
	   			if(fabs(a[1][j])>0.00001)
	   				b[i+j] += a[0][i]*a[1][j];
	   		}
	   	}
	   	sum = 0;
	for(i = 0;i<=2000;i++)
		if(fabs(b[i])>0.00001) sum++;
	printf("%d",sum);
	for(i = 2000;i>=0;i--)
		if(fabs(b[i])>0.00001)
			printf(" %d %.1lf",i,b[i]);
		printf("\n");
	return 0;
}