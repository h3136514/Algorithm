// 정렬
#include<iostream>
#include<queue>

using namespace std;
int N, num, visitied[2002];
priority_queue<int> q;

// 중복 빼고 정렬하기
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        num += 1000;
        if(!visitied[num]){
            visitied[num] = 1;
            q.push(-num);
        }
    }

    while(!q.empty()){
        cout << -q.top() - 1000 << " ";
        q.pop();
    }
    cout << "\n";

    return 0;
}