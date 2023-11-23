#include<cstdio>
#include<vector>
using namespace std;
vector<int> v;  //(LIS의길이, 요소X)
int n, input, i;
int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &input);
        if (v.empty() || v.back() < input) //비워있거나 맨뒤값보다 작을때
            v.push_back(input);
        else {
            v[lower_bound(v.begin(), v.end(), input) - v.begin()] = input;  //input값과 같거나 큰 숫자가 나오는 처음 위치(인덱스)에
        }
    }
    printf("%d", n - v.size()); //가장 긴 증가하는 부분 수열을 빼줌
}