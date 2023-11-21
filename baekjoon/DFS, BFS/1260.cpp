//주의: 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고(vector 대신 priority_queue사용)
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

queue<int> q;
priority_queue<int> v1[1001];
priority_queue<int> v2[1001];
int N, M, V, a, b, i, num[1001];//방문표시
//DFS
void dfs(int start){
    if(num[start])//이미방문했으면
        return;
    num[start]=1;
    printf("%d ",start);
    while(!v1[start].empty()){
        int x=-v1[start].top();
        v1[start].pop();
        dfs(x);
    }
}
//BFS
void bfs(int start){
    q.push(start);
    num[start]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        printf("%d ",x);
        //인접한 접점들 보기
        while(!v2[x].empty()){
            int y=-v2[x].top();
            v2[x].pop();
            if(!num[y])//방문 안했으면
            {
                q.push(y);
                num[y]=1;
            } 
        }
    }

}
//초기화
void init(){
    for(i=1;i<=N;i++)
        num[i]=0;
}
int main(){
    scanf("%d %d %d", &N, &M, &V);
    for(i=0;i<M;i++){
        scanf("%d %d", &a, &b);
        v1[a].push(-b);
        v1[b].push(-a);
        v2[a].push(-b);
        v2[b].push(-a);
    }
    dfs(V);
    printf("\n");
    init();
    bfs(V);
    return 0;
} 