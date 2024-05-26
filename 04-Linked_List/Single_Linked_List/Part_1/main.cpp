#include <iostream>
#include <string>

using namespace std;

// struct
// deklarasi single linked list
struct Buku {
    // komponen / member
    string judul, pengarang;
    int thnTerbit;

    // next
    Buku *next;
};
Buku *head, *tail, *cur, *newNode, *del;

// fungsi
void grs();
void createSingleLinkedList(string judul, string pengarang, int thnTerbit);
void printSingleLinkedList();
void addFirst(string judul, string pengarang, int thnTerbit);
void addLast(string judul, string pengarang, int thnTerbit);
void rmvFirst();
void rmvLast();
void changeFirst(string judul, string pengarang, int thnTerbit);
void changeLast(string judul, string pengarang, int thnTerbit);

int main(){
    createSingleLinkedList("Kata", "Geez & Aan", 2018);
    printSingleLinkedList();

    cout << "\n\n" << endl;

    addFirst("Dia adalah Kakakku", "Tiye Liye", 2009);
    printSingleLinkedList();

    cout << "\n\n" << endl;

    addLast("Aroma Karsa", "Dee Lestari", 2018);
    printSingleLinkedList();

    cout << "\n\n" << endl;
    
    rmvFirst();
    printSingleLinkedList();

    cout << "\n\n" << endl;

    rmvLast();
    printSingleLinkedList();

    cout << "\n\n" << endl;

    addLast("11.11", "Fiersa Besari", 2022);
    addLast("Garis Terdepan", "Fiersa Besari", 2021);
    printSingleLinkedList();

    cout << "\n\n" << endl;
    changeFirst("Statistika Dasar", "Ahli Statistika", 2005);
    changeLast("Machine Learning For Beginner", "Dhea Fasya Nadhira", 2004);
    
    printSingleLinkedList();


    return 0;
}


void grs(){
    cout << "=====================================================================" << endl;
}

void createSingleLinkedList(string judul, string pengarang, int thnTerbit){
    head = new Buku();
    head->judul = judul;
    head->pengarang = pengarang;
    head->thnTerbit = thnTerbit;
    head->next = NULL;
    tail = head;
}

void addFirst(string judul, string pengarang, int thnTerbit){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->thnTerbit = thnTerbit;
    newNode->next = head;
    head = newNode;
}

void addLast(string judul, string pengarang, int thnTerbit){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->thnTerbit = thnTerbit;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void rmvFirst(){
    del = head;
    head = head->next;
    delete del;
}

void rmvLast(){
    del = tail;
    cur = head;
    while (cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

void changeFirst(string judul, string pengarang, int thnTerbit){
    head->judul = judul;
    head->pengarang = pengarang;
    head->thnTerbit = thnTerbit;
}
void changeLast(string judul, string pengarang, int thnTerbit){
    tail->judul = judul;
    tail->pengarang = pengarang;
    tail->thnTerbit = thnTerbit;
}

void printSingleLinkedList(){
    cur = head;
    while(cur != NULL){
        cout << "Judul Buku : " << cur->judul << endl;
        cout << "Pengarang Buku Node : " << cur->pengarang << endl;
        cout << "Tahun Terbit Buku : " << cur->thnTerbit << endl;
        grs();
        cur = cur->next;
    }
}

