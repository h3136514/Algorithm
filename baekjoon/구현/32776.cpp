#include <iostream>
using namespace std;

// 가희와 4시간의 벽 2
int main() {
    int S, Ma, Fab, Mb;
    cin >> S >> Ma >> Fab >> Mb;
    
    int flight_time = Ma + Fab + Mb;
    
    // 조건1: 항공편이 고속철도보다 같거나 더 오래 걸림
    bool cond1 = flight_time >= S;
    // 조건2: 철도를 좋아하고 고속철도 시간이 4시간(240분) 이하
    bool cond2 = S <= 240;
    
    bool use_rail;
    if (cond2) {
        use_rail = true;
    } else {
        use_rail = cond1;
    }
    
    cout << (use_rail ? "high speed rail" : "flight") << endl;
    return 0;
}