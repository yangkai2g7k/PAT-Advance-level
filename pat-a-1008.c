/*PAT Advance 1008. Elevator (20)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,last,totaltime,now;
	scanf("%d",&n);
	last = 0;
	totaltime = 0;
	while(n--){
		scanf("%d",&now);
		if(now>last) totaltime += (now - last)*6 + 5;
		else if(now<last) totaltime += (last - now)*4 + 5;
		else totaltime += 5;
		last = now;
	}
	printf("%d\n",totaltime);
}