#ifndef TREEBASE_H

#define TREEBASE_H

class TreeBase
{
public:
  virtual ~TreeBase();

  virtual bool member(int x) = 0;

  virtual int predecessor(int x) = 0;
  virtual int successor(int x) = 0;
};

#endif // TREEBASE_H
