#include <iostream>

// struct
struct Identitas_Mahasiswa
{
    std::string nama;
    std::string NIM;
    std::string tgl_lahir;
    std::string jurusan;
    std::string kls;
    std::string hobi[3];
} mahasiswa1,mahasiswa2;

void garis(){
    std::cout << "=====================================================" << std::endl;
}

int main()
{
    mahasiswa1.nama = "Wahyu Wahid Nugroho";
    mahasiswa1.NIM = "062340833133";
    mahasiswa1.tgl_lahir = "31 Maret 2005";
    mahasiswa1.jurusan = "Manajemen Informatika";
    mahasiswa1.kls = "2MIC";
    mahasiswa1.hobi[0] = "Basket";
    mahasiswa1.hobi[1] = "Ngoding";
    mahasiswa1.hobi[2] = "Main gitar";


    std::cout << "Nama          :" << mahasiswa1.nama << std::endl;
    std::cout << "NIM           :" << mahasiswa1.NIM << std::endl;
    std::cout << "Tanggal Lahir :" << mahasiswa1.tgl_lahir << std::endl;
    std::cout << "Jurusan       :" << mahasiswa1.jurusan << std::endl;
    std::cout << "Kelas         :" << mahasiswa1.kls << std::endl;
    std::cout << "Hobi          :1. " << mahasiswa1.hobi[0] << std::endl;
    std::cout << "               2. " << mahasiswa1.hobi[1] << std::endl;
    std::cout << "               3. " << mahasiswa1.hobi[2] << std::endl;

    garis();    
    
    mahasiswa2.nama = "Dhea Fasya Nadhira";
    mahasiswa2.NIM = "062340833115";
    mahasiswa2.tgl_lahir = "28 Mei 2004";
    mahasiswa2.jurusan = "Manajemen Informatika";
    mahasiswa2.kls = "2MIC";
    mahasiswa2.hobi[0] = "Lari";
    mahasiswa2.hobi[1] = "Renang";
    mahasiswa2.hobi[2] = "Ngedit";

    std::cout << "Nama          :" << mahasiswa2.nama << std::endl;
    std::cout << "NIM           :" << mahasiswa2.NIM << std::endl;
    std::cout << "Tanggal Lahir :" << mahasiswa2.tgl_lahir << std::endl;
    std::cout << "Jurusan       :" << mahasiswa2.jurusan << std::endl;
    std::cout << "Kelas         :" << mahasiswa2.kls << std::endl;
    std::cout << "Hobi          :1. " << mahasiswa2.hobi[0] << std::endl;
    std::cout << "               2. " << mahasiswa2.hobi[1] << std::endl;
    std::cout << "               3. " << mahasiswa2.hobi[2] << std::endl;

    garis();
    
    Identitas_Mahasiswa mahasiswa3 = {"Asep", "02382138129", "23 Maret 1999", "Manajemen Informatika", "2MIC", {"Makan", "Lari", "Ngemil"}};
    std::cout << "Nama          :" << mahasiswa3.nama << std::endl;
    std::cout << "NIM           :" << mahasiswa3.NIM << std::endl;
    std::cout << "Tanggal Lahir :" << mahasiswa3.tgl_lahir << std::endl;
    std::cout << "Jurusan       :" << mahasiswa3.jurusan << std::endl;
    std::cout << "Kelas         :" << mahasiswa3.kls << std::endl;
    std::cout << "Hobi          :1. " << mahasiswa3.hobi[0] << std::endl;
    std::cout << "               2. " << mahasiswa3.hobi[1] << std::endl;
    std::cout << "               3. " << mahasiswa3.hobi[2] << std::endl;

    return 0;
}

