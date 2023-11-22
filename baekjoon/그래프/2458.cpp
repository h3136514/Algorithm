#include<cstdio>
#include<queue>
#include <vector>
using namespace std;

int i,j,N,M,a,b,cnt,answer;
int visited[501];
vector<int> lista[501]; // 정방향  
vector<int> listb[501];// 역방향 

void dfs(vector<int> t[], int a){
    visited[a]=1;
    for(int r=0;r<t[a].size();r++){
        int next = t[a][r];
        if(visited[next])
            continue;
        cnt++;
        dfs(t, next);
    }
}

void clear(){   //방문 초기화
    for(j=0;j<=N;j++)
        visited[j]=0;
}
int main(){
    scanf("%d %d",&N,&M);  
    for(i=0;i<M;i++){
        scanf("%d %d",&a,&b);      
        lista[a].push_back(b);      //간선 방향대로(자기보다큰)
        listb[b].push_back(a);      //간선 역방향대로(자기보다작은)
    }
    for(i=1;i<=N;i++){
        clear();
        dfs(lista, i);
        clear();
        dfs(listb, i);

        if(cnt==N-1)    //앞,뒤합==N-1(위치알수있음)
            answer++;
        cnt=0;
    }
    printf("%d",answer);
    return 0;
}