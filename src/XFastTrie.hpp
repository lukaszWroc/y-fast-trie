#ifndef XFASTTRIE_H

#define XFASTTRIE_H

#include <vector>

#include "PerfectHash.hpp"

class InternalNode
{
  int il_, ir_, descedant_;

public:
  InternalNode(int il, int ir, int descedant) : il_(il), ir_(ir), descedant_(descedant)
  {
  }

  int getDescedant()
  {
    return descedant_;
  }

  int getIndexLeft()
  {
    return il_;
  }

  int getIndexRight()
  {
    return ir_;
  }
};

class XFastTrie
{
  int universe_;
  int levels_;

  std::vector<int> input_;

  std::vector<PerfectHash<int, InternalNode>> levelsList_;

public:
  XFastTrie(int universe, std::vector<int> &input);
  ~XFastTrie();

  bool member(int x);

  int predSuccBase(int x);
  int predecessor(int x);
  int successor(int x);
};

#endif // XFASTTRIE_H
