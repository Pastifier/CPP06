#pragma once

#if defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86) || defined(__MACH__)
typedef unsigned long uintptr_t;
#else
typedef unsigned long long uintptr_t;
#endif

class Data;

class Serializer {
public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);

private:
  Serializer();
  ~Serializer();
  Serializer(Serializer const &other);
  Serializer &operator=(Serializer const &rhs);
};
