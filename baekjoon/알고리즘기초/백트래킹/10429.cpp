#include <iostream>
#include <vector>

using namespace std;
int N, M, visitied[3][3];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
char board[3][3];
bool gameTrue;
vector<pair<int, int>> v = {{0,0}, {0,2}, {1,1}, {2, 0}, {2,2}};

bool check(int x, int y){
    return x >= 0 && y >= 0 && x < 3 && y < 3;
}

void backtrack(int x, int y, int value, char c, int cnt, vector<pair<int, int>> tmp){
    if(cnt == M){
        if(value == N && !gameTrue){
            gameTrue = true;
            cout <<"1\n";
            for(int i = 0; i < tmp.size(); i++){
                cout << tmp[i].second << " " << tmp[i].first << "\n"; 
            }
        }
        return;
    }

    for(int i = 0; i < 4; i++){
        int ix = x + offer_X[i];
        int iy = y + offer_Y[i];

        if(check(ix, iy) && !visitied[iy][ix]){
            visitied[iy][ix] = 1;
            tmp.push_back({ix, iy});

            if(board[iy][ix] == '-' || board[iy][ix] == '+'){   // 부호일 때
                backtrack(ix, iy, value, board[iy][ix], cnt, tmp);
            }else{  // 숫자일 때
                if(c =='+'){
                    backtrack(ix, iy, value + (board[iy][ix] -'0'), '0', cnt + 1, tmp);
                }else{
                    backtrack(ix, iy, value - (board[iy][ix] -'0'), '0', cnt + 1, tmp);
                }
            }

            visitied[iy][ix] = 0;
            tmp.pop_back();
        }
    }

}

// QUENTO
int main(){
    cin >> N >> M;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;
        int v = board[y][x] - '0';

        visitied[y][x] = 1;
        backtrack(x, y, v,'0', 1, {{x,y}});
        visitied[y][x] = 0;
    }

    if(!gameTrue)
        cout << "0\n";

    return 0;
}