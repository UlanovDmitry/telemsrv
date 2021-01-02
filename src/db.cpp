#include "db.h"
#include <iostream>
#include <pqxx/pqxx>

int get_data()
{
    try
    {
        pqxx::connection C(
            "user=wr "
            "host=localhost "
            "password=rfvmju "
            "dbname=testdb");
        std::cout << "Connected to " << C.dbname() << std::endl;
        pqxx::work W{C};

        pqxx::result R{W.exec("SELECT comment FROM some_data")};

        std::cout << "Found " << R.size() << "data:\n";
        for (auto row: R)
            std::cout << row[0].c_str() << '\n';

        std::cout << "Changing comments...\n";
        W.exec0("UPDATE some_data SET comment = 'qwerty'");

        std::cout << "Making changes definite: ";
        W.commit();
        std::cout << "OK.\n";
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}