#include "wall.hh"
#include <stdexcept>
#include <stdio.h>
#include <iostream>
#include <string>
ulong pid_of(const char *command){
  FILE *p = popen(command, "r");
  char buff[16];
  fgets(buff, 16, p);
  ulong pid = 0;
  try{
    pid = std::stol(buff);
  }catch(std::invalid_argument &e){
    std::cout << "HWAT? " << &e << std::endl;
  }catch(std::overflow_error &e){
    std::cout << "PID overflow: " << &e << std::endl;
  }

  return pid; 
}

std::string pid_of_str(const char *command){
	
  FILE *p = popen(command, "r");
  char buff[16];
  fgets(buff, 16, p);

  return buff;
}
