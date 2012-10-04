#ifndef FUZZY_NINJA_OBJECTS_BROADCAST_H
#define FUZZY_NINJA_OBJECTS_BROADCAST_H

#include "FuzzyNinja/Objects/Communicator.h"

namespace FuzzyNinja
{
    namespace Objects
    {

class Broadcast
{
private:
    int root;
    ::FuzzyNinja::Objects::Communicator::SharedPtr communicator;
public:
    Broadcast(
        int aRoot,
        ::FuzzyNinja::Objects::Communicator::SharedPtr aCommunicator);

    Broadcast& operator<<(int value);
    Broadcast& operator>>(int &value);
};

    }
}

#endif
