#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Fungsi untuk menemukan semua pasangan bilangan yang jumlahnya sama dengan K
void findPairsWithSum(const vector<int>& arr1, const vector<int>& arr2, int K) {
    map<int, int> freq;

    // Masukkan elemen-elemen array pertama ke dalam map
    for (int i = 0; i < arr1.size(); i++) {
        freq[arr1[i]]++;
    }

    cout << "Pasangan yang jumlahnya sama dengan " << K << ":\n";
    bool found = false;

    // Iterasi melalui array kedua untuk mencari pasangan
    for (int j = 0; j < arr2.size(); j++) {
        int complement = K - arr2[j];
        if (freq[complement] > 0) {
            cout << "(" << complement << ", " << arr2[j] << ")\n";
            found = true;
            // Kurangi frekuensi untuk menghindari penggunaan ulang elemen
            freq[complement]--;
        }
    }

    if (!found) {
        cout << "Tidak ada pasangan yang jumlahnya sama dengan " << K << ".\n";
    }
}

int main() {
	
	cout << "Nama : Arie Nugraha" <<endl;
	cout << "NIM  : 231011401194" <<endl;
	cout << "Kelas: 03TPLP029" <<endl;
	
    int K;

    // Input nilai K
    cout << "Masukkan nilai K: ";
    cin >> K;

    // Contoh array
    vector<int> arr1 = {1, 4, 5, 7, 9};
    vector<int> arr2 = {3, 2, 8, 5, 1};

    // Panggil fungsi untuk menemukan pasangan
    findPairsWithSum(arr1, arr2, K);

    return 0;
}

