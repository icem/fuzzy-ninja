#include <iostream>

#include <boost/mpi.hpp>

void print_help()
{
    ::std::cout << "Usage: mpiexec compute-pi-boosted <interval count>"
                << ::std::endl;
}

int main(int argc, char *argv[])
{
    ::boost::mpi::environment env(argc, argv);
    ::boost::mpi::communicator world;

    if (argc != 2)
    {
        if (world.rank() == 0)
        {
            print_help();
        }
        return 1;
    }

    int intervalCount;

    if (world.rank() == 0)
    {
        ::std::istringstream(argv[1]) >> intervalCount;
    }

    ::boost::mpi::timer timer;

    ::boost::mpi::broadcast(world, intervalCount, 0);

    ::std::cout << "[" << world.rank() << "] intervalCount: " << intervalCount
                << ::std::endl;

    int i;
    double x, h, sum, partialValue;

    h = 1.0 / intervalCount;
    sum = 0.0;
    for (i = world.rank() + 1; i <= intervalCount; i += world.size())
    {
        x = h * ((double)i - 0.5);
        sum += 4.0 / (1.0 + x*x);
    }
    partialValue = h * sum;

    ::std::cout << "[" << world.rank() << "] partialValue: " << partialValue
                << ::std::endl;

    if (world.rank() == 0)
    {
        double answer;

        ::boost::mpi::reduce(
            world,
            partialValue,
            answer,
            ::std::plus<double>(), 0);

        ::std::cout.precision(18);
        ::std::cout << "Pi: " << answer << ::std::endl;
        ::std::cout.precision(3);
        ::std::cout << "Time: " << timer.elapsed() << "s" << ::std::endl;
    }
    else
    {
        ::boost::mpi::reduce(
            world,
            partialValue,
            ::std::plus<double>(),
            0);
    }

    return 0;
}
