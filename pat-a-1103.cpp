#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int n,p,k;
vector<int> result,test;
void count(int value,int n,int max){
    if(value < 0)
        return ;
    if(n>=k&&value!=0)
        return ;
    if(value>(k - n)*pow(max, p))
        return ;
    if(value == 0&& k == n){
        if(result.size() == 0)
            result = test;
        else {
            int rs,ts;
            rs = ts = 0;
            for(int i = 0;i<k;i++){
                rs += result[i];
                ts += test[i];
            }
            if(ts>rs)
                result = test;
            else if(ts == rs){
                for(int i = 0;i<k;i++)
                    if(result[i]<test[i]){
                        result = test;
                        break;
                    }
                    else if(result[i]> test[i])
                        break;
            }
        }
    }
    for(int i = max;i>0;i--){
        test.push_back(i);
        count(value - pow(i, p), n+1, i);
        test.pop_back();
    }
}
int main(){
    scanf("%d%d%d",&n,&k,&p);
    count(n,0,n);
    if(result.size()!=k)
        printf("Impossible\n");
    else{
        printf("%d =",n);
        for(int i = 0;i<k;i++){
            printf(" %d^%d",result[i],p);
            if(i == k-1)
                printf("\n");
            else printf(" +");
        }
    }
    
    return 0;
}