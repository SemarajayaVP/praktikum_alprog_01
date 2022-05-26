#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void validasikehadiran();

void nilaiAkhir();

float hitungTotalNilaiTugas(float tugas1, float tugas2, float tugas3);

float hitungNilaiAngka(float kuis, float uts, float uas, float totalnilai_tugas, int absensi);

int validasi(char userInput[100]);

int clean();

int main(){
	char pilihan, enterCheck;
	system("cls");

        printf("\t\t+-------------------------------------------+\n");
        printf("\t\t|--         PROGRAM NILAI AKHIR           --|\n");
	printf("\t\t+-------------------------------------------+\n");
	printf("\t\t|==============[    MENU     ]==============|\n");
	printf("\t\t|            1. Cek Nilai Akhir             |\n");
	printf("\t\t|            2. Tutup Program               |\n");
        printf("\t\t+-------------------------------------------+\n");


	do{
		printf("\t\tMasukkan pilihan: ");
		if(((scanf(" %c%c", &pilihan, &enterCheck)) != 2 || enterCheck != '\n') && clean()){
			printf("\t\tInputan salah! Mohon hanya memasukkan angka dari 1 hingga 2\n\n");
		}
		else{
			if(pilihan == '1'){
				nilaiAkhir();
				break;
			}
			else if(pilihan == '2'){
				exit(0);
				break;
			}
			else{
				printf("\t\tInputan salah! Mohon hanya memasukkan angka dari 1 hingga 2\n\n");
			}
		}
	}while(1);

	return 0;
}

void nilaiAkhir(){
	char userInput[100]; // untuk menampung sementara inputan user yang nantinya apabila inputan tersebut valid akan dikonversi menjadi float
	char pilihan, enterCheck; // variabel pilihan untuk menampung hasil pilihan menu oleh user. variabel enterCheck untuk validasi inputan
	float tugas1, tugas2, tugas3, kuis, uts, uas, totalnilai_tugas, nilaiAngka;
	int absensi;
	/* mendeklarasikan beberapa variabel dengan tipe data float:
	   variabel tugas 1 - tugas 3 => untuk menampung nilai-nilai tugas dan dipergunakan untuk menghitung nilai akhir nanti
	   variabel kuis => untuk menampung nilai kuis dan dipergunakan untuk menghitung nilai akhir nanti
	   variabel uts => untuk menampung nilai UTS dan dipergunakan untuk menghitung nilai akhir nanti
	   variabel uas => untuk menampung nilai UAS dan dipergunakan untuk menghitung nilai akhir nanti
	   variabel absensi => untuk menampung absensi berapa kali dan dipergunakan untuk menghitung nilai uas serta nilai akhir nanti
	   variabel nilaiAngka => untuk menampung nilai angka setelah perhitungan  */

	system("cls");

	printf("\t\t+-------------------------------------------+\n");
	printf("\t\t|            PROGRAM NILAI AKHIR            |\n");
        printf("\t\t+-------------------------------------------+\n");



	do{
		printf("\t\tMasukkan jumlah kehadiran   : ");
		scanf(" %[^\n]s", &userInput); // meminta inputan absensi dan menyimpannya di dalam variabel userInput

		if(validasiAbsensi(userInput) == 1){ // apabila nilai dari userInput valid maka
			absensi = atoi(userInput); // konversikan nilai dari userInput menjadi integer dan inisialisasi ke dalam variabel absensi
			if(absensi < 0 || absensi > 15){ // apabila absensi kurang dari 0 danlebih dari 15 maka
				printf("\t\tInputan salah! absen minimal 0 max 15\n\n"); // tampilkan error
			}
			else{ // selain dari itu maka
				break; // keluar dari perulangan
			}
		}
		else{ // apabila tidak valid maka
			printf("\t\tInputan salah! Mohon hanya memasukkan angka\n\n"); // tampilkan error
		}
	}while(1);

         if(absensi==0)
        {
            printf("\n\t\t\t      \xaf\xf9\xae\n");
            printf("\t\t      Total Jumlah Kehadiran    : %d/15\n", absensi);
            printf("\t\t\xb2============================================\xb2\n");
            printf("\t\t\xba\t   Nilai Akhir: (E)         \xba\n");
            printf("\t\t\xb2============================================\xb2\n\n");
        }else{
	do{
		printf("\t\tMasukkan nilai Tugas 1: ");
		scanf(" %[^\n]s", &userInput); // meminta inputan nilai tugas dan menyimpannya di dalam variabel userInput

		if(validasi(userInput) == 1){ // apabila nilai dari userInput valid maka
			tugas1 = atof(userInput); // konversikan nilai dari userInput menjadi float dan inisialisasi ke dalam variabel tugas
			if(tugas1 > 100){ // apabila nilai tugas lebih dari 100 maka
				printf("\t\tInputan salah! inputan tidak boleh lebih dari 100\n\n"); // tampilkan error
			}
			else{ // selain dari itu maka
				break; // keluar dari perulangan
			}
		}
		else{ // apabila tidak valid maka
			printf("\t\tInputan salah! Mohon hanya memasukkan angka\n\n"); // tampilkan error
		}
	}while(1);

	do{
		printf("\t\tMasukkan nilai Tugas 2: ");
		scanf(" %[^\n]s", &userInput); // meminta inputan nilai tugas dan menyimpannya di dalam variabel userInput

		if(validasi(userInput) == 1){ // apabila nilai dari userInput valid maka
			tugas2 = atof(userInput); // konversikan nilai dari userInput menjadi float dan inisialisasi ke dalam variabel tugas
			if(tugas2 > 100){ // apabila nilai tugas lebih dari 100 maka
				printf("\t\tInputan salah! inputan tidak boleh lebih dari 100\n\n"); // tampilkan error
			}
			else{ // selain dari itu maka
				break; // keluar dari perulangan
			}
		}
		else{ // apabila tidak valid maka
			printf("\t\tInputan salah! Mohon hanya memasukkan angka.\n\n"); // tampilkan error
		}
	}while(1);

	do{
		printf("\t\tMasukkan nilai Tugas 3: ");
		scanf(" %[^\n]s", &userInput); // meminta inputan nilai tugas dan menyimpannya di dalam variabel userInput

		if(validasi(userInput) == 1){ // apabila nilai dari userInput valid maka
			tugas3 = atof(userInput); // konversikan nilai dari userInput menjadi float dan inisialisasi ke dalam variabel tugas
			if(tugas3 > 100){ // apabila nilai tugas lebih dari 100 maka
				printf("\t\tInputan salah! inputan tidak boleh lebih dari 100.\n\n"); // tampilkan error
			}
			else{ // selain dari itu maka
				break; // keluar dari perulangan
			}
		}
		else{ // apabila tidak valid maka
			printf("\t\tInputan salah! Mohon hanya memasukkan angka.\n\n"); // tampilkan error
		}
	}while(1);

	do{
		printf("\t\tMasukkan nilai Kuis: ");
		scanf(" %[^\n]s", &userInput); // meminta inputan nilai kuis dan menyimpannya di dalam variabel userInput

		if(validasi(userInput) == 1){ // apabila nilai dari userInput valid maka
			kuis = atof(userInput); // konversikan nilai dari userInput menjadi float dan inisialisasi ke dalam variabel tugas
			if(kuis > 100){ // apabila nilai kuis lebih dari 100 maka
				printf("\t\tInputan salah! inputan tidak boleh lebih dari 100.\n\n"); // tampilkan error
			}
			else{ // selain dari itu maka
				break; // keluar dari perulangan
			}
		}
		else{ // apabila tidak valid maka
			printf("\t\tInputan salah! Mohon hanya memasukkan angka.\n\n"); // tampilkan error
		}
	}while(1);

	do{
		printf("\t\tMasukkan nilai UTS: ");
		scanf(" %[^\n]s", &userInput); // meminta inputan nilai UTS dan menyimpannya di dalam variabel userInput

		if(validasi(userInput) == 1){ // apabila nilai dari userInput valid maka
			uts = atof(userInput); // konversikan nilai dari userInput menjadi float dan inisialisasi ke dalam variabel uts
			if(uts > 100){ // apabila nilai uts lebih dari 100 maka
				printf("\t\tInputan salah! inputan tidak boleh lebih dari 100.\n\n"); // tampilkan error
			}
			else{ // selain dari itu maka
				break; // keluar dari perulangan
			}
		}
		else{ // apabila tidak valid maka
			printf("\t\tInputan salah! Mohon hanya memasukkan angka.\n\n"); // tampilkan error
		}
	}while(1);

	do{
        if(absensi < 12){
        uas = 0;
            printf("\t\t\n------------------------------------------------------");
          	printf("\t\t\n>> Maaf, jumlah kehadiran Anda kurang dari 12 kali. <<\n");
			printf("\t\tNilai UAS     : %.2f\n", uas);
       		}else{
		printf("\t\tMasukkan nilai UAS: ");
		scanf(" %[^\n]s", &userInput); // meminta inputan nilai UAS dan menyimpannya di dalam variabel userInput

		if(validasi(userInput) == 1){ // apabila nilai dari userInput valid maka
			uas = atof(userInput); // konversikan nilai dari userInput menjadi float dan inisialisasi ke dalam variabel uas
			if(uas > 100){ // apabila nilai uas lebih dari 100 maka
				printf("\t\tInputan salah! inputan tidak boleh lebih dari 100.\n\n"); // tampilkan error
			}
			else{ // selain dari itu maka
				break; // keluar dari perulangan
			}
		}
		else{ // apabila tidak valid maka
			printf("\t\tInputan salah! Mohon hanya memasukkan angka.\n\n"); // tampilkan error

		}
	}
}
while(0);

        totalnilai_tugas = hitungTotalNilaiTugas(tugas1, tugas2, tugas3);
		nilaiAngka = hitungNilaiAngka(kuis, uts, uas, totalnilai_tugas, absensi);
		/* memanggil fungsi hitungNilaiAngka untuk menghitung nilai angka berdasarkan nilai tugas 1-3, kuis, UTS, dan UAS yang diinputkan
		   nilai yang dikembalikan oleh fungsi akan diinisialisasi ke dalam variabel nilaiAngka */
		   system("cls");
	            printf("\n\n\t\t\xb2============================================\xb2\n");
	            printf("\t\t\xba\t\t\xaf\xf9Nilai Akhir\xf9\xae\t\t     \xba\n");
	            printf("\t\t\xb2============================================\xb2\n");
	            printf("\t\t      Total Jumlah Kehadiran    : %d/15\n", absensi);
	            printf("\t\t      Total Nilai Tugas         : %.2f\n", totalnilai_tugas);
	            printf("\t\t      Total Nilai Kuis          : %.2f\n", kuis);
	            printf("\t\t      Total Nilai UTS           : %.2f\n", uts);
	            printf("\t\t      Total Nilai UAS           : %.2f\n", uas);
	            printf("\t\t\xb2============================================\xb2\n");
	            printf("\t\t      Nilai Akhir (Angka) : %.2f", nilaiAngka);

		if(nilaiAngka >= 0 && nilaiAngka < 45){ // apabila nilaiAngka lebih besar sama dengan 0 dan kurang dari 45 maka
			printf(" (E)", nilaiAngka); // tampilkan nilai akhir
		}
		else if(nilaiAngka >= 45 && nilaiAngka < 55){ // apabila nilaiAngka lebih besar sama dengan 45 dan kurang dari 55 maka
			printf(" (D)", nilaiAngka); // tampilkan nilai akhir
		}
		else if(nilaiAngka >= 55 && nilaiAngka < 65){ // apabila nilaiAngka lebih besar sama dengan 55 dan kurang dari 65 maka
			printf(" (C)", nilaiAngka); // tampilkan nilai akhir
		}
		else if(nilaiAngka >= 65 && nilaiAngka < 80){ // apabila nilaiAngka lebih besar sama dengan 65 dan kurang dari 80 maka
			printf(" (B)", nilaiAngka); // tampilkan nilai akhir
		}
		else if(nilaiAngka >= 80 && nilaiAngka <= 100){ // apabila nilaiAngka lebih besar sama dengan 80 dan kurang dari sama dengan 100 maka
			printf(" (A)", nilaiAngka); // tampilkan nilai akhir
		}

	printf("\n\n\t\tApakah Anda ingin mengulang menghitung nilai akhir?\n\t\tTekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.");
	do{
		printf("\n\t\tMasukkan pilihan: ");
		if(((scanf(" %c%c", &pilihan, &enterCheck)) != 2 || enterCheck != '\n') && clean()){ // meminta inputan pilihan untuk mengulang program atau tidak sekaligus divalidasi
			printf("\t\tInputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n"); // menampilkan error apabila inputan salah
		}
		else{
			if(pilihan == 'Y' || pilihan == 'y'){ // apabila ingin mengulang maka
				nilaiAkhir(); // panggil lagi prosedur nilaiAkhir
				break; // keluar dari perulangan
			}
			else if(pilihan == 'N' || pilihan == 'n'){ // apabila ingin kembali maka
				main(); // kembali lagi ke menu awal
				break; // keluar dari perulangan
			}
			else if(pilihan == 'K' || pilihan == 'k'){ // apabila ingin menutup program maka
				exit(0); // menutup program
				break; // keluar dari perulangan
			}
			else{ // selain dari itu maka
				printf("\t\tInputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan K untuk menutup program.\n\n"); // menampilkan error apabila inputan salah
			}
		}
	}while(1);
    }
}

float hitungTotalNilaiTugas(float tugas1, float tugas2, float tugas3){
	float totalnilai_tugas;

	totalnilai_tugas = ((tugas1+tugas2+tugas3)/3)*20/100;
	return  totalnilai_tugas;
}

float hitungNilaiAngka(float kuis, float uts, float uas, float totalnilai_tugas, int absensi)
{
	float nilaiAngka;

   	kuis = kuis*15/100;
    uts	= uts*30/100;
    uas	= uas*30/100;
    nilaiAngka = (absensi*5/15) + totalnilai_tugas + kuis + uts + uas; // setelah perhitungan selesai dilakukan, maka fungsi akan mengembalikan hasil penghitungan tersebut
	return nilaiAngka;
}

int validasi(char userInput[100]){
	int valid=1, dotCount=0, numberCount=0,i;
	/* mendeklarasikan beberapa variabel dengan tipe data integer:
	   variabel valid => merupakan status validasi, apabila bernilai 1 maka inputan valid. apabila bernilai 0 maka inputan tidak valid
	   variabel dotCount => untuk menghitung jumlah karakter titik yang terdapat pada inputan
	   variabel numberCount => untuk menghitung jumlah karakter angka yang terdapat pada inputan
	   variabel i => untuk menampung nilai iterasi pada perulangan for */

	for(i=0; i<strlen(userInput); i++){ // melakukan perulangan untuk setiap karakter yang terdapat pada inputan
		if(userInput[i] >= '0' && userInput[i] <= '9'){ // apabila karakter pada index ke-i merupakan angka maka
			numberCount++; // tambahkan nilai 1 ke variabel numberCount
		}
		else if(userInput[i] == '.'){ // apabila karakter pada index ke-i merupakan karakter titik maka
			dotCount++; // tambahkan nilai 1 ke variabel dotCount
		}
		else{ // selain dari itu maka
			valid = 0; // inputan tidak valid
		}
	}

	if(valid != 0){ // apabila inputan masih valid maka
		if(dotCount != 0 && dotCount != 1){ // apabila nilai dotCount bukan 0 dan juga bukan 1 maka
			valid = 0; // inputan tidak valid
		}
		else if(numberCount == 0 || userInput[0] == '.'){ // apabila nilai numberCount sama dengan 0 atau karakter pertama pada inputan adalah karakter titik maka
			valid = 0; // inputan tidak valid
		}
	}

	return valid; // mengembalikan nilai pada variabel valid
}

int validasiAbsensi(char userInput[100]){
	int valid=1, dotCount=0, numberCount=0,i;
	/* mendeklarasikan beberapa variabel dengan tipe data integer:
	   variabel valid => merupakan status validasi, apabila bernilai 1 maka inputan valid. apabila bernilai 0 maka inputan tidak valid
	   variabel dotCount => untuk menghitung jumlah karakter titik yang terdapat pada inputan
	   variabel numberCount => untuk menghitung jumlah karakter angka yang terdapat pada inputan
	   variabel i => untuk menampung nilai iterasi pada perulangan for */

	for(i=0; i<strlen(userInput); i++){ // melakukan perulangan untuk setiap karakter yang terdapat pada inputan
		if(userInput[i] >= '0' && userInput[i] <= '9'){ // apabila karakter pada index ke-i merupakan angka maka
			numberCount++; // tambahkan nilai 1 ke variabel numberCount
		}
		else if(userInput[i] == '.'){ // apabila karakter pada index ke-i merupakan karakter titik maka
			dotCount++; // tambahkan nilai 1 ke variabel dotCount
		}
		else{ // selain dari itu maka
			valid = 0; // inputan tidak valid
		}
	}

	if(valid != 0){ // apabila inputan masih valid maka
		if(dotCount != 0){ // apabila nilai dotCount bukan 0 dan juga bukan 1 maka
			valid = 0; // inputan tidak valid
		}
		else if(numberCount == 0 || userInput[0] == '.'){ // apabila nilai numberCount sama dengan 0 atau karakter pertama pada inputan adalah karakter titik maka
			valid = 0; // inputan tidak valid
		}
	}

	return valid; // mengembalikan nilai pada variabel valid
}

int clean(){
	while(getchar() != '\n'); // apabila saat validasi inputan dilakukan terdapat kesalahan inputan,
	// maka fungsi ini akan membersihkan kesalahan inputan tersebut agar variabel dapat menampung inputan yang baru
	return 1;
}
