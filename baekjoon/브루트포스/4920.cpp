#include <iostream>

using namespace std;
int N, CNT, startX, startY, endX, endY, board[101][101], maxSum = -4000004;

// 막대기 모양
void position1(){
    int sum = 0;
    // 가로 막대기 확인
    startX = 1,startY = 1;
    endX = 4, endY = 1;
    while(true){
        if(endY > N)
            break;
        sum = 0;
        for(int i = startX; i <= endX; i++){
            sum += board[startY][i];
        }
        maxSum = max(maxSum, sum);

        if(endX == N){
            startX = 1;
            startY++;
            endX = 4;
            endY++;
            continue;
        }
        startX++;
        endX++;
    }
    // 세로 막대기 확인
    startX = 1,startY = 1;
    endX = 1, endY = 4;
    while(true){
        if(endX > N)
            break;
        sum = 0;
        for(int i = startY; i <= endY; i++){
            sum += board[i][startX];
        }
        maxSum = max(maxSum, sum);

        if(endY == N){
            startX++;
            startY = 1;
            endX++;
            endY = 4;
            continue;
        }
        startY++;
        endY++;
    }
}

// 지렁이 모양
void position2(){
    int sum = 0;
    // 옆 모양 지렁이 확인
    startX = 1,startY = 1;
    endX = 3, endY = 2;
    while(true){
        if(endY > N)
            break;
   
        sum = board[startY][startX] + board[startY][startX+1] + board[endY][endX-1] + board[endY][endX];
        maxSum = max(maxSum, sum);

        if(endX == N){
            startX = 1;
            startY++;
            endX = 3;
            endY++;
            continue;
        }
        startX++;
        endX++;
    }
    // 위아래 모양 지렁이 확인
    startX = 1,startY = 1;
    endX = 2, endY = 3;
    while(true){
        if(endX > N)
            break;

        sum = board[startY][startX+1] + board[startY+1][startX+1] + board[endY][endX-1] + board[endY-1][endX-1];
        maxSum = max(maxSum, sum);

        if(endY == N){
            startX++;
            startY = 1;
            endX++;
            endY= 3;
            continue;
        }
        startY++;
        endY++;
    }
}

// 'ㄱ' 모양
void position3(){
    int sum = 0;
    // 왼쪽&오른쪽 확인
    startX = 1,startY = 1;
    endX = 3, endY = 2;
    while(true){
        if(endY > N)
            break;

        sum = board[startY][startX] + board[startY][startX+1] + board[startY][startX+2] + board[endY][endX];
        maxSum = max(maxSum, sum);
        sum = board[startY][startX] + board[startY+1][startX] + board[endY][endX-1]+ board[endY][endX];
        maxSum = max(maxSum, sum);

        if(endX == N){
            startX = 1;
            startY++;
            endX = 3;
            endY++;
            continue;
        }
        startX++;
        endX++;
    }
    // 위&아래 확인
    startX = 1,startY = 1;
    endX = 2, endY = 3;
    while(true){
        if(endX > N)
            break;
      
        sum = board[startY][startX] + board[startY][startX+1] + board[endY-1][endX-1] + board[endY][endX-1];
        maxSum = max(maxSum, sum);
        sum = board[startY][startX+1] + board[startY+1][startX+1] + board[endY][endX-1]+ board[endY][endX];
        maxSum = max(maxSum, sum);

        if(endY == N){
            startX++;
            startY = 1;
            endX++;
            endY = 3;
            continue;
        }
        startY++;
        endY++;
    }


}

// 'ㅗ' 모양
void position4(){
    int sum = 0;
    // 위&아래 확인
    startX = 1,startY = 1;
    endX = 3, endY = 2;
    while(true){
        if(endY > N)
            break;
        
        sum = board[startY][startX] + board[startY][startX+1] + board[startY][startX+2] + board[endY][endX-1];
        maxSum = max(maxSum, sum);
        sum = board[startY][startX+1] + board[endY][endX-2] + board[endY][endX-1] + board[endY][endX];
        maxSum = max(maxSum, sum);

        if(endX == N){
            startX = 1;
            startY++;
            endX = 3;
            endY++;
            continue;
        }
        startX++;
        endX++;
    }
    // 왼쪽&오른쪽 확인
    startX = 1,startY = 1;
    endX = 2, endY = 3;
    while(true){
        if(endY > N)
            break;

       
        sum = board[startY][startX+1] + board[startY+1][startX] + board[startY+1][startX+1] + board[endY][endX];
        maxSum = max(maxSum, sum);
        sum = board[startY][startX] + board[startY+1][startX] + board[endY][endX-1] + board[endY-1][endX];
        maxSum = max(maxSum, sum);

        if(endX == N){
            startX = 1;
            startY++;
            endX = 2;
            endY++;
            continue;
        }
        startX++;
        endX++;
    }
}

// 'ㅁ' 모양
void position5(){
    int sum = 0;
    startX = 1,startY = 1;
    endX = 2, endY = 2;
    while(true){
        if(endY > N)
            break;
        sum = 0;
        sum = board[startY][startX] + board[startY][startX+1] + board[endY][endX-1] + board[endY][endX];
        maxSum = max(maxSum, sum);

        if(endX == N){
            startX = 1;
            startY++;
            endX = 2;
            endY++;
            continue;
        }
        startX++;
        endX++;
    }
}

// 테트리스 게임
int main(){
    while(true){
        CNT++;
        cin >> N;
        if(N == 0)
            break;
        
        for(int i = 1; i <= N; i++){
           for(int j = 1; j <= N; j++){
                cin >> board[i][j];
            } 
        }
        position1();
        position2();
        position3();
        position4();
        position5();

        cout << CNT <<". " << maxSum << "\n";

        maxSum = -4000004;  // 절댓값이 1,000,000을 넘지 않는 정수이므로(음수가능)
    }
    return 0;
}

