#ifndef BST_H

#define BST_H

#include <set>

class BST
{
  std::set<int> set_;
  std::set<int> rSet_;

  int max_;
  int min_;

public:
  BST();

  int maximum();
  int minimum();
  int size();
  int predecessor(int x);
  int successor(int x);

  void insert(int x);

  bool find(int x);
};

#endif // BST_H

