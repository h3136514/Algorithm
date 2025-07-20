#include <iostream>
#include <vector>

using namespace std;
int N, ago;
long long sum;
vector<int> v;

// 스케이트 연습
int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++)
        cin >> v[i];
    sum = 1;
    ago = 1;

    for(int i = N - 2; i >= 0; i--){
        if(v[i] > ago){
            ago++;
        }else{
            ago = v[i];
        }

        sum += ago;
    }

    cout << sum << "\n";

    return 0;
}