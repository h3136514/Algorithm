#include <string>
#include <vector>

using namespace std;
int startIdx, maxIdx, answerSize;
char maxNum;

string solution(string number, int k) {
    string answer = "";
    answerSize = number.size() - k; // k개 제거후 남은 숫자 수
    
    for(int i = 0; i < answerSize; i++){
        // startidx부터 k+i까지 확인해서 max값 찾음(뒤에 k-(i+1)개 수만큼 남김 => answerSize만큼의 수를 완성하기 위해)
        maxIdx = startIdx;
        maxNum = number[maxIdx];
        for(int j = startIdx; j <= i + k; j++){
            if(maxNum < number[j]){
                maxNum = number[j];
                maxIdx = j;
            }
        }
       
        answer += maxNum;
        startIdx = maxIdx+1;    // 최댓값 다음부터 탐색
    }
    
    return answer;
}