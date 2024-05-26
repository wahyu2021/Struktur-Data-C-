#include <iostream>
using namespace std;

const int maks = 5;
int front = 0;
int back = 0;
string antrianATM[maks];

// function
int count(){
    if(front == 0 && back == 0){
        return 0;
    } else{
        return back;
    }
}

bool isFull(){
    if(count() >= maks){
        return true;
    } else{
        return false;
    }
}

bool isEmpty(){
    if(count() <= 0){
        return true;
    } else{
        return false;
    }
}

void enqueue(string data){
    if(isFull()){
        cout << "Antrian Penuh!!!" << endl;
    } else{
        if(isEmpty()){
            antrianATM[back] = data;
            front++;
            back++;
        } else{
            antrianATM[back] = data;
            back++;
        }
    }
}

void dequeue(){
    if(isEmpty()){
        cout << "Antrian Kosong!!!" << endl;
    } else{
        if(front == back){
            antrianATM[front] = "";
            front = 0;
            back = 0;
        } else{
            for(int i = 0; i < back; i++){
                antrianATM[i] = antrianATM[i+1];
            }
            antrianATM[back-1] = "";
            back--;
        }
    }
}

void destroy(){
    if(isEmpty()){
        cout << "Antrian Kosong!!!" << endl;
    } else{
        for(int i = 0; i < maks; i++){
            antrianATM[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void display(){
    if(isEmpty()){
        cout << "Antrian Kosong!!!" << endl;
    } else{
        for(int i = 0; i < maks; i++){
            if(antrianATM[i] != ""){
                cout << "Antrean ke-" << i+1 << " : " << antrianATM[i] << endl;
            } else{
                cout << "Antrean ke-" << i+1 << " : (Kosong)" << endl;
            }
        }
        cout << "\n\n";
    }
}

int main(){
    enqueue("Wahyu");
    enqueue("Dhea");
    enqueue("Lina");
    enqueue("Kinara");
    enqueue("Amsyar");
    enqueue("Amsyar");
    display();
    dequeue();
    dequeue();
    dequeue();
    display();
    cout << count() << endl;

    return 0;
}