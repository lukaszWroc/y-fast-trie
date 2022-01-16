#include <bits/stdc++.h> 

#include "./src/TreeBase.hpp"
#include "./src/VEBTreeInterface.hpp"
#include "./src/XFastTrieInterface.hpp"
#include "./src/YFastTrieInterface.hpp"

using namespace std;

#define FAIL(x) if (x) goto fail;

struct Options
{
  string dataPath;
  string questionsPath;
  string outPath;
  string treeName;

  long long int universum;
  long long int state;
};

bool parseArgs(Options &options, int argc, char *argv[])
{
  FAIL(argc < 6);

  options.treeName      = argv[1];
  options.dataPath      = argv[2];
  options.questionsPath = argv[3];
  options.outPath       = argv[4];
  options.universum     = stoll(argv[5]);

  if (options.treeName == "--yfasttrie")
  {
    FAIL(argc != 7);

    options.state = stoi(argv[6]);
  }

  return false;

  fail:

  return true;
}

void readVector(string file, vector<long long int> &v)
{
  ifstream fhandle(file);

  if (fhandle.is_open())
  {
    while (!fhandle.eof())
    {
      char c;
      long long int x;

      fhandle >> c >> x;

      v.push_back(x);
    }

    fhandle.close();
  }
}

void writeVector(string file, vector<long long int> &v)
{
  fstream fhandle(file, ios::out);

  if (fhandle.is_open())
  {

    for (long long int x : v)
    {
      fhandle << x << "\n";
    }

    fhandle.close();
  }
}

void setTree(TreeBase *&tree, Options &options, vector<long long int> &v)
{
  if (options.treeName == "--veb")
  {
    tree = new VEBTreeInterface(v, options.universum);
  }
  else if (options.treeName == "--xfasttrie")
  {
    tree = new XFastTrieInterface(v, options.universum);
  }
  else if (options.treeName == "--yfasttrie")
  {
    tree = new YFastTrieInterface(v, options.universum, options.state);
  }
}

int main(int argc, char *argv[])
{
  Options options;

  if (parseArgs(options, argc, argv))
  {
    return -1;
  }

  vector<long long int> in;
  vector<long long int> out;
  vector<long long int> questions;

  readVector(options.dataPath,      in);
  readVector(options.questionsPath, questions);

  TreeBase *tree = NULL;

  setTree(tree, options, in);

  std::chrono::high_resolution_clock::time_point startTime(std::chrono::high_resolution_clock::now());

  for (long long int x : questions)
  {
    out.push_back(tree -> successor(x));
  }

  std::chrono::high_resolution_clock::time_point endTime(std::chrono::high_resolution_clock::now());

  ulong ms = std::chrono::duration_cast<std::chrono::milliseconds>(endTime-startTime).count();

  cout << ms;

  writeVector(options.outPath, out);

  return 0;
}