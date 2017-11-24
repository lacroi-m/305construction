//
// Step.hpp for  in /home/kopiz/Workplace/MATHS/mine/incs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Tue Nov 21 16:42:44 2017 Tom Jeammet
// Last update Thu Nov 23 13:03:46 2017 Tom Jeammet
//

#ifndef __STEP_HPP__
# define __STEP_HPP__

# include <vector>
# include <string>
# include <sstream>

# include "Exception.hpp"

class					Step
{
private:
  std::vector<std::string>		_pre;
  std::string				_code;
  std::string				_desc;
  int					_time;
  int					_startTimer;
  int					_endTimer;
  int					_priority;

public:
  //Ctor
  Step();
  //Dtor
  ~Step();
  //Member
  bool					isEqualTo(Step);
  void					checkLine(std::string &);
  void					printStep();
  void					init(std::string &);
  //Getter
  std::vector<std::string>		&getPre();
  std::string				&getCode();
  std::string				&getDesc();
  int					getTime();
  int					getStartTimer();
  int					getEndTimer();
  int					getPriority();
  //Setter
  void					setPre(std::vector<std::string> &);
  void					setCode(std::string &);
  void					setDesc(std::string &);
  void					setTime(int);
  void					setStartTimer(int);
  void					setEndTimer(int);
  void					setPriority(int);

};

#endif /* ! __STEP_HPP__ */
