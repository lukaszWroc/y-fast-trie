CFLAGS = -Wall -Wextra -Wpedantic -std=c++17 -Ofast -march=native -flto -s -DNDEBUG

TESTER_FILES = src/TreeBase.cpp src/VEBTree.cpp src/VEBTreeInterface.cpp src/XFastTrie.cpp src/XFastTrieInterface.cpp \
	src/YFastTrie.cpp src/YFastTrieInterface.cpp src/BST.cpp src/PrefectHash.cpp tester.cpp

TESTERGENERATOR_FILES = testgenerator.cpp

all: tester testgenerator

tester:
	mkdir -p build

	g++ ${CFLAGS} ${TESTER_FILES} -o ./build/tester

testgenerator:
	mkdir -p build

	g++ ${CFLAGS} ${TESTERGENERATOR_FILES} -o ./build/testgenerator

clean-tester:
	rm ./build/tester

clean-testgenerator:
	rm ./build/testgenerator

clean: clean-tester clean-testgenerator
