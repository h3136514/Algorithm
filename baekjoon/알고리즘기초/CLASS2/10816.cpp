#include<cstdio>
#include<map>
#include<queue>
using namespace std;
int N, M, num, i;
map<int,int> Map;
queue<int> q;

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d", &num);
        Map[num]++;
    }
    scanf("%d", &M);
    for(i=0;i<M;i++){
        scanf("%d", &num);
        q.push(num);
    }
    for(i=0;i<M;i++){
        printf("%d ", Map[q.front()]);
        q.pop();
    }
    printf("\n");
    return 0;
}