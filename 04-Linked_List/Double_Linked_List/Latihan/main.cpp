#include <iostream>
using namespace std;

// struct
struct DataUser{
    string username, email, password;
    DataUser *prev;
    DataUser *next;
} *head, *tail, *cur, *newNode, *del, *afterNode;

// fucntion
int count();
// create
void create(string data[3]);
// add
void addFirst(string data[3]);
void addMiddle(string data[3], int posisi);
void addLast(string data[3]);
// remove
void removeFirst();
void removeMiddle(int posisi);
void removeLast();
// display
void garis();
void display();
void displayLastToFirst();

int main(){
    string data1[3] = {"RCRYxFoxy", "foxy256@gmail.com", "124232"};
    string data2[3] = {"RCRYxASEP", "foxy256@gmail.com", "124232"};
    string data3[3] = {"RCRYxFoxe", "foxy256@gmail.com", "124232"};
    string data4[3] = {"RCRYxKobo", "foxy256@gmail.com", "124232"};
    string data5[3] = {"RCRYxMiss", "foxy256@gmail.com", "124232"};
    string data6[3] = {"RCRYxHoly", "foxy256@gmail.com", "124232"};

    create(data1);
    display();
    cout << "\n\n";
    addFirst(data2);
    display();
    cout << "\n\n";
    addLast(data3);
    display();
    cout << "\n\n";
    addLast(data2);
    display();
    cout << "\n\n";
    addMiddle(data5, 3);
    display();
    cout << "\n\n";
    removeMiddle(2);
    display();
    cout << "\n\n";
    cout << "Menampilkan secara terbalik" << endl;
    displayLastToFirst();

    return 0;
}

// fucntion
int count(){
    int jml = 0;
    cur = head;
    while(cur != NULL){
        cur = cur->next;
        jml++;
    }
    return jml;
}
// create
void create(string data[3]){
    head = new DataUser();
    head->username = data[0];
    head->email = data[1];
    head->password = data[2];
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}
// add
void addFirst(string data[3]){
    if(head == NULL){
        cout << "Linked List Belum Dibuat!!!" << endl;
    } else{
        newNode = new DataUser();
        newNode->username = data[0];
        newNode->email = data[1];
        newNode->password = data[2];
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }
}

void addMiddle(string data[3], int posisi){
    if(head == NULL){
        cout << "Linked List Belum Dibuat!!!" << endl;
    } else if(posisi < 1 || posisi > count()){
        cout << "Posisi Diluar Jangkauan!!!" << endl;
    } else if(posisi == 1 || posisi == count()){
        cout << "Bukan Posisi Tengah!!!" << endl;
    } else{
        newNode = new DataUser();
        newNode->username = data[0];
        newNode->email = data[1];
        newNode->password = data[2];
        
        // transversing
        cur = head;
        int nomor = 1;
        while(nomor < posisi-1){
            cur = cur->next;
            nomor++;
        }
        afterNode = cur->next;
        cur->next = newNode;
        newNode->prev = cur;
        afterNode->prev = newNode;
        newNode->next = afterNode;
    }
}
void addLast(string data[3]){
    if(head == NULL){
        cout << "Linked List Belum Dibuat!!!" << endl;
    } else{
        newNode = new DataUser();
        newNode->username = data[0];
        newNode->email = data[1];
        newNode->password = data[2];
        newNode->next = NULL;
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
// remove
void removeFirst(){
    if(head == NULL){
        cout << "Linked List Belum Dibuat!!!" << endl;
    } else{
        del = head;
        head = head->next;
        head->prev = NULL;
        delete del;   
    }
}

void removeMiddle(int posisi){
    if(head == NULL){
        cout << "Linked List Belum Dibuat!!!" << endl;
    } else if(posisi < 1 || posisi > count()){
        cout << "Posisi Diluar Jangkauan!!!" << endl;
    } else if(posisi == 1 || posisi == count()){
        cout << "Bukan Posisi Tengah!!!" << endl;
    } else{
        // transversing
        cur = head;
        int nomor = 1;
        while(nomor < posisi-1){
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
void removeLast(){
    if(head == NULL){
        cout << "Linked List Belum Dibuat!!!" << endl;
    } else{
        del = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete del;   
    }
}
// display
void garis(){
    cout << "===============================================" << endl;
}
void display(){
    if(head == NULL){
        cout << "Linked List Belum Dibuat!!!" << endl;
    } else{
        cout << "Jumlah data    : " << count() << endl;
        cout << "Isi data       :" << endl;
        garis();

        // transversing
        cur = head;
        while(cur != NULL){
            cout << "Username   : " << cur->username << endl;
            cout << "Email      : " << cur->email << endl;
            cout << "Password   : " << cur->password << endl;
            garis();
            cur = cur->next;
        } 
    }
}

void displayLastToFirst(){
    if(head == NULL){
        cout << "Linked List Belum Dibuat!!!" << endl;
    } else{
        cout << "Jumlah data    : " << count() << endl;
        cout << "Isi data       :" << endl;
        garis();

        // transversing
        cur = tail;
        while(cur != NULL){
            cout << "Username   : " << cur->username << endl;
            cout << "Email      : " << cur->email << endl;
            cout << "Password   : " << cur->password << endl;
            garis();
            cur = cur->prev;
        } 
    }
}