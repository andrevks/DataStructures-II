#ifndef redBlackTree_h
#define redBlackTree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    void* data;
    struct TreeNode *left;
    struct TreeNode *right;
    int color;
}TreeNode;


#endif