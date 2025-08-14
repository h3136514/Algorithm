// 스택
#include <iostream>
#include <string>

using namespace std;
int N, leftCnt, rightCnt, maxCnt;
string S;

// 북극곰은 괄호를 찢어
int main() {
    cin >> N;
    cin >> S;
    
    for(int i = 0; i < N; i++){
        if(S[i] =='('){
            if(rightCnt)
                rightCnt--;
            else{
                leftCnt++;
                maxCnt = max(maxCnt, leftCnt);
            }  
        }else{
            if(leftCnt)
                leftCnt--;
            else{
                rightCnt++;
                maxCnt = max(maxCnt, rightCnt);
            }  
        } 
    }

    if(leftCnt || rightCnt)
        maxCnt = -1;

    cout << maxCnt << "\n";
    
    return 0;
}