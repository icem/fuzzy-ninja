#include "FuzzyNinja/Objects/Reduce.h"

#include "FuzzyNinja/MpiEnvironment.h"

namespace FuzzyNinja
{
    namespace Objects
    {

Reduce::Reduce(
    int aRoot,
    Communicator::SharedPtr aCommunicator,
    MPI_Op anOperation)
    : root(aRoot), operation(anOperation), communicator(aCommunicator)
{
    // Do nothing.
}

double Reduce::operator<<(double value)
{
    double buffer = 0.0;

    ::FuzzyNinja::MpiEnvironment::checkCall(
        MPI_Reduce(
            &value,
            &buffer,
            1,
            MPI_DOUBLE,
            operation,
            root,
            communicator->getHandle()));
    return buffer;
}

    }
}
