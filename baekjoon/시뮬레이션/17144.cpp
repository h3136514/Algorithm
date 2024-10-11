#include <iostream>

using namespace std;
int R, C, T, CX1, CY1, CX2, CY2, sum, room[51][51], tmp[51][51];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};

void printRoom(){
    cout <<"------------- \n";
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << room[i][j] <<" ";
        }
        cout <<" \n";
    }
     cout <<"------------- \n";
}

// 범위확인
bool check(int x, int y){
    return x >= 0 && x < C && y >= 0 && y < R; 
}

// 미세먼지 확산
void spread(int x, int y){
    int value = room[y][x]/5;  //확산양
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        int ix = x + offer_X[i];
        int iy = y + offer_Y[i];

        if(check(ix, iy) && room[iy][ix] != -1){
            cnt++;
            tmp[iy][ix] += value;
        }
    }
    room[y][x] = room[y][x] - value*cnt;
}

// 공기청정기 바람
void clean(){
    // 위 청정(반시계)
    int tmpValue1 = 0, tmpValue2 = 0;
    for(int j = CX1 + 1; j < C; j++){   //오른쪽
        tmpValue2 = room[CY1][j];
        room[CY1][j] = tmpValue1;
        tmpValue1 = tmpValue2;
    }
    for(int j = CY1 - 1; j >= 0; j--){   //위
        tmpValue2 = room[j][C-1];
        room[j][C-1] = tmpValue1;
        tmpValue1 = tmpValue2;
    }
    for(int j = C-2; j >= 0; j--){   //왼쪽
        tmpValue2 = room[0][j];
        room[0][j] = tmpValue1;
        tmpValue1 = tmpValue2;
    }
    for(int j = 1; j < CY1; j++){   //아래
        tmpValue2 = room[j][0];
        room[j][0] = tmpValue1;
        tmpValue1 = tmpValue2;
    }

    tmpValue1 = 0;
    // 아래 청정 (시계)
     for(int j = CX2 + 1; j < C; j++){   //오른쪽
        tmpValue2 = room[CY2][j];
        room[CY2][j] = tmpValue1;
        tmpValue1 = tmpValue2;
    }
    for(int j = CY2 + 1; j < R; j++){   //아래
        tmpValue2 = room[j][C-1];
        room[j][C-1] = tmpValue1;
        tmpValue1 = tmpValue2;
    }
    for(int j = C-2; j >= 0; j--){   //왼쪽
        tmpValue2 = room[R-1][j];
        room[R-1][j] = tmpValue1;
        tmpValue1 = tmpValue2;
    }
    for(int j = R-2; j > CY2; j--){   //아래
        tmpValue2 = room[j][0];
        room[j][0] = tmpValue1;
        tmpValue1 = tmpValue2;
    }
}

// 미세먼지 안녕!
int main(){
    cin >> R >> C >> T;
    int cnt = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> room[i][j];
            if(room[i][j] == -1){
                if(cnt == 0){
                    CX1 = j;
                    CY1 = i;
                    cnt++;
                }else{
                    CX2 = j;
                    CY2 = i;
                }
               
            }
        }
    }

    while(T--){
        // 미세 먼지확산
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(room[i][j] != 0 && room[i][j] != -1){
                    spread(j, i);
                }
            }
        }
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(room[i][j] != -1){
                    room[i][j] += tmp[i][j];
                    tmp[i][j] = 0;
                }
            }
        }
       
        clean();
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(room[i][j] != -1) 
                sum += room[i][j];
        }
    }

    cout << sum << "\n";

    return 0;
}