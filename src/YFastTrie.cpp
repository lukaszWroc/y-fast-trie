#include "YFastTrie.hpp"

#include <algorithm>

YFastTrie::YFastTrie(int universe, std::vector<int> &in, int state) : universe_(universe),
  bstSize_(63 - __builtin_clzl(universe))
{
  bstSize_ = bstSize_ + (bstSize_ * state)/100;

  init(in);
}

YFastTrie::YFastTrie(int universe, std::vector<int> &in) : universe_(universe),
  bstSize_(63 - __builtin_clzl(universe))
{
  init(in);
}

void YFastTrie::init(std::vector<int> &in)
{
  std::vector<int> v;

  std::vector<int> input(in);

  sort(input.begin(), input.end());

  bstList_.emplace_back(BST());

  for (size_t i=0;i<input.size();i++)
  {
    if (i > 0 && input[i-1] == input[i])
    {
      continue;
    }

    if (bstList_.back().size() < bstSize_)
    {
      bstList_.back().insert(input[i]);
    }
    else
    {
      v.emplace_back(bstList_.back().maximum());

      bstList_.emplace_back(BST());

      bstList_.back().insert(input[i]);
    }
  }

  v.emplace_back(bstList_.back().maximum());

  for (size_t i=0;i<v.size();i++)
  {
    numToBst_.insert(v[i], new int(i));
  }

  xFastTrie = new XFastTrie(universe_, v);
}

YFastTrie::~YFastTrie()
{
  if (xFastTrie != NULL)
  {
    delete xFastTrie;

    xFastTrie = NULL;
  }

  bstList_.clear();
}

bool YFastTrie::member(int x)
{
  int pred = xFastTrie -> predecessor(x);

  int *idxPtr = numToBst_.find(pred);

  int idx = (idxPtr == NULL ? -1 : *idxPtr);

  if (idx != -1 && idx+1 < (int)bstList_.size())
  {
    return bstList_[idx+1].find(x);
  }

  return false;
}

int YFastTrie::predecessor(int x)
{
  int pred = xFastTrie -> predecessor(x);

  int *idxPtr = numToBst_.find(pred);

  int idx = (idxPtr == NULL ? -1 : *idxPtr);

  int ans = -1;

  if (idx != -1)
  {
    if (idx+1 < (int)bstList_.size())
    {
      ans = bstList_[idx+1].predecessor(x);
    }

    if (ans == -1)
    {
      ans = pred;
    }
  }

  return ans;
}

int YFastTrie::successor(int x)
{
  int succ = xFastTrie -> successor(x);

  int *idxPtr = numToBst_.find(succ);

  int idx = (idxPtr == NULL ? -1 : *idxPtr);

  int ans = -1;

  if (idx != -1)
  {
    ans = bstList_[idx].successor(x);
  }

  return ans;
}
