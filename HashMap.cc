#include <stdio.h>
#include <iostream>

template <typename KEY, typename VALUE>
KEY Node<KEY, VALUE>::getKey() {
  return key;
}

template <typename KEY, typename VALUE>
VALUE Node<KEY, VALUE>::getValue() {
  return value;
}

template <typename KEY, typename VALUE>
HashMap<KEY, VALUE>::HashMap():n(0), head(kHASHSIZE) {
  for (int i = 0; i < kHASHSIZE; i++) {
    Node<KEY, VALUE> *temp = new Node<KEY, VALUE>();
    head[i] = temp;
  }
}

template <typename KEY, typename VALUE>
int HashMap<KEY, VALUE>::size() {
  return n;
}

template <typename KEY, typename VALUE>
bool HashMap<KEY, VALUE>::empty() {
  return n == 0;
}

template <typename KEY, typename VALUE>
int HashMap<KEY, VALUE>::insert(KEY key, VALUE value) {
  unsigned long long hv = HashValue(key);
  int p = hv % kHASHSIZE;
  for (Node<KEY, VALUE> *ptr = head[p]; ptr->next; ptr = ptr->next)
    if (ptr->next->key == key) return 1;
  Node<KEY, VALUE> *node = new Node<KEY, VALUE>(key, value);
  node->next = head[p]->next;
  head[p]->next = node;
  ++n;
  return 0;
}

template <typename KEY, typename VALUE>
Node<KEY, VALUE> *HashMap<KEY, VALUE>::find(KEY key) {
  unsigned long long hv = HashValue(key);
  int p = hv % kHASHSIZE;
  for (Node<KEY, VALUE> *ptr = head[p]; ptr->next; ptr = ptr->next)
    if (ptr->next->key == key) return ptr->next;
  return NULL;
}

template <typename KEY, typename VALUE>
void HashMap<KEY, VALUE>::clear() {
  n = 0;
  for (int i = 0; i < kHASHSIZE; i++) {
    if (head[i]->next) delete head[i]->next;
  }
}

template <typename KEY, typename VALUE>
int HashMap<KEY, VALUE>::erase(KEY key) {
  unsigned long long hv = HashValue(key);
  int p = hv % kHASHSIZE;
  for (Node<KEY, VALUE> *ptr = head[p]; ptr->next; ptr = ptr->next)
    if (ptr->next->key == key) {
      Node<KEY, VALUE> *temp = ptr->next;
      ptr->next = temp->next;
      temp->next = NULL;
      delete temp;
      --n;
      return 0;
    }
  return 1;
}

template<typename KEY, typename VALUE>
unsigned long long HashMap<KEY, VALUE>::HashValue(KEY key) {
  return (unsigned long long)(key);
}

template<typename KEY, typename VALUE>
VALUE &HashMap<KEY, VALUE>::operator [] (const KEY &index) {
  Node<KEY, VALUE> *ptr = find(index);
  if (ptr != NULL) return ptr->value;
  VALUE *value = new VALUE();
  insert(index, *value);
  ptr = find(index);
  return ptr->value;
}
