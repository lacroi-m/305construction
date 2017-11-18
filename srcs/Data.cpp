//
// Data.cpp for  in /home/ze/305construction
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Wed Nov 15 14:25:23 2017 ze
// Last update Sat Nov 18 21:43:39 2017 DESKTOP-FQFT07H
//

#include "Main.hpp"
#include "Data.hpp"


void	info_isok(std::string info)
{
  int	i;

  i = 0;
  while (info.find(";") != std::string::npos)
    {
      info = info.substr(info.find(";") + 1);
      i++;
    }

  if (i < 2)
    throw(Err("File contains erros! Read the norme of the expected file."));
}

Data::Data(){}

Data::Data(const Data& cpy)
{
  _code = cpy._code;
  _description = cpy._description;
  _time = cpy._time;
  _pre = cpy._pre;
}

Data::Data(std::string &info)
{
  info_isok(info);
  _code = info.substr(0, info.find(";"));
  info = info.substr(info.find(";") + 1, info.size());
  
  _description = info.substr(0, info.find(";"));
  info = info.substr(info.find(";") + 1, info.size());
   
  _time = stoi(info.substr(0, info.find(";")));
  if (info.find(";") != std::string::npos)
    info = info.substr(info.find(";") + 1);
  else
    info.clear();
  
  while (info.find(";") != std::string::npos)
    {
      _pre.push_back(info.substr(0, info.find(";")));      
      info = info.substr(info.find(";") + 1);
    }
  if (!info.empty())
    _pre.push_back(info);
}

Data::~Data()
{}

void	Data::Switch(const Data &cpy)
{
  _code = cpy._code;
  _description = cpy._description;
  _time = cpy._time;
  _pre = cpy._pre;
}

size_t	Data::getPriority()
{
  return (_pre.size());
}

void	Data::Print()
{
  /*  std::cout << "code: '" << _code << "'" << std::endl;
  std::cout << "des: '" <<  _description << "'" << std::endl;
  std::cout << "time: '" << _time << "'" <<std::endl;
  std::cout << "pre : " << std::endl;
  
  for (size_t x = 0; x < _pre.size(); x++)
    std::cout << "'" <<_pre[x] << "'" << std::endl;
    std::cout << std::endl;*/
  std::cout << _pre.size() <<  " " << _code << " " << _description << std::endl;
}
