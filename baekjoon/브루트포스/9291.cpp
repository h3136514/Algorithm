#include <iostream>
#include <string>

using namespace std;
int T, num[10], board[9][9];
string emptyInput;

void init(){
    for(int i = 1; i < 10; i++)
        num[i] = 0;
}

bool checkSudoke(){
    init();

    // 각행, 각열 판별
    for(int j = 0; j < 9; j++){
        // 각행
        for(int k = 0; k < 9; k++){
            int a = board[j][k];
            if(num[a]){
                return false;
            }
            num[a] = 1;
        }
        init();

        // 각열
        for(int k = 0; k < 9; k++){
            int a = board[k][j];
            if(num[a]){
                return false;
            }
            num[a] = 1;
        }
        init();
    }

    // 3x3 정사각형 판별
    int startX = 0, startY = 0, endX = 2, endY = 2;
    while(endY < 9){
        for(int j = startY; j <= endY; j++){
            for(int k = startX; k <= endX; k++){
                int a = board[j][k];
                if(num[a]){
                    return false;
                }
                num[a] = 1;
            }
        }
        init();

        if(endX == 8){
            startX = 0, endX = 2;
            startY += 3;
            endY += 3;
        }else{
            startX += 3, endX += 3;
        }
    }

    return true;
}

// 스도쿠 채점
int main(){
    cin >> T;
    for(int i = 1; i <= T; i++){
        for(int j = 0; j < 9; j++)
            for(int k = 0; k < 9; k++)
                cin >> board[j][k];
        
        if(i != T){
            getline(cin, emptyInput);
            cin.ignore();
        }

        if(checkSudoke())
            cout << "Case " << i << ": CORRECT\n";
        else
            cout << "Case " << i << ": INCORRECT\n";
    }

    return 0;
}