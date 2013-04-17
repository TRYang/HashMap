#include <iostream>

#include "HashMap.h"

int main() {
  HashMap<int, int> h;
  h.insert(2, 1);
  h.insert(3, 10);
  std::cout << h[2] << std::endl;
  h[2] = 3;
  Node<int, int> *temp = h.find(2);
  if (temp) std::cout << temp->getKey() << ":" << temp->getValue() << std::endl;
  else std::cout << "!!!" <<std::endl;

  h.erase(2);
  temp = h.find(2);
  if (temp) std::cout << temp->getKey() << ":" << temp->getValue() << std::endl;
  else std::cout << "!!!" <<std::endl;
  return 0;
}
