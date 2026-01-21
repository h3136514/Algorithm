#include <iostream>
#include <vector>

using namespace std;
long long N, result, idx = 1;
vector<int> v;

// 2진수 뒤집기
int main(){
    cin >> N;
    while(N >0){
        if(N % 2 == 0){
            v.push_back(0);
        }else{
            v.push_back(1);
        }
        N /= 2;
    }

    for(int i = v.size()-1; i >= 0; i--){
        if(v[i] == 1){
            result += idx;
        }

        idx *=2;
    }

    cout << result << "\n";

    return 0;
}