//========================================================================
// computerGame
//------------------------------------------------------------------------
// Copyright (c) 2019 Ji Wong Park <sailfish009@gmail.com>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================


#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <algorithm>
#include <assert.h>
#include <cstdint>
#include <numeric>

// https://stackoverflow.com/questions/10956543/gcd-function-in-c-sans-cmath-library
template <typename Number>
Number GCD(Number u, Number v) 
{
  while (v != 0) 
  {
    Number r = u % v;
    u = v;
    v = r;
  }
  return u;
}

int computerGame(std::vector<int> a, std::vector<int> b)
{
  size_t a_size = a.size();
  size_t b_size = b.size();
  int pair_count = 0;
  int count = 0;

  std::vector<int> a_index;
  std::vector<int> b_index;

  for(size_t i =0; i<a_size; ++i)
  for(size_t j =0; j<b_size; ++j)
  {
    size_t a_index_size = a_index.size();
    size_t b_index_size = b_index.size();

    if (a_index_size != 0 && b_index_size != 0)
    {
      bool b_coprime = false;
      for(size_t k =0; k < a_index_size; ++k)
      {
        if (i == a_index[k]) { b_coprime = true; break; }
      }

      for(size_t l =0; l < b_index_size; ++l)
      {
        if (j == b_index[l]) { b_coprime = true; break; }
      }

      if (b_coprime == false)
      {
        if (GCD(a[i], b[j]) != 1)
        {
          a_index.push_back(i);
          b_index.push_back(j);
          // printf("%d [%d] [%d]\n", ++count, a[i], b[j]);
          ++pair_count;
        }
      }
    }
    else
    {
      if (GCD(a[i], b[j]) != 1)
      {
        a_index.push_back(i);
        b_index.push_back(j);
        // printf("%d [%d] [%d]\n", ++count, a[i], b[j]);
        ++pair_count;
      }
    }
  }
  return pair_count;
}

int function()
{
  auto split = [] (const std::string& s, char delimiter) 
  {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
       tokens.push_back(token);
    }
    return tokens;
  };

  // array element A 
  std::string element_a("");
  // array element B 
  std::string element_b("");

  std::getline(std::cin, element_a);
  std::getline(std::cin, element_b);

  // printf("[c :%s]\n", element_a.c_str());
  // printf("[v :%s]\n", element_b.c_str());

  std::vector<std::string> arg1 = split(element_a, ' ');
  std::vector<std::string> arg2 = split(element_b, ' ');

  std::vector<int> a;
  std::vector<int> b;

  // string to int in a
  std::transform
  (
    arg1.begin(), arg1.end(), std::back_inserter(a),
    [](const std::string & str) {return std::stoi(str); }
  );

  // string to int in b
  std::transform
  (
    arg2.begin(), arg2.end(), std::back_inserter(b),
    [](const std::string & str) {return std::stoi(str); }
  );

  return computerGame(a, b);
}

#if false
int main()
{
  int count = function();
  printf("%d\n", count);
  return 0;
}
#endif

