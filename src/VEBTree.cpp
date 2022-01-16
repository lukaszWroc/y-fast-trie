#include "VEBTree.hpp"

VEBTree::VEBTree(long long int universe) : universe_(universe), min_(VEBTREE_NIL),
  max_(VEBTREE_NIL), numOfBits_((63 - __builtin_clzl(universe))/2), summary_(NULL)
{
  if (universe_ <= 0)
  {
    return;
  }
  else if (universe_ > 2)
  {
    clusters_.resize(universe_ >> numOfBits_, NULL);
  }
}

VEBTree::~VEBTree()
{
  if (summary_)
  {
    delete summary_;

    summary_ = NULL;
  }

  for (VEBTree *c : clusters_)
  {
    delete c;
  }

  clusters_.clear();
}

void VEBTree::insert(long long int x)
{
  if (x < 0 || universe_ <= x)
  {
    return;
  }

  if (min_ == VEBTREE_NIL)
  {
    min_ = x;
    max_ = x;
  }
  else
  {
    if (x < min_)
    {
      std::swap(x, min_);
    }

    if (universe_ > 2)
    {
      long long int high = getHigh(x);
      long long int low  = getLow(x);

      if (clusters_[high] == NULL)
      {
        clusters_[high] = new VEBTree(universe_ >> numOfBits_);
      }

      if (clusters_[high] -> minimum() == VEBTREE_NIL)
      {
        if (summary_ == NULL)
        {
          summary_ = new VEBTree(universe_ >> numOfBits_);
        }

        summary_ -> insert(high);

        clusters_[high] -> insert(low);
      }
      else
      {
        clusters_[high] -> insert(low);
      }
    }
    
    if (x > max_)
    {
      max_ = x;
    }
  }
}

long long int VEBTree::successor(long long int x)
{
  if (universe_ == 2)
  {
    if (x == 0 && max_ == 1)
    {
      return 1;
    }
    else
    {
      return VEBTREE_NIL;
    }
  }
  else if (min_ != VEBTREE_NIL && x < min_)
  {
    return min_;
  }
  else
  {
    long long int high = getHigh(x);
    long long int low  = getLow(x);

    long long int maxLow = VEBTREE_NIL;

    if (clusters_[high] != NULL)
    {
      maxLow = clusters_[high] -> maximum();
    }

    if (maxLow != VEBTREE_NIL && low < maxLow)
    {
      long long int offset = clusters_[high] -> successor(low);

      return index(high, offset);
    }
    else
    {
      if (summary_ == NULL)
      {
        return VEBTREE_NIL;
      }

      long long int succCluster = summary_ -> successor(high);

      if (succCluster == VEBTREE_NIL)
      {
        return VEBTREE_NIL;
      }
      else
      {
        if (clusters_[succCluster] == NULL)
        {
          return VEBTREE_NIL;
        }

        long long int offset = clusters_[succCluster] -> minimum();

        return index(succCluster, offset);
      }
    }
  }

  return VEBTREE_NIL;
}

long long int VEBTree::predecessor(long long int x)
{
  if (universe_ == 2)
  {
    if (x == 1 && min_ == 0)
    {
      return 0;
    }
    else
    {
      return VEBTREE_NIL;
    }
  }
  else if (max_ != VEBTREE_NIL && x > max_)
  {
    return max_;
  }
  else
  {
    long long int high = getHigh(x);
    long long int low = getLow(x);

    long long int minLow = VEBTREE_NIL;

    if (clusters_[high] != NULL)
    {
      minLow = clusters_[high] -> minimum();
    }

    if (minLow != VEBTREE_NIL && low > minLow)
    {
      long long int offset = clusters_[high] -> predecessor(low);

      return index(high, offset);
    }
    else
    {
      if (summary_ == NULL)
      {
        return VEBTREE_NIL;
      }

      long long int predCluster = summary_ -> predecessor(high);

      if (predCluster == VEBTREE_NIL)
      {
        if (min_ != VEBTREE_NIL && x > min_)
        {
          return min_;
        }
        else
        {
          return VEBTREE_NIL;
        }
      }
      else
      {
        if (clusters_[predCluster] == NULL)
        {
          return VEBTREE_NIL;
        }

        long long int offset = clusters_[predCluster] -> maximum();

        return index(predCluster, offset);
      }
    }
  }

  return VEBTREE_NIL;
}

bool VEBTree::member(long long int x)
{
  if (x == min_ || x == max_)
  {
    return true;
  }
  else if (universe_ == 2)
  {
    return false;
  }
  else
  {
    long long int high = getHigh(x);
    long long int low  = getLow(x);

    if (clusters_[high] != NULL)
    {
      return clusters_[high] -> member(low);
    }
  }

  return false;
}