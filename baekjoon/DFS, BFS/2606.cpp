#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

queue<int> q;
vector<int> V[101];
int N, M, i, a, b, cnt, isCheck[101];

void bfs(int x){
	q.push(x);
	isCheck[x]=1;
	while(!q.empty()){
		int here=q.front();
		q.pop();
		for(i=0;i<V[here].size();i++){
			int num=V[here][i];
			if(!isCheck[num])
			{
				cnt++;
				isCheck[num]=1;
				q.push(num);
			}
		}
	}
}

int main(){
	scanf("%d", &N);
	scanf("%d", &M);
	for(i=0;i<M;i++){
		scanf("%d %d", &a, &b);
		V[a].push_back(b);
		V[b].push_back(a);
	}
	bfs(1);
	printf("%d", cnt);
	return 0;
}
