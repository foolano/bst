#include "tree.h"
#include "graphviztree.h"

int main() {
  Tree<int> t;
  t.insert(3);
  t.insert(5);
  t.insert(7);
  t.insert(4);
  t.insert(9);

  t.printTraverse(Tree<int>::InOrder);
  t.printTraverse(Tree<int>::PreOrder);
  t.printTraverse(Tree<int>::PostOrder);

  GraphVizTree<int> graphViz(&t);
  graphViz.generateDot();
}
