#include <iostream>
#include "../src/Trie.h"

using namespace std;

int main() {
  Trie* trie = new Trie();
  trie->add("asparagus");
  trie->add("aspen");
  cout << "This should be true: " << trie->search("asparagus") << endl;
  cout << "This should be false: " << trie->search("aaragus") << endl;
}