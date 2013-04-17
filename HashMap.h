#ifndef HASHMAP_H
#define HASHMAP_H
#include <stdio.h>
#include <vector>

#define kHASHSIZE 997001

template <typename KEY, typename VALUE> class HashMap;

template <typename KEY, typename VALUE> class Node {
public:
  KEY getKey();
  VALUE getValue();
private:
  friend class HashMap<KEY, VALUE>;
  Node():next(NULL), key(), value() {}
  Node(const KEY &k, const VALUE &v): key(k), value(v), next(NULL) {}
  ~Node() {
    if (next) delete next;
  }
  KEY key;
  VALUE value;
  Node *next;
};

template <typename KEY, typename VALUE> class HashMap {
public:
  HashMap();
  int size();
  bool empty();
  int insert(KEY, VALUE);
  Node<KEY, VALUE> *find(KEY);
  int erase(KEY);
  void clear();

  VALUE &operator [] (const KEY&);

private:
  unsigned long long HashValue(KEY);
  std::vector<Node<KEY, VALUE>*> head;
  int n;
};

#include "HashMap.cc"
#endif
