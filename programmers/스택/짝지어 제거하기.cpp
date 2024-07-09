#include<string>
#include<stack>

using namespace std;

stack<char> alp;

// 문자열에서 같은 알파벳이 2개 붙어 있는 짝을 찾아 그 둘을 제거한 뒤, 반복해서 문자열을 모두 제거한다면 1, 아니며누 0을 반환 (시간복잡도 : O(N))
int solution(string s)
{   
    for(int i = 0; i < s.length(); i++) {
        if(alp.empty() || alp.top() != s[i])    //스택이 비었거나 현재문자와같은 문자가 아닌 경우 푸시 
            alp.push(s[i]);
        else     //현재문자와 스택의 최상위 문자가 같은 경우 팝
            alp.pop();  
    }

    // 현재 스택이 비었으면 문자열의 짝이 맞다는 의미이므로 true반환, 아니면 false 반환
    return alp.empty();
}

#include <iostream>

int main()
{
    cout << solution("baabaa") << endl; // 1
    cout << solution("cdcd") << endl;   // 0 
    return 0;
}