//Inorder tree transversal
#include<stdio.h>
#include<stdlib.h>
struct treenode {
    int data;
    struct treenode  *left;
    struct treenode  *right;
};

struct treenode* newNode(int data)
{
struct treenode *node= (struct treenode*)malloc(sizeof(struct treenode));
node-> data= data;
node-> left= NULL;
node-> right= NULL;
return node;
}
void inorder(struct treenode  *node)  
    {  
        if(node != NULL)  
        {  
            inorder(node-> left);  
            printf("%d ", node-> data);
            inorder(node-> right);  
        }  
    }  

int main()
{  int a, b, c, d, e, f;

    printf("Enter root node: ");
    scanf("%d", &a);
    printf("Enter left child of root: ");
    scanf("%d", &b);
    printf("Enter left child of %d: ", b);
    scanf("%d", &c);
    printf("Enter right child of %d: ", b);
    scanf("%d", &d);
    printf("Enter right child of root: ");
    scanf("%d", &e);
    printf("Enter right child of %d: ", e);
    scanf("%d", &f);
    struct treenode *root = newNode(a);
    root->left= newNode(b);
    root->left->left= newNode(c);
    root->left->right= newNode(d);
    root->right= newNode(e);
    root->right->right= newNode(f);
    printf("\n");
    printf("Inorder Transversal:");
    inorder(root);
    printf("\n ");

    return 0;
    
}

