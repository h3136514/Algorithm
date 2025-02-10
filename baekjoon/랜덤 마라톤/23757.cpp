// 자료 구조, 우선순위 큐
#include <iostream>
#include <queue>

using namespace std;
int N, M, num;
bool check = true;
priority_queue<int> gift;
queue<int> child;

// 아이들과 선물 상자
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> num;
        gift.push(num);
    }

    for(int i = 0; i < M; i++){
        cin >> num;
        child.push(num);
    }

    while(!child.empty()){
        int a = child.front();
        child.pop();
        int b = gift.top();
        gift.pop();

        if(a > b){
            check = false;
            break;
        }

        gift.push(b-a);
    }

    if(check)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}