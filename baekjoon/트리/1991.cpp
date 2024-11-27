#include <iostream>

using namespace std;
int N, node[26][2];
char a, b, c;

// 전위 순회
void preorder(int idx) {
	cout << char(idx + 65);

	if (node[idx][0] != 0)
		preorder(node[idx][0]);

	if (node[idx][1] != 0)
		preorder(node[idx][1]);
}

// 중위 순회
void inorder(int idx) {

	if (node[idx][0] != 0)
		inorder(node[idx][0]);
	
	cout << char(idx + 65);

	if (node[idx][1] != 0)
		inorder(node[idx][1]);
}

// 후위 순회
void postorder(int idx) {

	if (node[idx][0] != 0)
		postorder(node[idx][0]);

	if (node[idx][1] != 0)
		postorder(node[idx][1]);

	cout << char(idx + 65);
}

// 트리 순회
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		int rootNode = int(a) - 65;
		if (b != '.') {
			int leftNode = int(b) - 65;
			node[rootNode][0] = leftNode;
		}
		if (c != '.') {
			int rightNode = int(c) - 65;
			node[rootNode][1] = rightNode;
		}
	}

	preorder(0);
	cout << "\n";

	inorder(0);
	cout << "\n";
	
	postorder(0);
	cout << "\n";

	return 0;
}