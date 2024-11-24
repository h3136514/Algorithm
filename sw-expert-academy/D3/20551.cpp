// 증가하는 사탕 수열
#include <iostream>

using namespace std;
int T, A, B, C;

int main(){
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> A >> B >> C;
        if(B < 2 || C < 3){
            cout << "#" << i << " -1\n";
            continue;
        }

        int cnt = 0;
        if(A >= B || B >= C){
            if(B >= C){
                cnt += B - C + 1;
                B -= B - C + 1;
            }
            if(A >= B){
                cnt += A - B + 1;
                A -= A - B + 1;
            }
        }

        cout << "#" << i << " " << cnt << "\n";
    }

    return 0;
}