double string_to_double(const char* from);
#include <iostream>
#include <cstdlib>
#include <vector>
#include <numeric>

int main(int argc, char* argv[])
{
  if (argc == 1)
  {
    std::cerr << "No arguments.\n";
    return 1;
  }

  std::vector<double> numbers;

  for (int i = 1; i < argc; ++i)
  {
    try
    {
      numbers.push_back(string_to_double(argv[i]));
    }
    catch (std::invalid_argument&)
    {
      return 1;
    }
  }

  double product = std::reduce(numbers.begin(), numbers.end());

  std::cout << product / numbers.size() << '\n';

  return 0;
};

double string_to_double(const char* from)
{
  double converted_number;

  try
  {
    converted_number = std::stod(from);
  }
  catch (std::invalid_argument& error)
  {
    std::cerr << "\e[41mInvalid number -> " << from << "\e[0m\n";
    throw error;
  }
  return converted_number;
}
