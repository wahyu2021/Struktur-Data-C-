#include <iostream>
#include <iomanip>
using namespace std;

struct Karyawan{
    char nama[14];
    int NIP;
    int jam;
} noKaryawan[10];

int gaji = 20000;

int pokok(int jam){
    return gaji*jam;
}

int lembur(int jam){
    if(jam > 7){
        return pokok(jam-7) * 1.5;
    } else{
        return 0;
    }
}

int makan(int jam){
    if(jam >= 8){
        return 5000;
    } else{
        return 0;
    }
}

int transport(int jam){
    if(jam >= 9){
        return 4000;
    } else{
        return 0;
    }
}

void input(){
    bool lanjut = true;
    char pilihan;
    int no = 0;
    cout << "Daftar Pegawai" << endl;
    while(lanjut && no < 10){
        cout << "Pegawai ke-" << no+1 << endl;
        cout << "NIP                : "; cin >> noKaryawan[no].NIP;
        cout << "Nama               : "; cin >> noKaryawan[no].nama;
        cout << "Jumlah Jam Kerja   : "; cin >> noKaryawan[no].jam;
        cout << endl;
        cout << "Lanjut [Y/N] : "; cin >> pilihan;

        while (pilihan != 'Y' && pilihan != 'y' && pilihan != 'N' && pilihan != 'n') { // && (dan) digunakan untuk kondisi yang benar
            cout << "Pilihan Tidak Ada!!!" << endl;
            cout << "Lanjut [Y/N]"; cin >> pilihan;
        }

        if(pilihan == 'Y' || pilihan == 'y'){
            lanjut = true;
            no++;
        }else if(pilihan == 'N' || pilihan == 'n'){
            lanjut = false;
        } else{
            cout << "Pilihan Tidak ada" << endl;
        }
        cout << endl;
    }
}

void display(){
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "NIP Nama           Gaji Pokok     Lembur     Uang Makan     Transport Lembur" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    for(int i = 0; i < 10; i++){
        cout << left << setw(3) << noKaryawan[i].NIP << " " << left << setw(14) << noKaryawan[i].nama << " " << left << setw(14) << pokok(noKaryawan[i].jam) << " " << left << setw(10) << lembur(noKaryawan[i].jam) << " " << left << setw(14) << makan(noKaryawan[i].jam) << " " << left << setw(16) << transport(noKaryawan[i].jam) << endl;   
    }
}

int main(){
    input();
    display();

    return 0;
}