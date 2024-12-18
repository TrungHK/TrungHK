#include <stdio.h>
#include <stdlib.h>
struct TNODE
{
    char label;
    struct TNODE *firstChild, *nextSibling;
};
// hàm cấp phát bộ nhớ động để lưu nút mới
struct TNODE *createNewNode(char label)
{
    struct TNODE *newNode = (struct TNODE*)malloc(sizeof(struct TNODE));
    newNode->label = label;
    newNode->firstChild=NULL;
    newNode->nextSibling=NULL;
    return newNode;
}
// thêm con mới cho nút root (khác NULL)
// nếu nó chưa có con thì nút mới là con đầu tiên
// ngược lại, nó sẽ là con kê tiếp sau con hiện tại của nút root
void addNewChild(struct TNODE *root, char label)
{
    // tạo ra nút con mới với nhãn label
    struct TNODE *newChild = createNewNode(label);
    // kiểm tra xem nút gốc đã có con chưa
    if(root->firstChild==NULL){
        // chưa có con thì gán nút mới là con đầu tiên
        root->firstChild = newChild;
    }
    else
    {
        // tìm tới nút con kế tiếp
        struct TNODE *nextBrother = root->firstChild;
        // đi tìm nút anh chị em cuối cùng của nút root hiện tại
        while(nextBrother->nextSibling!=NULL)
        {
            nextBrother = nextBrother->nextSibling;
        }
        // nút mới sẽ là người anh em nhỏ nhất
        nextBrother->nextSibling = newChild;
    }
}
// hàm tạo cây mặc định ban đầu
struct TNODE *initTree()
{
    struct TNODE *root;
    // nut gốc là A
    root = createNewNode('A');
    // thêm con của A là C,B,D theo đúng thứ tự (con trưởng --> con thứ)
    addNewChild(root, 'C');
    addNewChild(root, 'B');
    addNewChild(root, 'D');
    // thêm con của B là E và F
    // B = root->firstChild->nextSibling
    addNewChild(root->firstChild->nextSibling, 'E');
    addNewChild(root->firstChild->nextSibling, 'F');
    //Thêm con của D là I
    // D = root(A)->firstChild(C)->nextSibling(B)->nextSibling(D)
    addNewChild(root->firstChild->nextSibling->nextSibling, 'I');
    // thêm con của E là G và H
    // E = root(A)->firstChild(C)->nextSibling(B)->firstChild(E)
    addNewChild(root->firstChild->nextSibling->firstChild, 'G');
    addNewChild(root->firstChild->nextSibling->firstChild, 'H');
 
    return root;
}
// hàm duyệt cây theo thứ tự trước
void preOrderTraver(struct TNODE *root)
{
    if(root==NULL) return;
    printf("%c, ", root->label);
    // gọi đệ quy tới các cây con của gốc
    struct TNODE *nextBrother = root->firstChild;
    while(nextBrother!=NULL)
    {
        preOrderTraver(nextBrother);
        // di chuyển tới nút anh chị em kế tiếp trong các nút con của root
        nextBrother=nextBrother->nextSibling;
    }
}
int main()
{
    struct TNODE *root = initTree();
    preOrderTraver(root);
    return 0;
}