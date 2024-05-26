#include <iostream>
using namespace std;

const int maks = 5;
string dataBuku[maks];
int top = 0;

// prototype function
int count();
bool isFull();
bool isEmpty();
void push(string data);
void pop();
void change(string data, int posisi);
void peek(int posisi);
void display();
void destroy();

int main(){


    return 0;
}

// description function
int count(){
    return top;
}

bool isFull(){
    if(count() == maks){
        return true;
    } else{
        return false;
    }
}

bool isEmpty(){
    if(count() == 0){
        return true;
    } else{
        return false;
    }
}

void push(string data){
    if(isFull()){
        cout << "Stack Penuh!!!" << endl;
    } else{
        dataBuku[top] = data;
        top++;
    }
}

void pop(){
    if(isEmpty()){
        cout << "Stack Kosong!!!" << endl;
    } else{
        dataBuku[top-1] = "";
        top--;
    }
}

void change(string data, int posisi){
    if(isEmpty()){
        cout << "Stack Kosong!!!" << endl;
    } else{
        if(posisi <= 0 || posisi > maks){
            cout << "Posisi diluar jangkauan!!!" << endl;
        } else{
            dataBuku[top-posisi] = data;
        }
    }
}

void peek(int posisi){
    if(isEmpty()){
        cout << "Stack Kosong!!!" << endl;
    } else{
        if(posisi <= 0 || posisi > maks){
            cout << "Posisi diluar jangkauan!!!" << endl;
        } else{
            cout << "Data : " << dataBuku[top-posisi] << endl;
        }
    }
}
void display(){
    if(isEmpty()){
        cout << "Stack Kosong!!!" << endl;
    } else{
        int nomor = 1;
        cout << "Jumlah data : " << count() << endl;
        for(int i = top-1; i >= 0; i--){
            cout << nomor << " Data : " << dataBuku[i] << endl;
            nomor++;
        }
    }
}
void destroy(){
    if(isEmpty()){
        cout << "Stack Kosong!!!" << endl;
    } else{
        for(int i = top-1; i >= 0; i--){
            dataBuku[i] = "";
        }
        top = 0;
    }
}
