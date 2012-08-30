#include "tree.h"
#include "graphviztree.h"
#include <vector>

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

  std::vector<int> sorted({3,4,5,7,9});

  bool sortok = std::equal(
      sorted.begin(),
      sorted.end(),
      t.vectorTraverse(Tree<int>::InOrder).begin()
  );

  if (sortok) {
    std::cout << "Sorted OK" << std::endl;
  } else {
    std::cout << "Sorted Failed!!" << std::endl;
  }


  GraphVizTree<int> graphViz(&t);
  graphViz.generateDot();
}
