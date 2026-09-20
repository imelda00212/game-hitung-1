#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int soal = 1;
    int salah = 0;
    int skor = 0;

    int angka1, angka2;
    int jawaban;
    int hasil;
    int operator;

    srand(time(NULL));

    while (soal <= 30 && salah < 3) {

        if (soal <= 10) {
            angka1 = rand() % 10 + 1;
            angka2 = rand() % 10 + 1;
        }
        else if (soal <= 20) {
            angka1 = rand() % 30 + 1;
            angka2 = rand() % 30 + 1;
        }
        else {
            angka1 = rand() % 60 + 1;
            angka2 = rand() % 60 + 1;
        }

        operator = rand() % 4;

        if (operator == 0) {
            hasil = angka1 + angka2;
            printf("\nSoal %d: %d + %d = ", soal, angka1, angka2);
        }
        else if (operator == 1) {
            hasil = angka1 - angka2;
            printf("\nSoal %d: %d - %d = ", soal, angka1, angka2);
        }
        else if (operator == 2) {
            hasil = angka1 * angka2;
            printf("\nSoal %d: %d x %d = ", soal, angka1, angka2);
        }
        else {
            while (angka2 == 0 || angka1 % angka2 != 0) {
                if (soal <= 10) {
                    angka1 = rand() % 10 + 1;
                    angka2 = rand() % 10 + 1;
                }
                else if (soal <= 20) {
                    angka1 = rand() % 30 + 1;
                    angka2 = rand() % 30 + 1;
                }
                else {
                    angka1 = rand() % 60 + 1;
                    angka2 = rand() % 60 + 1;
                }
            }

            hasil = angka1 / angka2;
            printf("\nSoal %d: %d / %d = ", soal, angka1, angka2);
        }

        scanf("%d", &jawaban);

        if (jawaban == hasil) {
            if (soal <= 10) {
                skor += 5;
            }
            else if (soal <= 20) {
                skor += 10;
            }
            else {
                skor += 15;
            }

            printf("Benar! Skor kamu sekarang: %d\n", skor);
        }
        else {
            salah++;
            printf("Salah! Jawaban yang benar adalah %d\n", hasil);
            printf("Kesalahan: %d/3\n", salah);
        }

        soal++;
    }

    printf("\n=== GAME SELESAI ===\n");
    printf("Skor akhir: %d\n", skor);

    if (salah >= 3) {
        printf("Game berhenti karena kamu sudah 3 kali salah.\n");
    }
    else {
        printf("Kamu berhasil menyelesaikan 30 soal!\n");
    }

    return 0;
}