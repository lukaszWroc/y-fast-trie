#ifndef BST_H

#define BST_H

#include <set>

class BST
{
  std::set<long long int> set_;
  std::set<long long int> rSet_;

  long long int max_;
  long long int min_;

public:
  BST();

  long long int maximum();
  long long int minimum();
  long long int size();
  long long int predecessor(long long int x);
  long long int successor(long long int x);

  void insert(long long int x);

  bool find(long long int x);
};

#endif // BST_H

