//
// Launch.cpp for  in /home/ze/305construction
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Tue Nov 14 13:31:13 2017 ze
// Last update Mon Nov 20 11:24:29 2017 DESKTOP-FQFT07H
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

int           constructionDuration(std::vector<Data> dataguys)
{
  (void)dataguys;
  return(0);
}
void					launch(std::vector<std::string> &file)
{
  std::vector<Data> dataguys = sort(file);
  std::cout << "total duration of construction:\t" << constructionDuration(dataguys) << std::endl;
}
