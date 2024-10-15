#include <string>
#include <vector>

using namespace std;
int N, CNT, targetNum;
vector<int> v;

// 백트래킹
void dfs(int cnt, int sum){
    if(cnt == N){
        if(sum == targetNum)
            CNT++;
        
        return;
    }
    
    // 뺀 경우
    int num = sum - v[cnt];
    dfs(cnt+1, num);
    
    // 더한 경우
    num = sum + v[cnt];
    dfs(cnt+1, num);
}

// 사용할 수 있는 숫자가 담긴 배열, 타겟 넘버가 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 반환
int solution(vector<int> numbers, int target) {
    N = numbers.size();
    targetNum = target;
    v = numbers;
    
    dfs(0, 0);
    
    return CNT;
}