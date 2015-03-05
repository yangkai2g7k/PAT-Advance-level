/*PAT Advance 1015. Reversible Primes (20)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
int reverse(int a,int radix){
	int sum;
	sum = 0;
	while(a){
		sum = sum* radix + a%radix;
		a = a/radix;
	}
	return sum;
}

int Isprime(int n){
	int i;
	if(n == 1) return 0;
	for(i = 2;i*i<=n;i++)
		if(n % i == 0) break;
	if(i*i <= n) return 0;
	else return 1;
}
int main(){
	int a,radix,rever;
	while(scanf("%d",&a)&&a>0){
		scanf("%d",&radix);
		rever = reverse(a,radix);
		if(Isprime(rever)&&Isprime(a))
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}