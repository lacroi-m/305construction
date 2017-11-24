//
// Timer.hpp for  in /home/kopiz/Workplace/MATHS/mine/incs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Fri Nov 24 13:37:53 2017 Tom Jeammet
// Last update Fri Nov 24 21:07:23 2017 Tom Jeammet
//

#ifndef __TIMER_HPP__
# define __TIMER_HPP__

# include <iostream>
# include <string>
# include <vector>

# include "Builder.hpp"

class					Timer
{
private:
  int					_timer;

public:
  //Ctor
  Timer();
  //Dtor
  ~Timer();
  //Member
  bool					isPrevNeeded(std::string &, std::vector<std::string> &);
  void					setEnd(std::vector<Step>::iterator &, std::vector<Step> &, Step &, Step &);
  void					setStart(std::vector<Step>::iterator &, std::vector<Step> &, Step &);
  void					setTimers(std::vector<Step> &, Step &, int, int, int);
  void					printGraph(Builder &);
  void					printTimers(Builder &);
  void					timersLoop(Builder &);

  //Getter
  int					getTimer();
  //Setter
  void					setTimer(int);
  
};

#endif /* ! __TIMER_HPP__ */
