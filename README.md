# Sınav Puanlama ve T-Skoru Hesaplama
Bu proje, öğrenci sınav cevaplarını puanlamak, sınıf ortalamasını ve standart sapmasını hesaplamak, ayrıca T-skorlarını hesaplamak için bir C programı sağlar. Program, cevap anahtarı üretir, öğrenci cevapları simüle eder, puanlama yapar ve istatistiksel analizler gerçekleştirir.

## Özellikler
- Cevap Anahtarı Üretme: Soru başına rastgele doğru cevaplar üretir.
- Öğrenci Cevapları Simülasyonu: Belirli bir boş bırakma ve doğru cevap verme ihtimalleri ile öğrenci cevapları oluşturur.
- Puanlama: Öğrencilerin cevaplarını cevap anahtarı ile karşılaştırarak puanlama yapar.
- İstatistiksel Analiz: Sınıf ortalamasını, standart sapmayı ve T-skorlarını hesaplar.

## Kullanım
1. **Derleme ve Çalıştırma**
Kodunuzu çalıştırmadan önce, C derleyicisi ile derlemeniz gerekmektedir. Derleme işlemi, kodu makine diline dönüştürerek çalıştırılabilir bir program haline getirir. 
Derleme işlemi tamamlandıktan sonra, oluşturulan çalıştırılabilir dosyayı çalıştırarak programı başlatabilirsiniz.

2. **Girdi**
   Program, kullanıcıdan aşağıdaki bilgileri alır:
   - Öğrenci sayısı (`N`)
   - Soru sayısı (`S`)
   - Bir sorunun boş bırakılma ihtimali (`B`)
   - Bir sorunun doğru cevaplanma ihtimali (`D`)

3. **Programın Çalışması**
   - **Cevap Anahtarı Üretimi:** Program, rastgele bir cevap anahtarı üretir.
   - **Öğrenci Cevapları Oluşturma:** Belirtilen boş bırakma ve doğru cevap verme ihtimalleri doğrultusunda öğrenci cevapları simüle edilir.
   - **Puanlama:** Öğrencilerin cevapları puanlanır.
   - **İstatistiksel Analiz:** Sınıf ortalaması, standart sapma ve T-skorları hesaplanır.

## Fonksiyonlar
- `cevap_anahtari_uret(char cevap_anahtari[], int S)`: Rastgele bir cevap anahtarı üretir.
- `cevap_anahtari_yazdir(char cevap_anahtari[], int S)`: Cevap anahtarını ekrana yazdırır.
- `sinavi_uygula(char ogrenci_cevaplari[][100], char cevap_anahtari[], int N, int S, double B, double D)`: Öğrenci cevaplarını simüle eder.
- `ogrenci_cevabini_yazdir(char ogrenci_cevaplari[][100], int ogrenci_ID, int S)`: Belirli bir öğrencinin cevaplarını ekrana yazdırır.
- `ogrencileri_puanla(char ogrenci_cevaplari[][100], char cevap_anahtari[], double HBN[], int N, int S)`: Öğrencilerin puanlarını hesaplar.
- `sinif_ortalamasi_hesapla(double HBN[], int N)`: Sınıf ortalamasını hesaplar.
- `standart_sapma_hesapla(double ortalama, double HBN[], int N)`: Standart sapmayı hesaplar.
- `T_skoru_hesapla(double ortalama, double HBN[], int N, double std, double T_skoru[])`: T-skorlarını hesaplar.
