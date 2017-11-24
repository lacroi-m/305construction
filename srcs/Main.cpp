//
// Main.cpp for  in /home/kopiz/Workplace/MATHS/mine/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Tue Nov 21 16:30:29 2017 Tom Jeammet
// Last update Fri Nov 24 20:04:34 2017 Tom Jeammet
//

#include "Main.hpp"

void					checkFile(const char *filename, std::vector<std::string> &lines)
{
  std::fstream				file;
  std::string				tmp(filename);

  file.open(filename);
  if (!file.is_open())
    throw(Err("Error: cant find '" + (std::string)filename + "' check if you havnt made a typo and try again"));
  if (tmp.find(".csv") == std::string::npos)
    throw(Err("Error: Wrong extension !\nfile must have a .csv extension and must be conform to that norme"));
  while (std::getline(file, tmp))
    lines.push_back(tmp);
  file.close();
}

void					getSteps(std::vector<std::string> &file, std::vector<Step> &steps)
{
  std::vector<std::string>::iterator	it;
  std::string				tmp;
  Step					step;

  for (it = file.begin(); it != file.end(); it++)
    {
      tmp = *it;
      step.init(tmp);
      steps.push_back(step);
    }
}

void					launch(std::vector<std::string> &file)
{
  std::vector<Step>::iterator		it;
  std::vector<Step>			steps;
  Builder				builder;
  Timer					timer;
  Step					st;

  getSteps(file, steps);
  builder.setSteps(steps);
  builder.build();
  steps = builder.getDone();
  /*
  for (it = steps.begin(); it != steps.end(); it++)
    {
      st = *it;
      st.printStep();
    }
  */
  timer.timersLoop(builder);
  timer.printTimers(builder);
}

int					main(int ac, char **av)
{
  std::vector<std::string>		file;

  try
    {
      if (ac != 2)
	throw (Err("Usage:\n./305construction file"));
      checkFile(av[1], file);
      launch(file);
    }
  catch (Err &e)
    {
      e.print_msg();
      return (84);
    }
  return (0);
}
