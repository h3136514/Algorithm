#include <string>
#include <vector>

using namespace std;

// board의 크기를 벗어난 방향키 입력인지 확인
bool check(vector<int> board, int x, int y) {
    int ix = board[0]/2;
    int iy = board[1]/2;
    
    return x <= ix && x >= -ix && y <= iy && y >= -iy; 
}

vector<int> solution(vector<string> keyinput, vector<int> board) {
    int currentX = 0, currentY = 0;
    
    for(int i = 0; i < keyinput.size(); i++) {
        if(keyinput[i] == "up"){
            if(check(board, currentX, currentY + 1))
                currentY += 1;
        }else if(keyinput[i] == "down") {
            if(check(board, currentX, currentY - 1))
                currentY -= 1;
        }else if(keyinput[i] == "left") {
            if(check(board, currentX - 1, currentY))
                currentX -= 1;
        }else if(keyinput[i] == "right") {
            if(check(board, currentX + 1, currentY))
                currentX += 1;
        }     
    }
    
    return {currentX, currentY};
}


// 테스트 코드
#include <iostream>

void print(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "\n";
}

int main()
{
    print(solution({"left", "right", "up", "right", "right"}, {11, 11})); //출력값 : 2 1 
    print(solution({"down", "down", "down", "down", "down"}, {7, 9})); //출력값 : 0 -4  
  
    return 0;
}