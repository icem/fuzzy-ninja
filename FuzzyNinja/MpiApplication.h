#ifndef FUZZY_NINJA_MPI_APPLICATION_H
#define FUZZY_NINJA_MPI_APPLICATION_H

#include "FuzzyNinja/Interfaces/IProcessFactory.h"

namespace FuzzyNinja
{

class MpiApplication
{
public:
    MpiApplication(int *argc, char **argv[]);
    int run(::FuzzyNinja::Interfaces::IProcessFactory &aProcessFactory);
    virtual ~MpiApplication();
};

}

#endif
