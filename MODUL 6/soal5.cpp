#include "RedBlackTree.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void preorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& result) {
    if (node == nil) return;
    result.push_back(node->key);
    preorder(node->left, nil, result);
    preorder(node->right, nil, result);
}

void inorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& result) {
    if (node == nil) return;
    inorder(node->left, nil, result);
    result.push_back(node->key);
    inorder(node->right, nil, result);
}

void postorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& result) {
    if (node == nil) return;
    postorder(node->left, nil, result);
    postorder(node->right, nil, result);
    result.push_back(node->key);
}

void printTraversal(const string& label, const vector<int>& result) {
    cout << label << " : ";
    for (int i = 0; i < (int)result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    RedBlackTree rbt;

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        if (!rbt.contains(val)) {
            rbt.insert(val);
        }
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        string type;
        cin >> type;

        if (rbt.empty()) {
            cout << "Tree kosong. Tidak ada yang bisa ditampilkan." << endl;
            continue;
        }

        if (type == "PREORDER" || type == "ALL") {
            vector<int> result;
            preorder(rbt.root(), rbt.nil(), result);
            printTraversal("[Preorder] ", result);
        }
        if (type == "INORDER" || type == "ALL") {
            vector<int> result;
            inorder(rbt.root(), rbt.nil(), result);
            printTraversal("[Inorder]  ", result);
        }
        if (type == "POSTORDER" || type == "ALL") {
            vector<int> result;
            postorder(rbt.root(), rbt.nil(), result);
            printTraversal("[Postorder]", result);
        }
    }

    return 0;
}