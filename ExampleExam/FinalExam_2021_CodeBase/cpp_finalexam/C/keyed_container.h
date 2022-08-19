#ifndef KEYEDCONTAINER_H_4457345
#define KEYEDCONTAINER_H_4457345
#include <stdlib.h>
#include <iostream>
#include <map>
template <typename T1, typename T2 > class KeyedContainer { 
public:
  void PutIntoContainer(T1 key, T2 data)
  {
    container[key] = data;
  };
  T2 GetFromContainer(T1 key)
  {
    return container[key];
  };
  virtual ~KeyedContainer()
  {

  }
private:
  std::map<T1, T2> container; 
};
#endif //KEYEDCONTAINER_H_4457345
