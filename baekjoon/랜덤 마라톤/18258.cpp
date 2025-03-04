// 자료구조, 큐
#include <iostream>
#include <deque>
#include <string>

using namespace std;
int N, X, result;
string s;
deque<int> q;

// 큐 2
int main(){
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(0); // cin과 cout의 tie를 해제하여 성능 향상


    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s;
        if(s == "push"){
            cin >> X;
            q.push_back(X);
        }else{
            if(s == "pop"){
                if(q.empty())
                    result = -1;
                else{
                    result = q.front();
                    q.pop_front();
                }
            }else if(s == "size")
                result = q.size();
            else if(s == "empty"){
                if(q.empty())
                    result = 1;
                else
                    result = 0;
            }else if(s == "front"){
                if(q.empty())
                    result = -1;
                else
                    result = q.front();
            }else{
                if(q.empty())
                    result = -1;
                else
                    result = q.back();
            }

            cout << result << "\n";
        }
    }

    return 0;
}