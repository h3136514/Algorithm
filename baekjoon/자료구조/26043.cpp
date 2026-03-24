// 큐
#include <iostream>
#include <queue>

using namespace std;
int N, s, a, b;
queue<pair<int, int>> q;
priority_queue<int> A, B, C;

//식당 메뉴
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    while(N--){
        cin >> s;
        if(s == 1){
            cin >> a >> b;
            q.push({a, b});
        }else{
            cin >> b;
            if(q.front().second == b){
                A.push(-q.front().first);
            }else{
                B.push(-q.front().first);
            }
            q.pop();
        }
    }
    while(!q.empty()){
        C.push(-q.front().first);
        q.pop();
    }

    if(A.empty())
        cout << "None\n";
    else{
        while(!A.empty()){
            cout << -A.top();
            A.pop();
            if(!A.empty())
                cout << " ";
        }
        cout << "\n";
    }
    if(B.empty())
        cout << "None\n";
    else{
        while(!B.empty()){
            cout << -B.top();
            B.pop();
            if(!B.empty())
                cout << " ";
        }
        cout << "\n";
    }
    if(C.empty())
        cout << "None\n";
    else{
        while(!C.empty()){
            cout << -C.top();
            C.pop();
            if(!C.empty())
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}