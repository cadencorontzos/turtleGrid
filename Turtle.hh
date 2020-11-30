
#ifndef __TURTLE_H_
#define __TURTLE_H_
#include <string>
#include "Grid.hh"
class Turtle{

private:
  
  int x;
  int y;
  std::string name;
  int facing;            //north = 0, east = 1, south = 2, west = 3
  Grid* grid;
  bool trailOn;  
  std::string direction(int d);

public:
  Turtle(Grid* grid, std::string name);
  void forward(void);
  void trail(bool on);
  void left(void);
  void right(void);
  std::string to_string(void);

};
#endif
