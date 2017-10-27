#include "header-b.hpp"

B::B() : x(0), y(0), z(0) {}

B::B(A a) : x(a.i), y(a.f), z(a.d) {}
