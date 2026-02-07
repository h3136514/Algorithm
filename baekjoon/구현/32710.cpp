#include <iostream>
#include <map>

using namespace std;
int N;
map<int, bool> m;

// 구구단표
int main(){
    cin >> N;

    for(int i = 2; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            m[i] = true;
            m[j] = true;
            m[i*j] = true;
        }
    }

    if(m.find(N) == m.end())
        cout << "0\n";
    else
        cout << "1\n";

    return 0;
}