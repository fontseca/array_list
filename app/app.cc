#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <array>
#include <cassert>

#include "array_list.hpp"
#include "array_list_iterator.hpp"

auto main([[maybe_unused]] std::int32_t argc, [[maybe_unused]] char **argv)
  -> std::int32_t
{
  array_list<std::string> arr;

  arr.push_back("1");
  arr.push_back("2");
  arr.push_back("3");
  arr.push_back("4");
  arr.push_back("5");
  arr.push_back("6");
  arr.push_back("7");
  arr.push_back("8");
  arr.push_back("9");
  arr.push_back("ten");

  auto beg = std::begin(arr); 

  assert(*beg == "1");

  for (const auto &c : arr)
  {
    std::cout << c << std::endl;
  }

  assert(arr.size() == 10);
  assert(arr.capacity() == 16);

  return EXIT_SUCCESS;
}