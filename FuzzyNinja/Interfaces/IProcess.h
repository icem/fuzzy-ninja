#ifndef FUZZY_NINJA_INTERFACES_IPROCESS_H
#define FUZZY_NINJA_INTERFACES_IPROCESS_H

#include <memory>

namespace FuzzyNinja
{
    namespace Interfaces
    {

class IProcess
{
public:
    typedef ::std::shared_ptr<IProcess> SharedPtr;

    virtual int run() = 0;
};

    }
}

#endif
