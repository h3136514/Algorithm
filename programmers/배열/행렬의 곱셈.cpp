#include <string>
#include <vector>

using namespace std;

int sum = 0;

// 2차원 행렬 arr1과 arr2를 입력받아, arr1에 arr2를 곱한 결과를 반환(시간복잡도 : O(N^3))
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    //arr1과 arr2의 행렬곱을 수행했을때 최종적인 행렬의 크기만큼 공간을 미리 할당(특정 위치에 결과값을 저장할려면 미리 필요한 공간을 할당해야 됨)
    answer.assign(arr1.size(), vector<int>(arr2[0].size(), 0));

    for(int i = 0; i < arr1.size(); i++) {
        for(int j = 0; j < arr2[0].size(); j++) {
            sum = 0;
            for(int k =0; k < arr1[i].size();  k++) {
                // 두 행렬을 곱을 수행
                sum += arr1[i][k] * arr2[k][j];    
            }
            answer[i][j] = sum;
        }
    }
    return answer;
}