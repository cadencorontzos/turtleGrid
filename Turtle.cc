
#include <iostream>
#include <string>
#include "Grid.hh"
#include "Turtle.hh"

Turtle::Turtle(Grid* grid, std::string name):
  name{name},
  y{0},
  trailOn{false},
  x{0},
  facing{2},
  grid{grid}
{}

// returns the direction based off of the facing variable
std::string Turtle::direction(int d){
  std::string directions [4] = {"north","east","south","west"};
  return directions[d];

}

void Turtle::forward(){
  if(trailOn){
    grid->mark(y,x);
  }

  // moving up
  if(facing==0 and y>0){
    y--;
    if(trailOn){
      grid->markToSouth(y,x);
    }
  }
  
  //moving right
  else if(facing==1 and x<(*grid).getColumns()-1 ){
    if(trailOn){
      grid->markToEast(y,x);
    }
    x++;

  }

  //moving down
  else if(facing==2 and y<(*grid).getRows()-1 ){
    if(trailOn){
      grid->markToSouth(y,x);
    }
    y++;
  }

  //moving left
  else if(facing==3 and x>0){
    x--;
    if(trailOn){
      grid->markToEast(y,x);
    }
  }

}

void Turtle::left(){
  if(facing == 0){
    facing=3;
  }
  else{
    facing--;

  }
}

void Turtle::trail(bool on){
  trailOn = on;
}

void Turtle::right(){
  facing=((facing+1)%4);

}

std::string Turtle::to_string(){
  grid->display(y,x);
  std::string coordinates = "("+ std::to_string(x)+"," + std::to_string(y) + ")";
  return name + " the turtle is sitting at " + coordinates + " facing " + direction(facing) + "."; 

}

