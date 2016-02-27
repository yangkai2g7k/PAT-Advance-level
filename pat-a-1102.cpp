#include <iostream>
#include <vector>
#include <queue>
#define SIZE 20
using namespace std;
struct tree{
    int index;
    int left,right;
}T[SIZE];
vector<int> lorder,iorder;
int atoi(string num){
    int value = 0;
    for(int i = 0;i<num.length();i++)
        value = value*10 + num[i] - '0';
    return value;
}
void reverse(int index){
//    if(index == -1)
//        return ;
    int tmp = T[index].left;
    T[index].left = T[index].right;
    T[index].right = tmp;
    if(T[index].left!=-1)
        reverse(T[index].left);
    if(T[index].right!=-1)
        reverse(T[index].right);
}
void levelorder(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int index = q.front();
        q.pop();
        lorder.push_back(index);
        if(T[index].left!=-1)
            q.push(T[index].left);
        if(T[index].right!=-1)
            q.push(T[index].right);
    }
}
void inorder(int index){
    if(index == -1)
        return ;
    inorder(T[index].left);
    iorder.push_back(index);
    inorder(T[index].right);
}
bool visited[SIZE];
int main(){
    int n;
    int root = 0;
    cin >> n;
    for(int i = 0;i<n;i++){
        string ls,rs;
        cin >> ls >> rs;
        T[i].left = T[i].right = -1;
        if(ls[0]!='-'){
            T[i].left = atoi(ls);
            visited[T[i].left] = true;
        }
        if(rs[0]!='-'){
            T[i].right = atoi(rs);
            visited[T[i].right] = true;
        }
    }
    for(int i = 0;i<n;i++)
        if(!visited[i])
        {
            root = i;
            break;
        }
    reverse(root);
    levelorder(root);
    inorder(root);
    for(int i = 0;i<lorder.size();i++){
        cout << lorder[i];
        if(i == lorder.size()-1)
            cout << endl;
        else cout << ' ';
    }
    for(int i = 0;i<iorder.size();i++){
        cout << iorder[i];
        if(i == iorder.size()-1)
            cout << endl;
        else cout << ' ';
    }
    return 0;
}