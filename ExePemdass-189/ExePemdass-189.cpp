#include <iostream>
using namespace std;
class bidangDatar {
private:
	int x; //variabel untuk menyimpan input dari lingkaran maupun bujursangkar
public:
	bidangDatar() { //constructor
		x = 0;
	}
	virtual void input() {} // fungsi yang menerima input dan mengirim input melalui fungsi setX untuk disimpan di x
	virtual float Luas(int a) { return 0; } //fungsi untuk menghitung luas
	virtual float Keliling(int a) { return 0; } //fungsi untuk menghitung keliling
	void setX(int a) { //fungsi untuk memberi/mengirim nilai pada x
		this->x = a;
	}
	int getX() { //fungsi untuk membaca/mengambil nilai dalam x
		return x;
	}
};

class Lingkaran :public bidangDatar { 
public:
	void input() {
		int r;
		cout << "Masukkan jari-jari: ";
			cin >> r;
			setX(r);

	}

	float Luas() {
		float r = getX();
		return 3.14 * r * r;
	}

	float Keliling() {
		float r = getX();
		return 2 * 3.14 * r;
	}
};

class Bujursangkar :public bidangDatar {
public:
	void input() {
		int sisi;
		cout << "Masukkan panjang sisi bujursangkar: ";
		cin >> sisi;
		setX(sisi);
	}

	float Luas() {
		float sisi = getX();
		return sisi * sisi;
	}

	float Keliling() {
		float sisi = getX();
		return 4 * sisi;
	}
};

int main() {
	bidangDatar* objek;
	Lingkaran lingkaran;
	Bujursangkar bujursangkar;

	objek = &lingkaran; // Polymorphism, objek bertipe pointer ke objek Lingkaran
	objek->input(); // Memanggil fungsi input dari class Lingkaran
	cout << "Luas Lingkaran: " << objek->Luas(113.04) << endl; // Memanggil fungsi Luas dari class Lingkaran melalui pointer
	cout << "Keliling Lingkaran: " << objek->Keliling(37.68) << endl; // Memanggil fungsi Keliling dari class Lingkaran melalui pointer

	objek = &bujursangkar; // Polymorphism, objek bertipe pointer ke objek Bujursangkar
	objek->input(); // Memanggil fungsi input dari class Bujursangkar
	cout << "Luas Bujursangkar: " << objek->Luas(113.04) << endl; // Memanggil fungsi Luas dari class Bujursangkar melalui pointer
	cout << "Keliling Bujursangkar: " << objek->Keliling(37.68) << endl; // Memanggil fungsi Keliling dari class Bujursangkar melalui pointer

	return 0;
};

