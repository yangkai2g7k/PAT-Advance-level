/*PAT Advance 1055. The World's Richest (25)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct person{
		int age;
		int worth;
		char name[9];
	} ;
	
int compare(struct person a,struct person b){
	if(a.worth==b.worth)
		if(a.age == b.age)
			return -strcmp(a.name,b.name);
		else return -(a.age - b.age);
	else return (a.worth - b.worth);
}

void swamp(struct person *a,struct person *b){
	struct person tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void partition(struct person *a,int begin,int end){
	int i,j;
	struct person p;
	i = begin;
	p = a[begin];
	j = begin+1;
	        if(begin == end) return ;
	if(end - begin > 1){
	while(j<=end){
		if(compare(a[j],p)>0)
			swamp(&a[++i],&a[j]);
		j++;
	}
	if(compare(a[i],p)<0) swamp(&a[--i],&a[begin]);
	else swamp(&a[i],&a[begin]);
	partition(a,begin,i);
	partition(a,i+1,end);
 }
 else if(compare(a[begin],a[end])<0) swamp(&a[begin],&a[end]);
}
void quicksort(struct person a[],int n){
	if(n>1){
		partition(a,0,n-1);
	}
}


int main(){
	struct person *p;
	int n,k,times,count,i,st;
	int num,amin,amax;
	int a[201];
	fscanf(stdin,"%d%d",&n,&k);
	p = (struct person*)malloc(sizeof(struct person)*(n+1));  //????不改成+1就提示段错误，求解答
	for(i = 0;i<201;i++)
	a[i] = -1;
	for(i = 0;i<n;i++)
		fscanf(stdin,"%s%d%d",p[i].name,&p[i].age,&p[i].worth);
	quicksort(p,n);
	for(i = 0;i<n;i++)
	  if(a[p[i].age] == -1)
	    a[p[i].age] = i;
	times = 0;
	while(k--){
		times++;
		fscanf(stdin,"%d%d%d",&num,&amin,&amax);
		printf("Case #%d:\n",times);
		count = 0;
		st = 10000000;
		for(i = amin;i<=amax;i++)
		if(a[i] != -1&&a[i]<st)
        st = a[i];
        if(st<0||st>=n) st = 0;
		for(i=st;i<n;i++){
		if(p[i].age>=amin&&p[i].age<=amax){
			printf("%s %d %d\n",p[i].name,p[i].age,p[i].worth);
			count++;
		}
		if(count == num) break;
	    }
	    if(count == 0)
	    printf("None\n");
	}

}