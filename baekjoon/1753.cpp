#include<cstdio>
#include<queue>
#include<vector>

#define INF 3000000         // 300,000(E)*10
#define MAX 20001

using namespace std;
priority_queue <pair <int,int>> q;
vector <pair <int, int>> ver[MAX];
int V,E,K,u,v,w,i,dp[MAX];

void dijkstra(){
    int start=K;
    dp[start]=0;
    q.push({0,start});
    
    while(!q.empty()){
        int here =q.top().second;
        int cost= -q.top().first;
        q.pop();
        if(dp[here] < cost)
            continue;
        
        for(i=0;i<ver[here].size();i++)
        {
            int next=ver[here][i].first;
            int nextcost=ver[here][i].second + cost;

            if(nextcost < dp[next])
            {
                dp[next]=nextcost;
                q.push({-nextcost,next});
            }

        }
    }

}


int main(){

    scanf("%d%d",&V,&E);
    scanf("%d",&K);
    //dp 초기화
     for(i=1;i<=V;i++)
        dp[i]=INF;

    //간선입력
    while(E--){
        scanf("%d%d%d",&u,&v,&w);
        ver[u].push_back({v,w});
    }
    
    dijkstra();
    
    //출력
    for(i=1;i<=V;i++){
        if(dp[i]==INF)
            printf("INF\n");
        else 
            printf("%d\n",dp[i]);
    }
       
   
    return 0;
}