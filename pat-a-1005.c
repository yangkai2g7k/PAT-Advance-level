/*PAT Advance 1005. Spell It Right (20)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
#include<stdlib.h>

int main(){
	char num[101];
	int sum,i;
	int a[3];
	scanf("%s",num);
	i = 0;
	sum = 0;
	while(num[i]!='\0'){
		sum += num[i] - '0';
		i++;
	}
	a[2] = sum / 100;
	a[1] = (sum - a[2]*100)/10;
	a[0] = sum % 10;
	i = 2;
	while(a[i] == 0&&i)
		i--;
	while(i>0){
		switch(a[i]){
			case 0:printf("zero");break;
			case 1:printf("one");break;
			case 2:printf("two");break;
			case 3:printf("three");break;
			case 4:printf("four");break;
			case 5:printf("five");break;
			case 6:printf("six");break;
			case 7:printf("seven");break;
			case 8:printf("eight");break;
			case 9:printf("nine");break;
		}
		printf(" ");
		i--;
	}
	switch(a[0]){
		case 0:printf("zero");break;
			case 1:printf("one");break;
			case 2:printf("two");break;
			case 3:printf("three");break;
			case 4:printf("four");break;
			case 5:printf("five");break;
			case 6:printf("six");break;
			case 7:printf("seven");break;
			case 8:printf("eight");break;
			case 9:printf("nine");break;
	}
	printf("\n");
	return 0;
}