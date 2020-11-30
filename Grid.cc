#include <string>
#include "Grid.hh"
#include <iostream>


Grid::Grid(int r, int c):
  rows {r},
  columns{c},
  marked{new bool[r*c]},
  markedToEast{new bool[r*c]},
  markedToSouth{new bool[r*c]}
{}

//draws the row part, not the borders
// tr and tc are the coordinates of the turtle
void Grid::drawRow(int r, int tr, int tc){
  std::cout << "| ";
  for( int c = 0 ; c < columns ; c++){
    if(r == tr and c == tc){
      std::cout << "@";
    }
    else if(hasMark(r,c)){
      std::cout << "X";
    }
    else{
      std::cout << " ";
    }

    if(hasMarkToEast(r,c)){
      std::cout << "XXX";
	
    }
    else{
      std::cout << " | ";
      
    }

  }
  std::cout << std::endl;
}

//Draws the row border
void Grid::drawRowBorder(int r){
  std::cout << "+";
  for(int c = 0; c < columns ; c++){
    if(hasMarkToSouth(r,c)){
      std::cout << "-X-+";
      
    }
    else{
      std::cout << "---+";
    }
  }
  std::cout << std::endl;
}


//draws the grid
void Grid::display(int r, int c){
  std::cout << "+";
  for( int i = 0; i< columns ; i++){
    std::cout << "---+";
  }
  std::cout << std::endl;
  for( int j = 0; j< rows; j++){
    drawRow(j,r,c);
    drawRowBorder(j);
  }
}

int Grid::getRows(void){
  return rows;

}

int Grid::getColumns(void){
  return columns;

}

// to get to coordinates in a 1-d array, we use the equation (r,c) = (r*columns)+c
void Grid::mark(int r, int c){
  marked[(r*columns)+c] = true;
}

void Grid::markToEast(int r, int c){
  markedToEast[(r*columns)+c] = true;
}

void Grid::markToSouth(int r, int c){
  markedToSouth[(r*columns)+c] = true;
}

bool Grid::hasMark(int r, int c){
  return marked[(r*columns)+c];
}

bool Grid::hasMarkToEast( int r, int c){
  return markedToEast[(r*columns)+c];
}

bool Grid::hasMarkToSouth( int r, int c){
  return markedToSouth[(r*columns)+c];
}

//gives back the arrays to avoid memory leaks
Grid::~Grid(void){
  delete [] marked;
  delete [] markedToEast;
  delete [] markedToSouth;

}

