// 그리디, 정렬
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, a, A, B;
vector<int> v;

// Potato
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    while(!v.empty()){
        A += v[v.size() - 1];
        v.pop_back();

        if(v.empty())
            break;
        
        B += v[0];
        v.erase(v.begin());
    }

    cout << B  << " " << A << "\n";

    return 0;
}