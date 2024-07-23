
#include "wall.hh"

bool isDark(){ //very lazy way of getting color scheme
  FILE *p = popen("gsettings get org.gnome.desktop.interface 'color-scheme'", "r");
  if(!p) return false;
  char buff[15];
  fgets(buff, 15, p); 
  if(buff[13] == '\n'){ //stupid quick work around
    return true;
  }else return false;
}
