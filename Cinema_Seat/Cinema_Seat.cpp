#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
#include <string.h>
#include <ctype.h>

#define ROW 5
#define COL 10

typedef struct {
    char status;
} Kursi;

Kursi bioskop[ROW][COL];
int dipesan = 0, tersedia = 0;
int inisialisasi = 0;

void Inisialisasi_Kursi(){
    srand(time(NULL));
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            bioskop[i][j].status = (rand() % 2) ? 'O' : 'X';
            if (bioskop[i][j].status == 'X'){
            	dipesan++;
			}
			else{
				tersedia++;
			}
        }
        printf("\n");
    }
    inisialisasi = 1;
}

void Tampilan_Kursi(){
	if (!inisialisasi){
		Inisialisasi_Kursi();
	}
	printf("  A B C D E F G H I J\n");
    for (int i = 0; i < ROW; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < COL; j++) {
            printf("%c ", bioskop[i][j].status);
        }
        printf("\n");
    }
}

int convert_seat(char* lokasi, int* row, int* col) {
    if (strlen(lokasi) < 2) return 0;
    *row = lokasi[0] - '1';
    *col = toupper(lokasi[1]) - 'A';
    return (*row >= 0 && *row < ROW && *col >= 0 && *col < COL);
}

void Pesan_Kursi() {
    char lokasi[3];
    int row, col;
    printf("Masukkan lokasi kursi yang ingin dipesan (contoh: 3C): ");
    scanf("%s", lokasi);
    getchar();
    if (!convert_seat(lokasi, &row, &col)) {
        printf("Lokasi kursi tidak valid.\n");
        return;
    }
    if (bioskop[row][col].status == 'O') {
        bioskop[row][col].status = 'X';
        tersedia--;
        dipesan++;
        printf("Kursi berhasil dipesan.\n");
    } else {
        printf("Kursi sudah dipesan, silakan pilih kursi lain.\n");
    }
}

void Batal_Pesan_Kursi() {
    char lokasi[3];
    int row, col;
    printf("Masukkan lokasi kursi yang ingin dibatalkan (contoh: 3C): ");
    scanf("%s", lokasi);
    getchar();
    if (!convert_seat(lokasi, &row, &col)) {
        printf("Lokasi kursi tidak valid.\n");
        return;
    }
    if (bioskop[row][col].status == 'X') {
        bioskop[row][col].status = 'O';
        tersedia++;
        dipesan--;
        printf("Pemesanan kursi berhasil dibatalkan.\n");
    } else {
        printf("Kursi tidak berhasil dibatalkan.\n");
    }
}

void Lihat_Statistik(){
	printf("Kursi tersedia: %d\n", tersedia);
	printf("Kursi dipesan: %d\n", dipesan);
}

int main(){
	int choice;
	while (true){
		printf("Sistem Pemesanan Tempat Duduk Bioskop\n");
	    printf("1. Tampilkan Kursi\n");
    	printf("2. Pesan Kursi\n");
	    printf("3. Batalkan Pemesanan\n");
	    printf("4. Lihat Statistik Kursi\n");
	    printf("5. Keluar\n");
        printf("Pilih opsi: "); 
        scanf("%d", &choice);
		getchar();
		switch(choice){
		case 1:
    		Tampilan_Kursi();
    		break;
		case 2:
			Pesan_Kursi();
			break;
		case 3:
			Batal_Pesan_Kursi();
			break;
		case 4:
			Lihat_Statistik();
			break;
		case 5:
			return 0;
		default:
			printf("Tolong buat pilihan yang tepat\n");
			break;
	    } 
	}
	return 0;
}
