#include <iostream>
#include <math.h>
 
using namespace std;
 
void Jumlah();
void Kurang();
void Kali();
void Bagi();
void Mod();
 
int main(){
	 int operasi;
    char u;
     
    cout << " ===== Kalkulator Sederhana =====" << endl << endl;
q:  cout << " Pilih Operasi Aritmatika\n" << endl;
    cout << " 1. Penjumlahan" << endl;
    cout << " 2. Pengurangan" << endl;
    cout << " 3. Perkalian" << endl;
    cout << " 4. Pembagian" << endl;
    cout << " 5. Modulus" << endl;
    cout << " 0. Exit" << endl;
    cout << "\n Pilihan Anda : ";
    cin >> operasi;
    cout << " ==================================================" << endl;
    switch(operasi){
        case 1 :
            Jumlah();
            break;
        case 2 :
            Kurang();
            break;
        case 3 :
            Kali();
            break;
        case 4 :
            Bagi();
            break;
        case 5 :
            Mod();
            break;
        case 0 :
            exit(0);
            break;
        default :
            system("cls");
            cout << " Pilihan Anda Tidak Ada Dalam Menu. \n Silahkan Input Ulang \n" << endl;
            goto q;
            break;
    }
    cout << endl;
    cout << " ==================================================" << endl;
    cout << " Tekan Y jika Ingin Menginput Ulang "<<endl;
	cout << " Atau Tekan Huruf Lainnya Untuk Keluar " <<endl;
    cin >> u;
    if(u == 'Y' || u == 'y'){
        system("cls");
        goto q;
    } else {
        exit(0);
    }
    return 0;
}

void Jumlah(){
    float a, b;
    float hasil;
    cout << " Penjumlahan\n\n";
    cout << " Masukkan Bilangan Pertama : "; cin >> a;
    cout << " Masukkan Bilangan Kedua : "; cin >> b;
    hasil = a+b;
    cout << " Hasil Penghitungan : " << hasil;
}
 
void Kurang(){
    float a, b;
    float hasil;
    cout << " Pengurangan\n\n";
    cout << " Masukkan Bilangan Pertama : "; cin >> a;
    cout << " Masukkan Bilangan Kedua : "; cin >> b;
    hasil = a-b;
    cout << " Hasil Penghitungan : " << hasil;
}
 
void Kali(){
    float a, b;
    float hasil;
    cout << " Perkalian\n\n";
    cout << " Masukkan Bilangan Pertama : "; cin >> a;
    cout << " Masukkan Bilangan Kedua : "; cin >> b;
    hasil = a*b;
    cout << " Hasil Penghitungan : " << hasil;
}
 
void Bagi(){
    float a, b;
    float hasil;
    cout << " Pembagian\n\n";
    cout << " Masukkan Bilangan Pertama : "; cin >> a;
    cout << " Masukkan Bilangan Kedua : "; cin >> b;
    hasil = a/b;
    cout << " Hasil Penghitungan : " << hasil;
}
 
void Mod(){
    int a, b;
    float hasil = 0;
    cout << " Modulus\n\n";
    cout << " Masukkan Bilangan : ";
    cin >> a;
    cout << " Masukkan Bilangan Pembagi : ";
    cin >> b;
    hasil = a%b;
    cout << " Hasil Penghitungan : " << hasil;
}


