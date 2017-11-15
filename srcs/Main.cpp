//
// Main.cpp for  in /home/ze/305construction
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Tue Nov 14 13:21:32 2017 ze
// Last update Tue Nov 14 14:11:16 2017 ze
//

#include "Main.hpp"

int	main(int ac, char **av)
{
  try
    {
      std::vector<std::string> file;
      
      if (ac != 2)
	throw (Err("Usage:\n./305construction file"));
      checks(av[1], file);
      launch(file);
    }
  catch (Err &e)
    {
      e.print_msg();
      return (84);
    }
  return (0);
}
