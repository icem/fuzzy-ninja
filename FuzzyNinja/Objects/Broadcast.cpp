#include "FuzzyNinja/Objects/Broadcast.h"

#include "FuzzyNinja/MpiEnvironment.h"

namespace FuzzyNinja
{
    namespace Objects
    {

Broadcast::Broadcast(
    int aRoot,
    ::FuzzyNinja::Objects::Communicator::SharedPtr aCommunicator)
    : root(aRoot), communicator(aCommunicator)
{
    // Do nothing.
}

Broadcast& Broadcast::operator<<(int value)
{
    ::FuzzyNinja::MpiEnvironment::checkCall(
        MPI_Bcast(&value, 1, MPI_INT, root, communicator->getHandle()));
    return *this;
}

Broadcast& Broadcast::operator>>(int &value)
{
    int buffer = 0;
    ::FuzzyNinja::MpiEnvironment::checkCall(
        MPI_Bcast(&buffer, 1, MPI_INT, root, communicator->getHandle()));
    value = buffer;
    return *this;
}

    }
}
