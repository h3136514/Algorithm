//덱
#include <iostream>
#include <deque>

using namespace std;
int N;
deque<int> q;

// 카드
int main(){
    cin >> N;
    q.push_front(N);
    for(int i = N-1; i > 0; i--){
        q.push_front(i);

        for(int j = 0; j < i; j++){
            q.push_front(q.back());
            q.pop_back();
        }

    }

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop_front();
    }

    return 0;
}