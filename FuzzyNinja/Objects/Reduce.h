#ifndef FUZZY_NINJA_OBJECTS_REDUCE_H
#define FUZZY_NINJA_OBJECTS_REDUCE_H

#include "FuzzyNinja/Objects/Communicator.h"

#include <mpi.h>

namespace FuzzyNinja
{
    namespace Objects
    {

class Reduce
{
private:
    int root;
    MPI_Op operation;
    Communicator::SharedPtr communicator;
public:
    Reduce(
        int aRoot,
        Communicator::SharedPtr aCommunicator,
        MPI_Op anOperation);

    double operator<<(double value);
};

    }
}

#endif
