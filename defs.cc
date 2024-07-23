#include "wall.hh"

std::array<std::string, 2> walls_switch  {{"",""}};
std::vector<std::string> walls_dyn;
int current = -1;
int flags = 0;
char *dynamic_walls_dir;  
std::map<time_c, std::string> dyn_walls_map;
int change_wallpaper(const char *fpath);
int day = 0;
