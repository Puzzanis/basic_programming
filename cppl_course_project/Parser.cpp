#include "Parser.h"

ReadStream::ReadStream(const char* filename): filename_{ filename }
{
	f.open(filename_);
	if (!f.is_open())
	{
		throw std::runtime_error("File opening error: " + filename_);
	}
}

ReadStream::~ReadStream()
{
	f.close();
}

std::ifstream* ReadStream::getFile()
{
	return &f;
}

Parser::Parser(const char* filename) :ReadStream(filename)
{
	file = getFile();
	while (std::getline(*file, line_))
	{
		++lineNumber_;
		if (line_.empty() || line_[0] == ';' || line_[0] == '#')
		{
			continue;
		}

		if ((line_[0] == '[') && (line_[line_.length() - 1] == ']'))
		{
			currentSection_ = line_.substr(1, line_.length() - 2);
		}
		else
		{
			std::istringstream isString(line_);

			if (std::getline(isString, key_, '='))
			{
				if (std::getline(isString, value_))
				{
					size_t pos = value_.find(';');  // ищем позицию ";"

					if (pos != std::string::npos) 
					{
						value_ = value_.substr(0, pos);  // забираем значение переменной до ";"
					}
					Data_[currentSection_][Parser::removeSpaces(key_)] = Parser::removeSpaces(value_);

				}

				if (value_ == "")
				{
					throw std::runtime_error("нет значения переменной в секции " + currentSection_ + " на строке # " + std::to_string(lineNumber_));
				}
			}
		}
	}
}

std::string Parser::removeSpaces(std::string& input) const
{
	input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
	input.erase(std::remove(input.begin(), input.end(), '\t'), input.end());
	return input;
}


void Parser::printMap(const std::string& currentSection)
{
	const std::map<std::string, std::string>& innerMap = Data_[currentSection];

	std::cout << "В секции [" << currentSection << "] присутствуют следующие переменные :" << std::endl;
	for (auto innerIt = innerMap.begin(); innerIt != innerMap.end(); ++innerIt)
	{
		std::cout << innerIt->first << std::endl;
	}
}

std::string Parser::getStringValue(const std::string& input)
{
	std::string section;
	std::string key;
	std::istringstream iss(input);
	if (std::getline(iss, section, '.'))
	{
		
		if (Data_.find(section) == Data_.end())
		{
			throw std::runtime_error("Секция [" + section + "] не найдена");
		}
		
		if (std::getline(iss, key))
		{
			if (Data_[section].find(key) == Data_[section].end())
			{
				printMap(section);
				throw std::runtime_error("Переменная не найдена");
			}
			return Data_[section][key];
		}
		else
		{
			throw std::runtime_error("переменная с именем " + key + " не найдена ");
		}
	}
}
