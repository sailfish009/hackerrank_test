//========================================================================
// miniMaxSum
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


void miniMaxSum(std::vector<int> arr)
{
  size_t size = arr.size();
  assert(size != 0);
  std::vector<uint64_t> array(size);
  for (size_t index = 0; index < size; ++index)
  for (size_t i = 0; i < size; ++i)
  {
    if (index == i) continue;

    array[index] += arr[i];
  }

  uint64_t min = *std::min_element(std::begin(array), std::end(array));
  uint64_t max = *std::max_element(std::begin(array), std::end(array));

  printf("%llu %llu\n", min, max);

}

void function()
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

  // array element value
  std::string element_v("");
  std::getline(std::cin, element_v);
  std::vector<std::string> arg1 = split(element_v, ' ');
  std::vector<int> elem;

  if (arg1.size() != 0)
  {
    // string to int in elem
    std::transform
    (
      arg1.begin(), arg1.end(), std::back_inserter(elem),
      [](const std::string & str) {return std::stoi(str); }
    );

    miniMaxSum(elem);
  }

}

#if false
int main()
{
  function();
  return 0;
}
#endif

