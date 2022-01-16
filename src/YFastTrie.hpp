#ifndef YFASTTRIE_H

#define YFASTTRIE_H

#include <vector>

#include "XFastTrie.hpp"
#include "BST.hpp"
#include "PerfectHash.hpp"

class YFastTrie
{
  long long int universe_;
  long long int bstSize_;

  std::vector<long long int> input_;
  std::vector<BST> bstList_;

  XFastTrie *xFastTrie;

  PerfectHash<long long int, BST> numToBst_;

public:
  YFastTrie(long long int universe, const std::vector<long long int> &input);
  YFastTrie(long long int universe, const std::vector<long long int> &input, int state);
  ~YFastTrie();

  void init(const std::vector<long long int> &input);

  bool member(long long int x);

  std::pair<BST*, BST*> predSuccBase(long long int x);

  long long int predecessor(long long int x);
  long long int successor(long long int x);
};

#endif // YFASTTRIE_H
