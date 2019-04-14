//========================================================================
// diagonalDifference 
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
#include <cmath>

int diagonalDifference(std::vector<std::vector<int>> arr)
{
  int primary_sum = 0;
  int secondary_sum = 0;
  size_t size = arr.size();

  for (size_t i = 0; i < size; ++i)
  {
    auto v = arr[i];
    primary_sum += v[i];
    secondary_sum += v[size-i-1];
  }
  return abs(primary_sum - secondary_sum);
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

  int abs_diff = 0;
  // array element value
  std::vector<std::vector<int>> matrix;

  // number of rows and cols
  std::string dimension("");
  std::getline(std::cin, dimension);
  std::vector<std::string> arg1 = split(dimension, ' ');
  if (arg1.size() == 1)
  {
    bool wrong_input = false;
    int elem_c = std::stoi(arg1[0]);
    for (int i = 0; i < elem_c; ++i)
    {
      std::string element_v("");
      std::getline(std::cin, element_v);
      std::vector<std::string> argn = split(element_v, ' ');
      if (argn.size() != elem_c) { wrong_input = true; break; }
      std::vector<int> elem;

      // string to int in elem
      std::transform
      (
        argn.begin(), argn.end(), std::back_inserter(elem),
        [](const std::string & str){return std::stoi(str);}
      );

      matrix.push_back(elem);
    }

    if (wrong_input != true)
    {
      abs_diff = diagonalDifference(matrix);
    }
  }
  return abs_diff;
}

#if false 
int main()
{
  int diagonal_diff  = function();
  printf("%d\n", diagonal_diff);
  return 0;
}
#endif