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

  std::cout
    << "Value 6 " << (t.search(6) == 0 ? "not found" : "found") << std::endl;

  std::cout
    << "Value 7 " << (t.search(7) == 0 ? "not found" : "found") << std::endl;

  std::cout
    << "NumNodes " << (t.numberOfNodes() == sorted.size() ? "OK" : "failed") << std::endl;

  GraphVizTree<int> graphViz(&t);
  graphViz.generateDot();
}
