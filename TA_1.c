#include <stdio.h>
#include <string.h>

int main()
{
    // Inisialisasi Struct & Union
    union media
    {
        char buku[30];
        char majalah[30];
    };

    struct pustaka
    {
        char judul[100];
        int tahun;
        int tipe;
        union media jenis;
    };
    
    struct pustaka item;

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
    scanf ("%d", &item.tahun);
    printf ("\nJenis Item \n< 1 > Buku\n< 2 > Majalah\nPilih Jenis Item : ");
    scanf ("%d", &item.tipe);
    
    // Set Union
    switch (item.tipe)
    {
        case 1 : strcpy (item.jenis.buku, "Buku");
        break;
        case 2 : strcpy (item.jenis.majalah, "Majalah");
        break;
    }

    getchar ();
    printf ("\nInformasi item sudah tersimpan. Tekan ENTER untuk menampilkan hasil . . .");
    getchar ();

    // Output Data
    printf ("\n\n>> Informasi Item <<\n");
    printf ("--------------------\n\n");
    printf ("Judul Item   : %s\n", item.judul);
    printf ("Tahun Terbit : %d\n", item.tahun);
    switch (item.tipe)
    {
        case 1 : printf ("Jenis Item   : %s\n\n", item.jenis.buku);
        break;
        case 2 : printf ("Jenis Item   : %s\n\n", item.jenis.majalah);
        break;
        default : printf ("Jenis Item   : Maaf, pilihan anda tidak tersedia.\n\n");
    }
    
    printf ("TERIMA KASIH\n");
    
    return 0;
}