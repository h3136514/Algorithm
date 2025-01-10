// 수학, 조합론
#include <iostream>

using namespace std;
int N, r;

// 다각형의 대각선
int main(){
    cin >> N;
    if(N < 4)
        r = 0;
    else{

        // NC4 구하기
        r = 1;
        for(int i = 0; i < 4; i++){
            r *= N-i;
        }
        for(int i = 2; i <= 4; i++){
            r /= i;
        }
    }

    cout << r << "\n";

    return 0;
}