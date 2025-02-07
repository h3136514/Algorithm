// 구현, 문자열
#include <iostream>
#include <string>

using namespace std;
int CNT;
string num;

// 연속구간
int main(){
    for(int i = 0; i < 3; i++){
        cin >> num;
        int cnt = 1;
        CNT = cnt;
        for(int j = 1; j < num.size(); j++){
            if(num[j-1] == num[j])
                cnt++;
            else
                cnt = 1;
            
            CNT = max(CNT, cnt);
        }

        cout << CNT << "\n";
    }

    return 0;
}