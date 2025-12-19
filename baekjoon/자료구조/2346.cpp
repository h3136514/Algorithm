// 덱
#include <iostream>
#include <vector>
#include <deque>

using namespace std;
int N, num, mov;
vector<int> v;
deque<pair<int, int>> dq, tmp;

// 풍선 터뜨리기 
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> mov;
        dq.push_back({i, mov});
    }

    while(!dq.empty()){
        num = dq.front().first;
        mov = dq.front().second;
        dq.pop_front();
        v.push_back(num);

        if(dq.empty())
            break;

        if(mov > 0){
            for(int i = 0; i < mov-1; i++){
                dq.push_back(dq.front());
				dq.pop_front();
            }
        }else{
            for(int i = 0; i < mov*(-1); i++){
                dq.push_front(dq.back());
				dq.pop_back();
            }
        }
    }

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";

    return 0;
}