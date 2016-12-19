#include <stdio.h>

/*
Links:
    http://vicsydev.blogspot.com/2016/11/coroutines-in-c-revisited.html
    https://github.com/codr4life/libc4life
    https://en.wikipedia.org/wiki/Duff's_device
*/

//#define DECLARE() int state
//
//#define INIT() state = 0
//
//#define BEGIN switch (state) { \
//                      case 0:
//
//#define YIELD(val) do { \
//                        state = __LINE__;   \
//                        return val;         \
//                      case __LINE__:        \
//                        ;                   \
//                      } while (0)
//
//#define END }



#define INIT() static int state = 0

#define BEGIN switch (state) { \
                      case 0:

#define YIELD(val)  state = __LINE__;\
                        return val;  \
                    case __LINE__:   \


#define END ;} \
            return ((void* )0);



char* next() {
    INIT();

    BEGIN
        YIELD("TEST1")
        YIELD("TEST2")
        YIELD("TEST3")
    END
}


/*
After preprocessor (gcc coroutines.c -E > preprocessor.c)
int state;
state = 0;

char* next(int i) {
    switch (state) { 
        case 0:
            state = 41; 
            return "TEST1"; 
        case 41:
            state = 42; 
            return "TEST2"; 
        case 42:
            state = 43; 
            return "TEST3"; 
        case 43:
            ;
    }
    return ((void* )0);
}
*/

int main(int argc, char** argv) {
    char* val;
    while (val = next()) {
        printf("%s ", val);
    }
    
    return 0;
}