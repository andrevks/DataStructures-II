
#include <stdio.h>
#include <stdlib.h>

enum COLOR {Red, Black};

typedef struct tree_node {
  int data;
  struct tree_node *right;
  struct tree_node *left;
  struct tree_node *parent;
  enum COLOR color;
}tree_node;

typedef struct red_black_tree {
  tree_node *root;
  tree_node *NIL;
}red_black_tree;

tree_node* new_tree_node(int data);

red_black_tree* new_red_black_tree();

void left_rotate(red_black_tree *t, tree_node *x);

void right_rotate(red_black_tree *t, tree_node *x);

void insertion_fixup(red_black_tree *t, tree_node *z);

void insert(red_black_tree *t, tree_node *z);

void rb_transplant(red_black_tree *t, tree_node *u, tree_node *v);
/* 

*/

tree_node* minimum(red_black_tree *t, tree_node *x); 

void rb_delete_fixup(red_black_tree *t, tree_node *x);

void rb_delete(red_black_tree *t, tree_node *z);
/* 
Quando queremos eliminar o nó z e z tem menos do que dois filhos, 
z é removido da árvore e queremos que y seja z.

Quando z tem dois filhos, y deve ser o sucessor de z , e y passa para a posição de z na árvore. 

Também lembramos a cor de y antes de ele ser eliminado da árvore ou passar para dentro dela, 
e rastreamos o nó x que passa para a posição original de y na árvore porque o nó x também poderia 
causar violações das propriedades vermelho-preto
*/

void inorder(red_black_tree *t, tree_node *n);