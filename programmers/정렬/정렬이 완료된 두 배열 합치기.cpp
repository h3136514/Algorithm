#include <vector>

using namespace std;

vector<int> solution(vector<int> arr1, vector<int> arr2) {
    int i = 0, j =0;
    vector<int> v;

    // 두 배열을 순회하면서 정렬된 배열을 생성
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] <= arr2[j]) {
            v.push_back(arr1[i]);
            i++;
        }else {
            v.push_back(arr2[j]);
            j++;
        }
    }

    // 남아있는 원소들을 정렬된 배열 뒤에 추가
    while(i < arr1.size())
        v.push_back(arr1[i++]);

    while(j < arr2.size())
        v.push_back(arr2[j++]);

    return v;
}


#include <iostream>

using namespace std;

void print(vector<int> vec)
{
 for(int i = 0; i < vec.size(); i++)
    cout << vec[i] << " ";
  cout << "\n";
}

int main()
{
  print(solution({1, 3, 5}, {2, 4, 6})); // 출력값 : 1 2 3 4 5 6
  print(solution({1, 2, 3}, {4, 5, 6})); // 출력값 : 1 2 3 4 5 6
  
  return 0;
}