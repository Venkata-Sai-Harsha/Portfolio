#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Huffman tree node
struct Node {
    char data;
    int frequency;
    Node* left;
    Node* right;

    Node(char data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

// Comparison function for priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

void printHuffmanCodes(Node* root, string code, unordered_map<char, string>& codes) {
    if (root == nullptr) {
        return;
    }

    if (root->data != '$') {
        codes[root->data] = code;
    }

    printHuffmanCodes(root->left, code + "0", codes);
    printHuffmanCodes(root->right, code + "1", codes);
}

// Function to build Huffman tree and assign codes to characters
void buildHuffmanTree(string text) {
    // Count frequency of each character
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Create a priority queue to store nodes
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Print Huffman codes
    Node* root = pq.top();
    unordered_map<char, string> codes;
    string code;
    printHuffmanCodes(root, code, codes);

    cout << "Huffman Codes:\n";
    for (auto pair : codes) {
        cout << pair.first << " : " << pair.second << endl;
    }
}


int main() {
    string text = "hello world";
    buildHuffmanTree(text);
    return 0;
}

/*#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Node structure for the Huffman tree
struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparison class for priority queue
struct CompareNodes {
    bool operator()(HuffmanNode* lhs, HuffmanNode* rhs) const {
        return lhs->frequency > rhs->frequency;
    }
};

// Function to build the Huffman tree
HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& frequencyMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> pq;

    // Create nodes for each character and add them to the priority queue
    for (const auto& entry : frequencyMap) {
        pq.push(new HuffmanNode(entry.first, entry.second));
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();

        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* internalNode = new HuffmanNode('\0', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;

        pq.push(internalNode);
    }

    // The root of the Huffman tree is now at the top of the priority queue
    return pq.top();
}

// Function to generate Huffman codes
void generateHuffmanCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root) {
        if (root->data != '\0') {
            huffmanCodes[root->data] = code;
        }

        generateHuffmanCodes(root->left, code + "0", huffmanCodes);
        generateHuffmanCodes(root->right, code + "1", huffmanCodes);
    }
}

// Function to compress a string using Huffman coding
string compressString(const string& input, const unordered_map<char, string>& huffmanCodes) {
    string compressedString;
    for (char c : input) {
        compressedString += huffmanCodes.at(c);
    }
    return compressedString;
}

// Function to decompress a string using Huffman coding
string decompressString(const string& compressedString, const HuffmanNode* root) {
    string decompressedString;
    const HuffmanNode* current = root;

    for (char bit : compressedString) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->data != '\0') {
            decompressedString += current->data;
            current = root;  // Reset to the root for the next character
        }
    }

    return decompressedString;
}

int main() {
    // Input string
    string inputString = "hello world";

    // Calculate frequency of each character
    unordered_map<char, int> frequencyMap;
    for (char c : inputString) {
        frequencyMap[c]++;
    }

    // Build Huffman tree
    HuffmanNode* root = buildHuffmanTree(frequencyMap);

    // Generate Huffman codes
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Display Huffman codes
    cout << "Huffman Codes:" << endl;
    for (const auto& entry : huffmanCodes) {
        cout << entry.first << ": " << entry.second << endl;
    }

    // Compress the input string
    string compressedString = compressString(inputString, huffmanCodes);
    cout << "Compressed String: " << compressedString << endl;

    // Decompress the string
    string decompressedString = decompressString(compressedString, root);
    cout << "Decompressed String: " << decompressedString << endl;

    return 0;
}*/

