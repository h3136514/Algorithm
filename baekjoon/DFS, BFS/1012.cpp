#include<cstdio>
#include<queue>
using namespace std;

queue <pair<int,int>> q;

int T, M, N, K, X, Y, i,j,k,l, cnt, map[51][51],ischeck[51][51];
int ind_X[4]={-1,1,0,0};
int ind_Y[4]={0,0,-1,1};

void bfs(int a, int b){
    q.push({a,b});
    ischeck[a][b]=1;
    cnt++;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(l=0;l<4;l++){
            int ix= x + ind_X[l];
            int iy= y + ind_Y[l];
            if(ischeck[ix][iy])
                continue;
            if(ix<0||ix>=M || iy<0||iy>=N)  //범위를 벗어남
                continue;
            if(!ischeck[ix][iy] && map[ix][iy]==1){
                ischeck[ix][iy]=1;
                q.push({ix, iy});

            }
        }

    }
}
void init(){
    cnt=0;
    for(j=0;j<M;j++){
        for(k=0;k<N;k++){
            map[j][k]=0;
            ischeck[j][k]=0;
        }
    }
}
int main(){
    scanf("%d", &T);
    for(i=0;i<T;i++){
        scanf("%d %d %d", &M, &N, &K);
        for(j=0;j<K;j++){
            scanf("%d %d", &X, &Y);
            map[X][Y]=1;
        }
        for(j=0;j<M;j++){
            for(k=0;k<N;k++){
                if(map[j][k]==1 && !ischeck[j][k]){
                    bfs(j, k);
                }
            } 
        }
        printf("%d\n",cnt);
        init();
    }

    return 0;
}


