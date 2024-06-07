#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
#include <typeinfo>
#include <sstream>
#include <string>
#include <fstream>
#include <string>
#include <vector>

// Defines a type alias for a vector of strings.
typedef std::vector<std::string> Strings;

/**
 * @brief Opens a file with the provided file name.
 *
 * @param[in] kFileName, File name of the file to open.
 * @return file, return An opened file if it was successfully opened,
 * otherwise a default-constructed std::ifstream object indicating failure.
 */
std::ifstream OpenFile(const std::string& kFileName)
{
	try
	{
		std::ifstream file(kFileName);
		if (!file.is_open())
		{
			throw std::runtime_error("Failed to open file for reading");
		}
		return file;
	}
	catch (const std::exception& exception)
	{
		std::cerr << "Error: " << exception.what() << std::endl;
		return std::ifstream();
	}

}

/**
 * @brief Reads an int from the provided text file name.
 *
 * Opens the file with the provided file name, reads the first line of the file,
 * converts it to an int, and returns the result.
 * @param[in] kFileName, File name of the file containing the seed.
 * @return seed, The integer seed read from the file.
 * Returns 0 if the file cannot be opened or if the file is empty.
 */
int GetSeed(const std::string& kFileName)
{
	int seed = 0;
	std::ifstream file = OpenFile(kFileName);
	if (file.is_open())
	{
		std::string line = "";
		std::getline(file, line);
		seed = std::stoi(line);
		file.close();
	}
	return seed;
}

/**
 * @brief Reads details of CSpaces from a text file.
 *
 * Opens the file by provided file name, reads its content line by line,
 * and stores each line of CSpace details as a separate element in a vector of strings.
 *
 * @param[in] kFileName, File name of the text file containing details of CSpaces.
 * @return Spaces, A vector of strings containing the details of CSpaces read from the file,
 *         with each line's details stored as a separate string.
 *         If the file cannot be opened or is empty, an empty vector is returned.
 */
Strings GetCSpaces(const std::string& kFileName)
{
	Strings Spaces;
	std::ifstream file = OpenFile(kFileName);
	if (file.is_open())
	{
		std::string line = "";
		while (std::getline(file, line))
		{
			Spaces.push_back(line);
		}
		file.close();
	}
	return Spaces;
}

// Defines a type alias for a vector of unsigned shorts.
typedef std::vector<unsigned short> Shorts;

Shorts Prioritize(const short& kYear, const short kGradYear = 3)
{
	Shorts order;
	for (short i = kGradYear; i >= 1; i--)
	{
		short year = kYear + i - 1;
		if (year <= kGradYear)
		{
			order.push_back(year);
		}
		else
		{
			order.push_back(year % kGradYear);
		}
	}
	return order;
}

class MyClass : public std::enable_shared_from_this<MyClass> {
public:
    std::shared_ptr<MyClass> getShared() {
        return shared_from_this();
    }
};

std::vector<std::string> MergeStrings(std::vector<std::string> list)
{
    // Iterate through the list.
    for (auto element = list.begin(); element != list.end(); ++element)
    {
        if (element == list.end() || (element + 1) == list.end())
        {
            break;
        }
        // Check if the current string to int convertion is possible.
        std::istringstream currentString(*element);
        std::istringstream nextString(*(element + 1));
        int intValue = 0;
        if (!(currentString >> intValue))
        {
            // If the current string cannot be converted to an integer,
            // check the next element
            auto nextElement = element + 1;
            // Checks if the next element is not the end of the vactor and
            // checks if the next element to int convertion is possible.
            if (nextElement != list.end() && !(nextString >> intValue))
            {
                // Combine the current and next elements.
                std::string combinedElement = *element + " " + *nextElement;
                *element = combinedElement;
                // Erase the next element.
                list.erase(nextElement);
                // Checks if the new next element to int convertion is possible.
                nextElement = element + 1;
                if (nextElement != list.end())
                {
                    std::istringstream nextString(*nextElement);
                    if (!(nextString >> intValue))
                    {
                        // Move the iterator back to combine the current string and next string.
                        element--;
                    }
                }
            }
        }
    }
    return list;
}

std::vector<std::string> Split(std::string input)
{
    std::istringstream currentString(input);
    std::vector<std::string> list;
    std::string tempString;

    while(currentString >> tempString)
    {
        list.push_back(tempString);
    }
    return list;
}
void oldMain()
{
    Strings dataReadings = GetCSpaces("degrees.txt");
    for(auto& pData : dataReadings)
    {
        std::vector<std::string> params = MergeStrings(Split(pData));
        if (!params.empty())
        {
            int typeIndex = std::stoi(params[0]);
            switch (typeIndex)
            {
            case 1: // Assessment
                std::cout << "Assessment" << std::endl;
                break;
            case 2: // Welcome Week
                std::cout << "Welcome Week" << std::endl;
                break;
            case 3: // Extra - curricular Activity
                std::cout << "Extra - curricular Activity" << std::endl;
                break;
            case 4: // Bonus
                std::cout << "Bonus" << std::endl;
                break;
            case 5: // Bogus
                std::cout << "Bogus" << std::endl;
                break;
            case 6: // Plagiarism Hearing
                std::cout << "Plagiarism Hearing" << std::endl;
                break;
            case 7: // Accused of Plagiarism
                std::cout << "Accused of Plagiarism" << std::endl;
                break;
            case 8: // Skip Classes
                std::cout << "Skip Classes" << std::endl;
                break;
            }
        }
    }
}

class Fruit
{
// public:
//     int* ptr = new int;
//     Fruit(int num)
//     {
//         *ptr = num;
//     }
//     Fruit& operator=(const Fruit& kOriginal)
//     {
//         *this->ptr = *kOriginal.ptr;
//         std::cout << "Hutto" << std::endl;
//         return *this;
//     }
//     //Copy constructor
//     Fruit(const Fruit& kOriginal)
//     {
//         *(this->ptr) = *(kOriginal.ptr);
//     }
//     ~Fruit()
//     {
//         delete ptr;
//     }
};

class Orange : public Fruit
{

};

class Seedless : public Orange
{

};

void func(int n)
{
    if(n > 0)
    {
        func(--n);
    }
    std::cout << n << '\t';
}

int main()
{
    func(5);
    return 0;
}

// int main()
// {
//     int x = -1;
//     try
//     {
//         std::cout << "Inside try \n";
//         if (x < 0)
//         {
//             throw x;
//             std::cout << "After throw \n";
//         }
//     }
//     catch (int x)
//     {
//         std::cout << "Exception caught \n";
//     }
//     std::cout << "After catch \n";
//     return 0;
// }

// int main()
// {
//     // Fruit apple(5);
//     // Fruit grape = apple; //Calls copy constructor
//     // Fruit papaya(apple); //Calls copy constructor
//     // std::cout << *apple.ptr << std::endl;
//     // std::cout << *grape.ptr << std::endl;
//     // std::cout << *papaya.ptr << std::endl;
//     // *apple.ptr = 6;
//     // papaya = apple;
//     // std::cout << *apple.ptr << std::endl;
//     // std::cout << *grape.ptr << std::endl;
//     // std::cout << *papaya.ptr << std::endl;
//     // system("echo hello world");
//     Orange* o1 = new Orange();
//     Orange* o2 = new Orange();
//     Seedless* s1 = new Seedless();
//     Fruit* fruitBasket[] = {o1, o2, s1};
//     return 0;
// }

// int main()
// {
//     try
//     {
//         ;
//     }
//     catch (int param)
//     {
//         std::cout << "int exception\n";
//     }
//     catch (...)
//     {
//         std::cout << "default exception\n";
//     }
//     std::cout << "After Exception";
//     return 0;
// }

