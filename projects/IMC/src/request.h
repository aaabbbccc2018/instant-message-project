#ifndef REQUEST_H
#define REQUEST_H

typedef long long ll;

class Request
{public:
    ll op;
    ll param[3];

    Request(ll op = 0, ll p0 = 0, ll p1 = 0, ll p2 = 0);
    ~Request();
};


#endif
