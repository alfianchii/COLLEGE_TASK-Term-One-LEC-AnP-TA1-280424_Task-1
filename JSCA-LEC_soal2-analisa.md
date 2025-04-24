Program yang diberikan akan mencetak urutan angka [12, 25, 34, 64, 22] jika dijalankan. Dari hasil ini, kita bisa melihat bahwa deretan angka sudah terurut, kecuali pada elemen terakhir. Jika array kita ubah menjadi deret lebih sederhana yang sudah terurut seperti [1, 2, 3], program justru merusak urutan menjadi [1, 3, 2].

Saat array memasuki function sort, akan dimulai perulangan dengan range index i = [0, n-1]. Dalam setiap iterasi, ada proses perulangan lagi dengan range index j = [0, n]. Setiap iterasi j, akan terjadi pertukaran nilai pada index i dan j jika nilai pada index j lebih besar daripada i.

Kurang lebih berikut tahap-tahap yang terjadi pada program sort:

1. Bentuk array [1, 2, 3], index i = 0, dimana arr[i] adalah 1,
    1. Terjadi perubahan pada index j = 1, dimana arr[j] = 2 > arr[i] = 1,
    2. Akibat perubahan tersebut, arr[i] kini memiliki nilai 2 dan bentuk array menjadi [2, 1, 3],
    3. Terjadi perubahan lagi pada index j = 2, dimana arr[j] = 3 > arr[i] = 2,
    4. Bentuk array akhir setelah perulangan i = 0 adalah [3, 1, 2],
2. Index i = 1, dimana arr[i] adalah 1,
    1. Terjadi perubahan pada index j = 2, dimana arr[j] = 2 > arr[i] = 1,
    2. Bentuk akhir perulangan i = 1 adalah [1, 3, 2]
3. Loop berhenti pada index i = 2 sesuai kondisi i < n - 1

Jika kita mencetak bentuk array setiap terjadi pertukaran seperti berikut

```c
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
void sort(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n; j++) {
      if (arr[j] > arr[i]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        printArray(arr, n);
      }
    }
  }
}
```

Program akan mencetak deret seperti berikut sesuai analisa di atas.

```
2 1 3 
3 1 2 
1 3 2
```

Algoritma yang digunakan pada function sort ini tidak bisa dikategorikan sebagai selection sort, bubble sort, ataupun insertion sort, karena proses nya tidak lumrah. Untuk mengerti proses kerja algoritma sort ini, kita bisa membayangkan ada suatu array penampung. Setiap iterasi i, algoritma mencari nilai terbesar dari array lalu memasukkan nya kedalam array penampung. Pada iterasi selanjutnya, angka terbesar selanjutnya akan diletakkan di depan semua elemen di array penampung. Sebagai contoh:

```
arr = [3, 5, 4, 2]
i = 0 => temp = [5]
i = 1 => temp = [4, 5]
i = 2 => temp = [3, 4, 5]
i = 3 => temp = [2, 3, 4, 5]
```
Yang membuat rumit adalah semua proses terjadi in-place tanpa deklarasi array penampung, sehingga banyak terjadi swap.

Untuk memperbaiki kode, kita hanya perlu melakukan iterasi i =  n - 1 dengan mengubah test case pada perulangan i menjadi i < n. Dengan demikian, akan terjadi proses seperti berikut:

1. Bentuk array setelah index i = 1 adalah [1, 3, 2],
2. Index i = 2, arr[i] = 2
3. Terjadi perubahan pada j = 1, karena arr[j] = 3 > arr[i] = 2
4. Bentuk akhir array adalah [1, 2, 3]

Jika kita uji menggunakan angka random seperti berikut

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
void sort(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (arr[j] > arr[i]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
int main() {
  srand(time(NULL));
  int arr[20];
  int n = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }
  printArray(arr, n);
  sort(arr, n);
  printArray(arr, n);
  return 0;
}
```

Output yang dihasilkan akan menjadi seperti berikut

```
84 35 40 25 31 66 46 68 87 17 57 52 32 19 24 67 6 62 96 10 
6 10 17 19 24 25 31 32 35 40 46 52 57 62 66 67 68 84 87 96
```

Dengan demikian, kode awal yang telah dikoreksi adalah sebagai berikut:

```c
#include <stdio.h>
void sort(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (arr[j] > arr[i]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
int main() {
  int arr[] = {64, 34, 25, 12, 22};
  int n = sizeof(arr) / sizeof(arr[0]);
  sort(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
```

Berikut adalah flowchart dari program tersebut

![flowchart](/JSCA-LEC_soal2-flowchart.png)