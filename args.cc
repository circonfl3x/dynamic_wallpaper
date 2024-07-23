#include "wall.hh"
#include <iostream>
#include <string.h>
#include <sys/stat.h>
bool strc(char *a, char *b){
  if(strcmp(a,b) == 0) return true;
  return false;
}

void arg_parser(int argc, char **argv){  
  if(argc >= 2){
    for(int i = 0; i < argc; ++i){
      //std::cout << argv[i] << std::endl;
      
      if(strc(argv[i], (char*)"-d")){
        flags |= (1 << DYNAMIC); //toggle dynamic flag
        
        std::cout << "Open in dynamic mode" << std::endl;
      }else if(strc(argv[i], (char *)"-w")){
        flags |= (1 << WALLPAPERS); //toggle wallpapers flag
        if((flags & (1 << DYNAMIC))){
          if(i + 1 >= argc){
            std::cout << "No directory given!" << std::endl;
            exit(1);
          }
          struct stat st;
          stat(argv[i+1], &st);
          if((S_IFMT & st.st_mode) != S_IFDIR){
            std::cout << argv[i+1] << " is not a directory! Exiting..." << std::endl;
            exit(1);
          }else {
            dynamic_walls_dir = (char*)malloc(strlen(argv[i+1]) + 1);
            strcpy(dynamic_walls_dir, argv[i+1]);
            // std::cout << dynamic_walls_dir << std::endl;
          }
        }
        else if(argc - i < 2){
          std::cout << "Needs light and dark theme variant" << std::endl;
          exit(1);
        }else{
          if((flags & (1 << DYNAMIC)) == 0){ //is not dynamic?
            walls_switch.at(0) = argv[i+1];
            walls_switch.at(1) = argv[i+2];
            break;
          } else;
            

        }
      }
    }
  }

}
