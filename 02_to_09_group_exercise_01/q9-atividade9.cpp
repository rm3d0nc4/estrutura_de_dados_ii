#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

bool is_complete_tree(Node* root) {
    if (root == nullptr) {
        return true;
    }
    
    queue<Node*> q;
    q.push(root);
    bool flag = false;
    
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        if (curr->left) {
            if (flag) {
                return false;
            }
            q.push(curr->left);
        } else {
            flag = true;
        }
        
        if (curr->right) {
            if (flag) {
                return false;
            }
            q.push(curr->right);
        } else {
            flag = true;
        }
    }
    
    return true;
}

int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    if (is_complete_tree(root1))
        cout << "A arvore 1 e completa" << endl;
    else
        cout << "A arvore 1 nao e completa" << endl;

    // Árvore completa e não cheia
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);

    // Verifica se a segunda árvore é completa
    if (is_complete_tree(root2))
        cout << "A arvore 2 e completa" << endl;
    else
        cout << "A arvore 2 nao e completa" << endl;
        
    // Árvore completa e não cheia
    Node* root3 = new Node(1);
    root3->left = new Node(2);
    root3->right = new Node(3);
    root3->left->left = new Node(4);
    root3->left->right = new Node(5);
    root3->left->right->left = new Node(6);

    // Verifica se a terceira árvore é completa
    if (is_complete_tree(root3))
        cout << "A arvore 3 e completa" << endl;
    else
        cout << "A arvore 3 nao e completa" << endl;

    return 0;
}