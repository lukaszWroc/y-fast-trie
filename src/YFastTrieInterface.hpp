#ifndef YFASTTRIEINTERFACE_H

#define YFASTTRIEINTERFACE_H

#include "TreeBase.hpp"
#include "YFastTrie.hpp"

class YFastTrieInterface : public TreeBase
{
  YFastTrie *tree_;

public:
  YFastTrieInterface(std::vector<int>& input, int universe);
  YFastTrieInterface(std::vector<int>& input, int universe, int state);
  ~YFastTrieInterface();

  int predecessor(int x);
  int successor(int x);

  bool member(int x);
};

#endif // YFASTTRIEINTERFACE_H
