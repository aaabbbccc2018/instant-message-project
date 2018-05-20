#include "imc.h"

IMC::IMC()
{
    backend = new RequestCentre();
    frontend = new RequestEntry(backend);
}

IMC::~IMC()
{
    delete frontend;
    delete backend;
}