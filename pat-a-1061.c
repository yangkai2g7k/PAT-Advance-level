/*PAT Advance 1061. Dating (20)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>

int main()
{char a[4][61],ch;
int i,day,flag = 0;;
scanf("%s%s%s%s",a[0],a[1],a[2],a[3]);
for(i = 0;a[0][i] !='\0'&&a[1][i] != '\0';i++)
{
	if(a[0][i] == a[1][i] &&(a[0][i]>='A'&&a[0][i]<='G')&&flag == 0) {
	day = a[0][i] - 'A'+1;
	switch(day){
	case 1:printf("MON ");break;
	case 2:printf("TUE ");break;
	case 3:printf("WED ");break;
	case 4:printf("THU ");break;
	case 5:printf("FRI ");break;
	case 6:printf("SAT ");break;
	case 7:printf("SUN ");break;
	default:break;
	}
flag = 1;
continue;
	} 
	if(a[0][i] == a[1][i]&&(a[0][i]>='0'&&(a[0][i]<='9'||a[0][i]>='A'&&a[0][i]<='N')&&flag))
	{
	if(a[0][i]>='0'&&a[0][i]<='9') printf("0%d:",a[0][i] - '0');
	else printf("%d:",a[0][i]-'A'+10);
	break;}
}
	for(i = 0;a[2][i] !='\0'&&a[3][i] != '\0';i++)
	{
	if(a[2][i] == a[3][i] &&(a[2][i]>='A'&&a[2][i]<='Z'||a[2][i]>='a'&&a[2][i]<='z')) 
	{	if(i<10) printf("0%d\n",i);
		else printf("%d\n",i);
		break;}	}

return 0;
}
