#include <iostream>
#include <string>
#include <queue>

using namespace std;
string N, result;
bool isZero;
long long sum;  // 최대 10^5개의 숫자로 구성되어 있으므로 long long으로 해야한다.
priority_queue<char> q;

// 30
int main(){
    cin >> N;
    for(int i = 0; i < N.size(); i++)
        q.push(N[i]);
    
    while (!q.empty()){
        result += q.top();
        sum += q.top() -'0';
        if(q.top() == '0')
            isZero = true;

        q.pop();
    }

    // 0이 있고(마지막 숫자) 각 자리의 수의 합이 3의 배수이면 30의 배수이다. 
    if(isZero && sum % 3 == 0)
        cout << result << "\n";
    else
        cout << "-1\n";

    return 0;
}