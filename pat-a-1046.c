/*PAT Advance 1046. Shortest Distance (20)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,i,j,num1,num2,m,d1,d2,tmp;
	int *distance;
	scanf("%d",&n);
	distance = (int *)malloc(sizeof(int)*n);
	for(i = 0;i<n;i++){
		scanf("%d",&distance[i]);
		if(i)
			distance[i] += distance[i-1];
	}
	scanf("%d",&m);
	for(i = 0;i<m;i++){
		d1 = d2 = 0;
		scanf("%d%d",&num1,&num2);
		if(num1>num2){
			tmp = num1;
			num1 = num2;
			num2 = tmp;
		}
		if(num1 == 1)
		  d1 = distance[num2 - 2];
		else
		  d1 = distance[num2-2] - distance[num1-2];
		d2 = distance[n-1] - distance[num2 - 2] + distance[num1-2];
		/*
		for(j = num2-1;;j++){
			if(j == n)
				j = 0;
			if(j == num1-1)
			break;
			d2 += distance[j];
		}
		*/
		if(d1>d2)
				d1 = d2;
		printf("%d\n",d1);
	}
	return 0;
}