# Syslog-List
Bu proje, **syslog mekanizmasını taklit eden bir log yönetim sistemidir**.  
Sistem loglarını **tek yönlü bağlı liste (singly linked list)** kullanarak saklar, ekrana yazdırır ve bir dosyaya kaydeder.
##  Özellikler
-  **Dinamik Log Yönetimi** → Loglar **tek yönlü bağlı liste** ile yönetilir.
-  **Zaman Damgalı Loglar** → Her log mesajına **tarih ve saat eklenir**.
-  **Dosyaya Kaydetme** → Loglar **syslog.txt** dosyasına yazılabilir.
-  **Hafif ve Hızlı** → Yeni loglar **O(1)** sürede eklenir.

##  Kullanılan Teknolojiler
- **C Programlama Dili** 
- **Bağlı Liste (Linked List)** 
- **File I/O (Dosya İşlemleri)** 
- **Zaman Kütüphanesi (time.h)** 

##  Kurulum ve Çalıştırma
### **1️ Kaynak Kodları Klonla**
```bash


gcc syslog_list.c -o syslog
./syslog
