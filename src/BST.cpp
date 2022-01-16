#include "BST.hpp"

BST::BST() : max_(-1), min_(-1)
{
}

long long int BST::maximum()
{
  return max_;
}

long long int BST::minimum()
{
  return min_;
}

long long int BST::size()
{
  return set_.size();
}

void BST::insert(long long int x)
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

bool BST::find(long long int x)
{
  return set_.find(x) != set_.end();
}

long long int BST::predecessor(long long int x)
{
  std::set<long long int>::iterator it = rSet_.upper_bound(-x);

  if (it != rSet_.end())
  {
    return -1 * (*it);
  }

  return -1;
}

long long int BST::successor(long long int x)
{
  std::set<long long int>::iterator it = set_.upper_bound(x);

  if (it != set_.end())
  {
    return *it;
  }

  return -1;
}