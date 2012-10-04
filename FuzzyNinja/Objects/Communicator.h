#ifndef FUZZY_NINJA_OBJECTS_COMMUNICATOR_H
#define FUZZY_NINJA_OBJECTS_COMMUNICATOR_H

#include <memory>
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
    typedef ::std::shared_ptr<Communicator> SharedPtr;

    const static SharedPtr World;

    explicit Communicator(const MPI_Comm handle);
    MPI_Comm getHandle() const;

    int getSize() const;
    int getRank() const;

    ~Communicator();
};

    }
}

#endif
