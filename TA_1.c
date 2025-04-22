#include <stdio.h>
#include <string.h>

// Inisialisasi Struct & Union
typedef union {
    char buku[50];
    char majalah[50];
} JenisMedia;

typedef struct {
    char judul[100];
    int tahunTerbit;
    JenisMedia media;
    int tipeMedia;
} Perpustakaan;

int main()
{
    Perpustakaan item;

    // Start Page
    printf ("********************************\n");
    printf ("|       SISTEM INFORMASI       |\n");
    printf ("|    PERPUSTAKAAN SEDERHANA    |\n");
    printf ("********************************\n\n");

    // Input Data
    printf ("\n* Masukkan Informasi Item *\n");
    printf ("---------------------------\n\n");
    printf ("Judul Item       : ");
    scanf ("%[^\n]", item.judul);
    printf ("Tahun Terbit     : ");
    scanf ("%d", &item.tahunTerbit);
    printf ("\nJenis Item \n< 1 > Buku\n< 2 > Majalah\nPilih Jenis Item : ");
    scanf ("%d", &item.tipeMedia);
    
    // Set Union
    switch (item.tipeMedia)
    {
        case 1 : strcpy (item.media.buku, "Buku");
        break;
        case 2 : strcpy (item.media.majalah, "Majalah");
        break;
    }

    getchar ();
    printf ("\nInformasi item sudah tersimpan. Tekan ENTER untuk menampilkan hasil . . .");
    getchar ();

    // Output Data
    printf ("\n\n>> Informasi Item <<\n");
    printf ("--------------------\n\n");
    printf ("Judul Item   : %s\n", item.judul);
    printf ("Tahun Terbit : %d\n", item.tahunTerbit);
    switch (item.tipeMedia)
    {
        case 1 : printf ("Jenis Item   : %s\n\n", item.media.buku);
        break;
        case 2 : printf ("Jenis Item   : %s\n\n", item.media.majalah);
        break;
        default : printf ("Jenis Item   : Maaf, pilihan anda tidak tersedia.\n\n");
    }
    
    printf ("TERIMA KASIH\n");
    
    return 0;
}