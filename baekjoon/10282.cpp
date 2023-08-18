#include<cstdio>
#include <algorithm>	//fill함수 사용을 위한
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321
#define MAX 10001

int T, n,d,c, a,b,s,i,counts,sum,temp; 
int dp[MAX];
vector<pair<int, int>> v[MAX];
priority_queue<pair<int,int>> q;

// 다익스트라 알고리즘
void dijkstra() {
	int start=c;
	dp[start]=0;
	q.push({0,start});

	
	while(!q.empty()){
		int cost = -q.top().first;	//제일 작은 비용
		int here =q.top().second;	//연결된 컴퓨터
		q.pop();
		
		if(dp[here] < cost)	//이미 더 짧은 경로를 알고 있다면 무시
			continue;
		

		// 인접한 정점들을 검사하여 경로 갱신!
		for(i=0;i<v[here].size();i++)
		{
			int next =v[here][i].first;
			int nextCost= cost + v[here][i].second;

			if( dp[next] > nextCost)	//작은비용 갱신
				{
					dp[next]= nextCost;
					q.push({-nextCost, next});
				}
		}
		counts++;
		sum=dp[here];

	}

}

//초기화
void init(){
	fill(dp, dp+MAX, INF); 	//fill을 이용하여 초기화
	for(int j=0;j<MAX;j++)	//vector 초기화
		v[j].clear();

	counts=0;
	sum=0;
}

int main(){
	
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d%d",&n,&d,&c);
		for(i=0;i<d;i++){
			scanf("%d%d%d",&a,&b,&s);
			v[b].push_back({ a, s });
		}
		
		dijkstra();
		printf("%d %d\n",counts,sum);
		
	}
	
	return 0;
}
