/*PAT Advance 1006. Sign In and Sign Out (25)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int hour,minute,sec,n;
	int unlock,lock;
	char name[16];
	char unlk[16],lk[16];
	scanf("%d",&n);
	unlock = 24*3600;
	lock = 0;
	while(n--){
		scanf("%s%d:%d:%d",name,&hour,&minute,&sec);
		sec += hour*3600 + minute*60;
		if(sec<unlock) {
			unlock = sec;
			strcpy(unlk,name);
		}
		scanf("%d:%d:%d",&hour,&minute,&sec);
		sec += hour*3600 + minute*60;
		if(sec>lock){
			lock  = sec;
			strcpy(lk,name);
		}
	}
	printf("%s %s\n",unlk,lk);
	return 0;
}