#include <iostream>
#include <iomanip>
using namespace std;

// Hash Table
struct HashTable{
    // member
    string username, password;
} dataAkun[26];

// Function hash
int hashFunction(string key){
    return tolower(key[0])-97;
}

// cek daftar
bool cekDaftar(string username, string password){
    int index = hashFunction(password);

    // cek index masih kosong atau sudah ditempati
    if(dataAkun[index].username != "" && dataAkun[index].password != "" ){
        // Kalo sel index hash table tidak kosong
        cout << "User sudah ada!!!" << endl;
        return false;
    } else{
        // kalo sel index hash table kosong
        dataAkun[index].username = username;
        dataAkun[index].password = password;
        return true;
    }
}

// cek login
bool cekLogin(string username, string password){
    // hashing dulu
    int index = hashFunction(password);

    // cek username
    if(dataAkun[index].username == username && dataAkun[index].password == password ){
        return true;
    } else{
        return false;
    }
}

// cek hapus
bool cekHapus(int index){
    if(dataAkun[index].username == "" && dataAkun[index].password == "" ){
        cout << "\nData Akun Tidak Ada!!!" << endl;
        return false;
    } else{
        dataAkun[index].username = "";
        dataAkun[index].password = "";
        return true;
    }
}

// Print daftar akun
void printDataAkun(){
    cout << "\nDaftar Akun : " << endl;
    cout << "| index |  Username  |  password  |" << endl;
    for(int i = 0; i < 26; i++){
        if(dataAkun[i].username != "" && dataAkun[i].password != "" ){
            cout << "| " << right << setw(3) << i << setw(2) << "" << " |  " << left << setw(8) << dataAkun[i].username << "  |  " << left << setw(8) << dataAkun[i].password << "  |" << endl;
        } else{
            cout << "| " << right << setw(3) << i << setw(2) << "" << " |  --------  |  --------  |" << endl;
        }

    }
}

// view Daftar
void viewDaftar(){
    string username, password;
    cout << "\n== MENU DAFTAR ==" << endl;
    cout << "Masukkan username & password (maksimal 8 karakter)" << endl;
    cout << "Isi username anda : "; cin >> setw(8) >> username;
    cout << "Isi password anda : "; cin >> setw(8) >> password;

    if(cekDaftar(username, password)){
        cout << "Akun berhasil terdaftar!!!" << endl;
    } else{
        cout << "Akun gagal terdaftar!!!" << endl;
    }
}

// view tambah akun
void viewTambahAkun(){
    string username, password;
    cout << "\n== MENU TAMBAH AKUN ==" << endl;
    cout << "Masukkan username & password (maksimal 8 karakter)" << endl;
    cout << "Isi username anda : "; cin >> setw(8) >> username;
    cout << "Isi password anda : "; cin >> setw(8) >> password;

    if(cekDaftar(username, password)){
        cout << "Akun berhasil terdaftar!!!" << endl;
    } else{
        cout << "Akun gagal terdaftar!!!" << endl;
    }
}

// view hapus akun
void viewHapusAkun(){
    int index;
    cout << "\n== MENU HAPUS AKUN ==" << endl;
    cout << "Isi index : "; cin >> index;

    if(cekHapus(index)){
        cout << "Akun berhasil dihapus!!!" << endl;
    } else{
        cout << "Akun gagal dihapus!!!" << endl;
    }
}

// view menu login
void viewMenuLogin(){
    while(true){
        string pilihan;
        cout << "\n== MENU LOGIN ==" << endl;
        cout << "Menu Pilihan :" << endl;
        cout << "1. Tambah Akun" << endl;
        cout << "2. Hapus Akun" << endl;
        cout << "3. Lihat Data Akun" << endl;
        cout << "4. Logout" << endl;
        cout << "Pilih Menu [1/2/3/4] : ";
        cin >> pilihan;

        if(pilihan == "1"){
            viewTambahAkun();
        } else if(pilihan == "2"){
            viewHapusAkun();
        } else if(pilihan == "3"){
            printDataAkun();
        } else if(pilihan == "4"){
            cout << "Anda Berhasil Logout" << endl;
            break;
        } else{
            cout << "Pilihan tidak tersedia!!!" << endl;
        }
    }
}

// view login
void viewLogin(){
    string username, password;
    cout << "\n== VIEW LOGIN ==" << endl;
    cout << "Masukkan Username & Password" << endl;
    cout << "Isi Username Anda : "; cin >> username;
    cout << "Isi Password Anda : "; cin >> password;

    if(cekLogin(username, password) == true){
        cout << "\nLogin Berhasil!!!" << endl;
        viewMenuLogin();
    } else{
        cout << "\nLogin Gagal!!!" << endl;
    }
}

// tampilan utama
void welcome(){
    while(true){
        string pilihan;
        cout << "\n\n== PROGRAM LOGIN SEDERHANA DENGAN HASHING ==" << endl;
        cout << "Menu Pilihan :" << endl;
        cout << "1. Daftar" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih Menu [1/2/3] : ";
        cin >> pilihan;

        if(pilihan == "1"){
            viewDaftar();
        } else if(pilihan == "2"){
            viewMenuLogin();
        } else if(pilihan == "3"){
            cout << "Terimakasih sudah menggunakan aplikasi login sederhana" << endl;
            break;
        } else{
            cout << "Pilihan tidak tersedia!!!" << endl;
        }
    }
}

int main(){
    welcome();
    return 0;
}