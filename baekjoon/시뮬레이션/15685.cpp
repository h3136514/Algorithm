#include <iostream>
#include <vector>

using namespace std;
int N, x, y, d, g, CNT, board[101][101];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, -1, 0, 1};
vector<int> v[11] = {{0}, {0, 1}};

// 좌표 범위 확인
bool check(int xi, int yi){
    return xi >= 0 && xi <= 100 && yi >= 0 && yi <= 100;
}

//  네 꼭짓점이 모두 드래곤 커브의 일부인지 확인
void tri(){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1])
                CNT++;
        }
    }
}

// 드래곤 커브
int main(){
    cin >> N;

    // 드래곤 커브 세대 생성 
    for(int i = 2; i <= 10; i++){
        for(int j = 0; j < v[i-1].size(); j++){
            v[i].push_back(v[i-1][j]);
        }

        // 이전세대 역순 + 1
        for(int j = v[i-1].size()-1; j >= 0; j--){
            v[i].push_back((v[i-1][j]+1)%4);
        }   
    }

    for(int i = 0; i < N; i++){
        cin >> x >> y >> d >> g;
        board[y][x] = 1;
        for(int j = 0; j < v[g].size(); j++){
            x += offer_X[(v[g][j] + d) % 4];
            y += offer_Y[(v[g][j] + d) % 4];

            if(!check(x, y))
                break;

            board[y][x] = 1;
        }
    }

    tri();
    
    cout << CNT << "\n";

    return 0;
}