
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr) {
        cout << root->ch << " : "
             << (code.empty() ? "0" : code) << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void deleteTree(Node* root) {
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }
    priority_queue<Node*, vector<Node*>, Compare> pq;
    cout << "Enter character and its frequency:\n";
    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cin >> ch >> freq;

        if (freq <= 0) {
            cout << "Invalid frequency!" << endl;
            while (!pq.empty()) {
                deleteTree(pq.top());
                pq.pop();
            }
            return 0;
        }

        pq.push(new Node(ch, freq));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('\0',left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    Node* root = pq.top();

    cout << "Huffman Codes: ";
    printCodes(root, "");

    deleteTree(root);

    return 0;
}
