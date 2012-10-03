#include "MpiException.h"

#include <mpi.h>

namespace FuzzyNinja
{
    MpiException::MpiException(int errorCode)
        : errorCode(errorCode)
    {
        // Do nothing.
    }

    int MpiException::getErrorCode() const
    {
        return errorCode;
    }
}
