#include <iostream>
#include <string>
using namespace std;

int luas(int a)
{
	return a * a;
}

int main()
{
	string nama = "Dhea Fasya Nadhira";

	cout << "Nama: " << nama << endl;
	cout << "Alamat memori: " << &nama << endl;

	string *nama2 = &nama;
	*nama2 = "Wahyu Wahid Nugroho";
	cout << "==========================================" << endl;
	cout << "Nama2: " << *nama2 << endl;
	cout << "Alamat memori2: " << nama2 << endl;
	cout << "==========================================" << endl;
	cout << "Nama: " << nama << endl;
	cout << "Alamat memori: " << &nama << endl;

	

	return 0;
}