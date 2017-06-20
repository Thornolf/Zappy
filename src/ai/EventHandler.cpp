/*
** EventHandler.cpp for EventHandler in /home/warin_a/TEK2/rendu/PSU/PSU_2016_zappy/src/ai
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Tue Jun 20 15:00:59 2017 Adrien Warin
** Last update Tue Jun 20 15:30:58 2017 Adrien Warin
*/

#include "EventHandler.hpp"

EventHandler::EventHandler()
{
    this->_event["FORWARD"] = std::bind(&EventHandler::MoveUp, this, std::placeholders::_1, std::placeholders::_2);
    this->_event["RIGHT"] = std::bind(&EventHandler::TurnRight, this, std::placeholders::_1, std::placeholders::_2);
    this->_event["LEFT"] = std::bind(&EventHandler::TurnLeft, this, std::placeholders::_1, std::placeholders::_2);
    this->_event["LOOK"] = std::bind(&EventHandler::LookAround, this, std::placeholders::_1, std::placeholders::_2);
    this->_event["INVENTORY"] = std::bind(&EventHandler::Inventory, this, std::placeholders::_1, std::placeholders::_2);
    this->_event["BROADCAST_TEXT"] = std::bind(&EventHandler::BroadcastText, this, std::placeholders::_1, std::placeholders::_2);
    this->_event["FORK"] = std::bind(&EventHandler::Fork, this, std::placeholders::_1, std::placeholders::_2);
    this->_event["EJECT"] = std::bind(&EventHandler::Eject, this, std::placeholders::_1, std::placeholders::_2);
    this->_event["TAKE_OBJECT"] = std::bind(&EventHandler::TakeObject, this, std::placeholders::_1, std::placeholders::_2);
    this->_event["SET_OBJECT"] = std::bind(&EventHandler::SetObject, this, std::placeholders::_1, std::placeholders::_2);
    this->_event["INCANTATION"] = std::bind(&EventHandler::Incantation, this, std::placeholders::_1, std::placeholders::_2);
}
