#ifndef REQUEST_CENTRE_H
#define REQUEST_CENTRE_H
#include "request_handler.h"
#include <vector>


class RequestCentre
{public:
    std::vector<RequestHandler*> handlers;

    RequestCentre();
    ~RequestCentre();

    void add_request(Request* req);
    
};

#endif