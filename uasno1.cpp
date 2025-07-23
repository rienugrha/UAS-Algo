#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>




using namespace std;

// Struktur simpul Huffman
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    // Konstruktor untuk simpul dengan karakter dan frekuensi
    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}

    // Konstruktor untuk simpul internal dengan dua anak
    Node(int frequency, Node* left, Node* right) : ch('\0'), freq(frequency), left(left), right(right) {}
};

// Comparator untuk prioritas queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Traversal pohon Huffman untuk menghasilkan kode
void buildHuffmanCode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    buildHuffmanCode(root->left, str + "0", huffmanCode);
    buildHuffmanCode(root->right, str + "1", huffmanCode);
}

// Fungsi untuk membangun pohon Huffman
Node* buildHuffmanTree(const string& text) {
    // Hitung frekuensi setiap karakter
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Masukkan simpul ke dalam prioritas queue
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Gabungkan simpul hingga pohon terbentuk
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        int sum = left->freq + right->freq;
        pq.push(new Node(sum, left, right)); // Menggunakan konstruktor baru untuk simpul internal
    }

    return pq.top();
}

// Fungsi encoding
string encode(const string& text, unordered_map<char, string>& huffmanCode) {
    string encodedString;
    for (char ch : text) {
        encodedString += huffmanCode[ch];
    }
    return encodedString;
}

// Fungsi decoding
string decode(Node* root, const string& encodedString) {
    string decodedString;
    Node* current = root;
    for (char bit : encodedString) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (!current->left && !current->right) {
            decodedString += current->ch;
            current = root;
        }
    }
    return decodedString;
}

int main() {
	cout << "Nama : Arie Nugraha" <<endl;
	cout << "NIM  : 231011401194" <<endl;
	cout << "Kelas: 03TPLP029" <<endl;
    string text;

    cout << "Masukkan string untuk dikompresi: ";
    cin >> text;

    // Bangun pohon Huffman
    Node* root = buildHuffmanTree(text);

    // Bangun kode Huffman
    unordered_map<char, string> huffmanCode;
    buildHuffmanCode(root, "", huffmanCode);

    cout << "\nKode Huffman untuk setiap karakter:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << '\n';
    }

    // Encoding
    string encodedString = encode(text, huffmanCode);
    cout << "\nString setelah dikompresi: " << encodedString << '\n';

    // Decoding
    string decodedString = decode(root, encodedString);
    cout << "String setelah didekompresi: " << decodedString << '\n';

    return 0;
}

