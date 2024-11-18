#include <iostream>
#include <string>

using namespace std;
int N, M, box = 1;
string num[51];

// 정사각형 탐색(네점의 숫자가 같은지)
bool checkBox(int cnt){
    int ax = 0, ay = 0, bx = cnt-1, by = 0, cx = 0, cy = cnt-1, dx = cnt-1, dy = cnt-1;
    int xCnt = 0, yCnt =0;
    while(dy + yCnt < N){
        int numA = num[ay + yCnt][ax + xCnt] -'0';
        int numB = num[by + yCnt][bx + xCnt] -'0';
        int numC = num[cy + yCnt][cx + xCnt] -'0';
        int numD = num[dy + yCnt][dx + xCnt] -'0';

        if(numA == numB && numB == numC && numC == numD)
            return true;
        
        if(dx + xCnt == M - 1){
            xCnt = 0;
            yCnt++;
        }else
            xCnt++;
    }
    return false;
}


// 숫자 정사각형 
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> num[i];

    int cnt  = min(N, M);
    for(int i = cnt; i > 1; i--){
        if(checkBox(i)){
            box = i*i;
            break;
        }
    }

    cout << box << "\n";

    return 0;
}