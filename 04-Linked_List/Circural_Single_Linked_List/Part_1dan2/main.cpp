#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi untuk circural single linked list
struct Mahasiswa{
    string npm, nama, jurusan;

    Mahasiswa *next;
}*head, *tail, *newNode, *cur, *del, *before;

// create
void create(string data[3]){
    head = new Mahasiswa();
    head->npm = data[0];
    head->nama = data[1];
    head->jurusan = data[2];
    tail = head;
    tail->next = head;
    head->next = tail; 
}

// add
void addFirst(string data[3]){
    newNode = new Mahasiswa();
    newNode->npm = data[0];
    newNode->nama = data[1];
    newNode->jurusan = data[2];
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

void addMiddle(string data[3],int posisi){
    newNode = new Mahasiswa();
    newNode->npm = data[0];
    newNode->nama = data[1];
    newNode->jurusan = data[2];
    cur = head;
    int nomor = 1;
    while(nomor < posisi-1){
        cur = cur->next;
        nomor++;
    }
    newNode->next = cur->next;
    cur->next = newNode;
}

void addLast(string data[3]){
    newNode = new Mahasiswa();
    newNode->npm = data[0];
    newNode->nama = data[1];
    newNode->jurusan = data[2];
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
}

// remove
void removeFirst(){
    del = head;
    head = head->next;
    tail->next = head;
    delete del;
}

void removeMiddle(int posisi){
    cur = head;
    int nomor = 1;
    while(nomor <= posisi){
        if(nomor == posisi-1){
            before = cur;
        }
        if(nomor == posisi){
            del = cur;
        }
        cur = cur->next;
        nomor++;
    }
    before->next = cur;
    delete del;
}

void removeLast(){
    del = tail;
    cur = head;
    while(cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    tail->next = head;
    delete del;
}
// display
void garis(){
    for(int i = 0; i <= 69; i++){
        cout << "=";
    }
    cout << endl;
}

void print(){
    cur = head;
    cout << "Data Mahasiswa" << endl;
    garis();
    cout << "|" << right << setw(9) << "NPM" << right << setw(7) << "|" 
        << right << setw(14) << "Nama" << right << setw(11) << "|" 
        << right << setw(17) << "Jurusan" << right << setw(11) << "|" << endl;
    garis();
    while(cur->next != head){
        cout << "|" << left << setw(12) << cur->npm << right << setw(4) << "|" 
        << left << setw(23) << cur->nama << right << setw(2) << "|" 
        << left << setw(26) << cur->jurusan << right << setw(2) << "|" << endl;
        garis();
        cur = cur->next;
    }
    cout << "|" << left << setw(12) << cur->npm << right << setw(4) << "|" 
    << left << setw(23) << cur->nama << right << setw(2) << "|" 
    << left << setw(26) << cur->jurusan << right << setw(2) << "|" << endl;
    garis();
}

int main(){
    string data1[3] = {"062340833133", "Wahyu Wahid Nugroho", "Manajemen Informatika"};
    string data2[3] = {"062340833115", "Dhea Fasya Nadhira", "Manajemen Informatika"};
    create(data1);
    addFirst(data2);
    addLast(data2);
    addLast(data1);
    addMiddle(data2,3);
    removeMiddle(3);
    print();
    return 0;
}