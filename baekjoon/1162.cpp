#include<cstdio>
#include<queue>
#include<vector>

#define INF 500000000000 //50,000(최대 도로의 수) *  1,000,000(최대걸리는시간)
#define MAX 10001
using namespace std;

int N, M, K, a,b,s,i,j;
long long dp[MAX][21];
vector<pair<int,int>> v[MAX];
priority_queue<pair<long long ,pair<int,int>>> q;

void dijkstra(){
    dp[1][0]=0;
    q.push({-dp[1][0], {1, 0}});     //맨 처음 시작점

    while(!q.empty()){

        long long cost=-q.top().first;
        int here=q.top().second.first;
        int count=q.top().second.second;
        q.pop();
        
        if(dp[here][count] < cost)
            continue;

        for(i=0;i<v[here].size();i++){
            int next = v[here][i].first;
            long long nextCost= v[here][i].second + cost; //포장X 할 때 시간
            if(count<K) //포장O
            {
                if(dp[next][count+1] > cost){
                    dp[next][count+1] = cost; //포장 했으므로 걸리는 시간 0을 더함
                    q.push({-dp[next][count+1],{next, count+1}});
                }

            }
            if(dp[next][count] > nextCost) //포장X
            {
                dp[next][count]=nextCost; //포장 안했으므로 걸리는 시간을 더함
                q.push({-dp[next][count],{next, count}});
            }
        }   

    } 

}


int main(){
    scanf("%d%d%d",&N,&M,&K);
    //dp초기화
    for(i=1;i<=N;i++){
        for(j=0;j<=K;j++){
            dp[i][j]=INF;
        }
    }

    while(M--){
        scanf("%d%d%d",&a,&b,&s);
        v[b].push_back({ a, s });
        v[a].push_back({ b, s });
    }
    
    dijkstra();
    
    //최솟값 구하기
    long long min_c=INF;
    for(i=0;i<=K;i++){
        if(min_c >dp[N][i])
             min_c=dp[N][i];

    }
    printf("%lld\n",min_c);

    return 0;
}