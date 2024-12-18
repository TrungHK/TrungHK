#include <stdio.h>
#include <stdlib.h>
struct BNODE
{
    char label;
    struct BNODE *left, *right;
};
// Hàm tạo nút mới 
struct BNODE *createNewNode(char label)
{
    struct BNODE *newNode = (struct BNODE *)malloc(sizeof(struct BNODE));
    newNode->label = label;
    newNode->left=NULL;
    newNode->right=NULL;
}
// hàm thêm nút mới là con của nút root
void addNewChild(struct BNODE **root, char label)
{
    if(*root==NULL){
        struct BNODE *newNode = createNewNode(label);
        *root = newNode;
    }
    if((*root)->label==label) return;
    if((*root)->label>label){
        return addNewChild(&((*root)->left),label);
    }
    else{
        return addNewChild(&((*root)->right),label);
    }
}
// hàm khởi tạo cây
struct BNODE *initTree()
{
    struct BNODE *root = NULL;
    addNewChild(&root, 'C');
    addNewChild(&root, 'B');
    addNewChild(&root, 'D');
    addNewChild(&root, 'A');
    addNewChild(&root, 'F');
    addNewChild(&root, 'E');
    return root;
}
// duyệt theo thứ tự trước
void preOrder(struct BNODE *root)
{
    if(root==NULL) return;
    printf("%c, ", root->label);
    preOrder(root->left);
    preOrder(root->right);
}
// duyệt theo thứ tự trước
void inOrder(struct BNODE *root)
{
    if(root==NULL) return;
    inOrder(root->left);
    printf("%c, ", root->label);
    inOrder(root->right);
}
// hàm tính chiều cao của nút
int calHeight(struct BNODE *root)
{
    if(root==NULL) return -1;
    int leftHeight = calHeight(root->left);
    int rightHeight = calHeight(root->right);
    return 1+ (leftHeight>rightHeight?leftHeight:rightHeight);
}
// hàm tìm nút có giá trị label trên cây
struct BNODE *findNode(struct BNODE *root, char label)
{
    if(root==NULL||root->label==label) return root;
    struct BNODE *left = findNode(root->left, label);
    if(left!= NULL) return left;
    return findNode(root->right, label);
}
// hàm tính độ sâu của nút cur với gốc là root
int calDepth(struct BNODE *root, struct BNODE *cur)
{
    if(root==NULL) return -1;
    if(root==cur) return 0;
    int left = calDepth(root->left, cur);
    if(left>=0) return 1+left;
    int right = calDepth(root->right, cur);
    if(right>=0) return 1+right;
    return -1;
}
int main()
{
    struct BNODE *root = initTree();
    printf("Duyệt cây thứ tự trước: ");
    preOrder(root);
    printf("\n");
    printf("Duyệt cây thứ tự giữa: ");
    inOrder(root);
    printf("\n");
    printf("Chiều cao cây: %d\n",calHeight(root));
    struct BNODE *cur = findNode(root, 'C');
    printf("Độ sâu của nút %c là %d\n",cur->label, calDepth(root, cur));
    cur = findNode(root, 'H');
    printf("Độ sâu của nút %c là %d\n",cur->label, calDepth(root, cur));
    return 0;
}