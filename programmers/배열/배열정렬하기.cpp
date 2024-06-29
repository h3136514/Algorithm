#include<vector>
#include<algorithm> //sort사용을 위해
#include<iostream>

using namespace std;

// 배열 정렬하기(시간복잡도 : O(NlogN))
vector<int> solution(vector<int> arr) {
    sort(arr.begin(), arr.end());
    return arr;
}

int main() {
    vector<int> arr = solution({1, -6, 2, 4, 3});
    for(int i =0; i < arr.size(); i++){
        cout << arr[i] << endl;
    }
    return 0;
}