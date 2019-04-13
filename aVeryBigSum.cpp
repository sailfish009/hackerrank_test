//========================================================================
// aVeryBigSum 
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
#include <iostream>
#include <sstream>
#include <algorithm>
#include <assert.h>

long long aVeryBigSum(std::vector<long> ar)
{
  long long bigsum = 0;
  for (auto v : ar)
    bigsum += v;

  return bigsum;
}

long long function()
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

  // array element count
  std::string element_c("");
  // array element value
  std::string element_v("");

  std::getline(std::cin, element_c);
  std::getline(std::cin, element_v);

  // printf("[c :%s]\n", element_c.c_str());
  // printf("[v :%s]\n", element_v.c_str());

  std::vector<std::string> arg1 = split(element_c, ' ');
  std::vector<std::string> arg2 = split(element_v, ' ');

  long long bignum = 0;
  std::vector<long> arg3;
  try
  {
    if (arg1.size() == 1)
    {
      int elem_c = std::stoi(arg1[0]);
      if (elem_c == arg2.size())
      {
        for (auto v : arg2) arg3.push_back(std::stol(v));
        bignum = aVeryBigSum(arg3);
      }
    }
    else
    {
      printf("wrong input!!!\n");
    }
  }
  catch (...)
  {
    printf("wrong input!!!\n");
  }
  return bignum;
}



#if false 
int main()
{
  long long bignum =function();
  printf("%lld\n", bignum);
  return 0;
}
#endif
