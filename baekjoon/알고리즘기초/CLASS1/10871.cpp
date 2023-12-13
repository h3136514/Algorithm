#include<cstdio>
#include<queue>
using namespace std;
int N, X, num, i;
queue <int>q;

int main(){
    scanf("%d %d", &N, &X);
    for(i=0;i<N;i++){
        scanf("%d", &num);
        if(num<X)
            q.push(num);
    }
    while(!q.empty()){
        int here =q.front();
        printf("%d ", here);
        q.pop();
    }
    
    return 0;
}