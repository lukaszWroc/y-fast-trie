#ifndef XFASTTRIEINTERFACE_H

#define XFASTTRIEINTERFACE_H

#include "TreeBase.hpp"
#include "XFastTrie.hpp"

class XFastTrieInterface : public TreeBase
{
  XFastTrie *tree_;

public:
  XFastTrieInterface(std::vector<int>& input, int universe);
  ~XFastTrieInterface();

  int predecessor(int x);
  int successor(int x);

  bool member(int x);
};

#endif // XFASTTRIEINTERFACE_H
