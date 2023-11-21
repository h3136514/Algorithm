#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

queue <pair<int, int>> q;
priority_queue <int> q2; //단지들 오른차순 정리
int N, M, i, j, k, a, cnt, isCheck[25][25], map[25][25];
int ind_X[4] = { -1,1,0,0 };
int ind_Y[4] = { 0,0,-1,1 };
char c[26];

void bfs(int x, int y) {
	q.push({ x,y });
	isCheck[x][y] = 1;
	cnt++;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (k = 0; k < 4; k++) {
			int herea = a + ind_X[k];
			int hereb = b + ind_Y[k];
			if (herea < 0 || herea >= N || hereb < 0 || hereb >= N)
				continue;
			if (map[herea][hereb] == 0)
				continue;
			if (!isCheck[herea][hereb] && map[herea][hereb] == 1)
			{
				cnt++;
				isCheck[herea][hereb] = 1;
				q.push({ herea,hereb });
			}
		}
	}
	q2.push(-cnt);
	cnt = 0;
	
}

int main() {
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", &c);
		for (j = 0; j < N; j++) {
			a = c[j] - '0';
			map[i][j] = a;
		}

	}
		
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if(map[i][j]==1 && !isCheck[i][j]){
				bfs(i, j);
			}
		}
	}
	int s= q2.size();
	printf("%d\n",s);
	for (i = 0; i < s; i++){
		int num= -q2.top();
		q2.pop();
		printf("%d\n", num);
	}
		

	return 0;
}
