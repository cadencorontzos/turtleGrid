#include "Turtle.hh"
#include "Grid.hh"
#include <iostream>

int main(void) {

  std::string nm;
  std::cout << "What is the name of your turtle?" << std::endl;
  std::cin >> nm;
  
  Grid g {5,10};
  Turtle t {&g,nm};
  
  std::string command;
  do {
    std::cout << t.to_string() << std::endl;
    std::cout << "Enter a turtle command: ";
    std::cin >> command;
    if (command == "forward") {
      t.forward();
    } else if (command == "left") {
      t.left();
    } else if (command == "right") {
      t.right();
    } else if (command == "on") {
      t.trail(true);
    } else if (command == "off") {
      t.trail(false);
    } else if (command != "quit") {
      std::cout << "The turtle does not understand that command." << std::endl;
    }
  } while (command != "quit");
}
