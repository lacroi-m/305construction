//
// Step.cpp for  in /home/kopiz/Workplace/MATHS/mine/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Tue Nov 21 16:39:53 2017 Tom Jeammet
// Last update Fri Nov 24 14:03:25 2017 Tom Jeammet
//

#include "Step.hpp"

//Ctor
Step::Step()
{

}

//Dtor
Step::~Step()
{
  
}

//Member
bool					Step::isEqualTo(Step step)
{
  if (_pre == step.getPre())
    {
      if ((_code.compare(step.getCode())) == 0)
	{
	  if ((_desc.compare(step.getDesc())) == 0)
	    {
	      if (_time == step.getTime())
		return (true);
	      else
		return (false);
	    }
	  else
	    return (false);
	}
      else
	return (false);
    }
  else
    return (false);
}

void					Step::init(std::string &line)
{
  std::vector<std::string>::iterator	it;
  std::vector<std::string>		tab;
  std::stringstream			ss(line);
  std::string				tmp;

  _pre.clear();
  while (std::getline(ss, tmp, ';'))
    tab.push_back(tmp);
  _code = tab.at(0);
  _desc = tab.at(1);
  _time = stoi(tab.at(2));
  for (it = tab.begin() + 3; it != tab.end(); it++)
    _pre.push_back(*it);
  _startTimer = - 1;
  _endTimer = - 1;
  _priority = - 1;
}

void					Step::checkLine(std::string &line)
{
  int					i;

  i = 0;
  while (line.find(";") != std::string::npos)
    {
      line = line.substr(line.find(";") + 1);
      i++;
    }
  if (i < 2)
    throw(Err("File contains erros! Read the norme of the expected file."));
}

void					Step::printStep()
{
  std::vector<std::string>::iterator	it;

  std::cout << "Step code : " << _code << std::endl;
  std::cout << "Step desccription : " << _desc << std::endl;
  std::cout << "Step duration : " << _time << std::endl;
  std::cout << "Step pre list : " << std::endl;
  for (it = _pre.begin(); it != _pre.end(); it++)
    std::cout << *it << std::endl;
  std::cout << "priority : " << _priority << std::endl;
  std::cout << "startTimer : " << _startTimer << std::endl;
  std::cout << "endTimer : " << _endTimer << std::endl;
  std::cout << std::endl;
}

//Getter
std::vector<std::string>		&Step::getPre()
{
  return (_pre);
}

std::string				&Step::getCode()
{
  return (_code);
}

std::string				&Step::getDesc()
{
  return (_desc);
}

int					Step::getTime()
{
  return (_time);
}

int					Step::getStartTimer()
{
  return (_startTimer);
}

int					Step::getEndTimer()
{
  return (_endTimer);
}

int					Step::getPriority()
{
  return (_priority);
}

//Setter
void					Step::setPre(std::vector<std::string> &pre)
{
  _pre = pre;
}

void					Step::setCode(std::string &code)
{
  _code = code;
}

void					Step::setDesc(std::string &desc)
{
  _desc = desc;
}

void					Step::setTime(int time)
{
  _time = time;
}

void					Step::setStartTimer(int startTimer)
{
  _startTimer = startTimer;
}

void					Step::setEndTimer(int endTimer)
{
  _endTimer = endTimer;
}

void					Step::setPriority(int priority)
{
  _priority = priority;
}
