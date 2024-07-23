#include "wall.hh"
#include "dynamic.hh"
#include <cstring>
#include <ctime>
#include <iostream>
#include <linux/limits.h>
#include <memory.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main(int argc, char **argv) {

  arg_parser(argc, argv);

  if ((flags & (1 << WALLPAPERS)) == 0) {
    std::cout << "Wallpapers not defined!" << std::endl;
    exit(1);
  }

  if (0 == (flags & (1 << DYNAMIC))) {

    // NOT DYNAMIC
    while (true) {
      sleep(1);
      process_ld();
    }
  } else { // dynamic

    // DYNAMIC SECTION

    fs_crawler(dynamic_walls_dir);
    std::string dynamic_fpath = dynamic_walls_dir;
    if (dynamic_fpath.at(dynamic_fpath.length() - 1) != '/')
      dynamic_fpath += "/";
    if (walls_dyn.size() == 0) {
      std::cout << "No wallpapers in directory!" << std::endl;
      exit(1);
    }

    get_time();

    for (std::string a : walls_dyn) {
      std::cout << a << std::endl;

      if (dyn_walls_map.size() == 0) {
        std::cout << "No valid wallpaper name available" << std::endl;
      }
    }

    time_t t;
    struct tm *localt;
    std::map<time_c, std::string>::iterator current_wallpaper, next_wallpaper;
    bool init = false;
    int current_hour = 0;
    ulong pid = 0;
    std::string pidS = "";

    while (true) {

      sleep(1);
      time(&t);
      localt = localtime(&t);
      // std::cout << day << std::endl;
      // if (current.hours == localt->tm_hour && current.minutes ==
      // localt->tm_min)
      // ;
      if (current_hour == localt->tm_hour) {

      } else {
        pidS = pid_of_str("pidof swaybg");
        current_hour = localt->tm_hour;
        current_wallpaper = _current(localt, &dyn_walls_map);
        change_wallpaper(dynamic_walls_dir + current_wallpaper->second);
        sleep(1);
        std::string s = "kill ";
        s+=pidS;
        system(s.c_str());
        /*if(init){
          std::stringstream ss;
          ss << "kill ";
          ss << pid;
          std::string s;
          ss>> s;
          system(s.c_str());
          init = true;
        }*/
        // pidS = pid_of_str("pidof swaybg");

        /*if(pid == 0){
          fprintf(stderr, "Cannot get PID of current running swaybg process");
          // return 1;
        }*/
        /*pidS = pid_of_str("pidof swaybg");
        std::string s = "kill ";
        s += pidS;
        std::cout << s << std::endl;
        system(s.c_str());*/
      }
      // else {
      //   wallpaper = return_closest(localt, &dyn_walls_map, &wallpaper);
      //   if(wallpaper->first.hours == current_wallpaper.hours &&
      //   wallpaper->first.minutes == current_wallpaper.minutes){
      //     puts("Still valid wallpaper!");
      //     current = {localt->tm_hour, localt->tm_min};
      //   }else{
      //     day = localt->tm_yday;

      //     // current = {localt->tm_hour, localt->tm_min};
      //     // change_wallpaper(dynamic_walls_dir + wallpaper->second);
      //     // current_wallpaper = {wallpaper->first.minutes,
      //     wallpaper->first.hours};
      //   }
      // bool wall_changed = false;
      // for (std::pair f : dyn_walls_map) {
      //   int closest = 25;
      //   std::string closest_fpath;
      //   if (localt->tm_hour != f.first) {
      //     current_wall = return_closest(localt->tm_hour, dyn_walls_map);
      //     change_wallpaper(dynamic_walls_dir + current_wall);
      //     wall_changed = true;
      //     break;
      //   }else if(localt->tm_hour == f.first && current_wall->first !=
      //   f.first){
      //     current_wall = reinterpret_cast<std::pair<uint, std::string>*>(&f);
      //     change_wallpaper(dynamic_walls_dir + f.second);
      //     wall_changed = true;
      //   }
      //   else{
      //     if(wall_changed == true) wall_changed = false;
      //   }
      // }
    }
  }
}
