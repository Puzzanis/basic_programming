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
public:
	explicit Parser(const char* filename);
	std::string removeSpaces(std::string& input) const;

	void printMap(const std::string& currentSection);

	std::string getStringValue(const std::string& input);

	template<class T>
	T getValue(const std::string& section)
	{
		return getStringValue(section);
	}
	template<>
	int getValue(const std::string& section)
	{
		std::string res = getStringValue(section);

		if (res.find(",") != static_cast<size_t>(-1))
		{
			std::cout << "Warning. Тип этого значения double или float преобразуется в int" << std::endl;
		}
		try
		{
			iValue = std::stoi(res);
		}
		catch (const std::out_of_range& ex)
		{
			throw ex;
		}
		catch (const std::invalid_argument& ex)
		{
			throw ex;
		}
		return iValue;

	}

	template<>
	double getValue(const std::string& section)
	{
		std::string res = getStringValue(section);
		try
		{
			dValue = std::stod(res);
		}
		catch (const std::out_of_range& ex)
		{
			throw ex;
		}
		catch (const std::invalid_argument& ex)
		{
			throw ex;
		}
		return dValue;

	}

	template<>
	float getValue(const std::string& section)
	{
		std::string res = getStringValue(section);
		try
		{
			fValue = std::stof(res);
		}
		catch (const std::out_of_range& ex)
		{
			throw ex;
		}
		catch (const std::invalid_argument& ex)
		{
			throw ex;
		}
		return fValue;

	}

};