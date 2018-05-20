#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H
#include "request.h"
#include <queue>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

class RequestHandler
{public:
    std::queue<Request*> rq;
    pthread_mutex_t mutex_rq;
    sem_t sem_rq;
    pthread_t tid;

    RequestHandler();
    ~RequestHandler();

    static void* thread_entry(void* arg);
    void run();

    bool add_request(Request* req);
};

#endif