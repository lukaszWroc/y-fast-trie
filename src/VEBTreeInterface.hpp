#ifndef VEBTREEINTERFACE_H

#define VEBTREEINTERFACE_H

#include "TreeBase.hpp"
#include "VEBTree.hpp"

class VEBTreeInterface : public TreeBase
{
  VEBTree *tree_;

public:
  VEBTreeInterface(std::vector<int>& input, int universe);
  ~VEBTreeInterface();

  int predecessor(int x);
  int successor(int x);

  bool member(int x);
};

#endif // VEBTREEINTERFACE_H
