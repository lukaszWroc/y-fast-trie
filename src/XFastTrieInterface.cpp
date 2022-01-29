#include "XFastTrieInterface.hpp"

XFastTrieInterface::XFastTrieInterface(std::vector<int>& input, int universe)
{
  tree_ = new XFastTrie(universe, input);
}

XFastTrieInterface::~XFastTrieInterface()
{
  if (tree_ != NULL)
  {
    delete tree_;

    tree_ = NULL;
  }
}

int XFastTrieInterface::predecessor(int x)
{
  return tree_ -> predecessor(x);
}

int XFastTrieInterface::successor(int x)
{
  return tree_ -> successor(x);
}

bool XFastTrieInterface::member(int x)
{
  return tree_ -> member(x);
}