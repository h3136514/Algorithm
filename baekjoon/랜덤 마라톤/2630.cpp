// 분할 정복, 재귀
#include <iostream>

using namespace std;
int N, paperSize, white, blue, whiteCNT, blueCNT, num[129][129], visitied[129][129];

// 색종이 만들기
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> num[i][j];
        }
    }
    
    //  N/2 크기의 색종이 계속 확인
    for(int c = N; c >= 1; c /= 2){
        int startX = 0, startY = 0, endX = c, endY = c;
        
        while(endY <= N){
            white = 0;
            blue = 0;
            bool check = false;
            for(int i = startY; i < endY; i++){
                for(int j = startX; j < endX; j++){
                    if(visitied[i][j]){
                        check = true;
                        break;
                    }
                    
                    if(num[i][j])
                        blue++;
                    else
                        white++;

                }
            }

            if(!blue && !check)
                whiteCNT++;
            else if(!white && !check){
                blueCNT++;
            }

            // 방문 체크
            if(!check && (!blue || !white)){
                for(int i = startY; i < endY; i++)
                    for(int j = startX; j < endX; j++)
                        visitied[i][j] = 1;
            }

            if(endX == N){
                endX = c;
                endY += c;
                startX = 0;
                startY += c;
            }else{
                startX += c;
                endX += c;
            }
        }
    }

    cout << whiteCNT << "\n";
    cout << blueCNT << "\n";

    return 0;
}