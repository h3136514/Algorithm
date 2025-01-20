// 구현, 집합과 맵
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
unordered_map<string, int> m;
string str, p;
int N, sum;

// 야근
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str >> p;
        if(p == "+")
            m[str]++;
        else{
            if(m[str] == 0)
                sum++;
            else{
                m[str]--;
            }
        }
    }

    for(auto name : m)
        sum += name.second;

    cout << sum << "\n";


    return 0;
}