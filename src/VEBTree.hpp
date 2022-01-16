#ifndef VEBTREE_H

#define VEBTREE_H

#define VEBTREE_NIL -1

#include <vector>

class VEBTree
{
  long long int universe_;
  long long int min_;
  long long int max_;
  long long int numOfBits_;

  VEBTree *summary_;

  std::vector<VEBTree*> clusters_;

  inline long long int index(long long int high, long long int low)
  {
    return (high << numOfBits_) | low;
  };

  inline long long int getHigh(long long int x)
  {
    return x >> numOfBits_;
  };

  inline long long int getLow(long long int x)
  {
    return ((x >> numOfBits_) << numOfBits_) ^ x;
  };

public:
  VEBTree(long long int universe);
  ~VEBTree();

  void insert(long long int x);

  bool member(long long int x);

  long long int predecessor(long long int x);
  long long int successor(long long int x);

  inline long long int minimum()
  {
    return min_;
  }

  inline long long int maximum()
  {
    return max_;
  }
};

#endif // VEBTREE_H
