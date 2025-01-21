#pragma once
#include <exception>
#include <iostream>
#include <string>
#include <pqxx/pqxx>
#include <tuple>

enum class Column
{
	firstName,
	lastName,
	email,
	phone
};

struct User
{
	std::string firstName{};
	std::string lastName{};
	std::string email{};
	std::string phone{};

	User(std::string firstName, std::string lastName, std::string email, std::string phone) :
		firstName{ firstName }, lastName{ lastName }, email{ email }, phone{ phone } {};
};

class Database
{
private:
	std::string userName_{};
	std::string pwd_{};
	std::string dbName_{};
	std::string host_{};
	std::string port_{};
	pqxx::work* tx;
	pqxx::connection* conn;

	static Database* instance;

	Database(const std::string& userName, const std::string& pwd, const std::string& dbName, const std::string& host, const int& port);
	~Database();

	Column stringToEnum(const std::string& str);
public:
	// Delete the copy constructor and assignment operator
	Database(const Database&) = delete;
	Database& operator=(const Database&) = delete;
	static Database& getInstance(const std::string& userName, const std::string& pwd, const std::string& dbName, const std::string& host, const int& port);
	void CreateTable();
	void addUser(User& u);
	void updateUser(std::string whatToUpdate, User& u);
	void deleteUser(User& u);
};