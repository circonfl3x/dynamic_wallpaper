
#include "wall.hh"
#include <iostream>
#include <sstream>
void process_ld(){      
      //time(&current_time);
      //local_time = localtime(&current_time);

      
      if(current == isDark()) ;
      else{
        current = isDark();
        std::stringstream s;
        change_wallpaper(walls_switch.at(current));
      }   
}
int change_wallpaper(std::string fpath){
  std::string str = "nohup swaybg -i ";
  str += fpath;
  str += " &";
  std::cout << "Switching wallpaper to " << fpath << std::endl;
  return system(str.c_str());
} 
