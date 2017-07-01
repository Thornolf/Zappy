/*
** zappy.hpp for PSU_2016_zappy in /home/fossae_t/rendu2/PSU_2016_zappy/src/ai/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue Jun 20 10:41:59 2017 Thomas Fossaert
** Last update Sat Jul 01 14:06:21 2017 Thomas Fossaert
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
# include <vector>
# include "ZappException.hpp"

class Socket
{
  public:

    Socket(const std::string&, const std::string&);
    Socket(Socket const & other);
    ~Socket();
    Socket& operator=(Socket const & other);

    void sendMsg(const char *);
    void recvMsg();

    const std::string getLastMsg() const;
    const std::string getLastTile() const;
    const std::string getLastInventory() const;
    const std::string getLevelUp() const;
    const std::vector<std::string> getBroadCastText() const;

    void resetLevelUp();
    void resetBroacastText();

    const std::string getIp() const;
    const std::string getPort() const;

  private:
    struct protoent	    *pe;
    struct sockaddr_in	s_in;

    std::string         _ip;
    std::string         _lastMsg;
    std::string         _lastTile;
    std::string         _lastInventory;
    std::string         _levelUp;
    std::vector<std::string> _broadCastText;

    int                  _port;
    int                  _fd;
    char                 _buffer[4096];
};

#endif
