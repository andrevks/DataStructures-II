#include "redBlackTree3.h"

int main() {
  red_black_tree *t = new_red_black_tree();

  tree_node *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;
  a = new_tree_node(10);
  b = new_tree_node(20);
  c = new_tree_node(30);
  d = new_tree_node(100);
  e = new_tree_node(90);
  f = new_tree_node(40);
  g = new_tree_node(50);
  h = new_tree_node(60);
  i = new_tree_node(70);
  j = new_tree_node(80);
  k = new_tree_node(150);
  l = new_tree_node(110);
  m = new_tree_node(120);

  insert(t, a);
  insert(t, b);
  insert(t, c);
  insert(t, d);
  insert(t, e);
  insert(t, f);
  insert(t, g);
  insert(t, h);
  insert(t, i);
  insert(t, j);
  insert(t, k);
  insert(t, l);
  insert(t, m);

  rb_delete(t, a);
  rb_delete(t, m);

  inorder(t, t->root);

  return 0;
}