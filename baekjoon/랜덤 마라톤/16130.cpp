// 구현, 사칙연산, 시뮬레이션
#include <iostream>
#include <string>

using namespace std;
int N, sum, cnt, ago;
string str;

// 벌점 (DemeritPoints)
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str;

        sum = 0;
        cnt = 0;
        ago = 0;
        for(int j = 0; j < str.size(); j++){
            if(sum/10 > 4)
                continue;
            
            if(int(str[j]) <= 57){
                sum += int(str[j]) - 48;
            }else
                sum += int(str[j]) - 55;
            
            if(sum/10 < 4 && ago != sum/10 ){
                cnt += sum/10;
                ago = sum/10;
            }
        }

        string result = "";
        if(sum/10 == 4)
            result = "(weapon)";
        else if(sum/10 > 4)
            result = "(09)";
        
        cout << cnt << result << "\n";
    }

    return 0;
}