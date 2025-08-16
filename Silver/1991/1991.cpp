#include<iostream>
#include<vector>
using namespace std;

// 트리의 각 노드를 표현하는 구조체
// id : 노드의 이름, left/right : 왼쪽/오른쪽 자식 포인터
struct Node {
    char id;
    Node* left;
    Node* right;
    Node(char id) :id(id), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    vector<Node*> tree; // 모든 노드 포인터를 저장하는 배열 (A~Z 순)
    Node* root;         // 루트 노드(A)
public:
    // capacity 개수만큼 노드 생성 (문자 A, B, C...)
    Tree(int capacity) {
        for (int i = 0; i < capacity; ++i) {
            tree.push_back(new Node(i + 'A'));
        }
        root = tree[0]; // 루트는 항상 'A'
    }

    // 루트 노드 반환
    Node* Root() {
        return root;
    }

    // 노드 연결 (자식이 '.'이면 nullptr 유지)
    void Add(char node, char left, char right) {
        if (left != '.') {
            tree[node - 'A']->left = tree[left - 'A'];
        }
        if (right != '.') {
            tree[node - 'A']->right = tree[right - 'A'];
        }
    }

    // 중위 순회
    void inorderTraversal(Node* node) {
        if (node->left) inorderTraversal(node->left);
        cout << node->id;
        if (node->right) inorderTraversal(node->right);
    }

    // 전위 순회
    void preorderTraversal(Node* node) {
        cout << node->id;
        if (node->left) preorderTraversal(node->left);
        if (node->right) preorderTraversal(node->right);
    }

    // 후위 순회
    void postorderTraversal(Node* node) {
        if (node->left) postorderTraversal(node->left);
        if (node->right) postorderTraversal(node->right);
        cout << node->id;
    }
};

int main() {
    int N; cin >> N;
    Tree tree(N);

    // N개의 노드 정보 입력 및 연결
    // 부모, 왼쪽 자식, 오른쪽 자식 (자식 없으면 '.')
    for (int i = 0; i < N; ++i) {
        char c1, c2, c3;
        cin >> c1 >> c2 >> c3;
        tree.Add(c1, c2, c3);
    }

    // 전위, 중위, 후위 순회 결과 출력
    tree.preorderTraversal(tree.Root());
    cout << '\n';
    tree.inorderTraversal(tree.Root());
    cout << '\n';
    tree.postorderTraversal(tree.Root());
}