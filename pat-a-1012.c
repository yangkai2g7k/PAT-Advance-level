/*PAT Advance 1012. The Best Rank (25)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stud{
	char name[7];
	int a[3][2];
	double aver;
	int arank;
};
void sort(struct stud *p,int flag,int n){
	int i,j,min,index;
	struct stud tmp;
	if(flag<3){
	for(i = 0;i<n;i++)
		for(j = i+1;j<n;j++){
			if(p[i].a[flag][0]<p[j].a[flag][0]){
				tmp = p[i];
				p[i]= p[j];
				p[j]= tmp;
			}
		}
	for(i = 0;i<n;i++){
		if(i>0){
			if(p[i].a[flag][0] == p[i-1].a[flag][0])
				p[i].a[flag][1] = p[i-1].a[flag][1];
			else p[i].a[flag][1] = i;
		}
		else p[i].a[flag][1] = i;
		}
	}
	else{
		for(i = 0;i<n;i++)
			for(j = i+1;j<n;j++){
				if(p[i].aver<p[j].aver){
					tmp = p[i];
					p[i] = p[j];
					p[j] = tmp;
				}
			}
		for(i = 0;i<n;i++)
		if(i>0){
			if(p[i].aver == p[i-1].aver)
				p[i].arank = p[i-1].arank;
			else p[i].arank = i;
		}
		else p[i].arank = i;
	}
	}

char title(int n){
	if(n == 0)
		return 'C';
	else if(n == 1)
		return 'M';
	else if(n == 2)
		return 'E';
	else return 'A';
}
int main(){
    char name[7],ch;
    int aver,c,math,e,n,m,i,k,j,min,index;
    struct stud *p;
    scanf("%d%d",&n,&m);
    p = (struct stud*)malloc(sizeof(struct stud)*n);
    for(i = 0;i<n;i++){
    	scanf("%s%d%d%d",p[i].name,&p[i].a[0][0],&p[i].a[1][0],&p[i].a[2][0]);
    	p[i].aver = (p[i].a[0][0] + p[i].a[1][0] + p[i].a[2][0])*1.0/3;
    	p[i].arank = i;
        p[i].a[0][1] = p[i].a[1][1] = p[i].a[2][1] = i;
    }
    sort(p,0,n);
    sort(p,1,n);
    sort(p,2,n);
    sort(p,3,n);
    for(i = 0;i<m;i++){
    	scanf("%s",name);
    	for(j = 0;j<n;j++){
    		if(strcmp(p[j].name,name) == 0) break;
    	}
    	if(j<n){
    		min = 3000;
    		for(k = 0;k<3;k++)
    			if(p[j].a[k][1]<min){
    				min = p[j].a[k][1];
    				index = k;
    			}
    		if(min<p[j].arank){
    			ch = title(index);
    			printf("%d %c\n",min+1,ch);
    		}
    		else {
    			ch = title(3);
    			printf("%d %c\n",p[j].arank+1,ch);
    		}
    	}
    	else printf("N/A\n");
    }
		return 0;
}