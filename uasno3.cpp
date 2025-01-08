#include <iostream>
#include <vector>
#include <algorithm> // untuk std::partition
using namespace std;

// Fungsi untuk menggabungkan elemen-elemen hasil rekursi
vector<int> concatenate(const vector<int>& left, int pivot, const vector<int>& right) {
    vector<int> result = left;
    result.push_back(pivot);
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

// Fungsi quick sort berbasis rekursi
vector<int> quickSort(const vector<int>& arr) {
    // Basis rekursi: jika array kosong atau hanya satu elemen, kembalikan array
    if (arr.size() <= 1) {
        return arr;
    }

    // Pilih pivot (elemen pertama)
    int pivot = arr[0];

    // Partisi elemen-elemen array menjadi dua bagian: lebih kecil dari pivot dan lebih besar atau sama
    vector<int> left;
    vector<int> right;
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < pivot) {
            left.push_back(arr[i]);
        } else {
            right.push_back(arr[i]);
        }
    }

    // Rekursi untuk bagian kiri dan kanan
    vector<int> sortedLeft = quickSort(left);
    vector<int> sortedRight = quickSort(right);

    // Gabungkan hasil rekursi
    return concatenate(sortedLeft, pivot, sortedRight);
}

int main() {
	
	cout << "Nama : Arie Nugraha" <<endl;
	cout << "NIM  : 231011401194" <<endl;
	cout << "Kelas: 03TPLP029" <<endl;
	
    // Contoh input
    vector<int> arr = {3, 6, 8, 10, 1, 2, 1};

    // Pemanggilan quick sort
    vector<int> sorted = quickSort(arr);

    // Cetak hasil
    cout << "Hasil Quick Sort: ";
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

