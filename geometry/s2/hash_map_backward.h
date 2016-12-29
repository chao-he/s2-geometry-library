#pragma once

#define _GLIBCXX_PERMIT_BACKWARD_HASH

#if defined __GNUC__ || defined __APPLE__
#include <ext/hash_map>
#else
#include <hash_map>
#endif
using __gnu_cxx::hash_map;

#if defined __GNUC__ || defined __APPLE__
#include <ext/hash_set>
#else
#include <hash_set>
#endif
using __gnu_cxx::hash_set;


