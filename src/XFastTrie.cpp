#include "XFastTrie.hpp"

#include <algorithm>
#include <set>

XFastTrie::XFastTrie(long long int universe, const std::vector<long long int> &input) : universe_(universe),
  levels_(63 - __builtin_clzl(universe)), input_(input)
{
  long long int levels = levels_;

  sort(input_.begin(), input_.end());

  std::vector<long long int> tmp;
  std::vector<long long int> tmp2;

  levelsList_.resize(levels_ + 1);

  for (long long int i=0;i<(long long int)input_.size();i++)
  {
    if (i-1>=0 && input_[i-1] == input_[i])
    {
      continue;
    }

    long long int x = input_[i];

    levelsList_[levels].insert(x, new InternalNode(i, i, i));

    tmp.push_back(x);
  }

  while (--levels)
  {
    std::set<long long int> helperSet;

    for (size_t i=0;i<tmp.size();i++)
    {
      long long int x = tmp[i] >> 1;

      helperSet.insert(x);
    }

    for (std::set<long long int>::iterator it = helperSet.begin(); it != helperSet.end(); it++)
    {
      long long int x = *it;

      tmp2.push_back(x);

      long long int xl = x << 1;
      long long int xp = (x << 1) | 1;

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

    swap(tmp, tmp2);

    tmp2.clear();
  }
}

XFastTrie::~XFastTrie()
{
  levelsList_.clear();
}

bool XFastTrie::member(long long int x)
{
  return levelsList_[levels_].find(x) != NULL;
}

long long int XFastTrie::predSuccBase(long long int x)
{
  long long int l=0, r=levels_, m;

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

long long int XFastTrie::predecessor(long long int x)
{
  long long int idx = predSuccBase(x);

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

long long int XFastTrie::successor(long long int x)
{
  long long int idx = predSuccBase(x);

  if (idx != -1)
  {
    if (x < input_[idx])
    {
      return input_[idx];
    }
    else if (++idx < (long long int)input_.size())
    {
      return input_[idx];
    }
  }

  return -1;
}

