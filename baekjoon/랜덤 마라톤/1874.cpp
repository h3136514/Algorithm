// 자료구조, 스택
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int N, currentNum = 1, num[100001];
bool check;
vector<char> v;
stack<int> s;

// 스택 수열
int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num[i];
    }

    for(int i = 0; i < N; i++){

        if(!s.empty() && (s.top() == num[i])){
            v.push_back('-');
            s.pop();
            continue;
        }

        if(currentNum <= num[i]){
            for(int j = currentNum; j <= num[i]; j++){
                v.push_back('+');
                s.push(j);                
            }
            v.push_back('-');
            s.pop();
            currentNum = num[i] + 1;

            continue;
        }

        check = true;
        break;
    }

    if(check)
        cout << "NO\n";
    else{
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << "\n";
    }

    return 0;
}