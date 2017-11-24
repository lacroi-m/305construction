//
// Builder.cpp for  in /home/kopiz/Workplace/MATHS/mine/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Wed Nov 22 09:51:09 2017 Tom Jeammet
// Last update Fri Nov 24 19:51:16 2017 Tom Jeammet
//

#include "Builder.hpp"

//Ctor
Builder::Builder()
{

}

//Dtor
Builder::~Builder()
{

}

//Member
bool					Builder::isPossib(std::vector<std::string> &pre)
{
  std::vector<std::string>::iterator	it;
  std::vector<Step>::iterator		jt;
  std::string				name;
  std::string				name2;
  Step					tmp;
  int					nb;

  nb = 0;
  for (it = pre.begin(); it != pre.end(); it++)
    {
      name = *it;
      for (jt = _done.begin(); jt != _done.end(); jt++)
	{
	  tmp = *jt;
	  name2 = tmp.getCode();
	  if ((name.compare(name2)) == 0)
	    nb = nb + 1;
	}
    }
  if (nb == (int)pre.size())
    return (true);
  else
    return (false);
}

std::vector<Step>			Builder::getPossibSteps(std::vector<Step> &toDo)
{
  std::vector<Step>::iterator		it;
  Step					tmp;

  toDo.clear();
  for (it = _steps.begin(); it != _steps.end(); it++)
    {
      tmp = *it;
      if (isPossib(tmp.getPre()))
	toDo.push_back(tmp);
    }
  return (toDo);
}

int					Builder::indexOfStep(Step &step)
{
  std::vector<Step>::iterator		it;
  Step					tmp;
  int					i;

  i = 0;
  for (it = _steps.begin(); it != _steps.end(); it++)
    {
      tmp = *it;
      if (tmp.isEqualTo(step))
	return (i);
      i = i + 1;
    }
  return (- 1);
}

bool					Builder::isDone(std::string &name)
{
  std::vector<Step>::iterator		it;
  std::string				code;
  Step					tmp;
  int					i;

  i = 0;
  for (it = _done.begin(); it != _done.end(); it++)
    {
      tmp = *it;
      code = tmp.getCode();
      if ((code.compare(name)) == 0)
	i = i + 1;
    }
  if (i == 0)
    return (false);
  else
    return (true);
}

bool					Builder::missing(std::vector<std::string> &pre, std::string &name)
{
  std::vector<std::string>::iterator	it;
  std::string				tmp;

  for (it = pre.begin(); it != pre.end(); it ++)
    {
      tmp = *it;
      if (!isDone(tmp))
	{
	  if ((tmp.compare(name)) != 0)
	    return (true);
	}
    }
  return (false);
}

bool					Builder::isInToDo(std::vector<Step> &toDo, std::string &name)
{
  std::vector<Step>::iterator		it;
  Step					step;
  std::string				code;

  for (it = toDo.begin(); it != toDo.end(); it++)
    {
      step = *it;
      code = step.getCode();
      if ((code.compare(name)) == 0)
	return (true);
    }
  return (false);
}

bool					Builder::isEnough(std::string &name, std::vector<Step> &toDo)
{
  std::vector<Step>::iterator		it;
  std::vector<std::string>		pre;
  Step					step;

  if (_steps.size() == 1)
    return (true);
  else
    {
      for (it = _steps.begin(); it != _steps.end(); it++)
	{
	  step = *it;
	  if (!isInToDo(toDo, step.getCode()))
	    {
	      pre = step.getPre();
	      if (!missing(pre, name))
		return (true);
	    }
	}
    }
  return (false);
}

void					Builder::pushOther(std::vector<Step> &other, std::vector<Step> &save)
{
  std::vector<Step>::iterator		it;
  Step					step;
  int					index;
  
  for (it = other.begin(); it != other.end(); it++)
    {
      step = *it;
      step.setPriority(0);
      save.push_back(step);
      index = indexOfStep(step);
      _steps.erase(_steps.begin() + index);
    }
}

void					Builder::pushStepsToDo(std::vector<Step> &toDo)
{
  std::vector<Step>::iterator		it;
  std::vector<Step>			other;
  std::vector<Step>			save;
  Step					step;
  int					index;

  for (it = toDo.begin(); it != toDo.end(); it++)
    {
      step = *it;
      if (isEnough(step.getCode(), toDo))
	{
	  step.setPriority(1);
	  save.push_back(step);
	  index = indexOfStep(step);
	  _steps.erase(_steps.begin() + index);
	}
      else
	other.push_back(step);
    }
  pushOther(other, save);
  for (it = save.begin(); it != save.end(); it++)
    _done.push_back(*it);
}

void					Builder::build()
{
  std::vector<Step>::iterator		it;
  std::vector<Step>			toDo;
  Step					step;

  while (!_steps.empty())
    {
      toDo = getPossibSteps(toDo);
      pushStepsToDo(toDo);
      toDo.clear();
    }
}

//Getter
std::vector<Step>			&Builder::getDone()
{
  return (_done);
}

std::vector<Step>			&Builder::getSteps()
{
  return (_steps);
}

//Setter
void					Builder::setDone(std::vector<Step> &done)
{
  _done = done;
}

void					Builder::setSteps(std::vector<Step> &steps)
{
  _steps = steps;
}
