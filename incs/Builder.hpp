//
// Builder.hpp for  in /home/kopiz/Workplace/MATHS/mine/incs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Wed Nov 22 09:48:43 2017 Tom Jeammet
// Last update Fri Nov 24 19:50:17 2017 Tom Jeammet
//

#ifndef __BUILDER_HPP__
# define __BUILDER_HPP__

# include <vector>
# include <string>

# include "Step.hpp"

class                                   Builder
{
private:
  std::vector<Step>			_done;
  std::vector<Step>			_steps;

public:
  //Ctor
  Builder();
  //Dtor
  ~Builder();
  //Member
  std::vector<Step>			getPossibSteps(std::vector<Step> &);
  bool					isInToDo(std::vector<Step> &, std::string &);
  bool					missing(std::vector<std::string> &, std::string &);
  bool					isPossib(std::vector<std::string> &);
  bool					isEnough(std::string &, std::vector<Step> &);
  bool					isDone(std::string &);
  void					pushOther(std::vector<Step> &, std::vector<Step> &);
  void					pushStepsToDo(std::vector<Step> &);
  void					build();
  int					indexOfStep(Step &);
  //Getter
  std::vector<Step>			&getDone();
  std::vector<Step>			&getSteps();
  //Setter
  void                                  setDone(std::vector<Step> &);
  void					setSteps(std::vector<Step> &);

};

#endif /* ! __BUILDER_HPP__ */
