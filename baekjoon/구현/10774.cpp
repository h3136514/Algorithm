// https://www.acmicpc.net/problem/10774
#include <iostream>
#include <map>

using namespace std;
int N, M, a, num[1000001], CNT;
map<char, int> m;
char c;

// 저지
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    m['S'] = 1, m['M'] = 2, m['L'] = 3;
    cin >> N;
    cin >> M;
    for(int i = 0; i < N; i++){
        cin >> c;
        num[i+1] = m[c];
    }

    for(int j = 0; j < M; j++){
        cin >> c >> a;
        if(num[a] >= m[c]){
            num[a] = 0;
            CNT++;
        }
    }

    cout << CNT << "\n";

    return 0;
}