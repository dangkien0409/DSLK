#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 99

// Cấu trúc lưu thông tin của file
typedef struct FileInfo {
    char name[50];  
    int size;      
    int lastModified; //time
} FileInfo;


void nhapThongTin(FileInfo files[], int *n) {
    printf("Nhập số lượng file: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhập thông tin file %d:\n", i + 1);
        printf("Tên file: ");
        scanf("%s", files[i].name);
        printf("Dung lượng (KB): ");
        scanf("%d", &files[i].size);
        printf("Thời gian lưu (số nguyên): ");
        scanf("%d", &files[i].lastModified);
    }
}

//hiển thị danh sách file
void hienThiDanhSach(FileInfo files[], int n) {
    printf("\nDanh sách file:\n");
    printf("Tên file\tDung lượng (KB)\tThời gian lưu\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\n", files[i].name, files[i].size, files[i].lastModified);
    }
}

//so sánh để sắp xếp file theo dung lượng tăng dần (nếu có nhiều file cùng dung lượng =>> lưu theo thời gian lưu)
int soSanh(const void *a, const void *b) {
    FileInfo *fileA = (FileInfo *)a;
    FileInfo *fileB = (FileInfo *)b;

    if (fileA->size != fileB->size) {
        return fileA->size - fileB->size; // Sắp xếp theo dung lượng
    }
    return fileA->lastModified - fileB->lastModified; // Nếu dung lượng bằng nhau, sắp theo thời gian lưu
}

//xóa file có dung lượng bé nhất và thời gian lưu lâu nhất
void xoaFile(FileInfo files[], int *n) {
    if (*n == 0) {
        printf("Danh sách file rỗng, không có file nào để xóa!\n");
        return;
    }

    //xóa file đầu tiên do danh sách đã được sắp xếp
    printf("Xóa file: %s (Dung lượng: %d KB, Thời gian lưu: %d)\n",
           files[0].name, files[0].size, files[0].lastModified);

    // Dịch các phần tử còn lại lên trên
    for (int i = 1; i < *n; i++) {
        files[i - 1] = files[i];
    }
    (*n)--; 
}

int main() {
    FileInfo files[MAX_FILES];
    int n;
    nhapThongTin(files, &n);

    printf("\nDanh sách file ban đầu:");
    hienThiDanhSach(files, n);

    // Sắp xếp file theo dung lượng tăng dần và thời gian lưu
    qsort(files, n, sizeof(FileInfo), soSanh);
    printf("\nDanh sách file sau khi sắp xếp:");
    hienThiDanhSach(files, n);

    // Xóa file có dung lượng bé nhất và thời gian lưu lâu nhất
    xoaFile(files, &n);
    printf("\nDanh sách file sau khi xóa:");
    hienThiDanhSach(files, n);

    return 0;
}
