#include <cstdint>
#include <iostream>
#include <vector>
#include "Graph.hpp"
#include <fstream>

#include <sys/resource.h>

long getMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;
}

using namespace std;

int main(int argc, const char * argv[]) {

    string str;
    
    if (argc > 1) str = string(argv[1]);
    else return 1;

    uint32_t Reservoir_size = 12;
    if(argc > 2) Reservoir_size = stoi(argv[2]);

    double tau = 0.95;
    if(argc > 3) tau = stod(argv[3]);

    
    Graph *g = new Graph(str.data(), Reservoir_size, tau);
    
    clock_t startTime,endTime;
    startTime = clock();

    vector<uint64_t> accurate_value;
    
    g->read_graph();
    
    endTime = clock();
    cout << "The read_graph time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    
    
    accurate_value = g->triangle_enum();

    startTime = clock();
    vector<uint64_t> HTCount_results = g->HTCount();
    endTime = clock();
    
    cout<<"inner triangle error: "<<((double)HTCount_results[0] - (double)accurate_value[0])/(double)accurate_value[0]<<endl;
    cout<<"hybrid triangle error: "<<((double)HTCount_results[1] - (double)accurate_value[1])/(double)accurate_value[1]<<endl;
    cout<<"outer triangle error: "<<((double)HTCount_results[2] - (double)accurate_value[2])/(double)accurate_value[2]<<endl;
    cout << "The HTCount time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    cout<<endl;

    g->init();

    startTime = clock();
    vector<uint64_t> HTCount_P_results = g->HTCount_P();
    endTime = clock();

    cout<<"inner triangle error: "<<((double)HTCount_P_results[0] - (double)accurate_value[0])/(double)accurate_value[0]<<endl;
    cout<<"hybrid triangle error: "<<((double)HTCount_P_results[1] - (double)accurate_value[1])/(double)accurate_value[1]<<endl;
    cout<<"outer triangle error: "<<((double)HTCount_P_results[2] - (double)accurate_value[2])/(double)accurate_value[2]<<endl;
    cout << "The HTCount_P time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC  << endl;
    cout<<endl;
    
    return 0;
}
