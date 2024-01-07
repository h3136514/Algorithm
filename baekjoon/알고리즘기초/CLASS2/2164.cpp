#include<cstdio>
#include<queue>
using namespace std;

int N, i;
queue<int> q;
int main(){
    scanf("%d", &N);
    for(i=1;i<=N;i++){
        q.push(i);
    }
    while(true){
        if(q.size() == 1)
            break;
        q.pop();
        int num =q.front();
        q.pop();
        q.push(num);
    }
    printf("%d\n", q.front());
}