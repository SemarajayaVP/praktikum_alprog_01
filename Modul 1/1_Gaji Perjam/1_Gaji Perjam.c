#include <stdio.h>
#include <stdlib.h>

void home();
void hitunggaji();
void ulang();
float validasi();

//pendeklarasian struct
typedef struct{
    int harian_perjam;
    int lembur_perjam;
    int harian_jam;
    int lembur_jam;
    int lembur_gaji;
    int harian_gaji;
} Gaji;

//program utama
int main(){
    
	home();
	
    system("cls");
    
    return 0;
}

//tampilan home
void home(){
    float a;
    int jam;
    system("cls");
    printf("=================================================\n");
	printf("|                 SELAMAT DATANG                |\n");
	printf("|         PROGRAM PENGHITUNGAN GAJI HARIAN      |\n");
	printf("=================================================\n\n");
    printf("---------------------------------------------------\n");
    printf("==> Masukkan Jumlah Jam Kerja Anda : ");
    while(a!=jam || a<1 || a>24){
        a=validasi();
        jam=(int)a;
        if(a!=jam || a<1 || a>24){
           printf("\n================================================\n");
            printf("|             INPUTAN ANDA ERROR               |\n");
            printf("|         SILAHKAN MENGULANGI INPUTAN          |\n");
            printf("================================================\n");
            printf(">>> Silahkan Masukan Angka Yang Baru : ");
        }
    }
    
    system("cls");
    hitunggaji(jam);

}


void hitunggaji(int jam){
    Gaji g;
    int total;
    g.harian_perjam;
    g.lembur_perjam;
    g.harian_jam;
    g.lembur_jam;
    g.lembur_gaji;
    g.harian_gaji;
    
    g.harian_perjam=10625;
    g.lembur_perjam=10625*8;
    g.harian_jam=jam;
    
    if(g.harian_jam>8){
        g.lembur_jam=g.harian_jam-8;
        g.harian_jam=8;
        g.lembur_gaji=g.lembur_jam*g.lembur_perjam;
    }
    g.harian_gaji=g.harian_jam* g.harian_perjam;
    
    if(jam>8){
        total=g.harian_gaji+g.lembur_gaji;
    }
    
    if (jam>8){
	printf("=============================================================\n");
	printf("                     TOTAL GAJI HARIAN                \n");
	printf("=============================================================\n");
    printf("       GAJI HARIAN         |       GAJI LEMBUR          \n");
	printf("=============================================================\n");
    printf("  GAJI PER JAM : Rp. %d   | GAJI PER JAM : Rp. %d     \n", g.harian_perjam, g.lembur_perjam);
    printf("  JAM KERJA    : %d JAM       | JAM KERJA    : %d JAM         \n",g.harian_jam, g.lembur_jam);
    printf("  GAJI         : Rp. %d   | GAJI LEMBUR  : Rp. %d     \n",g.harian_gaji, g.lembur_gaji);
	printf("=============================================================\n");
    printf("  TOTAL GAJI                 |  Rp. %d                  \n",total);
	printf("=============================================================\n");
    }
    
    else if(jam<=8){
	printf("=============================================================\n");
	printf("                     TOTAL GAJI HARIAN                 \n");
	printf("=============================================================\n");
	printf("       	          GAJI HARIAN      		   \n");
	printf("=============================================================\n");
    printf("  GAJI PER JAM      : Rp. %d                    	     \n", g.harian_perjam);
    printf("  JAM KERJA         : %d JAM                        	      \n",g.harian_jam);
    printf("  GAJI              : Rp. %d                    	      \n",g.harian_gaji);
	printf("=============================================================\n");
    printf("  TOTAL GAJI        : Rp. %d                    	     \n",g.harian_gaji);
	printf("=============================================================\n");
    }
    
    printf("Tekan apa saja untuk melanjutkan...");
    
	getch();
    ulang();
}

float validasi(){

    char input[100];
    int a, i;
    int negatif=0;
    int salah=0;
    int koma=0;
    int belakang=0;
    int deret=0;
    int depan=0;
    float nolKoma=1;
    float hasil;

    scanf("%[^\n]", &input);
    fflush(stdin);

    if(input[a]=='\0'){
        salah=1;
    }

    while(input[a]!='\0'){
        if(input[a]=='.'){
            koma++;
            if(input[0]=='.' || input[a+1]=='\0' || koma>1 ){
                salah=1;
                input[a]='\0';
            }
            a++;
        }else if(input[a]>='0' && input[a]<='9'){
            if(koma==1){
                belakang=(belakang*10)+(input[a]-48);
                deret++;
                a++;
            }else{
                depan=(depan*10)+(input[a]-48);
                a++;
            }
        }else{
            salah=1;
            input[a]='\0';
        }
    }

    if(koma==1){
        for(i=0;i<deret;i++){
            nolKoma=nolKoma/10;
        }
        hasil=belakang*nolKoma+depan;

    }else{
        hasil=depan;
    }

    if(salah==1){
        printf("\n==============================================\n");
        printf("|       INPUTAN YANG ANDA MASUKAN ERROR      |\n");
        printf("|           SILAHKAN MASUKAN ULANG           |\n");
        printf("==============================================\n");

        printf("|  MASUKKAN INPUTAN YANG BARU : ");
        return validasi();
    }else{
        return hasil;
    }

}

void ulang(){
    float a;
    int b;

    system("cls");
    printf("=========================================================\n");
    printf("|  APAKAH ANDA INGIN MENGULANG PERHITUNGAN GAJI HARIAN? |\n");
    printf("=========================================================\n");
    printf("| PILIHAN :                                             |\n");
    printf("| --> YA    = 1                                         |\n");
    printf("| --> TIDAK = 2                                         |\n");
    printf("=========================================================\n");
    printf(">>> Masukkan Pilihan : ");
    a=validasi();
    b=(int)a;
    
    while(a!=b || a<1 || a>2){
      printf("\n================================================\n");
        printf("|              INPUTAN ANDA ERROR              |\n");
        printf("|         SILAHKAN MENGULANGI INPUTAN          |\n");
        printf("================================================\n");
        printf(">>> Silahkan Masukan Angka Yang Baru : ");
        a=validasi();
        b=(int)a;
    }

    if(a==1){
        home();
    }
	
	else if(a==2){
        printf("\n  Terima Kasih");
    }
    exit(0);
}
