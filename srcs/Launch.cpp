//
// Launch.cpp for  in /home/ze/305construction
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Tue Nov 14 13:31:13 2017 ze
// Last update Wed Nov 15 15:21:52 2017 ze
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


void			sort(std::vector<std::string> &file)
{
  std::vector<Data>	dataguys;
  
  for (size_t x = 0; x < file.size(); x++)
    {
      dataguys.push_back(Data(file[x]));
    }

  for (size_t x = 0; x < dataguys.size(); x++)
    {
      dataguys[x].Print();
    }
  
  //  std::vector<std::string> ref = {"landscaping", "foundations", "carpenter", "masonery", "cover", "electricity", "plumbing", "heat", "finishing touches"};

  
  
}
void			launch(std::vector<std::string> &file)
{
  //  std::cout << "printing file:\n" << std::endl;
  //for (size_t x = 0; x < file.size(); x++)
  //std::cout << file[x] << std::endl;
  sort(file);
}
