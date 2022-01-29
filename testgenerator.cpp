#include <bits/stdc++.h> 

using namespace std;

#define FAIL(x) if (x) goto fail;

typedef std::function<void(int, int)> createFunction;

mt19937 random_generator;

void create(char c, int n, int univ)
{
  while (n--)
  {
    cout << c << " " << std::uniform_int_distribution<unsigned int>(0,univ)(random_generator) << "\n";
  }
}
void createData(int n, int univ)
{
  create('i', n, univ);
}

void createQuestions(int n, int univ)
{
  create('q', n, univ);
}

map<string, createFunction> funcList{
  {"data", createData}, {"questions", createQuestions}};

size_t sysrandom(void* dst, size_t dstlen)
{
  char* buffer = reinterpret_cast<char*>(dst);
  ifstream stream("/dev/urandom", std::ios_base::binary | std::ios_base::in);
  stream.read(buffer, dstlen);

  return dstlen;
}

int main(int argc, char *argv[])
{
  map<string, createFunction>::iterator ele;
  int n;
  int univ;

  std::array<int, std::mt19937::state_size> state;
  sysrandom(state.begin(), state.size()*sizeof(int));
  std::seed_seq s(state.begin(), state.end());

  random_generator.seed(s);

  FAIL(argc != 4);

  ele = funcList.find(argv[1]);

  FAIL(ele == end(funcList));

  n    = stoi(argv[2]);
  univ = stoll(argv[3]);

  FAIL((0 > n || n > 2e8));
  FAIL((0 > univ || univ > 2e19));

  ele -> second(n, univ);

  return 0;

  fail:

  return -1;
}