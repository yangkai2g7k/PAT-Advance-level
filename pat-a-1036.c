/*PAT Advance 1036. Boys vs Girls (25)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
#include<stdlib.h> 
struct Heapstruct;  
typedef struct Heapstruct *PriorityQueue;  
#define MinData -1
struct Heapstruct{  
    int capacity;  
    int size;  
    struct grade *a;  
}; 
struct grade{
	int score;
	char gender;
	char name[11];
	char id[11];
};
PriorityQueue Initialize(int MaxElements){  
    PriorityQueue h;  
    h = (PriorityQueue)malloc(sizeof(struct Heapstruct));  
    if(h == NULL){  
        printf("Out of Space\n");  
        return NULL;  
    }  
    h->a = (struct grade *)malloc(sizeof(struct grade)*MaxElements);  
    if(h->a == NULL){  
        printf("Out of Space\n");  
        return NULL;  
    }  
    h->capacity = MaxElements;  
    h->size = 0;  
    h->a[0].score = MinData;  
    return h;  
}  
  
int IsEmpty(PriorityQueue h){  
    return h->size == 0;  
}  
  
int IsFULL(PriorityQueue h){  
    return h->size == h->capacity-1;  
}  
  
void Insert(struct grade x,PriorityQueue h,int flag){  
    int i;  
    if(IsFULL(h)){  
        printf("Priority queue is full\n");  
        return ;  
    }
    if(flag){  
    for(i = ++h->size;h->a[i/2].score>x.score;i = i/2)  
        h->a[i] = h->a[i/2];  
    h->a[i] = x;
    }
    else {
    	h->a[0].score = 101;
    	for(i = ++h->size;h->a[i/2].score<x.score;i = i/2)  
        h->a[i] = h->a[i/2];  
    h->a[i] = x;
    }
    }  

struct grade FindMin(PriorityQueue h){  
    if(IsEmpty(h)){  
        printf("Priority queue is empty\n");    
    }
	else  
    return h->a[1];  
}    
int main(){
	struct grade stu;
	PriorityQueue p1,p2;
	int n,i,flag,score;
	scanf("%d",&n);
	getchar();
	p1 = Initialize(n+1);
	p2 = Initialize(n+1);
	while(n--){
		scanf("%s %c %s %d",stu.name,&stu.gender,stu.id,&stu.score);

		//printf("%c\n",stu.gender);
		if(stu.gender == 'M')
			Insert(stu,p1,1);
		else Insert(stu,p2,0);
	}
	flag = 0;

	if(!IsEmpty(p2)){
		stu = FindMin(p2);
		printf("%s %s\n",stu.name,stu.id);
		score = stu.score;
	}
	else{
		flag = 1;
		printf("Absent\n");
	}
		if(!IsEmpty(p1)){
		stu = FindMin(p1);
		printf("%s %s\n",stu.name,stu.id);
		
	}
	else{
		flag = 1;
		printf("Absent\n");
	}
	if(flag)
		printf("NA\n");
	else 
		printf("%d\n",score - stu.score);
	return 0;
}