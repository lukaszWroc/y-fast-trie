#ifndef XFASTTRIE_H

#define XFASTTRIE_H

#include <vector>

#include "PerfectHash.hpp"

class InternalNode
{
  long long int il_, ir_, descedant_;

public:
  InternalNode(long long int il, long long int ir, long long int descedant) : il_(il), ir_(ir), descedant_(descedant)
  {
  }

  long long int getDescedant()
  {
    return descedant_;
  }

  long long int getIndexLeft()
  {
    return il_;
  }

  long long int getIndexRight()
  {
    return ir_;
  }
};

class XFastTrie
{
  long long int universe_;
  long long int levels_;

  std::vector<long long int> input_;

  std::vector<PerfectHash<long long int, InternalNode>> levelsList_;

public:
  XFastTrie(long long int universe, const std::vector<long long int> &input);
  ~XFastTrie();

  bool member(long long int x);

  long long int predSuccBase(long long int x);
  long long int predecessor(long long int x);
  long long int successor(long long int x);
};

#endif // XFASTTRIE_H
