#include "config_loader.h"
#include "db.h"
#include <iostream>
//#include <RecReg.pb.h>
//#include <tbb/tbb.h>
//#include <thread>

using namespace std;

void hello() { cout << "Hello World!" << endl; }

int main() {
  //GOOGLE_PROTOBUF_VERIFY_VERSION;

  get_data();

  //std::cout << "TBB version: " << TBB_VERSION_MAJOR << "." << TBB_VERSION_MINOR << std::endl;

  //std::thread t(hello);
  //t.join();

  ConfigLoader cl;
  cl.doSmth();

  return 0;
}
