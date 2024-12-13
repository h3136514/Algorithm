// 구현, 수학
#include <iostream>
#include <string>

using namespace std;
int N;
string acc;
float num, result;

// 화성 수학 
int main(){
    cin >> N;
    //  소수점 둘째 자리까지 출력
    cout << fixed;
    cout.precision(2);

    while(N--){
        cin >> num;
        getline(cin, acc); // 공백 포함 입력
        result = num;
        for(int i = 0; i < acc.size(); i++){
            if(acc[i] == ' ')
                continue;
            
            if(acc[i] == '@')
                result *=3;
            else if(acc[i] == '%')
                result +=5;
            else if(acc[i] == '#')
                result -=7;
        }

        cout << result << "\n";
    }

    return 0;
}