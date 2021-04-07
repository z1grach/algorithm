#include <iostream>

using namespace std;


typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} BinTreeIntNode;


BinTreeIntNode* treeInsert(BinTreeIntNode *t, int data) {
    BinTreeIntNode *newNode;
    newNode = (BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    BinTreeIntNode *current = t;
    BinTreeIntNode *parent = t;
    if (t == NULL) {
        t = newNode;
    } else {
        while (current->key != data) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}


void printBinTree(BinTreeIntNode *root) {
    if (root) {
        printf("%d", root->key);
        if (root->left || root->right) {
            printf("(");
            if (root->left)
                printBinTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printBinTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}


int countList(BinTreeIntNode *node)
{
    if(node == NULL)
        return 0;

    int countLeft=0, countRight=0;

    if(node->left != NULL){
        countLeft=countList(node->left);
    }
    if(node->right != NULL){
        countRight=countList(node->right);
    }

    return ((countLeft>countRight) ? countLeft : countRight)+1;

}

bool isBalanced(BinTreeIntNode *root)
{
    int Left=countList(root->left);
    int Right=countList(root->right);
    if(Left==NULL && Right==NULL)
        return true;
    else if(Left>Right)
        return (Left-Right)<=1;
    else return (Right-Left)<=1;
}


void exer1()
{
    BinTreeIntNode *node=NULL;
    BinTreeIntNode *tree=treeInsert(node, 10);
    treeInsert(tree, 5);
    treeInsert(tree, 15);
    treeInsert(tree, 3);
    treeInsert(tree, 4);

    isBalanced(tree) ? cout << "True\n" : cout << "False\n";
}


int main()
{
//Ex.1
    exer1();


    return 0;
}
