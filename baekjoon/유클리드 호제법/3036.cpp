// https://www.acmicpc.net/problem/3036
#include <iostream>
#include <vector>

using namespace std;
int N, target;
vector<int> v;

int gcd(int a, int b){
    if(!b)
        return a;
    return gcd(b, a%b);
}

// 링
int main(){
    cin >> N;
    cin >> target;
    v.resize(N-1);

    for(int i = 0; i < N - 1; i++){
        cin >> v[i];
    }

    for(int i = 0; i < N - 1; i++){
        int g = gcd(target, v[i]);

        cout << target/g << "/" << v[i]/g << "\n"; 
    }

    return 0;
}
