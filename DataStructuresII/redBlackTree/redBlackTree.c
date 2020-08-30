#include "redBlackTree.h"





TreeNode * initTree(TreeNode * tree, TreeNode * parent){
    tree = (TreeNode*) malloc(sizeof(TreeNode));   
    tree->data = 0;
    tree->left = tree->right = NULL;
    tree->parent = parent;
    tree->color = 0;

    return tree;
}

void leftRotate(TreeNode ** root, TreeNode * x){

    //Y apontando para o filho à direita de x
    TreeNode * y = x->right;

    //Filho de x à direita aponta para
    //o filho à esquera de y
    x->right = y->left;

    //Atualizando o parent do x à direita
    if(x->right != NULL) x->right->parent = x;

    //atulizando o parent do y
    y->parent = x->parent;

    //Se o o parente de x é nulo, y se torna a raiz
    if(x->right != NULL) (*root) = y;

    //Coloque o y no lugar de x
    else if(x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;

    //Faça x como um filho à esquerda de y
    y->left = x;

    //O novo parent de x é y
    x->parent = y;
}