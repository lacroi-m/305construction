//
// Data.cpp for  in /home/ze/305construction
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Wed Nov 15 14:25:23 2017 ze
// Last update Wed Nov 15 15:29:49 2017 ze
//

#include "Main.hpp"
#include "Data.hpp"

Data::Data(std::string info)
{
  this->_code = info.substr(0, info.find(";"));
  info = info.substr(info.find(";") + 1, info.size());
  
  this->_description = info.substr(0, info.find(";"));
  info = info.substr(info.find(";") + 1, info.size());
   
  this->_time = stoi(info.substr(0, info.find(";")));  
  info = info.substr(info.find(";") + 1);

  while (info.find(";") != std::string::npos)
    {
      _pre.push_back(info.substr(info.find(";")));
      info = info.substr(info.find(";") + 1);
    }
  //  _pre.push_back(info);
}

Data::~Data()
{}

void	Data::Print()
{
  std::cout << "code:" << _code << std::endl;
  std::cout << "des:" <<  _description << std::endl;
  std::cout << "time:" << _time << std::endl; 

  std::cout << "pre : " << std::endl;
  for (size_t x = 0; x < _pre.size(); x++)
    std::cout << _pre[x] << std::endl;
  
}
