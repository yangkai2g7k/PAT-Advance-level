#include <iostream>
#include <algorithm>
#include <vector>
#define SIZE 100000
using namespace std;
int a[SIZE],sorted[SIZE];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        sorted[i] = a[i];
    }
    sort(sorted, sorted+n);
    vector<int> result;
    int max = 0;
    for(int i = 0;i<n;i++){
        if(a[i]>max)
            max = a[i];
        if(sorted[i]!=a[i])
            continue;
        if(a[i]>=max)
        {
            result.push_back(a[i]);
        }
    }
    sort(result.begin(),result.end());
    printf("%d\n",result.size());
    if(result.size() == 0)
        printf("\n");
    for(int i = 0;i<result.size();i++)
        if(i<result.size()-1)
            printf("%d ",result[i]);
        else printf("%d\n",result[i]);
    return 0;
}