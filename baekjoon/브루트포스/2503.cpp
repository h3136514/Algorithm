#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N, S, B, CNT, visitied[10];
string num;
vector<pair<string, pair<int, int>>> nums;

// 모든 질문 체크(스트라이크, 볼)
bool check(string str){
    for(int i = 0; i < nums.size(); i++){
        int s = 0, b = 0;
        num = nums[i].first;
        for(int j = 0; j < 3; j++){
           for(int k = 0; k < 3; k++){
                if(str[j] == num[k] && j == k)
                    s++;
                else if(str[j] == num[k])
                    b++;
            } 
        }
        if(s != nums[i].second.first || b != nums[i].second.second){
            return false;
        }
    }

    return true;
}

// 백트래킹(모든 숫자야구 경우)
void dfs(int cnt, string s){
    if(cnt == 3){
        if(check(s))
            CNT++;
        
        return;
    }

    for(int i = 1; i < 10; i++){
        if(!visitied[i]){
            visitied[i] = 1;
            s += i + '0';
            dfs(cnt+1, s);
            visitied[i] = 0;
            s.erase(s.size()-1, 1);
        }
    }

}

// 숫자 야구
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num >> S >> B;
        nums.push_back({num, {S, B}});
    }

    dfs(0, "");

    cout << CNT << "\n";

    return 0;
}
