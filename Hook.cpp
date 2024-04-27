#include <list>
#include <vector>
#include <cstring>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.h"
#include "Includes/Macros.h"
#include "Tools.h"
int (*osub_1B40B4)(const char *a1, unsigned int a2);
int hsub_1B40B4(const char *a1, unsigned int a2)
{
    while(true)
    {
        sleep(10000);
    }
    return osub_1B40B4(a1,a2);
}

void * hack_thread(void *) {
       do {
        sleep(1);
    } while (!isLibraryLoaded("libanort.so"));
    HOOK_LIB("libanort.so", "0x1B40B4", hsub_1B40B4, osub_1B40B4);
    return NULL;
}

__attribute__((constructor)) void mainload() {
        pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
       
    }
    
  
