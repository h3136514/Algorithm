#include <vector>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;
stack<int> st;
queue<int> q;

// 배열 arr에서 연속적으로 나타나는 숫자는 하나만 남기고 전부 제거함
vector<int> solution(vector<int> arr) 
{   
    for(int num : arr){
        if(st.empty() || st.top() != num){
            st.push(num);
            q.push(num);
        }
        else{
            continue;
        }
    }
    vector<int> answer;
    while(!q.empty()){
        answer.push_back(q.front());
        q.pop();
    }


    return answer;
}

// unique()함수로 간단하게
/*
#include <algorithm>

vector<int> solution(vector<int> arr) 
{

    arr.erase(unique(arr.begin(), arr.end()),arr.end());

    vector<int> answer = arr;
    return answer;
}
*/