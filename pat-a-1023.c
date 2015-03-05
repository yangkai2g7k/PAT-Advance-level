/*PAT Advance 1023. Have Fun with Numbers (20)*/
/*Author:Andy Yang*/
/*Email:andyyang0212@hotmail.com*/
#include<stdio.h>
#include<string.h> 
void reverse(char *a,int n){
	int i,j;
	char tmp;
	for(i = 0,j= n-1;i<=j;i++,j--){
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}
void sort(char *a,int n){
	int i,j;
	char tmp;
	for(i = 0;i<n;i++)
		for(j = i+1;j<n;j++){
			if(a[i]>a[j]){
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
}
int main(){
	char a[20],b[20],c[20];
	int i,j,lena,lenb,num,carriage;
	scanf("%s",a);
	lena = strlen(a);
	reverse(a,lena);
	for(i = 0,carriage = 0;i<lena;i++){
		b[i] = ((a[i] - '0')*2 + carriage) % 10 + '0';
		carriage = ((a[i] - '0' )*2+ carriage) / 10;
	}
	if(carriage)
		b[i++] = carriage + '0';
	b[i] = '\0';
	lenb = strlen(b);
	reverse(b,lenb);
	strcpy(c,b);
	sort(a,lena);
	sort(b,lenb);
	if(strcmp(a,b)==0&&carriage==0)
		printf("Yes\n");
	else printf("No\n");
	printf("%s\n",c);
	return 0;
}