//
// Launch.cpp for  in /home/ze/305construction
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Tue Nov 14 13:31:13 2017 ze
// Last update Mon Nov 20 14:00:06 2017 DESKTOP-FQFT07H
//

#include "Main.hpp"

void checks(const char *filename, std::vector<std::string> &stock)
{
  std::fstream	file;
  std::string	tmp(filename);

  file.open(filename);
  if (!file.is_open())
    throw(Err("Error: cant find '" + (std::string)filename + "' check if you havnt made a typo and try again"));
  if (tmp.find(".csv") == std::string::npos)
    throw(Err("Error: Wrong extension !\nfile must have a .csv extension and must be conform to that norme"));
  while (std::getline(file, tmp))
    stock.push_back(tmp);
  file.close();
}

int           constructionDuration(std::vector<Data> &dataguys)
{
  int		time = 0;
  
  for (size_t x = 0; x < dataguys.size(); x++)
    time = time + dataguys[x].getTime();
  return(time);
}

void					printTimings(std::vector<Data> &dataguys)
{
  std::string		onlyTime = " must begin at ";
  std::string		multiTime = " must begin between ";

  for (size_t x = 0; x < dataguys.size(); x++)
    {
      //      if (onlyTime)
      std::cout << dataguys[x].getCode() << onlyTime << dataguys[x].getTime() << std::endl;
      //    else if (multiTime)
      //      std::cout << dataguys[x].getCode() << onlyTime << getTimeBeg(dataguys, dataguys[x].getCode()) << " and " << getTimeEnd(dataguys, dataguys[x].getCode()) << std::endl;
    }
  std::cout << std::endl;
}

void					printCalandar(std::vector<Data> &dataguys)
{
  (void)dataguys;
}

void					launch(std::vector<std::string> &file)
{
  std::vector<Data> dataguys = sort(file);
  std::cout << "total duration of construction:\t" << constructionDuration(dataguys) << std::endl << std::endl << std::endl;
  printTimings(dataguys);
  printCalandar(dataguys);
}
