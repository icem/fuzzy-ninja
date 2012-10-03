#ifndef FUZZY_NINJA_OBJECTS_COMMUNICATOR_H
#define FUZZY_NINJA_OBJECTS_COMMUNICATOR_H

#include <mpi.h>

namespace FuzzyNinja
{
    namespace Objects
    {

class Communicator
{
private:
    MPI_Comm handle;
public:
    const static Communicator World;

    explicit Communicator(const MPI_Comm handle);
    MPI_Comm getHandle() const;

    int getSize() const;
    int getRank() const;

    ~Communicator();
};

    }
}

#endif
