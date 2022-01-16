#include "YFastTrie.hpp"

#include <algorithm>

YFastTrie::YFastTrie(long long int universe, const std::vector<long long int> &in, int state) : universe_(universe),
  bstSize_(63 - __builtin_clzl(universe))
{
  bstSize_ = bstSize_ + (bstSize_ * state)/100;

  init(in);
}

YFastTrie::YFastTrie(long long int universe, const std::vector<long long int> &in) : universe_(universe),
  bstSize_(63 - __builtin_clzl(universe))
{
  init(in);
}

void YFastTrie::init(const std::vector<long long int> &in)
{
  std::vector<long long int> v;

  std::vector<long long int> input(in);

  sort(input.begin(), input.end());

  bstList_.push_back(BST());

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
      v.push_back(bstList_.back().maximum());

      bstList_.push_back(BST());

      bstList_.back().insert(input[i]);
    }
  }

  v.push_back(bstList_.back().maximum());

  for (size_t i=0;i<v.size();i++)
  {
    numToBst_.insert(v[i], &bstList_[i]);
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

bool YFastTrie::member(long long int x)
{
  long long int pred = xFastTrie -> predecessor(x+1);
  long long int succ = xFastTrie -> successor(x-1);

  BST *bstPred = numToBst_.find(pred);
  BST *bstSucc = numToBst_.find(succ);

  return (bstPred != NULL ? bstPred -> find(x) : false) || 
         (bstSucc != NULL ? bstSucc -> find(x) : false);
}

std::pair<BST*, BST*> YFastTrie::predSuccBase(long long int x)
{
  long long int pred = xFastTrie -> predecessor(x+1);
  long long int succ = xFastTrie -> successor(x-1);

  if (succ == pred)
  {
    succ = xFastTrie -> successor(x);
  }

  BST *bstPred = numToBst_.find(pred);
  BST *bstSucc = numToBst_.find(succ);

  return std::make_pair(bstPred, bstSucc);
}

long long int YFastTrie::predecessor(long long int x)
{
  std::pair<BST*, BST*> bstPair = predSuccBase(x);

  long long int x1 = -1, x2 = -1;

  if (bstPair.first != NULL)
  {
    x1 = bstPair.first -> predecessor(x);
  }

  if (bstPair.second != NULL)
  {
    x2 = bstPair.second -> predecessor(x);
  }

  if (x1 != -1 && x2 != -1)
  {
    return (x1 < x2 ? x2 : x1);
  }
  else if (x1 != -1)
  {
    return x1;
  }
  else
  {
    return x2;
  }

  return -1;
}

long long int YFastTrie::successor(long long int x)
{
  std::pair<BST*, BST*> bstPair = predSuccBase(x);

  long long int x1 = -1, x2 = -1;

  if (bstPair.first != NULL)
  {
    x1 = bstPair.first -> successor(x);
  }

  if (bstPair.second != NULL)
  {
    x2 = bstPair.second -> successor(x);

    if (bstPair.first != NULL && x1 == -1 && bstPair.first -> find(x))
    {
      x1 = bstPair.second -> minimum();
    }
  }

  if (x1 != -1 && x2 != -1)
  {
    return (x1 > x2 ? x2 : x1);
  }
  else if (x1 != -1)
  {
    return x1;
  }
  else
  {
    return x2;
  }

  return -1;
}

