#include <vector>
using namespace std;

// 노드를 정의
class Node {
public:
    int val;
    Node *left, *right;
    
    Node(int key) : val(key), left(nullptr), right(nullptr) {}
};

// 이진 탐색 트리 정의
class BST { 
private:
    Node* root;

    Node* insertNode(Node* node, int key) {
        // 트리가 없을 경우
        if(!node) {
            return new Node(key);
        }
        //키 값과 현재 노드의 값을 비교해서 이진탐색트리 규칙에 맞는 위치로 이동
        if (key < node->val) { 
            node->left = insertNode(node->left, key);   // 왼쪽 서브트리에 삽입(현재의 값 보다 작으므로)
        } else {
            node->right = insertNode(node->right, key); // 오른쪽 서브트리에 삽입(현재의 값 보다 크거나 같으므로)
        }

        return node;
    }

    bool searchNode(Node* node, int key) {
        // 찾는 키 값이 없는 경우
        if(!node) {
            return false;
        }
        // 이진탐색트리에서 키 값을 찾은 경우
        if(key == node->val) {
            return true;
        }
        // 아직 값을 찾지 못한 경우, 현재 노드값과 key 값을 비교해서, 어느 노드에서 탐색할지 결정
        return key < node->val ?
                searchNode(node->left, key):
                searchNode(node->right, key);
    }
    public:
        BST() : root(nullptr) {}

        void insert(int key) {
            root = insertNode(root, key);
        }

        bool search(int key) {
            return searchNode(root, key);
        }
};

// 이진 탐색 트리를 생성하고 각 원소가 이진 탐색 트리에 존재하는지(탐색) 반환 (시간복잡도 : O(N^2))
vector<bool> solution(vector<int> lst, vector<int> search_lst) {
  BST bst;
  // 이진 탐색 트리에 노드 삽입
  for (int key : lst) {
    bst.insert(key);
  }

  vector<bool> result;
  // 이진 탐색 트리에서 찾는 값이 있는지 확인하고 탐색결과를 result에 추가
  for (int search_val : search_lst) {
    result.push_back(bst.search(search_val));
  }

  return result;
}


#include <iostream>
void print(vector<bool> vec)
{
    cout << vec[0];
    for(int i =1; i < vec.size(); i++){
        cout << " " << vec[i];
    }
    cout << endl;
}

int main()
{
    // bool을 출력할 때 true는 1 false는 0 입니다.
    print(solution({5, 3, 8, 4, 2, 1, 7, 10}, {1, 2, 5, 6})); //출력값 : 1 1 1 0
    print(solution({1, 3, 5, 7, 9}, {2, 4, 6, 8, 10})); //출력값 : 0 0 0 0 0    
    return 0;
}
