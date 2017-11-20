#include "Main.hpp"

bool			is_sortedbysize(std::vector<Data> &dataguys)
{
  for (size_t x = 0; x < dataguys.size() - 1; x++)
    {
      if (dataguys[x + 1].getPreSize() < dataguys[x].getPreSize())
	return (false);
    }
  return (true);
}

bool      is_befor(std::vector<Data> &dataguys, size_t pos, std::string &code)
{
  size_t x = -1;

  while (++x < pos)
    if (dataguys[x]._code == code)
      return (true);
  return (false);
}

bool      is_sortedbypriority(std::vector<Data> &dataguys)
{
  for (size_t x = 0; x < dataguys.size() - 1; x++)
  {
      for (size_t y = 0; y < dataguys[x].getPreSize(); y++)
        if (!is_befor(dataguys, x, dataguys[x].getPre()[y]))
          return (false);
  }
  return (true);
}

void                  sortOrder(std::vector<Data> &dataguys)
{
  Data      swap;
  while (!is_sortedbysize(dataguys))
    {
     for (size_t x = 0; x < dataguys.size() - 1; x++)
        {
          if (x + 1 <= dataguys.size() && (dataguys[x + 1].getPreSize() < dataguys[x].getPreSize()))
             {
               swap = dataguys[x+1];
               dataguys[x+1] = dataguys[x];
               dataguys[x] = swap;
             }
        }
    }
  std::cout << "is sorted by order" << std::endl;
}

std::vector<Data>			sort(std::vector<std::string> &file)
{
  std::vector<Data>	dataguys;
 /*
  std::vector<int>::iterator it;
  size_t k;
  it = dataguys.begin();*/

  for (size_t x = 0; x < file.size(); x++)
      dataguys.push_back(Data(file[x]));
  sortOrder(dataguys);
  /*
    while (!is_sortedbypriority(dataguys))
    {
      
    }*/
  for (size_t x = 0; x < dataguys.size(); x++)
    dataguys[x].Print(); // permet de visualiser le tri
  return (dataguys);
}
