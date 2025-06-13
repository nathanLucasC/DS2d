#include <stdio.h>

namespace gb {

    //macro
    #define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
}