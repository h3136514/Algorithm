#include <iostream>
#include <string>
#include <map>

using namespace std;
int N, M, CNT;
string str;
map<string, int> m;

// 문자열 집합(문자열 중에서 집합에 포함되어 있는 것이 총 몇 개인지)
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> str;
        m[str] = 1;
    }

    for(int i = 0; i < M; i++){
        cin >> str;
        if(m.find(str) != m.end())
            CNT++;
    }

    cout << CNT << "\n";
    
    return 0;
}