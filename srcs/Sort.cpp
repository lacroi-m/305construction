//
// Sort.cpp for  in /mnt/c/Users/ze/Desktop/gitshit/305construction
// 
// Made by DESKTOP-FQFT07H
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Mon Nov 20 13:03:43 2017 DESKTOP-FQFT07H
// Last update Mon Nov 20 13:31:37 2017 DESKTOP-FQFT07H
//

#include "Main.hpp"

bool			is_sortedbysize(std::vector<Data> &dataguys)
{
  for (size_t x = 0; x < dataguys.size() - 1; x++)
    {
      if (dataguys[x + 1].getPreSize() < dataguys[x].getPreSize())
	return (false);
    }
  return (true);
}

bool		        is_befor(std::vector<Data> &dataguys, size_t pos, std::string &code)
{
  size_t x = -1;

  while (++x < pos)
    if (dataguys[x]._code == code)
      return (true);
  return (false);
}

bool		     is_sortedbypriority(std::vector<Data> &dataguys)
{
  for (size_t x = 0; x < dataguys.size() - 1; x++)
  {
      for (size_t y = 0; y < dataguys[x].getPreSize(); y++)
        if (!is_befor(dataguys, x, dataguys[x].getPre()[y]))
          return (false);
  }
  return (true);
}

void                  sortOrder(std::vector<Data> &dataguys)
{
  Data      swap;
  while (!is_sortedbysize(dataguys))
    {
     for (size_t x = 0; x < dataguys.size() - 1; x++)
        {
          if (dataguys[x + 1].getPreSize() < dataguys[x].getPreSize())
	    {
	      swap = dataguys[x+1];
	      dataguys[x+1] = dataguys[x];
	      dataguys[x] = swap;
	    }
        }
    }
}

void		sortPriority(std::vector<Data> &dataguys)
{
  while (!is_sortedbypriority(dataguys))
    {
      for (size_t x = 0; x < dataguys.size() - 1; x++)
	{
	  for (size_t y = 0; y < dataguys[x].getPreSize(); y++)
	    if (!is_befor(dataguys, x, dataguys[x].getPre()[y]))
	      {
		dataguys.insert(dataguys.begin() + x + 2, dataguys[x]);
		dataguys.erase(dataguys.begin() + x);
	      }
	}
    }
}

std::vector<Data>			sort(std::vector<std::string> &file)
{
  std::vector<Data>	dataguys;

  for (size_t x = 0; x < file.size(); x++)
    dataguys.push_back(Data(file[x]));
  for (size_t x = 0; x < dataguys.size(); x++)
    dataguys[x].Print(); // permet de visualiser le tri
  std::cout << std::endl;
  sortOrder(dataguys);
  for (size_t x = 0; x < dataguys.size(); x++)
    dataguys[x].Print();// permet de visualiser le tri
  std::cout << std::endl;
  sortPriority(dataguys);
  for (size_t x = 0; x < dataguys.size(); x++)
    dataguys[x].Print(); // permet de visualiser le tri
  std::cout << std::endl;
  return (dataguys);
}
