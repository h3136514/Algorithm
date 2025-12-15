//https://www.acmicpc.net/problem/3986
// 스택
#include <iostream>
#include <stack>
#include <string>

using namespace std;
int N, CNT;
string word;
stack<char> s;

// 좋은 단어
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> word;

        for(int j = 0; j < word.size(); j++){
            if(s.empty() || s.top() != word[j]){
                s.push(word[j]);
                continue;
            }

            s.pop();
        }

        if(s.empty())
            CNT++;

        while(!s.empty())
            s.pop();
    }

    cout << CNT << "\n";

    return 0;
}