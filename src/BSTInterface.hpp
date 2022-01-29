#ifndef BSTINTERFACE_H

#define BSTINTERFACE_H

#include "TreeBase.hpp"
#include "BST.hpp"

#include <vector>

class BSTInterface : public TreeBase
{
  BST *tree_;

public:
  BSTInterface(std::vector<int>& input)
  {
    tree_ = new BST;

    for (size_t i=0;i<input.size();i++)
    {
      tree_ -> insert(input[i]);
    }

  }

  ~BSTInterface()
  {
    if (tree_ != NULL)
    {
      delete tree_;
    }
  }

  int predecessor(int x)
  {
    return tree_ -> predecessor(x);
  }

  int successor(int x)
  {
    return tree_ -> successor(x);
  }

  bool member(int x)
  {
    return tree_ -> find(x);
  }
};

#endif // BSTINTERFACE_H
