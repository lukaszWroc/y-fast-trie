#include "VEBTreeInterface.hpp"

VEBTreeInterface::VEBTreeInterface(std::vector<int>& input, int universe)
{
  tree_ = new VEBTree(universe);

  for (int x : input)
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

int VEBTreeInterface::predecessor(int x)
{
  return tree_ -> predecessor(x);
}

int VEBTreeInterface::successor(int x)
{
  return tree_ -> successor(x);
}

bool VEBTreeInterface::member(int x)
{
  return tree_ -> member(x);
}