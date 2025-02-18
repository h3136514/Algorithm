// 브루트포스, 정렬
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> v;
priority_queue<int> q;
int sum, check[9];
bool rush;

// 일곱 난쟁이
int main(){
    v.resize(9);

    for(int i = 0; i < 9; i++){
        cin >> v[i];
        sum += v[i];
    }

    for(int i = 0; i < 8; i++){
        sum -= v[i];
        check[i] = 1;
        for(int j = i+1; j < 9; j++){
            sum -= v[j];
            check[j] = 1;
            if(sum == 100){
                rush = true;
                break;
            }
            sum += v[j];
            check[j] = 0;
        }

        if(rush)
            break;

        sum += v[i];
        check[i] = 0;
    }

    for(int i = 0; i < 9; i++){
        if(check[i])
            continue;
        
        q.push(-v[i]);
    }

    while(!q.empty()){
        cout << - q.top() << "\n";
        q.pop();
    }

    return 0;
}

