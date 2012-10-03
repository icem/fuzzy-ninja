#include "FuzzyNinja/MpiApplication.h"
#include "FuzzyNinja/MpiEnvironment.h"

#include <mpi.h>

namespace FuzzyNinja
{

MpiApplication::MpiApplication(int *argc, char **argv[])
{
    MpiEnvironment::Initialize(argc, argv);
}

int MpiApplication::run(::FuzzyNinja::Interfaces::IProcessFactory &aProcessFactory)
{
    return aProcessFactory.createProcess(0)->run();
}

MpiApplication::~MpiApplication()
{
    MpiEnvironment::Finalize();
}

}
