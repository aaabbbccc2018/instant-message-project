#ifndef REQUEST_ENTRY_H
#define REQUEST_ENTRY_H

#include "request_centre.h"
#include "pthread.h"


class RequestEntry
{public:
    RequestCentre* backend;
    pthread_t tid;

    RequestEntry(RequestCentre* rc);
    ~RequestEntry();

    static void* thread_entry(void* arg);
    void run();
    
};

#endif