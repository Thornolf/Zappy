#ifndef   _UTILS_HPP_
# define  _UTILS_HPP_

# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
# include <unordered_map>
# include <functional>
# include "ai/ZappException.hpp"

class Utils
{
  public:

    Utils();
    ~Utils();

    void epur(std::string &s);
    std::vector<std::string> explode(const std::string&, const char&);
    bool has_any_digits(const std::string& s);
};

#endif
