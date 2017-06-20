#include "zappy.hpp"

Zappy::Zappy(char **av)
{
  int i = 1;

  while (av[i])
    {
      if (std::string(av[i -1]) == "-p")
        this->_port = std::string(av[i]);
      else if (std::string(av[i -1]) == "-n")
        this->_teamName = std::string(av[i]);
      else if (std::string(av[i -1]) == "-h")
        this->_machineName = std::string(av[i]);
      i++;
    }
  if (_port.empty() || _teamName.empty() || _machineName.empty())
    throw ZappException("An argument was not defined");
}

Zappy::~Zappy()
{
}

Zappy::Zappy(Zappy const & other)
{
  (void)other;
}

Zappy& Zappy::operator=(Zappy const & other)
{
  (void)other;
  return *this;
}

void Zappy::init(void)
{
}
