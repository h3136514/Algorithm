#include <iostream>
#include <queue>

using namespace std;
int N, M, K, r, c, m, s, d, sum;
int offer_X[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int offer_Y[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
queue<pair<int, pair<int, int>>> tmp[51][51], q[51][51];

// 모든 파이어볼 이동
void move(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            while(!q[i][j].empty()){
                int im = q[i][j].front().first;
                int is = q[i][j].front().second.first;
                int id = q[i][j].front().second.second;

                int ir = i + is%N*offer_Y[id];
                if(ir < 1)
                    ir += N;
                else if(ir > N)
                    ir -= N;

                int ic = j + is%N*offer_X[id];
                if(ic < 1)
                    ic += N;
                else if(ic > N)
                    ic -= N;
                
                tmp[ir][ic].push({im, {is, id}});
                q[i][j].pop();
            }
        }
    }

    // 임시 큐 초기화
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            while(!tmp[i][j].empty()){
                int im = tmp[i][j].front().first;
                int is = tmp[i][j].front().second.first;
                int id = tmp[i][j].front().second.second;

                q[i][j].push({im, {is, id}});
                tmp[i][j].pop();
            }
        }
    }
}

// 이동이 끝난뒤 작업
void work(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(q[i][j].size() == 1 && q[i][j].front().first == 0){
                q[i][j].pop();
            }

            // 2개 이상의 파이어볼이 있는 칸
            if(q[i][j].size() > 1){
                int imSum = 0, isSum = 0, idSum = 0;
                int cnt = q[i][j].size();
                while(!q[i][j].empty()){
                    imSum += q[i][j].front().first;
                    isSum += q[i][j].front().second.first;
                    if(q[i][j].front().second.second%2 == 0)
                        idSum++;

                    q[i][j].pop();
                }

                int im = imSum/5;
                // 질량이 0이면 소멸
                if(im == 0)
                    continue;

                int is = isSum/cnt;
                int id = (idSum == cnt || idSum == 0) ? 0 : 1;

                for(int l = 0; l <= 6; l +=2){
                    q[i][j].push({im, {is, l+id}});
                }

            }
        }
    }
}

// 모든 질량의 합
void sumM(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            while(!q[i][j].empty()){
                sum += q[i][j].front().first;
                q[i][j].pop();
            }
        }
    }
}

// 마법사 상어와 파이어볼
int main(){
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++){
        cin >> r >> c >> m >> s >> d;
        q[r][c].push({m, {s, d}});
    }

    while(K--){
        move();
        work();
    }

    sumM();

    cout << sum << "\n";

    return 0;
}