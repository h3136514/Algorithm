#include <string>
#include <vector>

using namespace std;

// 전위 순회
string preorder(vector<int> nodes, int idx) {
    if(idx < nodes.size()) {
        string ret = to_string(nodes[idx]) + " "; // 부모 노드
        ret += preorder(nodes, idx*2 + 1);  // 왼쪽 자식
        ret += preorder(nodes, idx*2 + 2);  // 오른쪽 자식
        return ret;
    }
    
    return "";
}

// 중위 순회
string inorder(vector<int> nodes, int idx) {
    if(idx < nodes.size()) {
        string ret = inorder(nodes, idx*2 + 1); // 왼쪽 자식
        ret += to_string(nodes[idx]) + " ";  // 부모 노드
        ret += inorder(nodes, idx*2 + 2); // 오른쪽 자식
        return ret;
    }

    return "";
}

// 후위 순회
string postorder(vector<int> nodes, int idx) {
    if(idx < nodes.size()) {
        string ret = postorder(nodes, idx*2 + 1); // 왼쪽 자식
        ret += postorder(nodes, idx*2 + 2); // 오른쪽 자식
        ret += to_string(nodes[idx]) + " ";  // 부모 노드
        return ret;
    }

    return "";
}

// 전위 순회, 중위 순회, 후위 순회 결과를 각각 계산하고 이를 반환 (시간복잡도 : O(N))
vector<string> solution(vector<int> nodes) {
    vector<string> result;
    // 순회를 실시
    string pre = preorder(nodes, 0);
    string in = inorder(nodes, 0);
    string post = postorder(nodes, 0);

    // 마지막에 생긴 공백을 제거
    pre.pop_back();
    in.pop_back();
    post.pop_back();

    // 결과를 result에 추가
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);

    return result;
}



#include <iostream>

void print(vector<string> vec)
{
    for(int i =0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
}

int main()
{
    print(solution({1, 2, 3, 4, 5, 6, 7})); 
    /** 
     출력값 
     1 2 4 5 3 6 7
     4 2 5 1 6 3 7
     4 5 2 6 7 3 1
    **/
    
    return 0;
}