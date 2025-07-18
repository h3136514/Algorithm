#include <iostream>
#include <stack>

using namespace std;
int N, P, n, p, sum;
stack<int> s[8];

//외계인의 기타 연주
int main() {
    cin >> N >> P;
    for (int i = 0; i < N; i++) {
        cin >> n >> p;
        if (s[n].empty()) {
            s[n].push(p);
            sum++;
        }
        else {
            if (s[n].top() > p) {
                while (s[n].top() > p) {
                    s[n].pop();
                    sum++;

                    if (s[n].empty()) {
                        s[n].push(p);
                        sum++;
                        break;
                    }
                }

                if (s[n].top() < p) {
                    s[n].push(p);
                    sum++;
                }
            }
            else if (s[n].top() < p) {
                s[n].push(p);
                sum++;
            }
        }
    }
    
    cout << sum << "\n";

    return 0;
}