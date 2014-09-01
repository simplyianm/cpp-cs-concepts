#include "Trie.h"

Trie::Trie() {
  top = new TrieNode('\0');
}

bool Trie::add(string val) {
  TrieNode* node = top;
  bool created;
  // Iterate and create nodes if they don't exist
  for (int i = 0; val[i] != '\0'; i++) {
    char c = val[i];

    // Find the node
    vector<TrieNode*>* nodes = &node->nodes;

    // The next node
    TrieNode* next = 0;

    // Iterate over the nodes
    for (vector<TrieNode*>::iterator it = nodes->begin(); it != nodes->end(); ++it) {
      // Break if value is equal
      if ((*it)->val == c) {
        next = *it;
        break;
      }
    }

    // Create the node if it doesn't exist
    if (!next) {
      created = true;
      next = new TrieNode(c);
      nodes->push_back(next);
    }


    // Set the next iterated node
    node = next;
  }
  return created;
}

bool Trie::search(string val) {
  TrieNode* node = top;
  // Iterate and create nodes if they don't exist
  for (int i = 0; val[i] != '\0'; i++) {
    char c = val[i];

    // Find the node
    vector<TrieNode*>* nodes = &node->nodes;
    bool found = false;
    for (vector<TrieNode*>::iterator it = nodes->begin(); it != nodes->end(); ++it) {
      if ((*it)->val == c) {
        node = *it;
        found = true;
        break;
      }
    }

    if (!found) {
      return false;
    }
  }
  return true;
}
