#include<cstdio>
#include<queue>
using namespace std;
queue<pair<int,int>> q;
int N, M, i, j, num;
int Ischeck[201][201];  //방문 유무
int map[201][201];  //좌표 저장
int dist[201][201]; //해당좌표까지 거리합
//주변 좌표 포기위한 인덱스
int index_X[4]={-1, 1, 0, 0};
int index_Y[4]={0, 0, -1, 1};
char c[101];

void bfs(int x, int y){
    q.push({x, y});
    Ischeck[x][y]=1;
    dist[x][y]=1;

    while(!q.empty()){
        int a=q.front().first;
        int b=q.front().second;
        q.pop();

        //근처 좌표보기
        for(i=0;i<4;i++){
            int ix= a + index_X[i];
            int iy= b + index_Y[i];
            if(ix<0||ix>=N || iy<0||iy>=M)  //범위를 벗어남
                continue;
            if(map[ix][iy]==0)  //안지나감
                continue;
            if(map[ix][iy]==1 && Ischeck[ix][iy]==0){
                dist[ix][iy]=dist[a][b]+1;
                q.push({ix, iy});
                Ischeck[ix][iy]=1;
            }
        }
    }
    printf("%d", dist[N-1][M-1]);
}


int main(){
    scanf("%d %d",&N, &M);
    for(i=0;i<N;i++){
        scanf("%s", &c);
        for(j=0;j<M;j++){
            num=c[j]-'0';
            map[i][j]=num;
        }
    }
    bfs(0,0);
    return 0;
}