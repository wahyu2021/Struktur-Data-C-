#include <iostream>

using namespace std;

// struct
struct Mahasiswa{
    string nama;
    string NIM;
    string kls;
    int IPK;

    Mahasiswa *next;
} *head, *tail, *cur, *newNode, *del, *before;

//function
int count();
// create linked list
void create(string nama, string NIM, string kls, int IPK);
// add node
void addFirst(string nama, string NIM, string kls, int IPK);
void addLast(string nama, string NIM, string kls, int IPK);
void addMiddle(string nama, string NIM, string kls, int IPK, int posisi);
// change node
void changeFirst(string nama, string NIM, string kls, int IPK);
void changeLast(string nama, string NIM, string kls, int IPK);
void changeMiddle(string nama, string NIM, string kls, int IPK, int posisi);
// delete
void deleteFirst();
void deleteLast();
void deleteMiddle(int posisi);
// menampilkan
void garis();
void display();

int main(){


    return 0;
}

//function
int count(){
    int jml = 0;
    cur = head;
    while(cur != NULL){
        jml++;
        cur = cur->next;
    }
    return jml;
}
// create linked list
void create(string nama, string NIM, string kls, int IPK){
    head = new Mahasiswa();
    head->nama = nama;
    head->NIM = NIM;
    head->kls = kls;
    head->IPK = IPK;
    head->next = NULL;
    tail = head;
}
// add node
void addFirst(string nama, string NIM, string kls, int IPK){
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->NIM = NIM;
    newNode->kls = kls;
    newNode->IPK = IPK;
    newNode->next = head;
    head = newNode;
}
void addLast(string nama, string NIM, string kls, int IPK){
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->NIM = NIM;
    newNode->kls = kls;
    newNode->IPK = IPK;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}
void addMiddle(string nama, string NIM, string kls, int IPK, int posisi){
    if(posisi < 1 || posisi > count()){
        cout << "Posisi diluar jangkauan" << endl;
    } else if(posisi == 1 || posisi == count()){
        cout << "Posisi bukan ditengah" << endl;
    } else{
        newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->NIM = NIM;
        newNode->kls = kls;
        newNode->IPK = IPK;

        cur = head;
        int nomor = 1;
        while(nomor < posisi-1){
            cur = cur->next;
            nomor++;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}
  
// change node
void changeFirst(string nama, string NIM, string kls, int IPK){
    head->nama = nama;
    head->NIM = NIM;
    head->kls = kls;
    head->IPK = IPK;
}
void changeLast(string nama, string NIM, string kls, int IPK){
    tail->nama = nama;
    tail->NIM = NIM;
    tail->kls = kls;
    tail->IPK = IPK;
}
void changeMiddle(string nama, string NIM, string kls, int IPK, int posisi){
    if(posisi < 1 || posisi > count()){
        cout << "Posisi diluar jangkauan" << endl;
    } else if(posisi == 1 || posisi == count()){
        cout << "Posisi bukan ditengah" << endl;
    } else{
        cur = head;
        int nomor = 1;
        while(nomor < posisi){
            cur = cur->next;
            nomor++;
        }
        cur->nama = nama;
        cur->NIM = NIM;
        cur->kls = kls;
        cur->IPK = IPK;
    }
}
// delete
void deleteFirst(){
    del = head;
    head = head->next;
    delete del;
}
void deleteLast(){
    del = tail;
    cur = head;
    while(cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}
void deleteMiddle(int posisi){
    if(posisi < 1 || posisi > count()){
        cout << "Posisi diluar jangkauan" << endl;
    } else if(posisi == 1 || posisi == count()){
        cout << "Posisi bukan ditengah" << endl;
    } else{
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
}
// menampilkan
void garis(){
    cout << "===================================================" << endl;
}
void display(){
    cur = head;
    while(cur != NULL){
        garis();
        cout << "Nama       : " << cur->nama << endl;
        cout << "NIM        : " << cur->NIM << endl;
        cout << "Kelas      : " << cur->kls << endl;
        cout << "IPK        : " << cur->IPK << endl;
        cur = cur->next;
    }
}