#include<cstdio>
#include<queue>
using namespace std;
priority_queue <int> q;
queue <int> q2[32001], r;
int i,j,N,M,num[32001],a,b,c,broot,croot;

int main(){
    scanf("%d %d", &N, &M);
    for(i=0;i<M;i++){
        scanf("%d %d", &a, &b);
        num[b]++;
        q2[a].push(b);
    }
    // 진입차수가 0인 정점들을 큐에 삽입
    for(j=1;j<=N;j++){
        if(num[j]==0)
            q.push(j);
    }
    for(i=0;i<N;i++){
        if(q.empty())
            break;;

        int here=q.top(); // 현재 방문한 노드의 번호
        q.pop();
        r.push(here); // 방문 결과 저장
        // 현재 노드와 연결된 노드 중 진입차수가 0인 노드가 있다면 큐에 삽입
        while(!q2[here].empty()){
            c=q2[here].front();
            num[c]--;
            if(num[c]==0)
                q.push(c);
            q2[here].pop();
        }
    }
    //출력
    while(!r.empty()){
        printf("%d ", r.front());
        r.pop();
    }

    return 0;
}