#include <string>
#include <vector>
#include <stack>
#include<iostream>

using namespace std;
vector<int> up;
vector<int> down;
stack<int> deleted;
int upCnt, downCnt, check[1000002];

//모든 명령어를 수행한 후 삭제되지 않은 행은 O, 삭제된 행은 X로 표시하여 문자열 형태로 반환(표의 행 개수: n, 처음에 선택된 행의 위치: k, 수행한 명령어들이 담긴 문자열 배열: cmd, 시간복잡도 : O(N))
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
  
    //각자 위아래 가리키는걸 지정(n+2: 테이블 양끝 추가)
    for(int i=0; i<n+2;i++){
        up.push_back(i - 1);
        down.push_back(i + 1);
        if(i > 0 && i <= n)
            check[i] =1;
    }
    //임시공간을 고려한 현재위치 
    k++;
    
    for(int i=0; i<cmd.size(); i++){
        
        if(cmd[i][0] == 'C'){
            
            deleted.push(k);
            check[k] = 0;
            up[down[k]] = up[k];
            down[up[k]] = down[k];
            // 선택 행 변경(삭제한 행이 마지막행이면)
            if(down[k] == n + 1)
                k = up[k];
            else
                k = down[k];
            
        }else if(cmd[i][0] == 'Z'){
            //가장 최근에 삭제한 행을 복원
            int num = deleted.top();
            check[num] = 1;
            
            up[down[num]] = num;
            down[up[num]] = num;
            deleted.pop();
        }else{
            int strNum = stoi(cmd[i].substr(2)); //str => int형으로 변환
            if(cmd[i][0] == 'U'){
                for(int j = 0; j < strNum; j++){
                    k = up[k];
                }
            }else if(cmd[i][0] == 'D'){
                for(int j = 0; j < strNum; j++){
                    k = down[k];
                } 
            }
        }
    }
    
    for(int i=1; i<n+1;i++){
        if(check[i])
            answer +='O';
        else
            answer +='X';
    }
    // 스택만 이용해서도 가능
    /*
     //삭제된 행의 위치에 “X”, 그렇지 않은 행의 위치에 “X” 로 표시한 문자열 반환
    answer.append(n, 'O');
    while (!deleted.empty()) {
        answer[deleted.top() - 1] = 'X';
        deleted.pop();
    }
    */

    return answer;
}

#include <iostream>

int main()
{
    
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"}) << endl;              //OOOOXOOO
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"}) << endl;  //OOXOXOOO
    return 0;
}