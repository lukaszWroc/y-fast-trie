#ifndef YFASTTRIEINTERFACE_H

#define YFASTTRIEINTERFACE_H

#include "TreeBase.hpp"
#include "YFastTrie.hpp"

class YFastTrieInterface : public TreeBase
{
  YFastTrie *tree_;

public:
  YFastTrieInterface(std::vector<long long int>& input, long long int universe);
  YFastTrieInterface(std::vector<long long int>& input, long long int universe, int state);
  ~YFastTrieInterface();

  long long int predecessor(long long int x);
  long long int successor(long long int x);

  bool member(long long int x);
};

#endif // YFASTTRIEINTERFACE_H
