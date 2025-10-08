#include <string>
#include <vector>

using namespace std;
int answer = 0;

// 최소 공약수
int gcd(int a, int b){
    if(!b)
        return a;
    return gcd(b, a%b);
}

int solution(vector<int> arr) {
    answer = arr[0];
    
    for(int i = 1; i < arr.size(); i++){
        answer = (answer * arr[i])/gcd(answer, arr[i]); // 최소 공배수
    }
    
    return answer;
}