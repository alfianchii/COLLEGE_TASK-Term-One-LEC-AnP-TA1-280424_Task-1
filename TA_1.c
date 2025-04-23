#include <stdio.h>
#include <string.h>

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
    union media jenis;
} item;

void InputData (struct pustaka *item);

void OutputData (struct pustaka *item);

int main()
{
    int tipe;
    
    // Start Page
    printf ("********************************\n");
    printf ("|       SISTEM INFORMASI       |\n");
    printf ("|    PERPUSTAKAAN SEDERHANA    |\n");
    printf ("********************************\n\n");

    // Input Data
    InputData (&item);

    getchar ();
    printf ("\nInformasi item sudah tersimpan. Tekan ENTER untuk menampilkan hasil . . .");
    getchar ();

    // Output Data
    OutputData (&item);    
    printf ("TERIMA KASIH\n");
    
    return 0;
}

void InputData (struct pustaka *item)
{
    int tipe;

    // Input Data
    printf ("\n* Masukkan Informasi Item *\n");
    printf ("---------------------------\n\n");
    printf ("Judul Item       : ");
    scanf (" %[^\n]", item->judul);
    printf ("Tahun Terbit     : ");
    scanf ("%d", &item->tahun);
    printf ("\nJenis Item \n< 1 > Buku\n< 2 > Majalah\nPilih Jenis Item : ");
    scanf ("%d", &tipe);
    
    // Set Union
    if (tipe == 1)
    {
        strcpy (item->jenis.buku, "Buku");
    }
    else if (tipe == 2)
        {
            strcpy (item->jenis.majalah, "Majalah");
        }
        else
        {
            strcpy (item->jenis.buku, "Maaf, pilihan anda tidak tersedia.");
        }
}

void OutputData (struct pustaka *item)
{
    // Output Data
    printf ("\n\n>> Informasi Item <<\n");
    printf ("--------------------\n\n");
    printf ("Judul Item   : %s\n", item->judul);
    printf ("Tahun Terbit : %d\n", item->tahun);
    printf ("Jenis Item   : %s\n\n", item->jenis.buku);
}