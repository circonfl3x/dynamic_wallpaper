#ifndef _ARGS_HH

    #define _ARGS_HH 1
    namespace args{

        class error{
            private:
                const char *ret;
            public:
                error(const char *msg) throw();
                const char *what() throw(){
                    return ret;
                }
        };

        extern void parser(int argc, char **argv);
    }; 
#endif
