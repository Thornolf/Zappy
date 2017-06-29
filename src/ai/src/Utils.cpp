/*
** Utils.cpp for ai in /home/fossae_t/rendu2/PSU_2016_zappy/src/ai
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Jun 29 15:22:18 2017 Thomas Fossaert
** Last update Thu Jun 29 15:23:17 2017 Thomas Fossaert
*/

#include "Utils.hpp"

Utils::Utils()
{
}

Utils::~Utils()
{

}
void Utils::epur(std::string &s)
{
  bool space = false;
  auto p = s.begin();
  for (auto ch : s)
    if (std::isspace(ch)) {
      space = p != s.begin();
    } else {
      if (space) *p++ = ' ';
      *p++ = ch;
      space = false; }
  s.erase(p, s.end());
}

std::vector<std::string> Utils::explode(const std::string& str, const char& ch)
{
    std::string next;
    std::vector<std::string> result;

    for (auto it = str.begin(); it != str.end(); it++)
      {
        if (*it == ch)
          {
              result.push_back(next);
              next.clear();
          }
        else
          next += *it;
    }
    if (!next.empty())
        result.push_back(next);
    return (result);
}

bool Utils::has_any_digits(const std::string& s)
{
    return std::any_of(s.begin(), s.end(), ::isdigit);
}
