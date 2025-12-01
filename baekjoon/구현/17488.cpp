#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;
int N, M, num;
vector<int> v[1001];
priority_queue<int> student[1001];
map<int, int> m;

// 수강 바구니
int main(){
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> num;
        m[i] = num;
    }
    for(int i = 1; i <= N; i++){
        while(true){
            cin >> num;
            if(num == -1)
                break;
            
            v[num].push_back(i);
        }
    }

    for(int i = 1; i <= M; i++){
        if(m[i] >= v[i].size()){
            m[i] -= v[i].size();
            for(int j = 0; j < v[i].size(); j++){
                student[v[i][j]].push(-i);
            }

            v[i].clear();
        }
    }
    for(int i = 1; i <= N; i++){
        while(true){
            cin >> num;
            if(num == -1)
                break;
            
            v[num].push_back(i);
        }
    }

    for(int i = 1; i <= M; i++){
        if(m[i] >= v[i].size()){
            m[i] -= v[i].size();
            for(int j = 0; j < v[i].size(); j++){
                student[v[i][j]].push(-i);
            }
            v[i].clear();
        }
    }

    for(int i = 1; i <= N; i++){
        if(student[i].empty()){
            cout <<"망했어요\n";
        }else{
            while(!student[i].empty()){
                cout << -student[i].top() << " ";
                student[i].pop();
            }
            cout << "\n";
        }
    }

    return 0;
}