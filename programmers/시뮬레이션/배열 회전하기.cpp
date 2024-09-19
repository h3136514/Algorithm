#include <vector>

using namespace std;
vector<vector<int>> result;
int N;

vector<vector<int>> solution(vector<vector<int>> arr, int n) {
    N = arr.size();
    result.resize(N, vector<int>(N, 0));    // 크기가 같은 2차원 백터 재활당(초깃값은 0)
    
    // 2차원 벡터를 90도로 n번 회전
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                result[j][N - i - 1] = arr[i][j];
        
        arr = result;
    }

    return result;
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
  print(solution({
                   {1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}
                 }, 1));
  /*
    출력값
    13 9 5 1 
    14 10 6 2 
    15 11 7 3 
    16 12 8 4 
  */
  
  print(solution({
                   {1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}
                 }, 3));
  /*
    출력값
    4 8 12 16 
    3 7 11 15 
    2 6 10 14 
    1 5 9 13 
  */
             
  return 0;
}