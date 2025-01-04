// 수학, 구현, 사칙연산
#include <iostream>
#include <string>
#include <cmath>    // floor()함수(내림)

using namespace std;
int N, sum = 0;
string str;

// '나교수' 교수님의 악필
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str;
        if(str != "100"){
            for(int j = 0; j < str.size(); j++){
                if(str[j] == '0' || str[j] == '6')
                    str[j] = '9';
            }
        }
        sum += stoi(str);
    }

    cout << floor(sum/(double)N + 0.5) << "\n"; // 반올림

    return 0;
}