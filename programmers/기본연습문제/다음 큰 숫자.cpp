#include <string>
#include <vector>

using namespace std;
int nCnt;

// 2진수로 변환했을 때 1의 갯수 반환
int twoCount(int num){
    int cnt = 0;
    while(num > 0){
        if(num%2 != 0){
            num--;
            cnt++;
        }else
            num /= 2;
    }
    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    nCnt = twoCount(n);
    
    while(true){
        n++;
        if(nCnt == twoCount(n)){
            answer = n;
            break;
        }
    }
    
    return answer;
}