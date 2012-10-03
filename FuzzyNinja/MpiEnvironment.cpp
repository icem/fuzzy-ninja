#include "MpiEnvironment.h"
#include "MpiException.h"

#include <mpi.h>

namespace FuzzyNinja
{

void MpiEnvironment::Initialize(
    int *argc,
    char **argv[])
{
    CheckCall(MPI_Init(argc, argv));
}

void MpiEnvironment::CheckCall(
    const int errorCode)
{
    if (errorCode != MPI_SUCCESS)
    {
        throw MpiException(errorCode);
    }
}

void MpiEnvironment::Finalize()
{
    CheckCall(MPI_Finalize());
}

}
