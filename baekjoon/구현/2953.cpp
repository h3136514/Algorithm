#include <iostream>
#include <queue>

using namespace std;
int num, sumN[5];
priority_queue<pair<int, int>> q;

// 나는 요리사다
int main() {
    for(int i = 0; i < 5; i++){
        int sum = 0;
        for(int j = 1; j < 5; j++){
            cin >> num;
            sum += num;
        }
    
        sumN[i] = sum;
    }

     for(int i = 0; i < 5; i++){
         q.push({sumN[i], i+1});
     }

    cout << q.top().second << " " << q.top().first << "\n";
    
    return 0;
}