#include "BST.hpp"

BST::BST() : max_(-1), min_(-1)
{
}

int BST::maximum()
{
  return max_;
}

int BST::minimum()
{
  return min_;
}

int BST::size()
{
  return set_.size();
}

void BST::insert(int x)
{
  if (x > max_)
  {
    max_ = x;
  }

  if (x < min_ || min_ == -1)
  {
    min_= x;
  }

  set_.insert(x);
  rSet_.insert(-x);
}

bool BST::find(int x)
{
  return set_.find(x) != set_.end();
}

int BST::predecessor(int x)
{
  std::set<int>::iterator it = rSet_.upper_bound(-x);

  if (it != rSet_.end())
  {
    return -1 * (*it);
  }

  return -1;
}

int BST::successor(int x)
{
  std::set<int>::iterator it = set_.upper_bound(x);

  if (it != set_.end())
  {
    return *it;
  }

  return -1;
}