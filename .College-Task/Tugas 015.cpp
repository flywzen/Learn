//Muhammad Rafly Yahya Ramadhan
//123140148
//RE

#include <iostream>
#include <iomanip> // Untuk format output
using namespace std;

// Node untuk Double Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan node di awal list
void insertAtHead(Node*& head, Node*& tail, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Fungsi untuk menambahkan node di akhir list
void insertAtTail(Node*& head, Node*& tail, int data) {
    Node* newNode = createNode(data);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Fungsi untuk mencari node berdasarkan nilai
Node* findNode(Node* head, int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) return temp;
        temp = temp->next;
    }
    return NULL;
}

// Fungsi untuk mencetak list
void printList(Node* head) {
    if (head == NULL) {
        cout << "[]";
        return;
    }
    cout << "[";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << ", ";
        temp = temp->next;
    }
    cout << "]";
}

// Fungsi untuk mencetak list
void printListdif(Node* tail) {
    if (tail == NULL) {
        cout << "[]";
        return;
    }
    cout << "[";
    Node* temp = tail;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->prev != NULL) cout << ", ";
        temp = temp->prev;
    }
    cout << "]";
}

// Fungsi untuk menghitung rata-rata
double calculateAverage(Node* head) {
    if (head == NULL) return 0;
    int sum = 0, count = 0;
    Node* temp = head;
    while (temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    return count > 0 ? (double)sum / count : 0;
}

// Fungsi untuk menghitung rata-rata
double calculateAveragedif(Node* tail) {
    if (tail == NULL) return 0;
    int sum = 0, count = 0;
    Node* temp = tail;
    while (temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->prev;
    }
    return count > 0 ? (double)sum / count : 0;
}


// Fungsi untuk memproses input sesuai ketentuan soal
void processList(int n, int arr[], int a) {
    Node *head = NULL, *tail = NULL; // List utama

    // Memasukkan elemen ke dalam list
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) { // Genap ke awal list
            insertAtHead(head, tail, arr[i]);
        } else { // Ganjil ke akhir list
            insertAtTail(head, tail, arr[i]);
        }
    }

    // Mencari node dengan nilai a
    Node* aNode = findNode(head, a);

    // Membagi list menjadi kiri dan kanan
    Node* leftHead = NULL, *leftTail = NULL;
    Node* rightHead = NULL, *rightTail = NULL;

    if (aNode != NULL) {
        // List kiri: elemen sebelum a
        Node* temp = head;
        while (temp != aNode) {
            insertAtTail(leftTail, leftHead, temp->data);
            temp = temp->next;
        }

        // List kanan: elemen setelah a
        temp = aNode->next;
        while (temp != NULL) {
            insertAtTail(rightHead, rightTail, temp->data);
            temp = temp->next;
        }
    }

    // Output hasil
    cout << "List kiri: ";
    printList(rightHead);
    cout << " = " << fixed << setprecision(1) << calculateAverage(rightHead) << endl;

    cout << "List kanan: ";
    printListdif(leftHead);
    cout << " = " << fixed << setprecision(1) << calculateAveragedif(leftHead) << endl;
}

int main() {
    // Input jumlah angka
    int n, a;
    cout << "Masukkan jumlah angka (n): ";
    cin >> n;

    int arr[n];
    cout << "Masukkan " << n << " angka: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Masukkan angka a: ";
    cin >> a;

    processList(n, arr, a);

    return 0;
}
