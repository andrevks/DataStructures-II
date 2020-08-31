#ifndef redBlackTree_h
#define redBlackTree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    void* data;
    struct TreeNode * parent;
    struct TreeNode *left;
    struct TreeNode *right;
    int color; // 0 = Negro/Preto, 1 = Rubro
}TreeNode;

/*
A red-black tree has the following properties:

1 - Every node in T is either red or black.

2 - The root node of T is black.

3 - Every NULL node is black. (NULL nodes are the leaf nodes. 
They do not contain any keys. When we search for a key that is not 
present in the tree, we reach the NULL node.)

4 - If a node is red, both of its children are black. This means no two nodes on a path can be red nodes.

5 - Every path from a root node to a NULL node has the same number of black nodes.
*/

TreeNode * initTree(TreeNode * tree, TreeNode * parent); 

void leftRotate(TreeNode ** tree, TreeNode * x);
/*
    Para fazer uma rotação ara esquerda de x
    Suponhe-se que que seu filho à direita y não é NULL;
    x pode  ser qualquer nó na árvore na qual seu filho à direita é diferente de NULL.

    A rotação para a esquerda, gira ao redor da ligação de x para y. 
    Transforma y na nova raiz da subárvore, com x como filho à esquerda de y
    e o filho à esquerda de y como filho à direita de x.
*/


void rightRotate(TreeNode **root,TreeNode *y);
    
void insertFixUp(TreeNode ** root, TreeNode *z);

void insert(TreeNode **root, int data);

#endif