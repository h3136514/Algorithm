#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N, cnt;
char d;

// 숫자 빈도수
int main(){
    cin >> N >> d;
    for(int i = 1; i <= N; i++){
        string num = to_string(i);
        if(num.find(d) != string::npos){
          for(int j = 0; j < num.size(); j++){
            if(num[j] == d)
                cnt++;
          }
        }
    }

    cout << cnt << "\n";

    return 0;
}