// 자료구조, 큐
#include <iostream>
#include <queue>

using namespace std;
int N, num;
queue<int> q;

// 카드1
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        q.push(i);
    }

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
        if(!q.empty()){
            num = q.front();
            q.pop();
            q.push(num);
        }
    }

    return 0;
}