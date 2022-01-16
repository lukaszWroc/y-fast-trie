#ifndef TREEBASE_H

#define TREEBASE_H

class TreeBase
{
public:
  virtual ~TreeBase();

  virtual bool member(long long int x) = 0;

  virtual long long int predecessor(long long int x) = 0;
  virtual long long int successor(long long int x) = 0;
};

#endif // TREEBASE_H
