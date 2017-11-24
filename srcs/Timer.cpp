//
// Timer.cpp for  in /home/kopiz/Workplace/MATHS/mine/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Fri Nov 24 13:37:23 2017 Tom Jeammet
// Last update Fri Nov 24 21:23:05 2017 Tom Jeammet
//

#include "Timer.hpp"

//Ctor
Timer::Timer()
{
  _timer = 0;
}

//Dtor
Timer::~Timer()
{

}

//Member
bool					Timer::isPrevNeeded(std::string &name, std::vector<std::string> &pre)
{
  std::vector<std::string>::iterator	it;
  std::string				name2;

  for (it = pre.begin(); it != pre.end(); it++)
    {
      name2 = *it;
      if ((name.compare(name2)) == 0)
	return (true);
    }
  return (false);
}

void					Timer::setTimers(std::vector<Step> &done, Step &step, int t, int st, int e)
{
  _timer = _timer + t;
  step.setStartTimer(st);
  step.setEndTimer(e);
  done.push_back(step);
}

void					Timer::printGraph(Builder &b)
{
  std::vector<Step>::iterator		it;
  std::vector<Step>			steps;
  Step					tmp;
  int					i;

  steps = b.getDone();
  for (it = steps.begin(); it != steps.end(); it++)
    {
      i = 0;
      tmp = *it;
      std::cout << tmp.getCode() << '\t';
      if (tmp.getPriority() == 1)
	std::cout << "(0)\t";
      else
	std::cout << '(' << tmp.getEndTimer() - tmp.getStartTimer() << ")\t";
      while (i < tmp.getStartTimer())
	{
	  std::cout << ' ';
	  i = i + 1;
	}
      i = 0;
      while (i < tmp.getTime())
	{
	  std::cout << '=';
	  i = i + 1;
	}
      std::cout << std::endl;
    }
}

void					Timer::printTimers(Builder &b)
{
  std::vector<Step>::iterator		it;
  std::vector<Step>			steps;
  Step					tmp;

  steps = b.getDone();
  std::cout << std::endl;
  for (it = steps.begin(); it != steps.end(); it++)
    {
      tmp = *it;
      if (tmp.getPriority() == 1)
	std::cout << tmp.getCode() << " must begin at t=" << tmp.getStartTimer() << std::endl;
      else
	{
	  std::cout << tmp.getCode() << " must begin between t=" << tmp.getStartTimer();
	  std::cout << " and t=" << tmp.getEndTimer() << std::endl;
	}
    }
  std::cout << std::endl;
  printGraph(b);
}

void					Timer::setEnd(std::vector<Step>::iterator &it,
						      std::vector<Step> &done, Step &tmp, Step &tmp2)
{
  Step					tmp3;
  int					start;
  int					end;
  int					j;

  tmp3 = *(it + 1);
  while (tmp3.getPriority() == 0)
    {
      j = j + 1;
      tmp3 = *(it - j);
    }
  if (!isPrevNeeded(tmp.getCode(), tmp3.getPre()))
    {
      start = _timer - tmp2.getTime();
      end = start + tmp2.getTime() + tmp3.getTime() - tmp.getTime();
      setTimers(done, tmp, 0, start, end);
    }
  else
    setTimers(done, tmp, tmp.getTime(), _timer, _timer + tmp.getTime());
}

void					Timer::setStart(std::vector<Step>::iterator &it,
							std::vector<Step> &done, Step &tmp)
{
  Step					tmp2;
  int					j;
  
  tmp2 = *(it - 1);
  j = 1;
  while (tmp2.getPriority() == 0)
    {
      j = j + 1;
      tmp2 = *(it - j);
    }
  if (!isPrevNeeded(tmp2.getCode(), tmp.getPre()))
    setEnd(it, done, tmp, tmp2);
  else
    setTimers(done, tmp, tmp.getTime(), _timer, _timer + tmp.getTime());
}

void					Timer::timersLoop(Builder &b)
{
  std::vector<Step>::iterator		it;
  std::vector<Step>			steps;
  std::vector<Step>			done;
  Step					tmp;
  int					i;

  i = 0;
  steps = b.getDone();
  for (it = steps.begin(); it != steps.end(); it++)
    {
      tmp = *it;
      if (it != steps.begin() && it != (steps.end() - 1))
	setStart(it, done, tmp);
      else
	setTimers(done, tmp, tmp.getTime(), _timer, _timer + tmp.getTime());
      i = i + 1;
    }
  b.setDone(done);
  std::cout << "total duration of construction: " << _timer << " weeks" << std::endl;
}

//Getter
int					Timer::getTimer()
{
  return (_timer);
}

//Setter
void					Timer::setTimer(int timer)
{
  _timer = timer;
}
