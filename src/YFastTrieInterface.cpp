#include "YFastTrieInterface.hpp"

YFastTrieInterface::YFastTrieInterface(std::vector<long long int>& input, long long int universe)
{
  tree_ = new YFastTrie(universe, input);
}

YFastTrieInterface::YFastTrieInterface(std::vector<long long int>& input, long long int universe, int state)
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

long long int YFastTrieInterface::predecessor(long long int x)
{
  return tree_ -> predecessor(x);
}

long long int YFastTrieInterface::successor(long long int x)
{
  return tree_ -> successor(x);
}

bool YFastTrieInterface::member(long long int x)
{
  return tree_ -> member(x);
}