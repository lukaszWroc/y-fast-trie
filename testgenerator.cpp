#include <bits/stdc++.h> 

using namespace std;

#define FAIL(x) if (x) goto fail;

typedef std::function<void(int, long long int)> createFunction;

mt19937 random_generator;

void create(char c, int n, long long int univ)
{
  while (n--)
  {
    cout << c << " " << std::uniform_int_distribution<unsigned long long int>(0,univ)(random_generator) << "\n";
  }
}
void createData(int n, long long int univ)
{
  create('i', n, univ);
}

void createQuestions(int n, long long int univ)
{
  create('q', n, univ);
}

map<string, createFunction> funcList{
  {"data", createData}, {"questions", createQuestions}};

int main(int argc, char *argv[])
{
  map<string, createFunction>::iterator ele;
  int n;
  long long int univ;

  FAIL(argc != 4);

  ele = funcList.find(argv[1]);

  FAIL(ele == end(funcList));

  n    = stoi(argv[2]);
  univ = stoll(argv[3]);

  FAIL((0 > n || n > 2e8));
  FAIL((0 > univ || univ > 2e11));

  ele -> second(n, univ);

  return 0;

  fail:

  return -1;
}