#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

// 다항 해시 함수 구현
long long polynomial_hash(string str){
    const int p = 31; //메르센 소수
    const long long m = 1000000007;  // 버킷 크기
    long long hash_value = 0;

    for(char c : str) {
        hash_value = (hash_value * p + c) % m;
    }

    return hash_value;
}

// 각 쿼리 배열에(query_list) 있는 문자열이 문자열 배열에(string_list) 있는지 존재여부 반환 (string_list의 길이: N, query_list의 길이: K, 시간복잡도 : O(N + K))
vector<bool> solution(vector<string> string_list, vector<string> query_list) 
{   
    unordered_set<long long> hash_set;

    //string_list의 각 문자열에 대해 다항 해시값을 계산하고 저장
    for(string str : string_list){
        long long hash = polynomial_hash(str);
        hash_set.insert(hash);
    }

    // query_list의 문자열이 hash에 있는지 결과를 result에 저장
    vector<bool> result;

    //query_list의 각 문자열이 string_list에 있는지 확인하고 result에 추가
    for(string query : query_list){
        long long query_hash = polynomial_hash(query);
        bool found = false;
        //문자열이 존재
        if(hash_set.find(query_hash) != hash_set.end())
            found = true;
        result.push_back(found);
    }
    
    return result;
}

#include <iostream>
int main()
{
    //true를 출력하면 1 이고, false를 출력하면 0
    vector<bool> arr = solution({"apple", "banana", "cherry"}, {"banana", "kiwi", "melon", "apple"}); // 1 0 0 1
    for(int i =0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}