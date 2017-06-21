/*
** zappy.hpp for PSU_2016_zappy in /home/fossae_t/rendu2/PSU_2016_zappy/src/ai/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue Jun 20 10:41:59 2017 Thomas Fossaert
** Last update Wed Jun 21 14:32:02 2017 Thomas Fossaert
*/

#ifndef   _SOCKET_HPP_
# define  _SOCKET_HPP_

# include <iostream>
# include	<sys/types.h>
# include	<sys/socket.h>
# include	<netdb.h>
# include	<stdlib.h>
# include	<netinet/in.h>
# include	<arpa/inet.h>
# include	<unistd.h>
# include	<string.h>
# include	<stdio.h>
# include "ZappException.hpp"

class Socket
{
  public:
    Socket();
    Socket(Socket const & other);
    ~Socket();
    Socket& operator=(Socket const & other);

    void sendMsg(const char *);
    void recvMsg();
    const std::string getLastMsg() const;

  private:
    struct protoent	*pe;
    struct sockaddr_in	s_in;

    int         _port;
    std::string _ip;
    int         _fd;
    char _buffer[4096];
    std::string _lastMsg;
};

#endif
