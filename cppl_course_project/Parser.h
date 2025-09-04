#pragma once

#include <exception>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <string>

class ReadStream
{
private:
	std::ifstream f;
	std::string filename_;
public:
	explicit ReadStream(const char* filename);
	~ReadStream();
	std::ifstream* getFile();
};

class Parser: public ReadStream
{
private:
	std::string filename_;
	std::string currentSection_;
	std::string key_;
	std::string value_;
	std::ifstream* file;
	std::string line_;
	int lineNumber_{ 0 };
	int iValue{ 0 };
	double dValue{ 0.0 };
	float fValue{ 0.0 };
	std::map<std::string, std::map<std::string, std::string>> Data_;
private:
	std::string errorHandling( const std::string& val);
	std::string getStringValue(const std::string& input);

public:
	explicit Parser(const char* filename);
	std::string removeSpaces(std::string& input) const;

	void printMap(const std::string& currentSection);

	template<typename T>
	T getValue(const std::string& section) {
		T result{};

		std::string string_value = errorHandling(section);
		if (string_value.size() == 0)
		{
			_Exit(EXIT_FAILURE);
		}

		if constexpr (std::is_same<int, T>::value) {
			result = std::stoi(string_value);
		}
		else if constexpr (std::is_same<double, T>::value) {
			result = std::stod(string_value);
		}
		else if constexpr (std::is_same<std::string, T>::value) {
			result = string_value;
		}
		else if constexpr (std::is_same<float, T>::value) {
			result = std::stof(string_value);
		}
		else
		{
			static_assert(sizeof(T) == -1, "no implementation for this type!");
		}
		//возвращаем результат
		return result;
	}

};