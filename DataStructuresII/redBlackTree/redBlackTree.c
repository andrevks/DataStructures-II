#include "redBlackTree.h"





TreeNode * initTree(TreeNode * tree, TreeNode * parent){
    tree = (TreeNode*) malloc(sizeof(TreeNode));   
    tree->data = 0;
    tree->left = tree->right = NULL;
    tree->parent = parent;
    tree->color = 0;

    return tree;
}