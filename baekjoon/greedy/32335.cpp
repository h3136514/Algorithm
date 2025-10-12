#include <iostream>
#include <string>

using namespace std;
int N, M;
string s;

// 부자가 될 거야!
int main(){
    cin >> N >> M;
    cin >> s;


    // 앞자리 부터 가장 작은 수를 만듬
    for(int i = 0; i < N-1; i++){
        if(s[i] > '0'){
            int num = s[i] -'0';

            if(num + M >= 10){
                s[i] = '0';
                M -= (10-num);
            }

        }
    }

    if(M > 0){
        int num = s[N-1] -'0';
        num += M;
        num %= 10;
    
        s[N-1] = num + '0';
    }

    cout << s << "\n";

    return 0;
}
