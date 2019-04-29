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
#include <chrono>
#include <random>
#include <unordered_set>


// https://stackoverflow.com/questions/10956543/gcd-function-in-c-sans-cmath-library
template <typename Number>
Number GCD(Number u, Number v) 
{
  while (v != 0) 
  {
    u %= v;
    switch(u)
    {
    case 0: return v; 
    default: v %= u; break;
    }
  }
  return u;
}

int computerGame(std::vector<int> a, std::vector<int> b)
{
#if false
  std::chrono::high_resolution_clock::time_point t1 = 
    std::chrono::high_resolution_clock::now();
#endif

  int pair_count = 0;

  size_t a_size = a.size();
  size_t b_size = b.size();

  std::unordered_set<int> dup_a;
  std::unordered_set<int> dup_b;

  for (size_t i = 0; i < a_size; ++i)
  for (size_t j = 0; j < b_size; ++j)
  if (GCD(a[i], b[j]) != 1)
  {
    dup_a.insert(a[i]);
    dup_b.insert(b[j]);
  }
	
  size_t dup_a_size = dup_a.size();
  size_t dup_b_size = dup_b.size();
  pair_count = std::min(dup_a_size, dup_b_size);

#if false
  std::chrono::duration<double> time_span = 
    std::chrono::duration_cast<std::chrono::duration<double>>
    (std::chrono::high_resolution_clock::now() - t1);

  printf("%lf\n", time_span.count());
  printf("-end-\n");
#endif
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

  int pair_count = 0;

  // array element count 
  std::string element_c("");
  std::getline(std::cin, element_c);
  std::vector<std::string> arg1 = split(element_c, ' ');
  if (arg1.size() == 1)
  {
    int elem_c = std::stoi(arg1[0]);
    // array element A 
    std::string element_a("");
    // array element B 
    std::string element_b("");

    std::getline(std::cin, element_a);
    std::getline(std::cin, element_b);

    // printf("[c :%s]\n", element_a.c_str());
    // printf("[v :%s]\n", element_b.c_str());

    std::vector<std::string> arga = split(element_a, ' ');
    std::vector<std::string> argb = split(element_b, ' ');

    if (arga.size() == elem_c && argb.size() == elem_c)
    {
      std::vector<int> a;
      std::vector<int> b;

      // string to int in a
      std::transform
      (
        arga.begin(), arga.end(), std::back_inserter(a),
        [](const std::string & str) {return std::stoi(str); }
      );

      // string to int in b
      std::transform
      (
        argb.begin(), argb.end(), std::back_inserter(b),
        [](const std::string & str) {return std::stoi(str); }
      );

      pair_count = computerGame(a, b);
    }
  }
  return pair_count;
}

int main()
{

#if false 
  // const int nrolls = 10000; 
  // const int dist = 1000000000; 

  const int nrolls = 1000; 
  const int dist = 1000000000; 

  std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(2, dist);

  std::vector<int> a;
  std::vector<int> b;

  for (int i = 0; i < nrolls; ++i)
  {
    int numbera = distribution(generator);
    int numberb = distribution(generator);
    a.push_back(numbera);
    b.push_back(numberb);
  }
  int count = computerGame(a, b);
#endif

#if false 
  std::vector<int> a; a.push_back(2); a.push_back(5); a.push_back(6); a.push_back(7);
  std::vector<int> b; b.push_back(4); b.push_back(9); b.push_back(10); b.push_back(12);
  int count = computerGame(a, b);
#endif

  int count = function();
  printf("%d\n", count);
  return 0;
}
