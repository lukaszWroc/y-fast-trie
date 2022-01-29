#include "YFastTrieInterface.hpp"

YFastTrieInterface::YFastTrieInterface(std::vector<int>& input, int universe)
{
  tree_ = new YFastTrie(universe, input);
}

YFastTrieInterface::YFastTrieInterface(std::vector<int>& input, int universe, int state)
{
  tree_ = new YFastTrie(universe, input, state);
}

YFastTrieInterface::~YFastTrieInterface()
{
  if (tree_ != NULL)
  {
    delete tree_;

    tree_ = NULL;
  }
}

int YFastTrieInterface::predecessor(int x)
{
  return tree_ -> predecessor(x);
}

int YFastTrieInterface::successor(int x)
{
  return tree_ -> successor(x);
}

bool YFastTrieInterface::member(int x)
{
  return tree_ -> member(x);
}