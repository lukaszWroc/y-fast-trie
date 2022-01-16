#ifndef XFASTTRIEINTERFACE_H

#define XFASTTRIEINTERFACE_H

#include "TreeBase.hpp"
#include "XFastTrie.hpp"

class XFastTrieInterface : public TreeBase
{
  XFastTrie *tree_;

public:
  XFastTrieInterface(std::vector<long long int>& input, long long int universe);
  ~XFastTrieInterface();

  long long int predecessor(long long int x);
  long long int successor(long long int x);

  bool member(long long int x);
};

#endif // XFASTTRIEINTERFACE_H
