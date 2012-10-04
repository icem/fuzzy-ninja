#include "MpiEnvironment.h"
#include "MpiException.h"

#include <mpi.h>

namespace FuzzyNinja
{

void MpiEnvironment::initialize(
    int *argc,
    char **argv[])
{
    checkCall(MPI_Init(argc, argv));
}

void MpiEnvironment::checkCall(
    const int errorCode)
{
    if (errorCode != MPI_SUCCESS)
    {
        throw MpiException(errorCode);
    }
}

double MpiEnvironment::getTime()
{
    return MPI_Wtime();
}

void MpiEnvironment::finalize()
{
    checkCall(MPI_Finalize());
}

}
