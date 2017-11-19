//
// Launch.cpp for  in /home/ze/305construction
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Tue Nov 14 13:31:13 2017 ze
// Last update Sat Nov 18 21:47:39 2017 DESKTOP-FQFT07H
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

bool			is_sorted(std::vector<Data> &dataguys)
{
  for (size_t x = 0; x < dataguys.size() - 1; x++)
    {
      if (x + 1 <= dataguys.size())
	if (dataguys[x + 1].getPriority() < dataguys[x].getPriority())
	  return (false);
    }
  return (true);
}

std::vector<Data>			sort(std::vector<std::string> &file)
{
  std::vector<Data>	dataguys;
  Data			swap;
  
  for (size_t x = 0; x < file.size(); x++)
      dataguys.push_back(Data(file[x]));
  while (!is_sorted(dataguys))
    {
      for (size_t x = 0; x < dataguys.size() - 1; x++)
      	{
	         if (x + 1 <= dataguys.size())
	           if (dataguys[x + 1].getPriority() < dataguys[x].getPriority())
        	      {
		              swap = dataguys[x+1];
		              dataguys[x+1] = dataguys[x];
		              dataguys[x] = swap;
        	      }
      	}
    }
  for (size_t x = 0; x < dataguys.size(); x++)
    dataguys[x].Print();
  return (dataguys);
}

void					launch(std::vector<std::string> &file)
{
  sort(file);
  std::cout << "File is sorted" << std::endl;
}
