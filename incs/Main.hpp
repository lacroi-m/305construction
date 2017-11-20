//
// Main.hpp for  in /home/ze/305construction
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Tue Nov 14 13:22:43 2017 ze
// Last update Wed Nov 15 14:43:47 2017 ze
//

#ifndef  __MAIN_HPP__
# define  __MAIN_HPP__

# include <iostream>
# include <string>
# include <cstring>
# include <fstream>
# include <vector>

# include "Exception.hpp"
# include "Data.hpp"

void						 checks(const char *filename, std::vector<std::string> &stock);
void						 launch(std::vector<std::string> &file);
std::vector<Data>			 sort(std::vector<std::string> &file);

#endif /* ! __MAIN_HPP__ */
