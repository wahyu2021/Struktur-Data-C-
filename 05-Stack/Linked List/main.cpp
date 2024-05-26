#include <iostream>
using namespace std;

const int maks = 5;

// struct
struct DataBarang{
    string namaBrg;
    int hrgBrg;

    // pointer
    DataBarang *next;
    DataBarang *prev;
} *head, *tail, *cur, *del, *newNode;

int count();
bool isFull();
bool isEmpty();
void push(string namaBrg, int hrgBrg);
void pop();
void change(string namaBrg, int hrgBrg, int posisi);
void peek(int posisi);
void destroy();
void display();

int main(){
    push("Kawa-kawa", 1230000);
    push("Heneiken", 231000);
    push("Lasegar", 8000);
    push("Ramen instan", 5000);
    push("Sprite", 10000);
    // push("Fanta", 10000);
    display();
    // destroy();
    // display();

    return 0;
}

int count(){
    int jml = 0;
    cur = head;
    while(cur != NULL){
        cur = cur->next;
        jml++;
    }
    return jml;
}

bool isFull(){
    if(count() >= maks){
        return true;
    } else{
        return false;
    }
}

bool isEmpty(){
    if(head == NULL){
        return true;
    } else{
        return false;
    }
}

void push(string namaBrg, int hrgBrg){
    if(isFull()){
        cout << "Stack Penuh!!!" << endl;
    } else{
        if(isEmpty()){
            head = new DataBarang();
            head->namaBrg = namaBrg;
            head->hrgBrg = hrgBrg;
            head->prev = NULL;
            head->next = NULL;
            tail = head;
        } else{
            newNode = new DataBarang();
            newNode->namaBrg = namaBrg;
            newNode->hrgBrg = hrgBrg;
            newNode->next = NULL;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void pop(){
    if(isEmpty()){
        cout << "Stack Kosong!!!" << endl;
    } else{
        del = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL; // Jika stack hanya memiliki satu elemen
        }
        delete del;
    }
}

void change(string namaBrg, int hrgBrg, int posisi){
    if(isEmpty()){
        cout << "Stack Kosong!!!" << endl;
    } else{
        cur = tail;
        int nmr = 1;
        while(nmr < posisi){
            cur = cur->prev;
            nmr++;
        }
        cur->namaBrg = namaBrg;
        cur->hrgBrg = hrgBrg;
    }
}

void peek(int posisi){
    if(isEmpty()){
        cout << "Stack Kosong!!!" << endl;
    } else{
        cur = tail;
        int nmr = 1;
        while(nmr < posisi){
            cur = cur->prev;
            nmr++;
        }
        cout << "Nama Barang : " << cur->namaBrg << " || Harga : Rp" << cur->hrgBrg << endl;
    }
}
void destroy(){
    while(!isEmpty()){
        pop();
    }
}
void display(){
    if(isEmpty()){
        cout << "Stack Kosong!!!" << endl;
    } else{
        cout << "Jumlah Data : " << count() << endl;
        cout << "Data Barang " << endl;
        cur = tail;
        while(cur != NULL){
            cout << "Nama Barang : " << cur->namaBrg << " || Harga : Rp" << cur->hrgBrg << endl;
            cur = cur->prev;
        }
    }
}