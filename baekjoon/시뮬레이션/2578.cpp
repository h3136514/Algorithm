#include <iostream>
#include <unordered_map>

using namespace std;
int num, CNT, board[5][5];
bool result = false;
unordered_map<int, pair<int, int>> m;

// 빙고 확인
bool check(){
    int sum = 0, cnt = 0;
    for(int i = 0; i < 5; i++){
        // 가로줄 확인
        cnt = 0;
        for(int j = 0; j < 5; j++){
            if(board[i][j])
                cnt++;
        }
        if(cnt == 5)
            sum++;

        // 세로줄 확인
        cnt = 0;
        for(int j = 0; j < 5; j++){
            if(board[j][i])
                cnt++;
        }
        if(cnt == 5)
            sum++;
    }

    // 대각선 확인
    cnt = 0;
    for(int i = 0; i < 5; i++){
        if(board[i][i])
            cnt++;
    }
    if(cnt == 5)
        sum++;
    
    cnt = 0;
    for(int i = 0; i < 5; i++){
        if(board[i][4-i])
            cnt++;
    }
    if(cnt == 5)
        sum++;


    if(sum >= 3)
        return true;
    
    return false;
}

// 빙고
int main(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> num;
            m[num] = {i, j};
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> num;
            if(result)
                continue;
            
            CNT++;
            int y = m[num].first;
            int x = m[num].second;

            board[y][x] = 1;
            if(check()){
                result = true;
            }
        }
    }

    cout << CNT << "\n";

    return 0;
}