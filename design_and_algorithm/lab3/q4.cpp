#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(Node* const& n1, Node* const& n2) {
        return n1->freq > n2->freq;
    }
};

Node* buildHuffmanTree(vector<char>& chars, vector<int>& freq) {
    priority_queue<Node*, vector<Node*>, CompareNodes> minHeap;

    for (int i = 0; i < chars.size(); i++) {
        minHeap.push(new Node(chars[i], freq[i]));
    }

    while (minHeap.size() > 1) {
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();

        Node* internalNode = new Node('$', left->freq + right->freq);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    return minHeap.top();
}

void generateHuffmanCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        huffmanCodes[root->data] = code;
        return;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

void printHuffmanCodes(Node* root) {
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    cout << "Huffman Codes:" << endl;
    for (auto it = huffmanCodes.begin(); it != huffmanCodes.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
}

int main() {
    vector<char> chars = {'a', 'b', 'c', 'd', 'e'};
    vector<int> freq = {5, 9, 12, 13, 16};

    Node* root = buildHuffmanTree(chars, freq);
    printHuffmanCodes(root);

    return 0;
}
