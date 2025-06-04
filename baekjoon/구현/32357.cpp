#include <iostream>
#include <string>

using namespace std;
int N, sum;
string s;

bool isPalindrome(string a){
    int startIdx = 0, endIdx = a.size()-1;

    while(startIdx < endIdx){
        if(a[startIdx] != a[endIdx])
            return false;
        
        startIdx++;
        endIdx--;
    }

    return true;
}

// 더블팰린드롬
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s;
        if(isPalindrome(s))
            sum++;
    }

    sum = (sum <= 1) ? 0 : sum * (sum-1);
    cout << sum << "\n";

    return 0;
}