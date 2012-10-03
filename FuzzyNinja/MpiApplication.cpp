#include "FuzzyNinja/MpiApplication.h"
#include "FuzzyNinja/MpiEnvironment.h"
#include "FuzzyNinja/Objects/Communicator.h"

#include <mpi.h>

namespace FuzzyNinja
{

MpiApplication::MpiApplication(int *argc, char **argv[])
{
    MpiEnvironment::Initialize(argc, argv);
}

int MpiApplication::run(::FuzzyNinja::Interfaces::IProcessFactory &aProcessFactory)
{
    int rank = ::FuzzyNinja::Objects::Communicator::World.getRank();
    return aProcessFactory.createProcess(rank)->run();
}

MpiApplication::~MpiApplication()
{
    MpiEnvironment::Finalize();
}

}
