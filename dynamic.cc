#include "dynamic.hh"
#include "wall.hh"
#include <cstring>
#include <ctime>
#include <dirent.h>
#include <errno.h>
#include <iostream>
#include <map>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
using namespace dynamic;

void dynamic::fs_crawler(const char *fpath) {

  DIR *dirtree = opendir(fpath);
  struct stat st;
  if (!dirtree) {
    if (errno == ENOENT) {
      std::cout << "Directory ''" << fpath << "' doesn't exist" << std::endl;
    } else if (errno == ENOTDIR) {
      std::cout << "'" << fpath << "' is not a directory" << std::endl;
    } else if (errno == EACCES) {
      std::cout << "You do not have the permission to view '" << fpath << "'"
                << std::endl;
    }
    exit(1);
  }
  struct dirent *child;
  while ((child = readdir(dirtree)) != NULL) {
    stat(child->d_name, &st);
    // if ((st.st_mode & S_IFMT) == S_IFDIR) {
    // }
    // std::cout << (st.st_mode & S_IFMT)*2 << " " << S_IFREG << std::endl;
    if ((st.st_mode & S_IFMT) * 2 ==
        S_IFREG) { // Dont know why the fuck multiplying by 2 gives me the right
                   // result
      // std::cout << child->d_name << ":" << "File" << std::endl;

      char *dup = strdup(child->d_name);
      char *tok = strtok(dup, ".");
      if (tok == NULL)
        continue;
      std::string filename = strdup(tok);
      tok = strtok(NULL, ".");
      if (tok == NULL)
        ;
      else if (strc(tok, (char *)"jpg") || strc(tok, (char *)"png") || //looking at headers is too much work
               strc(tok, (char *)"jpeg") || strc(tok, (char *)"PNG"))
        wallpapers.push_back(child->d_name);
      free(dup);
    }
  }
}

void dynamic::get_time() {
  time_c t;
  for (std::string wallpaper : wallpapers) {
    char *dup = strdup(wallpaper.c_str());
    char *tok = strtok(dup, ":");

    try {
      t.hours = std::atol(wallpaper.c_str());
    } catch (std::out_of_range &e) {
      std::cout << "Number of hours too large" << std::endl;
      exit(1);
    } catch (std::invalid_argument &e) {
      std::cout << "Unknown clock format " << wallpaper << std::endl;
      exit(1);
    }
    tok = strtok(NULL, ":");
    if (tok != NULL) {
      try {
        t.minutes = atoi(tok);
      } catch (std::out_of_range &e) {
        std::cout << "Number of minutes too large" << std::endl;
        exit(1);
      } catch (std::invalid_argument &e) {
        std::cout << "Unknown clock format " << wallpaper << std::endl;
        exit(1);
      }
    } else
      t.minutes = 0;
    if (t.hours > 23) {
        if(t.hours > 24) std::cout << "How many hours are there in a day?" << std::endl;
        else std::cout << "Number of hours too large" << std::endl;
        exit(1);
    } else if (t.minutes > 59) {
      std::cout << "Bro do you know how to count minutes lmao" << std::endl;
      exit(1);
    }
    map.insert({t, wallpaper});
    free(dup);
  }
}


std::map<time_c, std::string>::iterator dynamic::_current
  (struct tm *t, std::map<time_c, std::string> *map_wallpapers)
{

  std::map<time_c, std::string>::iterator wallpaper, ret;
  int a = 0;
  time_c closest = {65,25}, max = {0,0};
  int closest_hour = 25;
  bool wall_def = false;
  for(wallpaper = map_wallpapers->begin() ; wallpaper != map_wallpapers->end(); ++wallpaper){
    if(t->tm_hour == wallpaper->first.hours){
      return wallpaper;
    }else if((a = t->tm_hour - wallpaper ->first.hours) > 0 && a < closest_hour){
      closest_hour = a;
      ret = wallpaper;
      wall_def = true;
    }
  }
  closest_hour = 0;
  if(!wall_def){
    for(wallpaper = map_wallpapers->begin(); wallpaper != map_wallpapers->end(); ++wallpaper){
      if(wallpaper->first.hours > closest_hour){
        closest_hour = wallpaper->first.hours;
        ret = wallpaper;
      }
    }
  }

  

  return ret;
    
}
