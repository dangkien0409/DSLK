#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

//tạo node mới
Node* taoNode(int data) {
    Node* nodeMoi = (Node*)malloc(sizeof(Node));
    nodeMoi->data = data;
    nodeMoi->next = NULL;
    return nodeMoi;
}
//thêm node vào cuối danh sách(để đảm bảo tuần tự và tái sử dụng)
void themCuoi(Node** head, int data) {
    Node* nodeMoi = taoNode(data);
    if (*head == NULL) {
        *head = nodeMoi;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nodeMoi;
}

//xóa node ở đầu danh sách
void xoaDau(Node** head) {
    if (*head == NULL) {
        printf("Danh sách rỗng!\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Đã xóa node ở đầu danh sách.\n");
}

//xóa node ở cuối danh sách
void xoaCuoi(Node** head) {
    if (*head == NULL) {
        printf("Danh sách rỗng!\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Đã xóa node ở cuối danh sách.\n");
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Đã xóa node ở cuối danh sách.\n");
}

//xóa node sau node cho trước
void xoaSau(Node* nodeTruoc) {
    if (nodeTruoc == NULL || nodeTruoc->next == NULL) {
        printf("Không có node nào để xóa sau node này!\n");
        return;
    }
    Node* nodeCanXoa = nodeTruoc->next;
    nodeTruoc->next = nodeCanXoa->next;
    free(nodeCanXoa);
    printf("Đã xóa node sau node cho trước.\n");
}

// Hàm hiển thị danh sách
void hienThiDanhSach(Node* head) {
    if (head == NULL) {
        printf("Danh sách rỗng!\n");
        return;
    }
    Node* temp = head;
    printf("Danh sách hiện tại: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // đưa dữ liệu vào danh sách
    themCuoi(&head, 1);
    themCuoi(&head, 2);
    themCuoi(&head, 3);
    themCuoi(&head, 4);

    printf("Trước khi xóa:\n");
    hienThiDanhSach(head);

    // Xóa đầu
    xoaDau(&head);
    printf("Sau khi xóa đầu:\n");
    hienThiDanhSach(head);

    // Xóa cuối
    xoaCuoi(&head);
    printf("Sau khi xóa cuối:\n");
    hienThiDanhSach(head);

    // Xóa sau một node
    printf("Xóa sau node đầu tiên:\n");
    xoaSau(head);
    hienThiDanhSach(head);

    return 0;
}
