#include <iostream>

using namespace std;
int T, H, W, CNT, visitied[51][51];
char c[51][51];

void init(){
    CNT = 0;
     for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            visitied[i][j] = 0;
        }
    }
}

void check(){
    if(H == 1 && W == 1){
        if(c[0][0] == '#')
            CNT++;

        return;
    }
    
    if(W >= H){// 행부터 확인
        // 행 확인
        for(int i = 0; i < H; i++){
            int cnt = 0;
            bool isPaint = false;
            for(int j = 0; j < W; j++){
                if(c[i][j] == '#'){
                    if(!visitied[i][j]){
                        isPaint = true;
                    }
                    cnt++;
                }else
                    break;
            }
            if(cnt == W && isPaint){
                for(int j = 0; j < W; j++)
                    visitied[i][j] = 1;
                CNT++;
            }
        }
        // 열 확인
        for(int i = 0; i < W; i++){
            int cnt = 0;
            bool isPaint = false;
            for(int j = 0; j < H; j++){
                if(c[j][i] == '#'){
                    if(!visitied[j][i]){
                        isPaint = true;
                    }
                    cnt++;
                }else
                    break;
            }
            if(cnt == H && isPaint){
                for(int j = 0; j < H; j++)
                    visitied[j][i] = 1;
                CNT++;
            }
        }
    }else{  // 열부터 확인
        // 열 확인
        for(int i = 0; i < W; i++){
            int cnt = 0;
            bool isPaint = false;
            for(int j = 0; j < H; j++){
                if(c[j][i] == '#'){
                    if(!visitied[j][i]){
                        isPaint = true;
                    }
                    cnt++;
                }else
                    break;
            }
            if(cnt == H && isPaint){
                for(int j = 0; j < H; j++)
                    visitied[j][i] = 1;
                CNT++;
            }
        }
        // 행 확인
        for(int i = 0; i < H; i++){
            int cnt = 0;
            bool isPaint = false;
            for(int j = 0; j < W; j++){
                if(c[i][j] == '#'){
                    if(!visitied[i][j]){
                        isPaint = true;
                    }
                    cnt++;
                }else
                    break;
            }
            if(cnt == W && isPaint){
                for(int j = 0; j < W; j++)
                    visitied[i][j] = 1;
                CNT++;
            }
        }
    }
}

// 페인트칠
int main(){
    cin >> T;
    while(T--){
        cin >> H >> W;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                cin >> c[i][j];
            }
        }
        
        check();

        cout << CNT << "\n";

        init();
    }

    return 0;
}