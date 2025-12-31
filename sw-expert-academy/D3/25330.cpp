#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkCondition(const string& s) {
    int n = s.length();
    vector<int> count(10, 0);
    vector<vector<int>> positions(10);
    
    // 각 숫자의 등장 횟수와 위치 저장
    for (int i = 0; i < n; i++) {
        int digit = s[i] - '0';
        count[digit]++;
        positions[digit].push_back(i);
    }
    
    // 조건 1: 각 숫자는 0번 또는 정확히 2번 등장해야 함
    for (int d = 0; d < 10; d++) {
        if (count[d] != 0 && count[d] != 2) {
            return false;
        }
    }
    
    // 조건 2: 숫자 d가 2번 등장하면, 두 숫자 사이에 d개의 숫자가 있어야 함
    for (int d = 0; d < 10; d++) {
        if (count[d] == 2) {
            int pos1 = positions[d][0];
            int pos2 = positions[d][1];
            int between = pos2 - pos1 - 1; // 두 위치 사이의 숫자 개수
            
            if (between != d) {
                return false;
            }
        }
    }
    
    return true;
}

// 거리 문자열
int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string s;
        cin >> s;
        
        if (checkCondition(s)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    return 0;
}