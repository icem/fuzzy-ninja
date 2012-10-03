#include "MpiApplication.h"
#include "MpiEnvironment.h"

#include <mpi.h>

namespace FuzzyNinja
{

MpiApplication::MpiApplication(int *argc, char **argv[])
{
    MpiEnvironment::Initialize(argc, argv);
}

int MpiApplication::run()
{
    // TODO
    return 0;
}

MpiApplication::~MpiApplication()
{
    MpiEnvironment::Finalize();
}

}
