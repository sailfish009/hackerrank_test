//========================================================================
// timeConversion
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

std::string timeConversion(std::string s)
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

  std::vector<std::string> arg1 = split(s, ':');

  // hour
  int hour = std::stoi(arg1[0]);

  assert(hour > 0 && hour < 13);

  // second 
  std::string second = arg1[2].substr(0, 2);
  std::string day_or_night = arg1[2].substr(2, 2);

  std::string converted_time("");
  std::stringstream ss;

  switch (day_or_night == "AM")
  {
    // AM
  case true:
  {
    switch (hour)
    {
    case 12: 
    {
      ss << std::setw(2) << std::setfill('0') << 0;
      std::string converted_hour = ss.str();
      converted_time = converted_hour + ":" + arg1[1] + ":" + second;
    }
      break;

    default:
    {
      ss << std::setw(2) << std::setfill('0') << hour;
      std::string converted_hour = ss.str();
      converted_time = converted_hour + ":" + arg1[1] + ":" + second;
    }
      break;
    }
  }
    break;

    // PM
  default:
  {
    switch (hour)
    {
    case 12: 
      converted_time = std::to_string(12) + ":" + arg1[1] + ":" + second;
      break;

    default:
      converted_time = std::to_string(12+hour) + ":" + arg1[1] + ":" + second;
      break;
    }
  }
    break;
  }

  return converted_time;
}

void function()
{
  // time value
  std::string time("");
  std::getline(std::cin, time);

  std::string s = timeConversion(time);
  printf("%s\n", s.c_str());
}

#if false
int main()
{
  function();
  return 0;
}
#endif
