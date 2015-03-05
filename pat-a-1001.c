/*PAT Advance 1001. A+B Format (20)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d;
	int n[3][3],i;
	scanf("%d%d", &a, &b);
 	i = 2;
 	c = a + b;
 	a = c / 1000;
	b = c / 1000000;
	d = c;
	while(d){
		n[i][0] = (d % 1000)/100;
		n[i][1] = ((d%1000) - n[i][0]*100)/10;
		n[i][2] = (d%1000)%10;
		d /= 1000;
		i--;
	}
	if (b) {
		printf("%d,", b);
		for(i = 0;i<3;i++) 
			printf("%d",abs(n[1][i]));
		printf(",");
		for(i = 0;i<3;i++) 
			printf("%d",abs(n[2][i]));
		printf("\n");
		}
	else if (a) {
		printf("%d,", a);
		for(i = 0;i<3;i++) printf("%d",abs(n[2][i]));
			printf("\n");
		}
	else printf("%d\n", c);
		return 0;
}
