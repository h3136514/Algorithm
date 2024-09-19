#include <vector>
using namespace std;

// 두 행렬 곱하기
vector<vector<int>> multiply(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
    // 결과값을 저장할 벡터를  0으로 초기화
    vector<vector<int>> result(3, vector<int>(3, 0));

    // 행렬 곱셈을 수행합니다.
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

// 전치 행렬 만들기
vector<vector<int>> transpose(vector<vector<int>> matrix) {
    // 결과값을 저장할 벡터를  0으로 초기화
    vector<vector<int>> result(3, vector<int>(3, 0));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result[i][j] = matrix[j][i];
        }
    }

    return result;
}

vector<vector<int>> solution(vector<vector<int>> matrix1, vector<vector<int>>matrix2) {
    // 주어진 두 행렬을 곱합니다.
    vector<vector<int>> multiplied = multiply(matrix1, matrix2);

    // 곱셈 결과의 전치 행렬을 계산합니다.
    vector<vector<int>> transposed = transpose(multiplied);
    return transposed;
}




#include <iostream>


void print(vector<vector<int>> vec)
{
    for(vector<int> v : vec){
        for(int num : v)
            cout << num << " ";
        cout << "\n";
    }
}


int main()
{
    print(solution( {
                     {1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9},
                    },
                    {
                     {9, 8, 7},
                     {6, 5, 4},
                     {3, 2, 1},
                    }
                    ));
    /*
    출력값 :
    30 84 138 
    24 69 114 
    18 54 90 
    */
                    
    print(solution( {
                     {2, 4 ,6},
                     {1, 3, 5},
                     {7, 8, 9},
                    },
                    {
                     {9, 1, 2},
                     {4, 5, 6},
                     {7, 3, 8},
                    }
                    ));
    /*
    출력값: 
    76 56 158 
    40 31 74 
    76 60 134 
    */
  return 0;
}