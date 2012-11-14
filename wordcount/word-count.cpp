#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <boost/mpi.hpp>
#include <boost/serialization/map.hpp>

using namespace std;
namespace mpi=::boost::mpi;

void print_help()
{
    cout << "Usage: mpiexec word-count <file path>..."
                << endl;
}

char separators[] = " ,.\n-+;:!?()\t[]{}<>'\"";

bool is_seperator (char c) { 
    char* end = separators + sizeof(separators) / sizeof(separators[0]);            
    char* position = std::find(separators, end, c);
    return (position != end); 
}

struct reverse_sort_pred {
    bool operator()(const std::pair<string,int> &left, const std::pair<string,int> &right) {
        return left.second > right.second;
    }
};

int main(int argc, char *argv[])
{
    mpi::environment env(argc, argv);
    mpi::communicator world;

    if (argc != 2)
    {
        if (world.rank() == 0)
        {
            print_help();
        }
        return 1;
    }
    
    //common variables
    int chunk_size;
    int map_nodes_count = world.size() - 1;
    int master_rank = 0;
    int max_chunk_size;
    unsigned int max_output_lines = 25;

    //master_rank vars
    char* buffer;
    int buffer_length;
    vector<map<string, unsigned long long int>> stats;
    map<string, unsigned long long int> result;

    //slaves vars
    map<string, unsigned long long int> stat;
    // vector<string, unsigned long long int> stat_plain;
    char* input = NULL;

    if (world.rank() == master_rank)
    {
        // read input file
        string word;
        ifstream infile(argv[1]);
        
        infile.seekg(0, ios::end);    
        buffer_length = infile.tellg();  
        infile.seekg(0, ios::beg);  
        buffer = new char[buffer_length];   
        infile.read(buffer, buffer_length); 
        infile.close(); 

        chunk_size = buffer_length / map_nodes_count;
        max_chunk_size = chunk_size * 2;

        mpi::broadcast(world, max_chunk_size, master_rank);

        // split in chunks and send    
        int i, start_index = 0;
        for (i = 1; i < map_nodes_count; i ++){
            if (start_index >= buffer_length)
            {
                world.send(i, 0, buffer + buffer_length, 1);
            }
            else
            {
                int size = chunk_size;
                while (size < max_chunk_size && start_index + size <= buffer_length && 
                       !is_seperator(buffer[start_index + size - 1]))
                { 
                    size++;
                }
                buffer[start_index + size - 1] = 0;
                world.send(i, 0, buffer + start_index, max(size, 1));
                start_index += size;
            }
        }
        world.send(i, 0, buffer + min(start_index, buffer_length), max(buffer_length - start_index + 1, 1));
    }
    else {
        // get inputs
        mpi::broadcast(world, max_chunk_size, master_rank);
        input = new char[max_chunk_size];
        world.recv(master_rank, 0, input, max_chunk_size);

        //cout << "worker #" << world.rank() << ": '" << input << "'" << endl; //DEBUG
    }
    //barrier and timing
    world.barrier();
    mpi::timer timer;

    // do word count
    if(world.rank() != master_rank) {
        char * word;
        word = strtok(input,separators);
        while (word != NULL)
        {
            stat[*new string(word)] += 1;
            word = strtok (NULL, separators);
        }
        vector<string> smth;
        world.send(master_rank, 1, smth);
    }

    mpi::gather(world, stat, stats, master_rank);

    if(world.rank() == master_rank)
    {
        for(vector<map<string, unsigned long long int>>::iterator it = stats.begin(); it != stats.end(); ++it) {
            for (map<string, unsigned long long int>::iterator vit = it->begin(); vit != it->end(); ++vit) {
                result[vit->first] += vit->second;
            }            
        }
    }

    if (world.rank() == master_rank) 
    {
        cout << "Time: " << timer.elapsed() << "s" << endl;
        cout << "Total words: " << result.size() << endl;
        vector<pair<string, unsigned long long int>> output;
        for (map<string, unsigned long long int>::iterator it = result.begin(); it != result.end(); ++it) {
            output.push_back(make_pair(it->first, it->second));
        }
        sort(output.begin(), output.end(), reverse_sort_pred());
        for (unsigned int i = 0; i < output.size() && i < max_output_lines; i++) {
            cout << output[i].first << " => " << output[i].second << endl;
        }
    }
    return 0;
}
