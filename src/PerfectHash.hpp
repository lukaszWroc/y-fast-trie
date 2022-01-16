#ifndef PERFECTHASH_H

#define PERFECTHASH_H

#include <unordered_map>

template<class KEY, class VAL>
class PerfectHash
{
  std::unordered_map<KEY, VAL*> table_;

public:
  VAL *find(KEY x)
  {
    if (table_.find(x) != table_.end())
    {
      return table_[x];
    }

    return NULL;
  }

  void insert(KEY key, VAL *val)
  {
    if (find(key) == NULL)
    {
      table_[key] = val;
    }
  }
};

#endif // PERFECTHASH_H

