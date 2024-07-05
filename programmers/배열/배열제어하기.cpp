#include<vector>
#include<algorithm> 
#include<iostream>

using namespace std;

// 정렬 기준 정의
bool compare(int a, int b) {
    return a > b;
}

// 배열 제어하기(배열 중복 값 제거 및 내림차순 정렬, 시간복잡도 : O(NlogN))
vector<int> solution(vector<int> arr) {
    // 내림차순 정렬
    sort(arr.begin(), arr.end(), compare); // sort(arr.rbegin(), arr.rend());
    // 중복값 제거
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}

int main() {
    vector<int> arr = solution({4, 2, 2, 1, 3, 4});
    for(int i =0; i < arr.size(); i++){
        cout << arr[i] << endl;
    }
    return 0;
}