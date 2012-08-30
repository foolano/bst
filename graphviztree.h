#ifndef GRAPHVIZTREE_H
#define GRAPHVIZTREE_H

#include <iostream>
#include <functional>
#include <sstream>
#include <fstream>

template <class T>
class GraphVizTree {
  public:
  GraphVizTree(Tree<T>* tree) : m_tree(tree) {};

  void generateDot() {
    m_tree->traverse(
        Tree<T>::TraversalOrder::PreOrder,
        std::bind(
          &GraphVizTree::_printDotNode,
          this,
          std::placeholders::_1
          )
        );
    std::ofstream ofile;
    ofile.open ("output.dot");
    ofile 
      << 
      "digraph G\n" 
      "{\n"
      "  node [shape = record];\n"
      <<
      m_edges
      <<
      "\n\n"
      << 
      m_vertices
      <<
      "}\n"
      ;
    ofile.close();
  }

  private:
  void _printDotNode(Node<T>* node) {
    _vertex(node);
    if (node->left) {
      _edgeStr(node, node->left, 0);
    }
    if (node->right) {
      _edgeStr(node, node->right, 2);
    }
  }

  void _vertex(Node<T>* node) {
    std::ostringstream oss;
    oss << "  node" << node->id << " [ label =\"<f0> | <f1> "<< node->value << " | <f2> \"];\n";
    m_edges += oss.str();
  }

  void _edgeStr(Node<T>* parent, Node<T>* child, unsigned int f) {
    std::ostringstream oss;
    oss << "  \"node" << parent->id << "\":f" << f << " -> \"node" << child->id << "\":f1 ;\n";
    m_vertices += oss.str();
  }

  private:
  Tree<T>* m_tree;
  std::string m_edges;
  std::string m_vertices;
};

#endif 
