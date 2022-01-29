#ifndef YFASTTRIE_H

#define YFASTTRIE_H

#include <vector>

#include "XFastTrie.hpp"
#include "BST.hpp"
#include "PerfectHash.hpp"

class YFastTrie
{
  int universe_;
  int bstSize_;

  std::vector<int> input_;
  std::vector<BST> bstList_;

  XFastTrie *xFastTrie;

  PerfectHash<int, int> numToBst_;

public:
  YFastTrie(int universe, std::vector<int> &input);
  YFastTrie(int universe, std::vector<int> &input, int state);
  ~YFastTrie();

  void init(std::vector<int> &input);

  bool member(int x);

  std::pair<BST*, BST*> predSuccBase(int x);

  int predecessor(int x);
  int successor(int x);
};

#endif // YFASTTRIE_H
