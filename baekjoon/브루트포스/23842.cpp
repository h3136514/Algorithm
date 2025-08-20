#include <iostream>
#include <string>

using namespace std;
int N, num[10];
string result = "impossible";

void backtrack(string a, string b, string c, int cnt){
    if(cnt == 6){
        if(stoi(a) + stoi(b) != stoi(c))
            return;

        int sum = 4;
        for(int i = 0; i < 2; i++){
            sum += num[a[i] - '0'];
            sum += num[b[i] - '0'];
            sum += num[c[i] - '0'];
        }

        if(sum == N){
            result = a + "+" + b + "=" + c;
        }
        return;
    }

    for(int i = 0; i < 10; i++){
        char ch = i + '0';
        if(cnt < 2){
            backtrack(a+ch, b, c, cnt+1);
        }else if(cnt < 4){
            backtrack(a, b+ch, c, cnt+1);
        }else{
            backtrack(a, b, c+ch, cnt+1);
        }
    }
}

// 성냥개비
int main(){
    cin >> N;
    num[0] = 6, num[1] = 2, num[2] = 5, num[3] = 5, num[4] = 4, num[5] = 5, num[6] = 6, num[7] = 3, num[8] = 7, num[9] = 6;

    backtrack("", "", "", 0);

    cout << result << "\n";

    return 0;
}