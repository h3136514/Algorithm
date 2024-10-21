#include <string>
#include <vector>
#include <cmath>

using namespace std;
int CNT, visitied[8];
bool num[10000000];
string target;

// 에라토스테네스의 체 (소수 판별)
void primNumber(int N){
    num[0] = true;
    num[1] = true;
    for(int i = 2; i <= sqrt(N); i++){
        if(num[i])
            continue;
        for(int j = i+i; j <= N; j += i){
            if(num[j])
                continue;
            num[j] = true;
        }
    }
}

// 백트래킹 (자리수별 숫자 조합)
void dfs(string str, int cnt){
    if(cnt == str.size()){
        int number = stoi(str);
        if(!num[number]){
            CNT++;
            num[number] = true;     // 소수는 아니지만 이미 추가한걸 표시하기위해
        }
        
        return;
    }
    
    for(int i = 0; i < target.size(); i++){
        if(visitied[i])
            continue;
        
        str += target[i];
        visitied[i]= 1;
        dfs(str, cnt);
        //원상복귀
        visitied[i]= 0;
        str.pop_back();
    }
}

int solution(string numbers) {
    target = numbers;
    primNumber(9999999);    // 최대 숫자까지 
    
    for(int i = 1; i <= target.size(); i++){
        dfs("", i);
    }
    
    return CNT;
}