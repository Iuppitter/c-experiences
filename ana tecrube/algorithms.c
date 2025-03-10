//
//  algorithms.c
//  tecrube
//  Created by Murat C. Akyol on 25.12.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algorithms.h"

// Bir sayıyı girdi alıp o sayının asallığını kontrol eden fonksiyon

int isPrime(int n){
    for(int i = 2; i < n; i++){
        if(n<=1 || n%i == 0)
            return 0;
    }
    return 1;
}

// Kendi kendini çağıran (rekürsif) üs alma fonksiyonu

int powRecursive (int taban, int us){
    if (us == 0)
        return 1;
    else
        return taban * powRecursive(taban, us - 1);
}

// Bir string dizisinin palindromluğunu kontrol eden fonksiyon

int isPalindrome(const char *str){
    size_t len = strlen(str);
    for(int i = 0; i < len/2; i++){
        if(str[i] != str[len - i - 1])
           return 0;
    }
    return 1;
}

/* Bir string dizisinin karakterlerini sırasını ters çeviren fonksiyon
 * ([girdi:örnek ----> çıktı:kenrö] gibi)
 */

void reverseArr (char *str, char *reversed){
    size_t len = strlen(str);
    int temp;
    strcpy(reversed, str);
    for(int i = 0; i < len/2; i++){
        temp = reversed[i];
        reversed[i] = reversed[len - i - 1];
        reversed[len - i - 1] = temp;
    }
}

// Kendi kendini çağıran faktöriyel hesabı yapan fonksiyon

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1; // 0! ve 1! = 1
    return n * factorial(n - 1); }

// Bubble sort algoritması

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Girdi olarak alınan matrisin transpozunu alan fonksiyon

void transposeMatrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Öklid algoritması ile OBEB hesaplayan kendi kendini çağıran fonksiyon

int obeb(int a, int b) {
    if (b == 0)
        return a;
    return obeb(b, a % b);
}

// OKEK hesaplayan fonksiyon (OBEB fonksiyonu kullanarak)

int okek(int a, int b) {
    return (a * b) / obeb(a, b);
}

// Fibonacci serisini hesaplayan rekürsif fonksiyon
// Girdi olarak kaçıncı fibonacci sayısını alacağını alır

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Hanoi kuleleri (soracağını zannetmiyorum)

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Diski %c çubuğundan %c çubuğuna taşı\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("Diski %c çubuğundan %c çubuğuna taşı\n", from, to);
    hanoi(n - 1, aux, to, from);
}

// VERİLEN BİR DİZİDE MAKSİMUM VE MİNİMUM DEĞERLERİ BULAN FONKSİYONLAR

// Maksimum Bulma

int findMax(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int max = findMax(arr, n - 1);
    return (arr[n - 1] > max) ? arr[n - 1] : max;
}

// Minimum Bulma

int findMin(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int min = findMin(arr, n - 1);
    return (arr[n - 1] < min) ? arr[n - 1] : min;
}

// BOYUT GİRDİSİ ALARAK ÜÇGEN ÇİZDİREN FONKSİYONLAR

// Yukarı doğru üçgen

void upwardTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) { // Boşluk koyma
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) { // Yıldız koyma
            printf("*");
        }
        printf("\n");
    }
}

// Aşağı doğru üçgen

void downwardTriangle(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) { // Boşluk koyma
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) { // Yıldız koyma
            printf("*");
        }
        printf("\n");
    }
}

// Dik üçgen

void rightangledTriangle(int n) {
    for (int i = 1; i <= n; i++) { // Satır sayısı 1'den n'e kadar artar
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}
    
