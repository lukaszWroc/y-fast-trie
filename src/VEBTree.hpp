#ifndef VEBTREE_H

#define VEBTREE_H

#define VEBTREE_NIL -1

#include <vector>

class VEBTree
{
  int universe_;
  int min_;
  int max_;
  int numOfBits_;

  VEBTree *summary_;

  std::vector<VEBTree*> clusters_;

  inline int index(int high, int low)
  {
    return (high << numOfBits_) | low;
  };

  inline int getHigh(int x)
  {
    return x >> numOfBits_;
  };

  inline int getLow(int x)
  {
    return ((x >> numOfBits_) << numOfBits_) ^ x;
  };

public:
  VEBTree(int universe);
  ~VEBTree();

  void insert(int x);

  bool member(int x);

  int predecessor(int x);
  int successor(int x);

  inline int minimum()
  {
    return min_;
  }

  inline int maximum()
  {
    return max_;
  }
};

#endif // VEBTREE_H
