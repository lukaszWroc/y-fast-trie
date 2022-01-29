#include "XFastTrie.hpp"

#include <algorithm>
#include <set>

XFastTrie::XFastTrie(int universe, std::vector<int> &input) : universe_(universe),
  levels_(63 - __builtin_clzl(universe))
{
  std::swap(input, input_);

  int levels = levels_;

  sort(input_.begin(), input_.end());

  std::vector<int> tmp;

  levelsList_.resize(levels_ + 1);

  for (int i=0;i<(int)input_.size();i++)
  {
    if (i-1>=0 && input_[i-1] == input_[i])
    {
      continue;
    }

    int x = input_[i];

    levelsList_[levels].insert(x, new InternalNode(i, i, i));

    tmp.emplace_back(x);
  }

  while (--levels)
  {
    std::set<int> helperSet;

    for (size_t i=0;i<tmp.size();i++)
    {
      int x = tmp[i] >> 1;

      helperSet.insert(x);
    }

    tmp.clear();
    tmp.shrink_to_fit();

    for (std::set<int>::iterator it = helperSet.begin(); it != helperSet.end(); it++)
    {
      int x = *it;

      tmp.emplace_back(x);

      int xl = x << 1;
      int xp = (x << 1) | 1;

      InternalNode *nl = levelsList_[levels + 1].find(xl);
      InternalNode *nr = levelsList_[levels + 1].find(xp);

      if (nl != NULL && nr != NULL)
      {
        levelsList_[levels].insert(x, new InternalNode(nl -> getIndexLeft(), nr -> getIndexRight(), -1));
      }
      else if (nl != NULL)
      {
        levelsList_[levels].insert(x, new InternalNode(nl -> getIndexLeft(), nl -> getIndexRight(), nl -> getIndexRight()));

      }
      else if (nr != NULL)
      {
        levelsList_[levels].insert(x, new InternalNode(nr -> getIndexLeft(), nr -> getIndexRight(), nr -> getIndexLeft()));
      }
    }
  }
}

XFastTrie::~XFastTrie()
{
  levelsList_.clear();
}

bool XFastTrie::member(int x)
{
  return levelsList_[levels_].find(x) != NULL;
}

int XFastTrie::predSuccBase(int x)
{
  int l=0, r=levels_, m;

  InternalNode *node = NULL;

  while (l <= r)
  {
    m = (l+r)/2;

    if (levelsList_[m].find(x >> (levels_ - m)))
    {
      node = levelsList_[m].find(x >> (levels_ - m));

      l = m + 1;
    }
    else
    {
      r = m -1;
    }
  }

  if (node != NULL)
  {
    return node -> getDescedant();
  }

  return -1;
}

int XFastTrie::predecessor(int x)
{
  int idx = predSuccBase(x);

  if (idx != -1)
  {
    if (x > input_[idx])
    {
      return input_[idx];
    }
    else if (--idx >= 0)
    {
      return input_[idx];
    }
  }

  return -1;
}

int XFastTrie::successor(int x)
{
  int idx = predSuccBase(x);

  if (idx != -1)
  {
    if (x < input_[idx])
    {
      return input_[idx];
    }
    else if (++idx < (int)input_.size())
    {
      return input_[idx];
    }
  }

  return -1;
}

