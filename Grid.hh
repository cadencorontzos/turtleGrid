
#ifndef __GRID_H_
#define __GRID_H_

class Grid{
private:
  int rows;
  int columns;
  bool* marked;
  bool* markedToEast; //we use three arrays to keep track of marks
  bool* markedToSouth;
  void drawRow(int r, int tr, int tc);
  void drawRowBorder(int r);
public:
  void mark(int r, int c);
  void markToEast(int r, int c);
  void markToSouth(int r, int c);
  bool hasMark(int r, int c);
  bool hasMarkToEast( int r, int c);
  bool hasMarkToSouth( int r, int c);
  void display(int r, int c);
  Grid(int r, int c);
  int getRows(void);
  int getColumns(void);
  ~Grid(void);//deletes the three arrays

};

#endif
