#include <iostream>
#include "./include/database.h"
#include <Windows.h>

Database* Database::instance = nullptr;

int main()
{
	setlocale(0, "");  //setting the language standard
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Database& db = Database::getInstance("postgres", "root", "Test", "localhost", 5432);
	User* user1 = new User("Sergey", "Popov", "popov@email.com", "+7(934) 555-54-43");
	User* user2 = new User("Max", "Lemonov", "Lemonov@email.com", "+7(921) 777-89-11");
	User* user3 = new User("Oleg", "Vsedostupov", "vsedostupov@email.com", "+7(977) 222-22-22");
	//создание таблицы 'user'
	db.CreateTable();
	//добавление записей в таблицу
	db.addUser(*user1);
	//db.addUser(*user2);
	//db.addUser(*user3);

	
	try
	{
		//обновление записей в таблице
		user1->phone = "+7(934) 765-78-77";
		//user1->phone = "NULL";
		db.updateUser("phone1", *user1);

		user1->firstName = "Eduard";
		db.updateUser("firstName", *user1);

		user1->lastName = "Surokov";
		db.updateUser("lastName", *user1);

		user1->email = "Surokov@email.com";
		db.updateUser("email", *user1);

		//поиск в таблице
		db.findUser(*user1);

		//удаление записей из таблицы
		db.deleteUser(*user1);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		return -1;
	}

	delete user1;
	delete user2;
	delete user3;
	return EXIT_SUCCESS;
}
