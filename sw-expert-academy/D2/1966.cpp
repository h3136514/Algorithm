#include<cstdio>
#include<queue>
using namespace std;
priority_queue <int> q[11];
int T, N, i, j, k, num;

int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d", &N);
        for(j=0;j<N;j++){
            scanf("%d", &num);
            q[i].push(-num);
        }
        
    }
    for(i=1;i<=T;i++){
        printf("#%d ", i);
        N=q[i].size();
        for(j=0;j<N;j++){
            num=-q[i].top();
            q[i].pop();
            printf("%d ", num);
        }
        printf("\n");
    }
    return 0;
}