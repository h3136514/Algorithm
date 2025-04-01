// 그리디, 정렬
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, num, result;
vector<int> v;

// Young한 에너지는 부족하다
int main(){
    cin >> N;
    for(int i = 0; i < N*3; i++){
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    result = v[N*2-1] - v[N];

    cout << result << "\n";

    return 0;
}