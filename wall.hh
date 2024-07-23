#pragma once
#ifndef _WALL_HH
  #define _WALL_HH 1
  #include <string>
  #include <array>
  #include <vector>
  #include <map>
  #include "extras.hh"
  enum ARG_FLAGS{
    DYNAMIC, WALLPAPERS, CHANGED
  };

  extern int flags;
  //extern bool dyn , buff_wall_arg , wall_def , change;
  extern std::array<std::string, 2> walls_switch ;
  extern std::vector<std::string> walls_dyn;
  extern std::map<time_c, std::string> dyn_walls_map;
  extern int current, day; 
  // static const std::string info_path = "/tmp/ioptfr.txt"; //if something else uses this path istg
  extern char *dynamic_walls_dir;  
  extern bool strc(char *a, char *b);
  extern void arg_parser(int argc, char **argv);
  extern int change_wallpaper(std::string fpath);
  extern bool isDark();
  extern void process_ld();
  extern ulong pid_of(const char *command);

  extern std::string pid_of_str(const char *command);

#endif
