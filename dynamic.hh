
#ifndef _DYNAMICWALL_H 
  #define _DYNAMICWALL_H 1
  #include <map>
  #include <string>
  #include "extras.hh"
  extern void fs_crawler(const char *fpath);
  extern void get_time();
  extern std::map<time_c, std::string>::iterator return_closest //DEPRECATED
    (struct tm *t, std::map<time_c, std::string> *map_walls, std::map<time_c, std::string>::iterator *current_wallpaper);
  extern std::map<time_c, std::string>::iterator return_next
    (struct tm *t, std::map<time_c, std::string> *map_wallpapers) ;
  
  extern std::map<time_c, std::string>::iterator return_current
    (struct tm *t, std::map<time_c, std::string> *map_wallpapers);

  extern std::map<time_c, std::string>::iterator _current
    (struct tm *t, std::map<time_c, std::string> *map_wallpapers);
#endif
