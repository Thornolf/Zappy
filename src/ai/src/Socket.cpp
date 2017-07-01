/*
** Socket.cpp for PSU_2016_zappy in /home/fossae_t/rendu2/PSU_2016_zappy/src/ai
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Wed Jun 21 09:12:26 2017 Thomas Fossaert
** Last update Sat Jul 01 10:52:13 2017 Pierre
*/

#include "Socket.hpp"

Socket::Socket(const std::string& ip, const std::string& port)
{
 this->_port = std::stoi(port);
 this->_ip = ip;
 pe = getprotobyname("TCP");
 if (!pe)
   throw ZappException("Error while retrieving proto");
 this->_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
 if (this->_fd == -1)
   throw ZappException("Could not connect create socket");
 s_in.sin_family = AF_INET;
 s_in.sin_port = htons(this->_port);
 s_in.sin_addr.s_addr = inet_addr((this->_ip).c_str());
 if (connect(this->_fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
   {
     if (close(this->_fd) == -1)
      throw ZappException("Error while closing socket");
     throw ZappException("Error while connecting to server");
   }
   std::cout << "Connected to server" << '\n';
}

Socket::~Socket()
{
}

Socket::Socket(Socket const & other)
{
  (void)other;
}

Socket& Socket::operator=(Socket const & other)
{
  (void)other;
  return *this;
}

void Socket::sendMsg(const char *msg)
{
  std::cout << "\ncommande : " << msg << '\n';
  send(this->_fd, msg, strlen(msg), 0);
}

void Socket::recvMsg()
{
  int i = 0;

  recv(this->_fd, _buffer, 4096, 0);
  std::cout << std::string(_buffer);
  if (std::string(_buffer).find("[ player") != std::string::npos)
    _lastTile = _buffer;
  else if (std::string(_buffer).find("[ food") != std::string::npos)
    _lastInventory= _buffer;
  else
    _lastMsg = std::string(_buffer);
  while (_buffer[i])
    {
      _buffer[i] = '\0';
      i++;
    }
}

const std::string Socket::getLastMsg() const
{
  return (std::string(this->_lastMsg));
}

const std::string Socket::getLastTile() const
{
  return (std::string(this->_lastTile));
}

const std::string Socket::getLastInventory() const
{
  return (std::string(this->_lastInventory));
}

const std::string Socket::getIp() const
{
  return (std::string(this->_ip));
}

const std::string Socket::getPort() const
{
  return (std::to_string(this->_port));
}
