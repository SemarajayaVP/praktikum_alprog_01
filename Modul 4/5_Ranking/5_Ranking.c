#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mahasiswa{
    char nama[256];
	int nilai;
} Mahasiswa;

typedef struct list_mahasiswa{
	Mahasiswa mhs[100];
	int len;
} ListMahasiswa;

ListMahasiswa listMhs;

void urutkan(Mahasiswa *arr, int size);
void trim(char str[], char new_str[]);
void baca();
void cetak(void);
void simpanUrutan();
char exite();
void asistenin();
void asistenout();
void tampilan();

void tampilan(){
		printf("\t\t\t=======================================================================================\n");
        printf("\t\t\t                       PROGRAM SORTING DATA DI DALAM FILE TXT                         |\n");
		printf("\t\t\t=======================================================================================\n");
		printf("\t\t\t| 1.File asistenin.txt                                                                |\n");
		printf("\t\t\t| 2.File asistenout.txt                                                               |\n");
		printf("\t\t\t| 3.Keluar                                                                            |\n");
		printf("\t\t\t=======================================================================================\n");
		printf("\t\t\t| Masukkan pilihan(1/2/3) :                                                           |\n");
		printf("\t\t\t=======================================================================================\n");
}

int main(){
	Mahasiswa mhs; //pendeklrasian dari struct mahasiwa
	int pilihan;
	char dir[256];
    char xit;
	FILE *fs, *fd; //pendeklarasian operasi file dengan nama file fs fd dengan pointer
	
    tampilan();
    system("cls");
    do{
        system("cls");
		tampilan();
		pilihan=cek_menu();
		baca(dir);
          if(pilihan==1){
                system("cls");
                asistenin();
          }else if(pilihan==2){
                system("cls");
                asistenout();
          }else{
                exit(0);
          }
        printf("\n\t\t\t|apakah anda ingin kembali kembali ke menu awal\n\t\t\t|tekan Y jika ingin kembali ke menu awal \n\t\t\t|tekan [N/Y] jika ingin keluar :");
        xit= exite();
    }while(xit =='Y' || xit =='y');

	return 0;
}

void asistenin(){
    printf("\t\t\t===========================================\n");
    printf("\t\t\t| Program Sorting Data di dalam File txt  |\n");
    printf("\t\t\t===========================================\n");
	printf("\t\t\t| File asistenin.txt : \n\n                  |");
	cetak();
	printf("\t\t\t=============================================\n");
}

void asistenout(){
    printf("\t\t\t===========================================\n");
    printf("\t\t\t| Program Sorting Data di dalam File txt  |\n");
    printf("\t\t\t===========================================\n");
	urutkan(listMhs.mhs, listMhs.len);
	printf("\t\t\tFile asistenout.txt : \n\n");
	cetak();
	simpanUrutan();
	printf("\t\t\t=============================================\n");
}

//untuk membaca isi dari file
void baca(){
	FILE *fp = fopen("asistenin.txt", "r"); //menggunakan mode 'r' atau read
	int i = 0;
	char buff[256];
	int nilai;
	listMhs.len= 0;

	while(fgets (buff, 256, fp) != NULL){
        if(i % 2){
			sscanf(buff, "%d\n", &nilai);
			listMhs.mhs[listMhs.len].nilai = nilai;
			listMhs.len++;
		}else
			trim(buff, listMhs.mhs[listMhs.len].nama);
            i++;
	}
	fclose(fp);
}

//untuk mengurutkan nilai dari besar ke kecil
void urutkan(Mahasiswa *arr, int size){
    int i, j, x;
	Mahasiswa tmp;

	for (i = 1; i < size; i++){
		for(j = i-1; j >= 0; j--){
			if(arr[j+1].nilai > arr[j].nilai){
                tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				continue;
			}
			break;
		}
	}
}

//mengecek validasi dari operasi file
void trim(char str[], char new_str[]){
	int i, j = 0;

	for (i = 0; i < strlen(str); i++) {
		if(str[i] == '\n' || str[i] == '\t')
        continue;
		new_str[j] = str[i];
		j++;
	}
}

void cetak(void){
	int i;

	if(listMhs.len==0)
    printf("\n\t\t\tTidak Ada Data\n\n");
	for(i = 0; i < listMhs.len; i++){
		printf("\t%d. %s : %3d\n", i+1, listMhs.mhs[i].nama, listMhs.mhs[i].nilai);
	}
}

//untuk menyimpan urutan
void simpanUrutan(){
	FILE *fp = fopen("asistenout.txt", "w");
	int i;

    fprintf(fp, "Nilai Mata Kuliah Algoritma dan Pemrograman\n");
	for(i = 0; i < listMhs.len; i++)
    fprintf(fp, "%d. %s %3d\n", i+1, listMhs.mhs[i].nama, listMhs.mhs[i].nilai);
	fclose(fp);
}

//validasi
int valid_input(){
    char masukan[100];
    int i = 0;
    int belakang = 0;
    int isi_depan = 0;
    int isi_belakang = 0;
    int status = 0;
    int titik = 0;
    int salah = 0;
    int minus = 0;
    int hasil;
    scanf("%[^\n]", &masukan);
    fflush(stdin);
    while(masukan[i] != '\0'){
        if(masukan[i] == '.'){
            salah = 1;
            masukan[i] = '\0';
        }else if(masukan[i] == ' '){
            salah = 1;
            masukan[i] = '\0';
        }else if(masukan[i]>='0' && masukan[i]<='9' ||  masukan[0] == '-'){
            if(masukan[i] == '-'){
                minus=minus + 1;
                if(minus >1 || masukan[i+1]=='\0'){
                    salah=1;
                    masukan[i]='\0';
                }
            } else if(masukan[i]>='0' && masukan[i]<='9'){
                if(masukan[0]=='0'){
                    salah=1;
                    masukan[i]='\0';
                }else{
                    isi_depan = (isi_depan * 10) + (masukan[i] - 48);
                }
            }else{
                salah=1;
                masukan[i]='\0';
            }
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
        
    }//end while
    if(masukan[0]=='\0'){
        salah=1;
    }
    hasil = isi_depan;
    if(minus == 1){
        hasil = hasil - (hasil * 2);
    }
    if(salah == 1){
        printf("\t\t\ttidak valid! coba lagi: ");
    }else{
        return hasil;
    }
return valid_input();
}

//validasi menu
int cek_menu(){
    int input;
    while(1){
        input=valid_input();
        if(input>=1 && input<=3){
            return input;
        }
        printf("\t\t\ttidak valid!,coba lagi:");
    }
}


char exite(){
    char masukan[100];
    while(1){
        int i=0;
        int salah;
        scanf("%[^\n]",&masukan);
        fflush(stdin);
        if(masukan [i+1] =='\0'){
            if(masukan[0]=='y'  || masukan[0]=='Y' && masukan[1]=='\0'){
                return masukan[0];
            }else if (masukan[0]=='n'  || masukan [0]=='N' && masukan[1]=='\0'){
                return masukan[0];
            }else{
                salah=1;
            }
        }
        salah=1;
        if(salah==1){
            printf("\t\t\ttidak valid,coba lagi :");
        }
    }
}
