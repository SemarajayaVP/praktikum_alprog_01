#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void judul();
int program();
double check();


int main(){

	judul();
	program();
}


void judul(){


	printf("=================================\n");
	printf("|      Program Bangun Ruang     |\n");
	printf("=================================\n");
	printf("|                               |\n");
	printf("|                               |\n");
	printf("|             From:             |\n");
	printf("|          Kelompok 1           |\n");
	printf("|                               |\n");
	printf("|                               |\n");
	printf("|                               |\n");
	printf("|                               |\n");
	printf("|                               |\n");
	printf("=================================\n");
	getch();
	system("cls");
}


int program(){

 int lama,bunga,pinjaman, ulang;
 double angsuran,bunga_per_bulan,angsuran_per_bulan,total_bunga=0,total_angsuran=0;

 printf("Pokok Pinjaman : ");
 pinjaman=check();

 printf("Besar Bunga    : ");
 bunga=check();

 printf("Lama Pinjaman  : ");
 lama=check();


 printf("=============================================================================\n");

 printf(" Bulan     Bunga          Angsuran Pokok          Angsuran Perbulan     \n");



 for(int i=1;i<=lama;i++){



 angsuran=pinjaman/lama;

 bunga_per_bulan= (pinjaman-((i-1)*angsuran)) * bunga/12;

 total_bunga += bunga_per_bulan;
 total_angsuran += angsuran+bunga_per_bulan/100;


 printf("\n  %d      Rp. %.2f         Rp. %.2f               Rp. %.2f     ", i, bunga_per_bulan/100, angsuran, angsuran+bunga_per_bulan/100);


 }

 printf("\n===========================================================================\n");

 printf("Total Bunga     : %.2f\n", total_bunga/100);
 printf("Total Angsuran  : %.2f", total_angsuran);

 printf("\nIngin Menghitung Lagi? (Pilih 1 untuk mengulang || Pilih 2 untuk keluar): ");
 ulang=check();
 if (ulang == 1){
    system ("cls"); //UNTUK MEMBERSIHKAN LAYAR
	program(); // MEMANGGIL FUNGSI PROGRAM LAGI - JADI DIARAHKAN KE PROGRAM

 }
 else if(ulang == 2 ){
    system ("cls");
	printf("\n=================================================\n");
	printf("| Terima kasih telah menggunakan program kami!  |\n");
	printf("|                   By: Koko                    |\n");
	printf("=================================================\n");

 }

}

double check(){
	double input;
	char checkinput;
	int cek;

	cek=scanf("%lf%c", &input,&checkinput);

	if(cek!=2 || checkinput!='\n'){
		printf("inputan anda tidak sesuai kriteria!\n");
		printf("Masukkan angka bukan huruf: ");
		fflush(stdin);
		cek=1;
		return check();

	}
	else if(input<=0){
		printf("inputan anda tidak sesuai kriteria! \n");
		printf("Masukkan angka selain -/0 : ");
		fflush(stdin);
		cek=1;
		return check();
	}
	else{
		cek=0;
		fflush(stdin);
		return input;
	}

}