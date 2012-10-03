#include "FuzzyNinja/Objects/Communicator.h"

#include "FuzzyNinja/MpiEnvironment.h"

namespace FuzzyNinja
{
    namespace Objects
    {

const Communicator Communicator::World = Communicator(MPI_COMM_WORLD);

Communicator::Communicator(const MPI_Comm handle): handle(handle)
{
    // Do nothing.
}

MPI_Comm Communicator::getHandle() const
{
    return handle;
}

int Communicator::getSize() const
{
    int size;
    ::FuzzyNinja::MpiEnvironment::CheckCall(
        MPI_Comm_size(handle, &size));
    return size;
}

int Communicator::getRank() const
{
    int rank;
    ::FuzzyNinja::MpiEnvironment::CheckCall(
        MPI_Comm_rank(handle, &rank));
    return rank;
}

Communicator::~Communicator()
{
    
}

    }
}
