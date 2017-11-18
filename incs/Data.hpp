//
// Data.hpp for  in /home/ze/305construction
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Wed Nov 15 14:26:59 2017 ze
// Last update Sat Nov 18 21:44:04 2017 DESKTOP-FQFT07H
//

#ifndef _DATA_HPP_
#define _DATA_HPP_


class	Data
{
  public:  
  std::string			_code;
  std::string			_description;
  int				_time;
  std::vector<std::string>	_pre;

  Data();
  Data(std::string &info);
  Data(const Data& cpy);
  ~Data();
  void Switch(const Data& cpy);
  void Print();
  size_t	getPriority();
};

#endif /*_DATA_HPP*/
