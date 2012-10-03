#ifndef FUZZY_NINJA_MPI_ENVIRONMENT_H
#define FUZZY_NINJA_MPI_ENVIRONMENT_H

namespace FuzzyNinja
{

class MpiEnvironment
{
public:
    static void Initialize(
        int *argc,
        char **argv[]);
    static void CheckCall(
        const int errorCode);
    static void Finalize();
};

}

#endif
