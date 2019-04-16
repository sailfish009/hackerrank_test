//========================================================================
// staircase 
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
#include <sstream>
#include <algorithm>
#include <assert.h>

const char note = '#';
const char space = ' ';

void staircase(int n)
{
  for (int i = 0, line = 1; i < n; ++i, ++line)
  {
    int j = 0; 
    for (j = 0; j < (n - line); ++j) printf("%c", space);
    for (int k = j; k < n; ++k) printf("%c", note);
    printf("\n");
  }
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

  // array element count
  std::string element_c("");
  std::getline(std::cin, element_c);
  std::vector<std::string> arg1 = split(element_c, ' ');
  if (arg1.size() == 1)
  {
    int elem_c = std::stoi(arg1[0]);
    staircase(elem_c);
  }
}

#if false
int main()
{
  function();
  return 0;
}
#endif
