//========================================================================
// birthdayCakeCandles
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


int birthdayCakeCandles(std::vector<int> ar)
{
  int blown_candle = 0;
  std::sort(ar.begin(), ar.end(), std::greater<int>());
  int tmp_v = -1;
  for (auto v : ar)
  {
    if (tmp_v == -1)
    {
      tmp_v = v;
      ++blown_candle;
    }
    else if( v == tmp_v)
    {
      ++blown_candle;
    }
    else
    {
      break;
    }
  }
  return blown_candle;
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

  int blown_candle = 0;

  // array element count
  std::string element_c("");
  // array element value
  std::string element_v("");

  std::getline(std::cin, element_c);
  std::getline(std::cin, element_v);

  std::vector<std::string> arg1 = split(element_c, ' ');
  std::vector<std::string> arg2 = split(element_v, ' ');

  if (arg1.size() == 1)
  {
    int elem_c = std::stoi(arg1[0]);
    if (elem_c == arg2.size())
    {
      std::vector<int> elem;
      std::transform
      (
        arg2.begin(), arg2.end(), std::back_inserter(elem),
        [](const std::string & str) {return std::stoi(str); }
      );
      blown_candle = birthdayCakeCandles(elem);
    }
  }
  return blown_candle;
}

#if false
int main()
{
  int candle = function();
  printf("%d\n", candle);
  return 0;
}
#endif

