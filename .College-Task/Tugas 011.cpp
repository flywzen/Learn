
 
#include <iostream> 
 
using namespace std; 
 
// Definisi konstanta untuk ukuran array 
constexpr int Arraysize = 6; 
 
// Fungsi untuk mencetak isi array 
void printArray(const int angka[], int size) 
{ 
    cout << "Array : "; 
    for (int i = 0; i < size; ++i) 
    { 
        cout << angka[i] << " "; 
    } 
    cout << endl; 
} 
 
// Fungsi untuk melakukan binary search dalam array 
int binarySearch(const int angka[], int size, int target) 
{ 
    // Inisialisasi variabel low, high, dan result 
    int low = 0; 
    int high = size - 1; 
    int result = -1; 
 
    // Iterasi sampai low kurang dari atau sama dengan high 
    while (low <= high) 
    { 
        // Hitung indeks tengah 
        int mid = low + (high - low) / 2; 
 
        // Jika nilai tengah sama dengan target 
        if (angka[mid] == target) 
        { 
            // Simpan indeks dan perbarui high untuk mencari nilai di sebelah 
kiri 
            result = mid; 
            high = mid - 1; 
        } 
        // Jika nilai tengah kurang dari target 
        else if (angka[mid] < target) 
        { 
            // Perbarui low untuk mencari nilai di sebelah kanan 
            low = mid + 1; 
        } 
        // Jika nilai tengah lebih dari target 
        else 
        { 
            // Perbarui high untuk mencari nilai di sebelah kiri 
            high = mid - 1; 
        } 
    } 
 
    // Kembalikan indeks tempat nilai ditemukan atau -1 jika tidak ditemukan 
    return result; 
} 
 
int main() 
{ 
    // Array yang akan dicari 
    int angka[Arraysize] = {1, 2, 2, 4, 5, 5}; 
 
    // Memanggil fungsi untuk mencetak isi array 
    printArray(angka, Arraysize); 
 
    // Meminta pengguna untuk memasukkan nilai yang ingin dicari 
    int target; 
    cout << "Masukkan nilai yang ingin dicari: "; 
    cin >> target; 
 
    // Memanggil fungsi binarySearch untuk mencari nilai dalam array 
    int result = binarySearch(angka, Arraysize, target); 
 
    // Mengecek apakah nilai ditemukan atau tidak 
    if (result != -1) 
    { 
        // Jika nilai ditemukan, mencetak indeks di mana nilai ditemukan 
        cout << "Nilai ditemukan pada indeks ke-" << result << " dalam array." 
<< endl; 
    } 
    else 
    { 
        // Jika nilai tidak ditemukan, mencetak pesan bahwa nilai tidak 
ditemukan 
        cout << "Nilai tidak ditemukan dalam array." << endl; 
    } 
 
    return 0; 
} 
 
 
 
//Linear Search 
 
#include <iostream> 
 
using namespace std; 
 
// Definisi konstanta untuk ukuran array 
constexpr int Arraysize = 6; 
 
// Fungsi untuk mencetak isi array 
void printArray(const int angka[], int size) 
{ 
    cout << "Array : "; 
    for (int i = 0; i < size; ++i) 
    { 
        cout << angka[i] << " "; 
    } 
    cout << endl; 
} 
 
// Fungsi untuk melakukan pencarian linear dalam array 
int linearSearch(const int angka[], int size, int target) 
{ 
    // Melakukan iterasi melalui setiap elemen dalam array 
    for (int i = 0; i < size; ++i) 
    { 
        // Jika nilai pada indeks ke-i sama dengan nilai target 
        if (angka[i] == target) 
        { 
            // Mengembalikan indeks di mana nilai target ditemukan 
            return i; 
        } 
    } 
    // Jika nilai target tidak ditemukan dalam array, mengembalikan -1 
    return -1; 
} 
 
int main() 
{ 
    // Array yang akan dicari 
    int angka[Arraysize] = {1, 2, 2, 4, 5, 5}; 
 
    // Memanggil fungsi untuk mencetak isi array 
    printArray(angka, Arraysize); 
 
    // Meminta pengguna untuk memasukkan nilai yang ingin dicari 
    int target; 
    cout << "Masukkan nilai yang ingin dicari: "; 
cin >> target; 
// Memanggil fungsi linearSearch untuk mencari nilai dalam array 
int result = linearSearch(angka, Arraysize, target); 
// Mengecek apakah nilai ditemukan atau tidak 
if (result != -1) 
{ 
// Jika nilai ditemukan, mencetak indeks di mana nilai ditemukan 
cout << "Nilai ditemukan pada indeks ke-" << result << " dalam array." 
<< endl; 
} 
else 
{ 
// Jika nilai tidak ditemukan, mencetak pesan bahwa nilai tidak 
ditemukan 
cout << "Nilai tidak ditemukan dalam array." << endl; 
} 
return 0; 
}
