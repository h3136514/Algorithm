#include <string>
#include <vector>
#include <stack>

using namespace std;
stack<int> st; //보드판에서 꺼낸 인형을 담을 스택

// 인형뽑기로 가장 최근에 들어간 블럭과 현재 블럭이 같으면 터트리고 사라진 인형의 개수를 반환(시간복잡도 : O(N^2 + M))
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    for(int i = 0; i < moves.size(); i++) {
        for(int j = 0; j < board.size(); j++){

            // board값이 0이 아닐경우
            if(board[j][moves[i] - 1]){
                if(st.empty())
                    st.push(board[j][moves[i] - 1]);
                else {
                    if(st.top() == board[j][moves[i] - 1]){ // 같은 모양의 인형 두 개가 바구니에 연속해서 쌓인 경우
                        st.pop();
                        answer += 2;
                    }else
                        st.push(board[j][moves[i] - 1]);
                }
                board[j][moves[i] - 1] = 0;
                break;
            }  
        }
    }
    return answer;
}

#include <iostream>

int main()
{
    cout << solution({{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}}, {1,5,3,5,1,2,1,4}) << endl; // 4
    return 0;
}