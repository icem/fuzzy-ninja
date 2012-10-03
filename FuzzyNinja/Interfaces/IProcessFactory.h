#ifndef FUZZY_NINJA_INTERFACES_IPROCESS_FACTORY_H
#define FUZZY_NINJA_INTERFACES_IPROCESS_FACTORY_H

#include "FuzzyNinja/Interfaces/IProcess.h"

namespace FuzzyNinja
{
    namespace Interfaces
    {

class IProcessFactory
{
public:
    virtual IProcess::SharedPtr createProcess(
        const int aRank,
        const int processCount) = 0;
};

    }
}

#endif
