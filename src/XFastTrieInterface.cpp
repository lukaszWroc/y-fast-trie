#include "XFastTrieInterface.hpp"

XFastTrieInterface::XFastTrieInterface(std::vector<long long int>& input, long long int universe)
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

long long int XFastTrieInterface::predecessor(long long int x)
{
  return tree_ -> predecessor(x);
}

long long int XFastTrieInterface::successor(long long int x)
{
  return tree_ -> successor(x);
}

bool XFastTrieInterface::member(long long int x)
{
  return tree_ -> member(x);
}