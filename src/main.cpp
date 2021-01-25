#include <iostream>
#include <thread>
#include "db.h"
#include <tbb/tbb.h>

using namespace std;

void hello(){
    cout << "Hello World!" << endl;
}

int main()
{
    get_data();

    std::cout << "TBB version: " << TBB_VERSION_MAJOR
          << "." << TBB_VERSION_MINOR << std::endl;

    std::thread t(hello);
    t.join();
    return 0;
}


