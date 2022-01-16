#include "VEBTreeInterface.hpp"

VEBTreeInterface::VEBTreeInterface(std::vector<long long int>& input, long long int universe)
{
  tree_ = new VEBTree(universe);

  for (long long int x : input)
  {
    tree_ ->insert(x);
  }
}

VEBTreeInterface::~VEBTreeInterface()
{
  if (tree_ != NULL)
  {
    delete tree_;

    tree_ = NULL;
  }
}

long long int VEBTreeInterface::predecessor(long long int x)
{
  return tree_ -> predecessor(x);
}

long long int VEBTreeInterface::successor(long long int x)
{
  return tree_ -> successor(x);
}

bool VEBTreeInterface::member(long long int x)
{
  return tree_ -> member(x);
}