//
// Data.hpp for  in /home/ze/305construction
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Wed Nov 15 14:26:59 2017 ze
// Last update Wed Nov 15 21:57:19 2017 ze
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

  Data(std::string info);
  ~Data();
  void Print();
};

#endif /*_DATA_HPP*/
