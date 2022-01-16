#ifndef VEBTREEINTERFACE_H

#define VEBTREEINTERFACE_H

#include "TreeBase.hpp"
#include "VEBTree.hpp"

class VEBTreeInterface : public TreeBase
{
  VEBTree *tree_;

public:
  VEBTreeInterface(std::vector<long long int>& input, long long int universe);
  ~VEBTreeInterface();

  long long int predecessor(long long int x);
  long long int successor(long long int x);

  bool member(long long int x);
};

#endif // VEBTREEINTERFACE_H
