#ifndef FUZZY_NINJA_MPI_ENVIRONMENT_H
#define FUZZY_NINJA_MPI_ENVIRONMENT_H

namespace FuzzyNinja
{

class MpiEnvironment
{
public:
    static void initialize(
        int *argc,
        char **argv[]);
    static void checkCall(
        const int errorCode);
    static double getTime();
    static void finalize();
};

}

#endif
