#include<vector>
using namespace std;


//  (시간복잡도 : O(N))
bool solution(vector<int> arr, int target)
{   
    //target+1개의 공간이 있는 hash벡터 선언
    vector<int> hash(target + 1, 0);
    //arr의 원소들 값에 대해서 hash table 생성
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > target) //target보다 큰 값은 담지 않음(답이 될 가능성이 없음)  
            continue;
        hash[arr[i]] = 1;
    }

    for(int i = 0; i < arr.size(); i++){
        //target에서 arr[i]를 뺀 값이 있는지 확인하기 위해 num 선언 
        int num = target - arr[i];

        if(arr[i] == num)   //중복되는 숫자가 없다.(특정값이 현재 숫자가 같은 경우)
            continue;
        if(num < 0)     //음수는 존재할 수 없으므로 답이 될 수 없다. 
            continue;
        if(hash[num])   //값을 찾은 경우(합이 target이 되는 변수를 찾음)
            return true;
    }
    // 두 수의 합이 target이 되는 경우를 찾지 못해서 false 반환 
    return false;
    
}

#include <iostream>
int main()
{
    //true를 출력하면 1 이고, false를 출력하면 0
    cout<< solution({1, 2, 3, 4, 8}, 6) << endl; // 1
    cout<< solution({2, 3, 5,9}, 10) << endl; // 0

    return 0;
}