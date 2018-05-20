#include "request_entry.h"
#include <cstdlib>
#include <iostream>


RequestEntry::RequestEntry(RequestCentre* rc)
{
    backend = rc;

    pthread_create(&tid, NULL, thread_entry, (void*)this);
    pthread_detach(tid);
}

RequestEntry::~RequestEntry()
{
    pthread_cancel(tid);
}

void* RequestEntry::thread_entry(void* arg)
{
    RequestEntry* This = (RequestEntry*)arg;
    This->run();

    return NULL;
}

void RequestEntry::run()
{
    int num;
    while (std::cin >> num)
    {
        for (int i = 0; i < num; i++)
        {
            Request* req = new Request(0x01);
            req->param[0] = random();
            backend->add_request(req);
        }
    }

}