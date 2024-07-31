#include "wall.hh"
#include "dynamic.hh"
#include "config.hh"
std::array<std::string, 2> walls_switch  {{"",""}};
std::vector<std::string> dynamic::wallpapers;
std::map<time_c, std::string> dynamic::map;
int current = -1;
int flags = 0;
char *dynamic::path, *config::path;
char *config_path;
std::map<time_c, std::string> dyn_walls_map;
int change_wallpaper(const char *fpath);
int day = 0;
