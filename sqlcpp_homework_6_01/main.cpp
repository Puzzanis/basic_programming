#include <exception>
#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <Windows.h>

#include "classesDB.h"

class User {
public:
    std::string name = "";
    std::string phone = "";
    int karma = 0;

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::field(a, phone, "phone");
        Wt::Dbo::field(a, karma, "karma");
    }
};

int main()
{
    setlocale(0, ""); // костыль для русского языка в консоли
    SetConsoleCP(65001); // два костыля для перевода exception'ов от библиотеки
    SetConsoleOutputCP(65001);

    try
    {
        std::string connectionString =
            "host=localhost "
            "port=5432 "
            "dbname=Test "
            "user=postgres "
            "password=root ";

        auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);
        Wt::Dbo::Session session;
        session.setConnection(std::move(postgres));
        session.mapClass<User>("user");
        session.createTables();
    }
    catch (const Wt::Dbo::Exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}

