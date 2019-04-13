//========================================================================
// compareTriplets 
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

std::vector<int> compareTriplets(std::vector<int> a, std::vector<int> b)
{
  assert(a.size() == b.size());

  std::vector<int> score;
  int a_score = 0, b_score = 0;

  for (size_t i = 0; i < a.size(); ++i)
  {
    if (a[i] == b[i])
    {
    }
    else if (a[i] > b[i])
    {
      ++a_score;
    }
    else if (a[i] < b[i])
    {
      ++b_score;
    }
  }

  score.push_back(a_score);
  score.push_back(b_score);

  return score;
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
    [](const std::string & str){return std::stoi(str);}
  );

  // string to int in b
  std::transform
  (
    arg2.begin(), arg2.end(), std::back_inserter(b),
    [](const std::string & str){return std::stoi(str);}
  );

  if ( a.size() > 0  &&  a.size() == b.size() )
  {
    std::vector<int> score = compareTriplets(a, b);
    std::vector<std::string> score_str;
    // int to string in score
    std::transform
    (
      score.begin(), score.end(), std::back_inserter(score_str),
      [](const int & v){return std::to_string(v);}
    );

    for (auto const& str : score_str)
      std::cout << str << ' ';

    std::cout << std::endl;
  }

}

#if false 
int main()
{
  function();
  return 0;
}
#endif
