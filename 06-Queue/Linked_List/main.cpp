#include <iostream>
using namespace std;

// struct
struct AntrianATM{
    // member
    string nama;
    int umur;

    // pointer
    AntrianATM *next;
} *head, *tail, *cur, *del, *newNode;
const int maks = 5;

int count(){
    if(head == NULL){
        return 0;
    } else{
        int jml = 0;
        cur = head;
        while(cur != NULL){
            jml++;
            cur = cur->next;
        }
        return jml;
    }
}

bool isFull(){
    return (count() >= maks) ? true : false;
}

bool isEmpty(){
    return (count() <= 0) ? true : false;
}

void create(string nama, int umur){
    head = new AntrianATM();
    head->nama = nama;
    head->umur = umur;
    head->next = NULL;
    tail = head;
}

void addLast(string nama, int umur){
    newNode = new AntrianATM();
    newNode->nama = nama;
    newNode->umur = umur;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void enqueue(string nama, int umur){
    if(isFull()){
        cout << "Antrian Penuh!!!" << endl;
    } else{
        if(isEmpty()){
            create(nama, umur);
        } else{
            addLast(nama, umur);
        }
    }
}

void dequeue(){
    if(isEmpty()){
        cout << "Tidak Ada Antrian!!!" << endl;
    } else{
        del = head;
        head = head->next;
        del->next = NULL;
        delete del;
    }
}

void destroy(){
    while(!isEmpty()){
        dequeue();
    }
}

void display(){
    if(isEmpty()){
        cout << "Tidak Ada Antrian!!!" << endl;
    } else{
        int noAntrian = 1;
        cur = head;
        while(noAntrian <= maks){
            if(cur != NULL){
                cout << noAntrian << ". " << cur->nama << " (" << cur->umur << " Tahun)" << endl;
                cur = cur->next;
            } else{
                cout << noAntrian << ". (Kosong)" << endl;
            } 
            noAntrian++;
        }     
    }
}

int main(){
    enqueue("wahyu", 18);
    enqueue("wahyu", 18);
    enqueue("wahyu", 18);
    display();
    cout << endl;
    destroy();
    display();
}