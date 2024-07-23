#ifndef _CONFIG_HH 
    #define _CONFIG_HH 1
    namespace config{
        extern char *path;
        void parse(const char *fpath);

        class error{
        private:
            const char *ret;
        public:
            error(const char *msg) throw();
            const char *what() throw(){
               return ret; 
            }
        };
    };
#endif
