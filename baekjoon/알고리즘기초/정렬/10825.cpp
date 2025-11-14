#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N, A, B, C;
string name;
vector<pair<pair<int, int>, pair<int, string>>> v;

// 국영수
int main() {
    cin >> N ;
    for (int i = 1; i <= N; i++) {
        cin >> name >> A >> B >> C;
        v.push_back({ {-A, B},{-C, name} });
    }
  
    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        cout << v[i].second.second << "\n";
    }
   

    return 0;
}