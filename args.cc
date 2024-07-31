#include "wall.hh"
#include "args.hh"
#include "dynamic.hh"
#include "config.hh"
#include <iostream>
#include <string.h>
#include <sys/stat.h>
using namespace args;
args::error::error(const char *msg) throw(){
   this->ret = msg; 
}
bool strc(char *a, char *b){
  if(strcmp(a,b) == 0) return true;
  return false;
}

void args::parser(int argc, char **argv){  
  if(argc >= 2){
    for(int i = 1; i < argc; ++i){
      //std::cout << argv[i] << std::endl;
      
      if(strc(argv[i], (char*)"-d")){
        flags |= (1 << DYNAMIC); //toggle dynamic flag
        
        std::cout << "\033[35mNotice: \033[0mOpening in dynamic mode" << std::endl;
      }else if(strc(argv[i], (char *)"-w")){
        flags |= (1 << WALLPAPERS); //toggle wallpapers flag
        if((flags & (1 << DYNAMIC))){
          if(i + 1 >= argc){
            
            throw(error("No directory given!"));
          }
          struct stat st;
          stat(argv[i+1], &st);
          if((S_IFMT & st.st_mode) != S_IFDIR){
            std::cout << argv[i+1] << " is not a directory! Exiting...";
            throw(error(""));
          }else {
            dynamic::path = (char*)malloc(strlen(argv[i+1]) + 1);
            strcpy(dynamic::path, argv[i+1]);
            // std::cout << dynamic_walls_dir << std::endl;
          }
        }
        else if(argc - i < 2){
          throw(error("Needs light and dark theme variant"));
        }else{
          if((flags & (1 << DYNAMIC)) == 0){ //is not dynamic?
            walls_switch.at(0) = argv[i+1];
            walls_switch.at(1) = argv[i+2];
            break;
          } else;
            

        }
        ++i;
      }else if(strc(argv[i], (char*)"-c")){
        flags |= (1 << CONFIG);
        if(i+1 >= argc){
            throw(error("No config file given!"));
        }
        struct stat st;
        stat(argv[i+1], &st);
        if((S_IFMT & st.st_mode) != S_IFREG){
            printf("'%s' is not a file", argv[i]);
            throw(error(""));
        }
        config::path = argv[i+1];
        ++i;
      }else{
        std::cout << "Uknown argument '" << argv[i] << "'";
        throw(error(""));
      }
    }
  }

}
