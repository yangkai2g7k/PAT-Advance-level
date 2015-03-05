/*PAT Advance 1027. Colors in Mars (20)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>

int main(){
	int r,g,b,a[3][2],i,j;
	scanf("%d%d%d",&r,&g,&b);
	a[0][0] = r / 13;
	a[0][1] = r % 13;
	a[1][0] = g / 13;
	a[1][1] = g % 13;
	a[2][0] = b / 13;
	a[2][1] = b % 13;
	printf("#");
	for(i = 0;i<3;i++)
		for(j = 0;j<=1;j++){
			if(a[i][j]>=10)
				printf("%c",a[i][j] - 10 + 'A');
			else printf("%d",a[i][j]);
	}
	printf("\n"); 
}