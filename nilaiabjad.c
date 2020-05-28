#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <io.h>

/* deklarasi struct data*/
struct DATA{
    double skor;
    int jumlahKata;
    int panjangKata[100];
    char kata[100][50];
} ;

double getCharPoint(char character) {

    double poin = 0;

    if(character == '0')
        poin = 6.10;
    else if(character == '1')
        poin = 6.15;
    else if(character == '2')
        poin = 6.20;
    else if(character == '3')
        poin = 6.25;
    else if(character == '4')
        poin = 6.30;
    else if(character == '5')
        poin = 6.35;
    else if(character == '6')
        poin = 6.40;
    else if(character == '7')
        poin = 6.45;
    else if(character == '8')
        poin = 6.50;
    else if(character == '9')
        poin = 6.55;
    else if(character == 'a')
        poin = 7.00;
    else if(character == 'b')
        poin = 7.05;
    else if(character == 'c')
        poin = 7.10;
    else if(character == 'd')
        poin = 7.15;
    else if(character == 'e')
        poin = 7.20;
    else if(character == 'f')
        poin = 7.25;
    else if(character == 'g')
        poin = 7.30;
    else if(character == 'h')
        poin = 7.35;
    else if(character == 'i')
        poin = 7.40;
    else if(character == 'j')
        poin = 7.45;
    else if(character == 'k')
        poin = 7.50;
    else if(character == 'l')
        poin = 7.55;
    else if(character == 'm')
        poin = 8.00;
    else if(character == 'n')
        poin = 8.05;
    else if(character == 'o')
        poin = 8.10;
    else if(character == 'p')
        poin = 8.15;
    else if(character == 'q')
        poin = 8.20;
    else if(character == 'r')
        poin = 8.25;
    else if(character == 's')
        poin = 8.30;
    else if(character == 't')
        poin = 8.35;
    else if(character == 'u')
        poin = 8.40;
    else if(character == 'v')
        poin = 8.45;
    else if(character == 'w')
        poin = 8.50;
    else if(character == 'x')
        poin = 8.55;
    else if(character == 'y')
        poin = 9.00;
    else if(character == 'z')
        poin = 9.05;

    return poin;
}

int panjangKata(char kata[100]) {
    int i = 0;
    while(kata[i] != '\0') {
        i++;
    }
    return i;
}

void prosesTextFromInputToOutput() {

    system("cls");

    FILE *f;
    f = fopen("data-big-challenge.txt", "r");
    if(f == NULL) {
        printf("File tidak bisa diproses!");
        exit(1);
    } else {
        char ch;
        char hasil[100][50];
        int idx1 = 0, idx2 = 0;
        int banyakEliminasi = 0;

        /*
        is: baca semua karakter dalam file
        fs: menghapus (eliminasi) semua karakter selain a-z A-Z dan 0-9
        */
        while ((ch = (char) tolower((char) fgetc(f))) != EOF) {

            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
                banyakEliminasi = 0;
                hasil[idx1][idx2] = ch;
                idx2++;
            } else {
                if(banyakEliminasi == 0) {
                    idx2 = 0;
                    banyakEliminasi++;
                    idx1++;
                }
            }

            // jika kata yang disimpan sudah sampai 99 kata
            if(idx1 == 99) {
                printf("Data sudah 99, lanjut ke proses selanjutnya");
                fflush(stdin);
                getchar();
                break;
            }
        }
        fclose(f);

        /*
        is: data array dua dimensi dari variabel hasil
        fs: mendapatkan total poin untuk semua kata
        */
         totalPoin[100];
        int i;
        for(i = 0; i < idx1; i++) {
            int j = 0;
            totalPoin[i] = 0;
            while(hasil[i][j] != '\0') {
                totalPoin[i] += getCharPoint(hasil[i][j]);
                j++;
            }
        }

        // tampilkan kata dengan total pointnyadouble
        for(i = 0; i < idx1; i++) {
            printf("=============\n");
            printf("%s\n", hasil[i]);
            printf("=============\n");
            printf("Total poin: %.2f\n", totalPoin[i]);
            printf("====================================\n\n");
        }

        struct DATA data[100];
        int idxData = 0;


        for(i = 0; i < idx1; i++) {
            if(idxData == 0) {
                data[idxData].skor = totalPoin[i];
                data[idxData].jumlahKata = 1;
                data[idxData].panjangKata[ data[idxData].jumlahKata-1 ] = panjangKata(hasil[i]);
                strcpy(data[idxData].kata[ data[idxData].jumlahKata-1 ], hasil[i]);
                idxData++;
            } else {

                // baca semua data yang sudah tersimpan
                int ketemu = 0;
                int j;
                for(j = 0; j < idxData; j++) {
                    // jika katanya sama
                    if(data[j].skor == totalPoin[i]) {
                        data[j].skor = totalPoin[i];
                        data[j].jumlahKata++;
                        data[j].panjangKata[ data[j].jumlahKata-1 ] = panjangKata(hasil[i]);
                        strcpy(data[j].kata[ data[j].jumlahKata-1 ], hasil[i]);
                        ketemu++;
                    }
                }

                // jika tidak ada kata yang sama
                if(ketemu == 0) {
                    data[idxData].skor = totalPoin[i];
                    data[idxData].jumlahKata = 1;
                    data[idxData].panjangKata[ data[idxData].jumlahKata-1 ] = panjangKata(hasil[i]);
                    strcpy(data[idxData].kata[ data[idxData].jumlahKata-1 ], hasil[i]);
                    idxData++;
                }
            }
        }

        /* proses pengelompokan data berdasarkan total poin yang didapat pada proses sebelumnya */
        /*
        1.baca semua kata yang sudah tersimpan
        2. cek, jika indexData == 0, maka kita anggap belum ada data yang tersimpan
                [skor] bertipe double
                [jumlah_kata] bertipe integer
                [panjang_kata] bertipe integer
                [kata] bertipe string atau array of char

                a. masukkan total poin kedalam variabel skor pada index ke indexData
                b. isikan jumlahKata dengan 0
                c. isikan panjang kata dengan panjang dari kata pada index ke jumlahKata
                d. masukkan kata kedalam variabel kata
                e. tambahkan variabel jumlahKata
                f. tambahkan variabel indexKata
        3. jika indexData != 0, maka kita anggap sudah ada yang tersimpan
            a. bandingkan panjangKata sekarang dengan semua panjang kata yang sudah tersimpan
            b. jika panjangKata sama dengan yang sudah tersimpan, maka:
                i.





                a. jika jumlahKata == 0
                    i. masukkan total poin kedalam variabel skor
                    ii. inisialisasi

        */


        // mengurutkan data struct berdasarkan skor
        for(i = 0; i < idxData; i++) {
            int j;
            for(j = 0; j < idxData-1; j++) {
                if(data[j].skor < data[j+1].skor) {
                    struct DATA temp;
                    temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;

                }
            }
        }

        // menampilkan data setelah diurutkan
        printf("DATA SETELAH DIURUTKAN\n");
        for(i = 0; i < idxData; i++) {

            //if(data[i].jumlahKata > 1) {
                printf("[%.2f] [%d] ", data[i].skor, data[i].jumlahKata);
                int j;
                for(j = 0; j < data[i].jumlahKata; j++) {
                        printf("[%d] [%s] ", data[i].panjangKata[j], data[i].kata[j]);
                }
            //}
            printf("\n");
        }

        printf("\n\nRANGKUMAN!\n");
        printf("Jumlah kata: %d\n", idx1);
        printf("Jumlah kata setelah dikelompokkan: %d\n", idxData);

        // masukkan kedalam file .bin
        FILE *output;
        output = fopen("output.bin", "wb");
        if(output == NULL) {
            printf("File tidak bisa diproses");
        } else {

            // mendapatkan handle file
            int FileHandle = fileno(output);
            long long int ukuran_file = filelength(FileHandle);

            // mengecek apakah file bisa diproses
            if(ukuran_file == -1L) {

                fclose(output);

                printf("Tidak dapat memperoleh ukuran file....\n");
                fflush(stdin);
                getchar();

                exit(1);
            }
                // untuk mengecek apakah minuman masih kosong
            else if(ukuran_file == 0) {
                for(i = 0; i < idxData; i++)
                    fwrite(&data[i], sizeof(data[i]), 1, output);

                fclose(output);
            }
        }
    } // else (jika file bisa diproses)
}

void tampilkanDataHasilProses() {

    system("cls");

    FILE *f;
    f = fopen("output.bin", "rb");
    if(f == NULL) {
        printf("File tidak bisa diproses\n");
    } else {
        // mendapatkan handle file
        int FileHandle = fileno(f);
        long long int ukuran_file = filelength(FileHandle);

        // mengecek apakah file bisa diproses
        if(ukuran_file == -1L) {
            printf("Tidak dapat memperoleh ukuran file....\n");
            fclose(f);
            fflush(stdin);
            getchar();

            exit(1);
        }
        // untuk mengecek apakah data yang tersimpan didalam file .bin masih kosong
        else if(ukuran_file == 0) {
            fclose(f);

            printf("Data belum diproses, silahkan tekan enter untuk memproses...");
            fflush(stdin);
            getchar();

            prosesTextFromInputToOutput();
        } else {
            struct DATA data;

            int n; // banyak data yang akan ditampilkan

            do {
                printf("Masukkan banyak data: ");
                scanf("%d", &n);
            } while(n < 1 || n > 25);

            int i = 0;
            for(;;){
                fread(&data, sizeof(data), 1, f);

                if(feof(f))
                    break
;
                int j;
                for(j = 0; j < data.jumlahKata; j++) {
                    printf("%.2f, %d, %d, %s\n", data.skor, data.jumlahKata, data.panjangKata[j], data.kata[j]);
                    i++;
                    if(i == n)
                        goto beres;
                }
            }
            beres:
            fclose(f);
        }
    }
}

int main() {

    int pilihan;
    do {
        system("cls");
        printf("1. Proses file .txt dan simpan kedalam file .bin\n"
               "2. Tampilkan di layar monitor maksimum n buah kata (0<n<=25)\n"
               "3. Selesai\n"
               "pilihan: "
               );
        scanf("%d", &pilihan);
        switch(pilihan) {
           case 1: {
               prosesTextFromInputToOutput();
           }break;

           case 2: {
               tampilkanDataHasilProses();
           }break;

           case 3: {
           }break;
        }

        if(pilihan != 3) {
            printf("\n\nTekan enter untuk kembali ke menu utama...");
            fflush(stdin);
            getchar();
        }

    } while (pilihan != 3);

    printf("Tekan enter untuk keluar dari program...");
    fflush(stdin);
    getchar();

    return 0;
}
