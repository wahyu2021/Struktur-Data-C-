#include <iostream>
using namespace std;

// struct
struct DataUser{
    string nama, username, email, password;
    DataUser *prev; // menunjuk ke nilai sebelum node
    DataUser *next; // menunjuk ke nilai setelah node;
};

DataUser *head, *tail, *cur, *newNode, *afterNode, *del;

// function
int count(){
    int jml = 0;
    cur = head;
    while(cur != NULL){
        jml++;
        cur = cur->next;
    }
    return jml;
}
// create node
void create(string data[4]){
    head = new DataUser();
    head->nama = data[0];
    head->username = data[1];
    head->email = data[2];
    head->password = data[3];
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}
// add
void addFirst(string data[4]){
    if(head == NULL){
        cout << "Double Linked List Belum Dibuat!!!" << endl;
    } else{
        newNode = new DataUser();
        newNode->nama = data[0];
        newNode->username = data[1];
        newNode->email = data[2];
        newNode->password = data[3];
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void addLast(string data[4]){
    if(head == NULL){
        cout << "Double Linked List Belum Dibuat!!!" << endl;
    } else{
        newNode = new DataUser();
        newNode->nama = data[0];
        newNode->username = data[1];
        newNode->email = data[2];
        newNode->password = data[3];
        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void addMiddle(string data[4], int posisi){
    if(head == NULL){
        cout << "Double Linked List Belum Dibuat!!!" << endl;
    } else if(posisi < 1 || posisi > count()){
        cout << "Posisi diluar jangkauan" << endl;
    } else if(posisi == 1 || posisi == count()){
        cout << "Posisi bukan ditengah" << endl;
    } else{
        newNode = new DataUser();
        newNode->nama = data[0];
        newNode->username = data[1];
        newNode->email = data[2];
        newNode->password = data[3];
        // transversing
        cur = head;
        int nomor = 1;
        while(nomor < posisi-1){
            cur = cur->next;
            nomor++;
        }
        afterNode = cur->next;
        afterNode->prev = newNode;
        newNode->next = afterNode;
        newNode->prev = cur;
        cur->next = newNode;
    }
}
// delete
void removeFirst(){
    if(head == NULL){
        cout << "Double Linked List Belum Dibuat!!!" << endl;
    } else{
        del = head;
        head = head->next;
        head->prev = NULL;
        delete del;
    }
}

void removeLast(){
    if(head == NULL){
        cout << "Double Linked List Belum Dibuat!!!" << endl;
    } else{
        del = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete del;
    }
}

void removeMiddle(int posisi){
    if(head == NULL){
        cout << "Double Linked List Belum Dibuat!!!" << endl;
    } else if(posisi < 1 || posisi > count()){
        cout << "Posisi diluar jangkauan" << endl;
    } else if(posisi == 1 || posisi == count()){
        cout << "Posisi bukan ditengah" << endl;
    } else{
        cur = head;
        int nomor = 1;
        while(nomor < posisi - 1){
            cur = cur->next;
            nomor++;
        }
        del = cur->next;
        afterNode = del->next;
        cur->next = afterNode;
        afterNode->prev = cur;
        delete del;
    }
}
// tampilkan
void garis(){
    cout << "=====================================================" << endl;
}

void display(){
    if(head == NULL){
        cout << "Double Linked List Belum Dibuat!!!" << endl;
    } else{
        cout << "Jumlah Data : " <<  count() << endl;
        cout << "Isi data : " << endl;
        garis();
        cur = head;
        while(cur != NULL){
            cout << "Nama       :" << cur->nama << endl;
            cout << "Username   :" << cur->username << endl;
            cout << "Email      :" << cur->email << endl;
            cout << "Password   :" << cur->password << endl;
            cur = cur->next;
            garis();
        }
    }
}

int main(){

}