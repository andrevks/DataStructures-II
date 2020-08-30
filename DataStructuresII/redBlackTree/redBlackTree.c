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

void rightRotate(TreeNode **root,TreeNode *y)
{
    TreeNode *x = y->left;

    y->left = x->right;

    if (x->right != NULL)x->right->parent = y;

    x->parent =y->parent;

    if (x->parent == NULL) (*root) = x;

    else if (y == y->parent->left) y->parent->left = x;

    else y->parent->right = x;
    
    x->right = y;
    y->parent = x;
}


void insertFixUp(TreeNode ** root, TreeNode *z){

    while( z != *root && z->parent->color == 1){
        TreeNode *y;

        if(z->parent == z->parent->parent->left)
            y = z->parent->parent->right;
        else 
            y = z->parent->parent->left;

        //Se o tio é vermelho, deve-se:
        // 1 - Mudar a cor do parent e tio para preto
        // 2 - Mudar a cord do avô para vermelho
        // 3 - Mudar z para o lugar do avô
        if(y->color == 1){
            y->color = 0;
            z->parent->parent->color = 1;
            z = z->parent->parent;
        }

        else
        {
            // Left-Left (LL) case, do following
            // (i)  Swap color of parent and grandparent
            // (ii) Right Rotate Grandparent
            if (z->parent == z->parent->parent->left &&
                z == z->parent->left)
            {
                int ch = z->parent->color ;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root,z->parent->parent);
            }
 
            // Left-Right (LR) case, do following
            // (i)  Swap color of current node  and grandparent
            // (ii) Left Rotate Parent
            // (iii) Right Rotate Grand Parent
            if (z->parent == z->parent->parent->left &&
                z == z->parent->right)
            {
                int ch = z->color ;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root,z->parent);
                rightRotate(root,z->parent->parent);
            }
 
            // Right-Right (RR) case, do following
            // (i)  Swap color of parent and grandparent
            // (ii) Left Rotate Grandparent
            if (z->parent == z->parent->parent->right &&
                z == z->parent->right)
            {
                int ch = z->parent->color ;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root,z->parent->parent);
            }
 
            // Right-Left (RL) case, do following
            // (i)  Swap color of current node  and grandparent
            // (ii) Right Rotate Parent
            // (iii) Left Rotate Grand Parent
            if (z->parent == z->parent->parent->right &&
                z == z->parent->left)
            {
                int ch = z->color ;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root,z->parent);
                LeftRotate(root,z->parent->parent);
            }
        }
    }
    (*root)->color = 0; //keep root always black
}

void insert(TreeNode **root, int data)
{
    // Allocate memory for new node
    TreeNode *z = (TreeNode*) malloc(sizeof(TreeNode));
    z->data = data;
    z->left = z->right = z->parent = NULL;
 
     //if root is null make z as root
    if (*root == NULL)
    {
        z->color = 0;
        (*root) = z;
    }
    else
    {
       TreeNode *y = NULL;
       TreeNode *x = (*root);
 
        // Follow standard BST insert steps to first insert the node
        while (x != NULL)
        {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (z->data > y->data)
            y->right = z;
        else
            y->left = z;
        z->color = 1;
 
        // call insertFixUp to fix reb-black tree's property if it
        // is voilated due to insertion.
        insertFixUp(root,z);
    }
}