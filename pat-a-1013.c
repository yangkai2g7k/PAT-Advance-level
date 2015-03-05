/*PAT Advance 1013. Battle Over Cities (25)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>

int a[1000][1000],vertix[1000];
void DFS(int n,int s,int destorycity){
	int i;
	for(i = 0;i<n;i++)
		if(a[s][i]&&i != destorycity&&!vertix[i]){
			vertix[i]  = 1;
			DFS(n,i,destorycity);
		}
}
int main(){
	int n,m,k,i,j,city,road,to;
	scanf("%d%d%d",&n,&m,&k);
	while(m--){
		scanf("%d%d",&i,&j);
		a[i-1][j-1] = 1;
		a[j-1][i-1] = 1;
	}
	while(k--){
		scanf("%d",&city);
		city--;
		for(j = 0;j<n;j++)
			vertix[j] = 0;
		for(j = 0,road = 0;j<n;j++)
		{
			if(j!=city&&!vertix[j]){
				vertix[j] = 1;
				road++;
				DFS(n,j,city);
			}
		}
		printf("%d\n",road-1); 
	}
	return 0;
}