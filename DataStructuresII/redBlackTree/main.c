#include "redBlackTree3.h"

int main() {
  red_black_tree *t = new_red_black_tree();

  tree_node *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;
  a = new_tree_node(101);
  b = new_tree_node(20);
  c = new_tree_node(123);
  d = new_tree_node(40);
  e = new_tree_node(12);
  f = new_tree_node(10);
  g = new_tree_node(58);
  h = new_tree_node(66);
  i = new_tree_node(86);
  j = new_tree_node(92);
  k = new_tree_node(250);
  l = new_tree_node(211);
  m = new_tree_node(222);

  insert(t, a);
  insert(t, b);
  insert(t, c);
  insert(t, d);
  insert(t, e);
  insert(t, f);
  insert(t, g);
  printf("\nImprimindo com a metade dos elementos:\n");
  inorder(t, t->root);
  
  insert(t, h);
  insert(t, i);
  insert(t, j);
  insert(t, k);
  insert(t, l);
  insert(t, m);
  
  printf("\nImprimindo com todos elementos:\n");
  inorder(t, t->root);

  rb_delete(t, a);
  rb_delete(t, m);
  rb_delete(t, h);
  rb_delete(t, f);

  printf("\nImprimindo após deletar os elementos:\n");
  inorder(t, t->root);

  return 0;
}