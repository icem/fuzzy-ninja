#ifndef FUZZY_NINJA_MPI_EXCEPTION_H
#define FUZZY_NINJA_MPI_EXCEPTION_H

#include <exception>

namespace FuzzyNinja
{

class MpiException: public ::std::exception
{
private:
    int errorCode;
public:
    MpiException(int errorCode);
    int getErrorCode() const;
};

}

#endif
