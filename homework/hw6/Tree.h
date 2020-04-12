//Kenneth Oseleononmen
//koseleo1


#ifndef _CTREE_H
#define _CTREE_H

#include <cstdlib>
#include <string>

// tree of characters, can be used to implement a trie
template<typename T>
class Tree {
  friend class TTreeTest;
  
  T data;     // the value stored in the tree node

  Tree * kids;  // children - pointer to first child of list, maintain order & uniqueness

  Tree * sibs;  // siblings - pointer to rest of children list, maintain order & uniqueness
                 // this should always be null if the object is the root of a tree

  Tree * prev;  // pointer to parent if this is a first child, or left sibling otherwise
                 // this should always be null if the object is the root of a tree

 public:
  template<typename X>
  friend std::ostream& operator<<(std::ostream& os, Tree<X>& rt);
  Tree(T val);

  ~Tree();  // clear siblings to right and children and this node
  
  Tree& operator^(Tree& rt);  //^ operator to do the same thing as addChild
  bool operator==(const Tree &root); // return true if two Trees match node by node
  
  // siblings and children must be unique, return true if added, false otherwise
  bool addChild(T val);

  // add tree root for better building, root should have null prev and sibs 
  // returns false on any type of failure, including invalid root
  bool addChild(Tree *root);

  std::string toString(); // all characters, separated by newlines, including at the end

  
 private:
  // these should only be called from addChild, and have the same restrictions
  // the root of a tree should never have any siblings
  // returns false on any type of failure, including invalid root
  bool addSibling(T val);
  bool addSibling(Tree *root);

};

#include "Tree.inc"

#endif
