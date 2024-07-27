#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_OGRENCI_SAYISI 100

double standart_sapma_hesapla(double ortalama, double HBN[ ], int N);
void ogrencileri_puanla(char ogrenci_cevaplari[ ][100], char cevap_anahtari[ ], double HBN[ ],int N, int S);
void T_skoru_hesapla(double ortalama, double HBN[ ], int N, double std, double T_skoru[ ]);

void cevap_anahtari_uret(char cevap_anahtari[], int S) {
    // S adet soru için rasgele A, B, C, D veya E harflerinden birini seçin
    for (int i = 0; i < S; i++) {
            int secim = rand() % 5; // 0, 1, 2, 3 veya 4 sayılarından birini seçin
    switch (secim) {
        case 0:
            cevap_anahtari[i] = 'A';
            break;
        case 1:
            cevap_anahtari[i] = 'B';
            break;
        case 2:
            cevap_anahtari[i] = 'C';
            break;
        case 3:
            cevap_anahtari[i] = 'D';
            break;
        case 4:
            cevap_anahtari[i] = 'E';
            break;
}
}
}

void cevap_anahtari_yazdir(char cevap_anahtari[], int S) {
    // Cevap anahtarını ekrana yazdırın
    printf("Cevap anahtari: ");
    for (int i = 0; i < S; i++) {
        printf("%c ", cevap_anahtari[i]);
    }
    printf("\n");
}

void sinavi_uygula(char ogrenci_cevaplari[][100], char cevap_anahtari[], int N, int S, double B, double D) {
    // N adet öğrenci için S adet sorunun cevaplarını oluşturun
    for (int i = 0; i < N; i++) {
            for (int j = 0; j < S; j++) {
                double rasgele = (double)rand() / RAND_MAX;
    if (rasgele < B*0.01) {
            // Soru boş bırakılsın (X karakteri kullanın)
            ogrenci_cevaplari[i][j] = 'X';

    }
    else {
           double rasgele2 = (double)rand() / RAND_MAX;

    if (rasgele2 < D*0.01) {
            // Doğru cevap verilsin
            ogrenci_cevaplari[i][j] = cevap_anahtari[j];
     }
     else {
            // Yanlış cevap verilsin (cevap anahtarından farklı bir harf seçin)
            char cevap = cevap_anahtari[j];
     while (cevap == cevap_anahtari[j]) {
            int secim = rand() % 5;
     switch (secim) {
         case 0:
             cevap = 'A';
             break;
         case 1:
             cevap = 'B';
             break;
         case 2:
             cevap = 'C';
             break;
         case 3:
             cevap = 'D';
             break;
         case 4:
             cevap = 'E';
             break;
          }
         }
         ogrenci_cevaplari[i][j] = cevap;
        }
      }
     }
    }
}


void ogrenci_cevabini_yazdir(char ogrenci_cevaplari[][100], int ogrenci_ID, int S) {
    // İstenen öğrencinin cevaplarını cekin ve ekrana yazdirin
    printf("Ogrenci %d cevaplari: ", ogrenci_ID + 1);
    for (int i = 0; i < S; i++) {
            printf("%c ", ogrenci_cevaplari[ogrenci_ID][i]);
    }
    printf("\n");
    }

void ogrencileri_puanla(char ogrenci_cevaplari[ ][100], char cevap_anahtari[ ], double HBN[ ],
int N, int S)
{
    int i, j;
    double not;

    for (i = 0; i < N; i++)
    {
        not = 0;
        for (j = 0; j < S; j++)
        {
            if (ogrenci_cevaplari[i][j] == cevap_anahtari[j])
                not += 1;
            else
                not -= (1.0 / 4.0);
        }
        if (not < 0)
            not = 0;
        HBN[i] = not;
    }
}

double sinif_ortalamasi_hesapla(double HBN[ ], int N)
{
    int i;
    double toplam = 0;

    for (i = 0; i < N; i++)
        toplam += HBN[i];

    return toplam / N;
}

double standart_sapma_hesapla(double ortalama, double HBN[ ], int N)
{
    int i;
    double toplam = 0;

    for (i = 0; i < N; i++)
        toplam += (HBN[i] - ortalama) * (HBN[i] - ortalama);

    return sqrt(toplam / N);
}

void T_skoru_hesapla(double ortalama, double HBN[ ], int N, double std, double T_skoru[ ])
{
    int i;

    for (i = 0; i < N; i++)
        T_skoru[i] = (HBN[i] - ortalama) / std;
}


int main(void) {
    int N, S;
    double B, D;
    double HBN[MAX_OGRENCI_SAYISI];
    double  std;
    char ogrenci_cevaplari[MAX_OGRENCI_SAYISI][100];
    char cevap_anahtari[100];
    double T_skoru[MAX_OGRENCI_SAYISI];


    // Kullanıcıdan N, S, B ve D parametrelerini alın
    printf("Lutfen ogrenci sayisini giriniz: ");
    scanf("%d", &N);
    printf("Lutfen soru sayisini giriniz: ");
    scanf("%d", &S);
    printf("Lutfen bir sorunun bos birakilma ihtimalini giriniz: ");
    scanf("%lf", &B);
    printf("Lutfen bir sorunun dogru cevaplanma ihtimalini giriniz: ");
    scanf("%lf", &D);


    // Cevap anahtarını oluşturan fonksiyonu çağırın

    cevap_anahtari_uret(cevap_anahtari, S);
    printf("Cevap anahtari uret : %s %d \n",cevap_anahtari,S);
    printf("%\n");

    // Öğrenci cevaplarını oluşturan fonksiyonu çağırın

    sinavi_uygula(ogrenci_cevaplari, cevap_anahtari, N, S, B, D);
    printf("Sinavi uygula : %s \n %s \n %d \n %d \n %.2f \n %.2f\n",ogrenci_cevaplari,cevap_anahtari,N ,S ,B ,D );
    printf("%\n");

    // Öğrenci cevaplarını ve cevap anahtarını oku
     ogrencileri_puanla(ogrenci_cevaplari, cevap_anahtari, HBN, N, S);
     printf("Ogrencileri cevapla : %s \n %s \n %.2f \n %d \n %d ",ogrenci_cevaplari,cevap_anahtari, HBN, N, S);
     printf("%\n");
    // HBN dizisindeki değerleri ekrana yazdır

    // Öğrenci ham başarı notlarını
    double ortalama = sinif_ortalamasi_hesapla(HBN, N);
    printf("Sinif ortalamasi: %.2f\n", ortalama);
    printf("%\n");


    // Öğrenci ham başarı notlarını ve sınıf ortalamasını oku
    double standart_sapma = standart_sapma_hesapla(ortalama, HBN, N);
    printf("Sinif standart sapmasi: %.2f\n", standart_sapma);
    printf("%\n");

    // Öğrenci ham başarı notlarını, sınıf ortalamasını ve sınıf standart sapmasını oku
    T_skoru_hesapla(ortalama, HBN, N, std, T_skoru);
    printf("T skoru hesapla : %.2f %.2f %d %.2f %.2f ",ortalama, HBN, N, std, T_skoru);
    printf("%\n");
    // T_skoru dizisindeki değerleri ekrana yazdır



    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_OGRENCI_SAYISI 100

double standart_sapma_hesapla(double ortalama, double HBN[ ], int N);
void ogrencileri_puanla(char ogrenci_cevaplari[ ][100], char cevap_anahtari[ ], double HBN[ ],int N, int S);
void T_skoru_hesapla(double ortalama, double HBN[ ], int N, double std, double T_skoru[ ]);

void cevap_anahtari_uret(char cevap_anahtari[], int S) {
    // S adet soru için rasgele A, B, C, D veya E harflerinden birini seçin
    for (int i = 0; i < S; i++) {
            int secim = rand() % 5; // 0, 1, 2, 3 veya 4 sayılarından birini seçin
    switch (secim) {
        case 0:
            cevap_anahtari[i] = 'A';
            break;
        case 1:
            cevap_anahtari[i] = 'B';
            break;
        case 2:
            cevap_anahtari[i] = 'C';
            break;
        case 3:
            cevap_anahtari[i] = 'D';
            break;
        case 4:
            cevap_anahtari[i] = 'E';
            break;
}
}
}

void cevap_anahtari_yazdir(char cevap_anahtari[], int S) {
    // Cevap anahtarını ekrana yazdırın
    printf("Cevap anahtari: ");
    for (int i = 0; i < S; i++) {
        printf("%c ", cevap_anahtari[i]);
    }
    printf("\n");
}

void sinavi_uygula(char ogrenci_cevaplari[][100], char cevap_anahtari[], int N, int S, double B, double D) {
    // N adet öğrenci için S adet sorunun cevaplarını oluşturun
    for (int i = 0; i < N; i++) {
            for (int j = 0; j < S; j++) {
                double rasgele = (double)rand() / RAND_MAX;
    if (rasgele < B*0.01) {
            // Soru boş bırakılsın (X karakteri kullanın)
            ogrenci_cevaplari[i][j] = 'X';

    }
    else {
           double rasgele2 = (double)rand() / RAND_MAX;

    if (rasgele2 < D*0.01) {
            // Doğru cevap verilsin
            ogrenci_cevaplari[i][j] = cevap_anahtari[j];
     }
     else {
            // Yanlış cevap verilsin (cevap anahtarından farklı bir harf seçin)
            char cevap = cevap_anahtari[j];
     while (cevap == cevap_anahtari[j]) {
            int secim = rand() % 5;
     switch (secim) {
         case 0:
             cevap = 'A';
             break;
         case 1:
             cevap = 'B';
             break;
         case 2:
             cevap = 'C';
             break;
         case 3:
             cevap = 'D';
             break;
         case 4:
             cevap = 'E';
             break;
          }
         }
         ogrenci_cevaplari[i][j] = cevap;
        }
      }
     }
    }
}


void ogrenci_cevabini_yazdir(char ogrenci_cevaplari[][100], int ogrenci_ID, int S) {
    // İstenen öğrencinin cevaplarını cekin ve ekrana yazdirin
    printf("Ogrenci %d cevaplari: ", ogrenci_ID + 1);
    for (int i = 0; i < S; i++) {
            printf("%c ", ogrenci_cevaplari[ogrenci_ID][i]);
    }
    printf("\n");
    }

void ogrencileri_puanla(char ogrenci_cevaplari[ ][100], char cevap_anahtari[ ], double HBN[ ],
int N, int S)
{
    int i, j;
    double not;

    for (i = 0; i < N; i++)
    {
        not = 0;
        for (j = 0; j < S; j++)
        {
            if (ogrenci_cevaplari[i][j] == cevap_anahtari[j])
                not += 1;
            else
                not -= (1.0 / 4.0);
        }
        if (not < 0)
            not = 0;
        HBN[i] = not;
    }
}

double sinif_ortalamasi_hesapla(double HBN[ ], int N)
{
    int i;
    double toplam = 0;

    for (i = 0; i < N; i++)
        toplam += HBN[i];

    return toplam / N;
}

double standart_sapma_hesapla(double ortalama, double HBN[ ], int N)
{
    int i;
    double toplam = 0;

    for (i = 0; i < N; i++)
        toplam += (HBN[i] - ortalama) * (HBN[i] - ortalama);

    return sqrt(toplam / N);
}

void T_skoru_hesapla(double ortalama, double HBN[ ], int N, double std, double T_skoru[ ])
{
    int i;

    for (i = 0; i < N; i++)
        T_skoru[i] = (HBN[i] - ortalama) / std;
}


int main(void) {
    int N, S;
    double B, D;
    double HBN[MAX_OGRENCI_SAYISI];
    double  std;
    char ogrenci_cevaplari[MAX_OGRENCI_SAYISI][100];
    char cevap_anahtari[100];
    double T_skoru[MAX_OGRENCI_SAYISI];


    // Kullanıcıdan N, S, B ve D parametrelerini alın
    printf("Lutfen ogrenci sayisini giriniz: ");
    scanf("%d", &N);
    printf("Lutfen soru sayisini giriniz: ");
    scanf("%d", &S);
    printf("Lutfen bir sorunun bos birakilma ihtimalini giriniz: ");
    scanf("%lf", &B);
    printf("Lutfen bir sorunun dogru cevaplanma ihtimalini giriniz: ");
    scanf("%lf", &D);


    // Cevap anahtarını oluşturan fonksiyonu çağırın

    cevap_anahtari_uret(cevap_anahtari, S);
    printf("Cevap anahtari uret : %s %d \n",cevap_anahtari,S);
    printf("%\n");

    // Öğrenci cevaplarını oluşturan fonksiyonu çağırın

    sinavi_uygula(ogrenci_cevaplari, cevap_anahtari, N, S, B, D);
    printf("Sinavi uygula : %s \n %s \n %d \n %d \n %.2f \n %.2f\n",ogrenci_cevaplari,cevap_anahtari,N ,S ,B ,D );
    printf("%\n");

    // Öğrenci cevaplarını ve cevap anahtarını oku
     ogrencileri_puanla(ogrenci_cevaplari, cevap_anahtari, HBN, N, S);
     printf("Ogrencileri cevapla : %s \n %s \n %.2f \n %d \n %d ",ogrenci_cevaplari,cevap_anahtari, HBN, N, S);
     printf("%\n");
    // HBN dizisindeki değerleri ekrana yazdır

    // Öğrenci ham başarı notlarını
    double ortalama = sinif_ortalamasi_hesapla(HBN, N);
    printf("Sinif ortalamasi: %.2f\n", ortalama);
    printf("%\n");


    // Öğrenci ham başarı notlarını ve sınıf ortalamasını oku
    double standart_sapma = standart_sapma_hesapla(ortalama, HBN, N);
    printf("Sinif standart sapmasi: %.2f\n", standart_sapma);
    printf("%\n");

    // Öğrenci ham başarı notlarını, sınıf ortalamasını ve sınıf standart sapmasını oku
    T_skoru_hesapla(ortalama, HBN, N, std, T_skoru);
    printf("T skoru hesapla : %.2f %.2f %d %.2f %.2f ",ortalama, HBN, N, std, T_skoru);
    printf("%\n");
    // T_skoru dizisindeki değerleri ekrana yazdır



    return 0;
}

