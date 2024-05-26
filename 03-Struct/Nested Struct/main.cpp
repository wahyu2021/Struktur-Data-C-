#include <iostream>

// struct
struct Identitas_Mahasiswa
{
    std::string nama, NIM, tgl_lahir, jurusan, kls, hobi[3];
    struct Alamat_mhs
    {
        std::string jalan;
        std::string nama_gang;
        int nmr_blk, rt, rw;
    };
};

struct Kampus
{
    std::string nama_kampus, alamat_kampus;
    int tahun_berdiri;
};

void garis()
{
    std::cout << "=====================================================" << std::endl;
}

int main()
{
    Identitas_Mahasiswa mahasiswa[3];
    Kampus myKampus[3];

    mahasiswa[0].nama = "Wahyu Wahid Nugroho";
    mahasiswa[0].NIM = "062340833133";
    mahasiswa[0].tgl_lahir = "31 Maret 2005";
    mahasiswa[0].jurusan = "Manajemen Informatika";
    mahasiswa[0].kls = "2MIC";
    mahasiswa[0].hobi[0] = "Basket";
    mahasiswa[0].hobi[1] = "Ngoding";
    mahasiswa[0].hobi[2] = "Main gitar";
    myKampus[0] = {"Polsri", "Jalan Sungai Sahang", 1988};


    std::cout << "Nama          :" << mahasiswa[0].nama << std::endl;
    std::cout << "NIM           :" << mahasiswa[0].NIM << std::endl;
    std::cout << "Tanggal Lahir :" << mahasiswa[0].tgl_lahir << std::endl;
    std::cout << "Jurusan       :" << mahasiswa[0].jurusan << std::endl;
    std::cout << "Kelas         :" << mahasiswa[0].kls << std::endl;
    std::cout << "Hobi          :1. " << mahasiswa[0].hobi[0] << std::endl;
    std::cout << "               2. " << mahasiswa[0].hobi[1] << std::endl;
    std::cout << "               3. " << mahasiswa[0].hobi[2] << std::endl;
    std::cout << "Kampus:\n";
    std::cout << "1. Nama          : " << myKampus[0].nama_kampus << std::endl;  
    std::cout << "2. Alamat Kampus : " << myKampus[0].alamat_kampus << std::endl;  
    std::cout << "3. Tahun Berdiri : " << myKampus[0].tahun_berdiri << std::endl;  
    garis();    
    
    mahasiswa[1].nama = "Dhea Fasya Nadhira";
    mahasiswa[1].NIM = "062340833115";
    mahasiswa[1].tgl_lahir = "28 Mei 2004";
    mahasiswa[1].jurusan = "Manajemen Informatika";
    mahasiswa[1].kls = "2MIC";
    mahasiswa[1].hobi[0] = "Lari";
    mahasiswa[1].hobi[1] = "Renang";
    mahasiswa[1].hobi[2] = "Ngedit";
    myKampus[1] = {"Polsri", "Jalan Sungai Sahang", 1988};

    std::cout << "Nama          :" << mahasiswa[1].nama << std::endl;
    std::cout << "NIM           :" << mahasiswa[1].NIM << std::endl;
    std::cout << "Tanggal Lahir :" << mahasiswa[1].tgl_lahir << std::endl;
    std::cout << "Jurusan       :" << mahasiswa[1].jurusan << std::endl;
    std::cout << "Kelas         :" << mahasiswa[1].kls << std::endl;
    std::cout << "Hobi          :1. " << mahasiswa[1].hobi[0] << std::endl;
    std::cout << "               2. " << mahasiswa[1].hobi[1] << std::endl;
    std::cout << "               3. " << mahasiswa[1].hobi[2] << std::endl;
    std::cout << "Kampus:\n";
    std::cout << "1. Nama          : " << myKampus[1].nama_kampus << std::endl;  
    std::cout << "2. Alamat Kampus : " << myKampus[1].alamat_kampus << std::endl;  
    std::cout << "3. Tahun Berdiri : " << myKampus[1].tahun_berdiri << std::endl; 
    garis();
    
    mahasiswa[2] = {"Asep", "02382138129", "23 Maret 1999", "Manajemen Informatika", "2MIC", {"Makan", "Lari", "Ngemil"}};
    myKampus[2] = {"Polsri", "Jalan Sungai Sahang", 1988};

    std::cout << "Nama          :" << mahasiswa[2].nama << std::endl;
    std::cout << "NIM           :" << mahasiswa[2].NIM << std::endl;
    std::cout << "Tanggal Lahir :" << mahasiswa[2].tgl_lahir << std::endl;
    std::cout << "Jurusan       :" << mahasiswa[2].jurusan << std::endl;
    std::cout << "Kelas         :" << mahasiswa[2].kls << std::endl;
    std::cout << "Hobi          :1. " << mahasiswa[2].hobi[0] << std::endl;
    std::cout << "               2. " << mahasiswa[2].hobi[1] << std::endl;
    std::cout << "               3. " << mahasiswa[2].hobi[2] << std::endl;
    std::cout << "Kampus:\n";
    std::cout << "1. Nama          : " << myKampus[2].nama_kampus << std::endl;  
    std::cout << "2. Alamat Kampus : " << myKampus[2].alamat_kampus << std::endl;  
    std::cout << "3. Tahun Berdiri : " << myKampus[2].tahun_berdiri << std::endl; 
    garis();

    return 0;
}

