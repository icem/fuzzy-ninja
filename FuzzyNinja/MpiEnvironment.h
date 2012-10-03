#ifndef FUZZY_NINJA_MPI_ENVIRONMENT
#define FUZZY_NINJA_MPI_ENVIRONMENT

namespace FuzzyNinja
{

class MpiEnvironment
{
public:
    static void Initialize(
        const int argc,
        const char *argv[]);
    static void Finalize();
};

}

#endif
