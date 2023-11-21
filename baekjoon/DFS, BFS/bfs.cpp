#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

queue<int> q;
vector<int> v[1001];
int N, M, V, a, b, i, num[1001];//방문표시

//BFS
void bfs(int start){
    q.push(start);
    num[start]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        printf("%d ",x);
        //인접한 접점들 보기
        for(i=0;i<v[x].size();i++){
            int y=v[x][i];
            if(!num[y])//방문 안했으면
            {
                q.push(y);
                num[y]=1;
            } 
        }
    }

}
int main(){
    scanf("%d %d %d", &N, &M, &V);
    for(i=0;i<M;i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(V);
    return 0;
} 