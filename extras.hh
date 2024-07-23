
#ifndef _EXTRAS_H
  #define _EXTRAS_H 1
  #include <stdlib.h>
  #include <map>

  //god save me 
  #define hours second
  #define minutes first
  
  
  typedef struct{
    //uint seconds; //
    int minutes;
    int hours;
  }time_c_deprecated; //struct misbehaving so fuck it
  
  typedef std::pair<uint, uint> time_c; //first minutes then hours
#endif
