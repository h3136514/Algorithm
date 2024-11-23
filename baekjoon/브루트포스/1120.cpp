#include <iostream>
#include <string>

using namespace std;
int CNT = 51;
string A, B;

//  A와 B의 차이를 최소화한 수
void checkDiffer(){
    for(int i = 0; i <= B.size()-A.size(); i++){
        int cnt = 0;
        for(int j = 0; j < A.size(); j++){
            if(A[j] != B[i+j])
                cnt++;
        }
        CNT = min(CNT, cnt);
    }
}

// 문자열
int main(){
    cin >> A >> B;
    checkDiffer();

    cout << CNT << "\n";

    return 0;
}
