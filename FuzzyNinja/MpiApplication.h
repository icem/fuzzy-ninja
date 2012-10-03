#ifndef FUZZY_NINJA_MPI_APPLICATION_H
#define FUZZY_NINJA_MPI_APPLICATION_H

namespace FuzzyNinja
{

class MpiApplication
{
public:
    MpiApplication(int *argc, char **argv[]);
    int run();
    virtual ~MpiApplication();
};

}

#endif
