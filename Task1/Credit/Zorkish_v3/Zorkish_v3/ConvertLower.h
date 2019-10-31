#pragma once
#include <string>

namespace
{
	std::string ConvertLower(std::string userInput)
	{
		std::string newString;

		for (size_t i = 0; i < userInput.length(); ++i)
		{
			newString.push_back(tolower(userInput[i]));
		}

		return newString;
	};
}
