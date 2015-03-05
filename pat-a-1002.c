/*PAT Advance 1002. A+B for Polynomials (25)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct polynomial{
	double c;
	int n;
	struct polynomial *next;
};
struct polynomial *ploynomialadd(struct polynomial *p,struct polynomial *q){
	struct polynomial *sum,*head,*tail;
	head = tail = NULL;
	head = (struct polynomial*)malloc(sizeof(struct polynomial));
	head->next = NULL;
	head->n = 0;
	p = p->next;
	q = q->next;
	while(p!=NULL&&q!=NULL){
		sum = (struct polynomial *)malloc(sizeof(struct polynomial));
		sum->next = NULL;
		if(p->n == q->n) {
			if(fabs(p->c + q->c)<0.00001)
			{
			p = p->next;
			q = q->next;
			continue;	
			} 
			else{
				sum->n = p->n;
				sum->c = p->c + q->c;
				p = p->next;
				q = q->next;
			}
		}
		else if(p->n > q->n){
			sum->n = p->n;
			sum->c = p->c;
			p = p->next;
		}
		else {
			sum->n = q->n;
			sum->c = q->c;
			q = q->next;
		}
		if(head->next == NULL)
			head->next = sum;
		else tail->next = sum;
		tail = sum;
		head->n++;
	}
	while(p!= NULL)
	  {
	  	if(head->next == NULL)
			head->next = p;
		else tail->next = p;
		tail = p;
		head->n++;
	  	p = p->next;
	  }
	while(q!= NULL){
	if(head->next == NULL)
			head->next = q;
		else tail->next = q;
		tail = q;
		head->n++;
	  	q = q->next;
	}
	return head;
}

int main(){
	struct polynomial *p1,*p2,*head,*tail;
	int k,n,sum,i;
	double an;
	p1 = p2 = NULL;
	p2 = (struct polynomial*)malloc(sizeof(struct polynomial));
	p2->next = NULL;
	p2->n = 0;
    for(i = 0;i<=1;i++){
		scanf("%d",&k);
		tail = head = NULL;
		head = (struct polynomial*)malloc(sizeof(struct polynomial));
		head->next = NULL;
		while(k--){
			scanf("%d%lf",&n,&an);
			if(fabs(an - 0.000) <= 0.00001)
			continue;
			p1 = (struct polynomial*)malloc(sizeof(struct polynomial));
			if(p1 == NULL){
				printf("Out of Space\n");
				return 0;
			}
			p1->n = n;
			p1->c = an;
			p1->next = NULL;
			if(head->next == NULL){
				head->next = p1;
				head->n = k+1;
			}
			else tail->next = p1;
			tail = p1;
		}
		p2 = ploynomialadd(head,p2);
	}
	sum  = p2->n;
	printf("%d",p2->n);
	for(i = 0,p2 = p2->next;i<sum;i++,p2 = p2->next)
		printf(" %d %.1lf",p2->n,p2->c);
	
	printf("\n");
}