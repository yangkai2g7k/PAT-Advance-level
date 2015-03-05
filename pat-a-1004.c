/*PAT Advance 1004. Counting Leaves (30)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
#include<stdlib.h>


#define Black 2
#define Gray 1
#define White 0
#define Infinite 1000
#define NIL -1

struct QueueRecord;
typedef struct QueueRecord *Queue;

#define MinQueueSize 5
int level[10],deepest;
struct QueueRecord{
	int capacity;
	int front;
	int rear;
	int size;
	int *a;
}; 

int IsEmpty(Queue q){
	return q->size == 0;
}
int IsFull(Queue q){  
    return q->size == q->capacity;  
}  

Queue CreateQueue(int MaxElements){
	Queue q;
	q = (Queue)malloc(sizeof(struct QueueRecord));
	if(q == NULL){
		printf("Out of Space\n");
	}
	q->a = (int *)malloc(sizeof(int)*MaxElements);
	if(q->a == NULL){
		printf("Out of Space\n");
		return NULL;
	}
	q->capacity = MaxElements;
	q->size = 0;
	q->front = 1;
	q->rear = 0;
	return q;
}

void DisposeQueue(Queue q){
	free(q->a);
	free(q);
}

void Enqueque(int x,Queue q){
	if(IsFull(q)){
		printf("The queue is full\n");
		return;
	}
	q->size++;
	q->rear++;
	if(q->rear==q->capacity)
		q->rear = 0;
		q->a[q->rear] = x;
}
int FrontAndDequeue(Queue q){  
    int n;  
    if(IsEmpty(q)){  
        printf("The queue is empty\n");  
        return -1;  
    }  
    n = q->a[q->front];  
    q->size--;  
    q->front++;  
    if(q->front<0)  
        q->front = q->capacity - 1;  
    return n;  
}  

struct map{
	int d;
	int color;
	int parent;
	int child;
} vertix[120];

void BSF(int a[120][120],int n,int s){
	int i,j;
	int tmp;
	Queue q;
	for(i = 0;i<=n;i++){
		vertix[i].d = Infinite;
		vertix[i].color = White;
		vertix[i].parent = NIL;
		vertix[i].child = 0;
	}
	vertix[s].color = Gray;
	vertix[s].d = 0;
	level[0] = 1;
	deepest = 0;
	q = CreateQueue(n+10);
	Enqueque(s,q);
	while(!IsEmpty(q)){
		tmp = FrontAndDequeue(q);
		for(i = 0;i<=n;i++)
			if(a[tmp][i])
				if(vertix[i].color == White){
					vertix[i].d = vertix[tmp].d + 1;
					level[vertix[i].d]++;
					if(deepest<vertix[i].d)
						deepest = vertix[i].d;
					vertix[i].color = Gray;
					vertix[i].parent = tmp;
					vertix[tmp].child++;
					Enqueque(i,q);
				}
		vertix[tmp].color = Black;
		if(vertix[tmp].child)
			level[vertix[tmp].d]--;
	}
	DisposeQueue(q);

}

int main(){
	int a[120][120];
	int i,j,n,m,num,d;
	Queue q;
	scanf("%d%d",&n,&m);
	for(i = 0;i<10;i++)
		level[i] = 0;
	for(i = 1;i<=n;i++)
		for(j = 1;j<=n;j++)
			a[i][j] = 0;
	while(m--){
		scanf("%d%d",&i,&num);
		while(num--){
			scanf("%d",&j);
			a[i][j] = 1;
		}
	}
	BSF(a,n,1);
	for(i = 0;i<deepest;i++)
		printf("%d ",level[i]);
    printf("%d\n",level[deepest]);
	return 0;
}