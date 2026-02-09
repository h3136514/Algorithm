#include <iostream>
#include <string>

using namespace std;
int T, N, M, num[1000001];

// 0의 개수 
int main(){

    num[0] = 1;
    for(int i = 1; i < 1000001; i++){
        string snum = to_string(i);
        int cnt = 0;
        for(int j = 0; j < snum.size(); j++){
            if(snum[j] =='0')
                cnt++;
        }
        num[i] = num[i-1] + cnt;
    }

    cin >> T;
    while(T--){
        cin >> N >> M;
        int sum = (N == 0) ? num[M] : num[M]-num[N-1];
        cout << sum << "\n";
    }

    return 0;
}