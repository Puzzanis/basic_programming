#include "./include/database.h"

Database::Database(const std::string& userName, const std::string& pwd, const std::string& dbName, const std::string& host, const int& port)
{
	userName_ = std::format("user={} ",		userName);
	dbName_   = std::format("dbname ={} ",	dbName);
	host_     = std::format("host={} ",		host);
	port_     = std::format("port={} ",		port);
	pwd_      = std::format("password={} ", pwd);

	try 
	{
		conn = new pqxx::connection(host_ + port_ + dbName_ + userName_ + pwd_ );
		tx = new pqxx::work(*conn);

		conn->prepare("create_table", "CREATE TABLE IF NOT EXISTS public.user (id serial PRIMARY KEY, firstname VARCHAR(255), lastname VARCHAR(255), email VARCHAR(255), phone VARCHAR(255));");
		conn->prepare("add_user", "INSERT INTO public.user(firstname, lastname, email, phone) VALUES ($1, $2, $3, $4);");
		conn->prepare("update_phone", "UPDATE public.user SET phone=$1 WHERE public.user.firstname=$2 and public.user.lastname=$3;");
		conn->prepare("update_firstName", "UPDATE public.user SET firstname=$1 WHERE public.user.lastname=$2 AND public.user.email=$3;");
		conn->prepare("update_lastName", "UPDATE public.user SET lastname=$1 WHERE public.user.firstname=$2 AND public.user.email=$3;;");
		conn->prepare("update_email", "UPDATE public.user SET email=$1 WHERE public.user.firstname=$2 and public.user.lastname=$3;");
		conn->prepare("delete_entry", "DELETE FROM public.user WHERE public.user.firstname=$1 and public.user.lastname=$2;");
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
};

Database::~Database()
{
	conn->~connection();
}

Database& Database::getInstance(const std::string& userName, const std::string& pwd, const std::string& dbName, const std::string& host, const int& port)
{
	if (!instance) {
		instance = new Database(userName, pwd, dbName, host, port);
	}
	return *instance;
}

void Database::CreateTable()
{
	tx->exec_prepared("create_table");
	tx->commit();
}

void Database::addUser(User& u)
{
	tx->exec_prepared("add_user", u.firstName, u.lastName, u.email, u.phone);
	tx->commit();
}

void Database::deleteUser(User& u)
{
	tx->exec_prepared("delete_entry", u.firstName, u.lastName);
	tx->commit();
}

void Database::updateUser(std::string whatToUpdate, User& u)
{
	Column value = stringToEnum(whatToUpdate);
	switch (value)
	{
		case Column::firstName:
			tx->exec_prepared("update_firstName", u.firstName, u.lastName, u.email);
			break;
		case Column::lastName:
			tx->exec_prepared("update_lastName", u.lastName, u.firstName, u.email);
			break;
		case Column::email:
			tx->exec_prepared("update_email", u.email, u.firstName, u.lastName);
			break;
		case Column::phone:
			tx->exec_prepared("update_phone", u.phone, u.firstName, u.lastName);
			break;
		default:
			break;
	}
	tx->commit();
}

Column Database::stringToEnum(const std::string& str)
{
	if (str == "firstName") {
		return Column::firstName;
	}
	else if (str == "lastName") {
		return Column::lastName;
	}
	else if (str == "email") {
		return Column::email;
	}
	else if (str == "phone") {
		return Column::phone;
	}
	else {
		
	}
}

