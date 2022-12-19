#ifndef FB4DF261_9418_4555_829A_2444EC104886
#define FB4DF261_9418_4555_829A_2444EC104886

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <string_view>
#include <sstream>
#include <concepts>
#include <cstddef>
#include <memory>

#include "array_list_iterator.hpp"

/* Random access and variable-size list data structure which allows
   elements to be added or removed. Overcomes the limit of static
   arrays, which have a fixed capacity that needs to be specified at
   allocation.  */
template <typename T>
class array_list final
{
public:
  /* Conventional types for containers.  */

  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = array_list_iterator<T>;
  using const_iterator = void;
  using difference_type = std::ptrdiff_t;
  using size_type = std::size_t;

public:
  /* Constructs a default array list.  */
  array_list() noexcept;

  /* Constructs an array list from another instance.  */
  array_list(const array_list &array_list_copy) noexcept;

  /* Moves an instance of an array list to the current instance. */
  array_list(array_list &&array_list_move) noexcept;


public:
  /* Inserts an element at the back of the array list.  */
  auto push_back(const value_type &value) noexcept
    -> void;

  auto begin() noexcept
    -> iterator;

  auto end() noexcept
    -> iterator;

  /* Checks whether the array list is empty.  */
  [[nodiscard]] inline auto empty() const noexcept
    -> bool;

  /* Gets the size of the array list.  */
  [[nodiscard]] inline auto size() const noexcept
    -> size_type;

  /* Obtains the capacity of the array list.  */
  [[nodiscard]] inline auto capacity() const noexcept
    -> size_type;

private:
  using m_array_type = std::unique_ptr<T[]>;
  m_array_type m_array;
  size_type m_size;
  size_type m_capacity;
};

#include "../src/array_list.cpp"

#endif
