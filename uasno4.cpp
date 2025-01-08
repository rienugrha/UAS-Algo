#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Fungsi untuk Radix Sort
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Hitung frekuensi digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Hitung posisi elemen
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Bangun array output
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Salin hasil ke array asli
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());

    // Lakukan counting sort untuk setiap digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

// Fungsi untuk Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi untuk Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
	
	cout << "Nama : Arie Nugraha" <<endl;
	cout << "NIM  : 231011401194" <<endl;
	cout << "Kelas: 03TPLP029" <<endl;
	
    vector<int> arr1 = {170, 45, 75, 90, 802, 24, 2, 66};
    vector<int> arr2 = arr1;
    vector<int> arr3 = arr1;

    // Radix Sort
    cout << "Radix Sort:\n";
    radixSort(arr1);
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << "\n";

    // Quick Sort
    cout << "Quick Sort:\n";
    quickSort(arr2, 0, arr2.size() - 1);
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << "\n";

    // Merge Sort
    cout << "Merge Sort:\n";
    mergeSort(arr3, 0, arr3.size() - 1);
    for (int num : arr3) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}

