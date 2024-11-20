#include <iostream>

using namespace std;
int N, A, B, CNT;
bool check;

// 토너먼트
int main(){
    cin >> N >> A >> B;
    for(int i = 0; i <= N/2; i++){
        CNT++;
        A = ((A + 1)% 2 == 1) ? A / 2 : (A+1)/2;
        B = ((B + 1)% 2 == 1) ? B / 2 : (B+1)/2;
        
        if(A == B){
            check = true;
            break;
        }
    }

    if(!check)
        CNT = -1;

    cout << CNT << "\n";
}