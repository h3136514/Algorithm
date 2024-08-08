// A번을 가진 참가자는 경쟁자로 생각하는 B번 참가자와 몇 번째 라운드에서 만나는지 반환(단, 서로 붙게 되기 전까지 항상 이긴다고 가정)(시간복잡도 : O(logN))
int solution(int n, int a, int b)
{
    int answer = 0;
    while( a != b){
        answer++;
        a = (a + 1)/2;
        b = (b + 1)/2;
    }

    return answer;
}

#include <iostream>

using namespace std;

int main()
{
    cout << solution(8, 4, 7) << endl; //출력값 : 3
    return 0;
}