#include<stdio.h>
#include<stdlib.h>
struct DNODE
{
	int data;
	struct DNODE* next, * prev;
};
 
struct DNODE* createNewNode(int data)
{
	struct DNODE* pnew = (struct DNODE*)malloc(sizeof(struct DNODE));
	pnew->data = data;
	pnew->next = NULL;
	pnew->prev = NULL;
	return pnew;
}
// hàm in ra danh sách hiện tại
void printList(const struct DNODE* head)
{
	printf("Danh sach hien tai: \n");
	while (head != NULL) {
		printf("%d --> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}
// Hàm thêm phần tử vào đâu danh sách 
void push_front(struct DNODE** head, int data)
{
	struct DNODE* pnew = createNewNode(data);
	// nếu danh sách ban đầu là rỗng thì phần tử mới là đầu mới luôn
	if (*head == NULL) {
		*head = pnew;
	}
	else // ngươc lại gắn pnew vào vị trí thích hợp
	{
		pnew->next = *head;
		(*head)->prev = pnew;
		*head = pnew;
	}
}
// hàm chèn phần tử mới vào sau vị trí thứ idx trong danh sách hiện tại
// nếu idx > số phần tử hiện có thì chèn vào cuối danh sách
// đầu danh sách là 1
void insertAt(struct DNODE** head, int data, int idx)
{
	// nếu danh sách hiện tại rỗng --> chèn vào đầu
	struct DNODE* pnew = createNewNode(data);
	if (*head == NULL) {
		*head = pnew;
		return;
	}
	// ngược lại, tìm với vi trí idx
	int count = 1;
	struct DNODE* prev=*head;
	while (prev->next != NULL && count < idx)
	{
		prev = prev->next;
		count++;
	}
	// nếu prev đã là cuối danh sách --> chèn vào cuối
	if (prev->next == NULL) {
		// chèn pnew vào sau prev
		prev->next = pnew;
		pnew->prev = prev;
	}
	else // prev chưa phải cuối danh sách --> cần xử lý đoạn prev->next
	{
		prev->next->prev = pnew;
		pnew->next = prev->next;
		prev->next = pnew;
		pnew->prev = prev;
	}
 
}
int main()
{
	struct DNODE* head = NULL;
	push_front(&head, 3);
	push_front(&head, 7);
	push_front(&head, 6);
	printList(head);
	insertAt(&head, 10, 3);
	insertAt(&head, 8, 3);
	printList(head);
	return 0;
}