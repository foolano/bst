#ifndef TREE_H
#define TREE_H

#include <functional>
#include <iostream>

template <class T>
struct Node {
  Node(T val) : value(val), left(0), right(0), id(0) {}
  T value;
  Node<T> *left;
  Node<T> *right;
  unsigned int id;
};


template <class T>
class Tree {
  public:
  enum TraversalOrder { PreOrder, InOrder, PostOrder};

  Tree() : m_root(0), m_lastid(0) {};

  void insert(T val) {
    _insert(m_root, val);
  }
  
  void traverse(TraversalOrder order, std::function<void(Node<T>*)> f) {
    _traverse(m_root, order, f);
  }

  void printTraverse(TraversalOrder order) {
    std::cout << "Traverse: " << std::endl;
    _traverse(
        m_root,
        order,
        std::bind(
          &Tree<T>::print_node,
          this,
          std::placeholders::_1
        )
    );
    std::cout << std::endl;
  }

  private:
  void _insert(Node<T>* &node, T val) {
    if (node == 0) {
      node = new Node<T>(val);
      node->id = ++m_lastid;
    } else if (val < node->value) {
      _insert(node->left, val);
    } else {
      _insert(node->right, val);
    }
  }

  void _traverse(Node<T>* node, TraversalOrder order, std::function<void(Node<T>*)> f) {
    if (node) {
      if (order == PreOrder) f(node);
      _traverse(node->left, order, f);
      if (order == InOrder) f(node);
      _traverse(node->right, order, f);
      if (order == PostOrder) f(node);
    }
  }

  void print_node(Node<T>* node) { 
    std::cout << node->value<< std::endl;
  }

  private:
  Node<T> *m_root;
  unsigned int m_lastid;
};

#endif
