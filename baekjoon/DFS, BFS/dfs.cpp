#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

queue<int> q;
vector<int> v[1001];
int N, M, V, a, b, i, num[1001];//방문표시

//DFS
void dfs(int start){
    if(num[start])//이미방문했으면
        return;
    num[start]=1;
    printf("%d ",start);
    for(i=0;i<v[start].size();i++){
        int x=v[start][i];
        dfs(x);
    }
}
int main(){
    scanf("%d %d %d", &N, &M, &V);
    for(i=0;i<M;i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(V);
    return 0;
} 