#include <iostream>
#include <thread>
#include "db.h"

using namespace std;

void hello(){
    cout << "Hello World!" << endl;
}

int main()
{
    get_data();
    std::thread t(hello);
    t.join();
    return 0;
}


