#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Log node yapisi
typedef struct LogNode {
    char message[256];  // Log mesaji
    char timestamp[64]; // Zaman bilgisi
    struct LogNode* next; // Sonraki dugum
} LogNode;

LogNode* head = NULL; // Log listesinin baslangici

// Zaman bilgisi alan fonksiyon
void getTimestamp(char* buffer, int size) {
    time_t t;
    struct tm* tm_info;
    time(&t);
    tm_info = localtime(&t);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", tm_info);
}

// Yeni log ekleme fonksiyonu
void addLog(const char* message) {
    LogNode* newNode = (LogNode*)malloc(sizeof(LogNode));
    if (!newNode) {
        printf("Bellek tahsis edilemedi!\n");
        return;
    }

    strncpy(newNode->message, message, sizeof(newNode->message));
    getTimestamp(newNode->timestamp, sizeof(newNode->timestamp));

    newNode->next = head;
    head = newNode;
}

// Loglari ekrana yazdiran fonksiyon
void printLogs() {
    LogNode* current = head;
    printf("\n--- SYSLOG KAYITLARI ---\n");
    while (current) {
        printf("[%s] %s\n", current->timestamp, current->message);
        current = current->next;
    }
}

// Loglari dosyaya kaydeden fonksiyon
void saveLogsToFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Dosya acilamadi!\n");
        return;
    }

    LogNode* current = head;
    while (current) {
        fprintf(file, "[%s] %s\n", current->timestamp, current->message);
        current = current->next;
    }

    fclose(file);
    printf("Loglar %s dosyasina kaydedildi.\n", filename);
}

// Log listesini temizleyen fonksiyon
void freeLogs() {
    LogNode* current = head;
    while (current) {
        LogNode* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

// Test icin main fonksiyonu
int main() {
    addLog("Sistem baslatildi.");
    addLog("Kullanici giris yapti.");
    addLog("Veritabani baglantisi kuruldu.");
    addLog("Hata: Dosya bulunamadi!");

    printLogs(); // Loglari ekrana yazdir

    saveLogsToFile("syslog.txt"); // Loglari dosyaya kaydet

    freeLogs(); // Bellek temizleme
    return 0;
}
