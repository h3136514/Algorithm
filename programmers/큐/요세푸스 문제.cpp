#include <string>
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int cnt;

// 1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다. (시간복잡도 : O(N*K))
void solution(int N, int K)
{
    //1부터 N까지의 번호를 큐에 추가
    for(int i=1; i<=N; i++)
        q.push(i);

    cout << "<";
    while(!q.empty()){
        //K번째 사람을 찾기 위해 K-1번째까지 제거하고 뒤에 추가
        for(int i=0; i < K-1; i++){
            int num  = q.front();
            q.push(num);
            q.pop();
        }

        //K번째 사람 출력
        if(q.size() > 1)
            cout << q.front() << ", ";
        else
             cout << q.front() << ">" << endl;
        
        //K번째 사람 제거
        q.pop();
    } 
}

int main()
{ 
    solution(7, 3); // <3, 6, 2, 7, 5, 1, 4>

    return 0;
}