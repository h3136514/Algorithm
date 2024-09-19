#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {

    // N*N 2차원 벡터를 선언하고 초깃값을 0으로 함
    vector<vector<int>> arr(n, vector<int>(n, 0));
    // 행과 열의 시작과 끝 인덱스를 설정
    int start_row = 0, end_row = n - 1;
    int start_col = 0, end_col = n - 1;
    int num = 1;

    // 달팽이 수열 채움
    while((start_row <= end_row) && (start_col <=end_col)) {
        
        // 왼쪽 -> 오른쪽
        for(int i = start_col; i <= end_col; i++)
            arr[start_row][i] = num++;
        start_row++;

        //위 -> 아래
        for(int i = start_row; i <= end_row; i++)
            arr[i][end_col] = num++;
        end_col--;

        if(start_row <= end_row) {
            // 오른쪽 -> 왼쪽
            for(int i = end_col; i >= start_col; i--)
                arr[end_row][i] = num++;
            end_row--;
        }

        if(start_col <= end_col) {
            // 아래 -> 위
            for(int i = end_row; i >= start_row; i--) 
                arr[i][start_col] = num++;
            start_col++;
        }

    }

    return arr;
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
    print(solution(3));
    /*
    출력값 :
    1 2 3 
    8 9 4 
    7 6 5
    */
                    
    print(solution(4));
    /*
    출력값: 
    1 2 3 4 
    12 13 14 5 
    11 16 15 6 
    10 9 8 7
    */
  return 0;
}