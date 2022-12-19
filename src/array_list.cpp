#ifdef FB4DF261_9418_4555_829A_2444EC104886

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

#include "array_list.hpp"
#include "array_list_iterator.hpp"

/* Constructs a default array list.  */
template <typename T>
array_list<T>::array_list() noexcept
  : m_size { 0 }
  , m_capacity { 4 }
{
  m_array.reset(new T[m_capacity]);
}

/* Constructs an array list from another instance.  */
template <typename T>
array_list<T>::array_list(const array_list<T> &array_list_copy) noexcept
  : m_size { array_list_copy.m_size }
  , m_capacity { array_list_copy.m_capacity }
{
  if (not m_array)
  {
    m_array = new T[m_capacity];
  }

  std::copy(m_array.get(), m_array.get() + m_size,
    array_list_copy.m_array.get());
}

/* Moves an instance of an array list to the current instance.  */
template <typename T>
array_list<T>::array_list(array_list<T> &&array_list_move) noexcept
  : m_size { array_list_move.m_size }
  , m_capacity { array_list_move.m_capacity }
{
  m_array.reset(std::move(array_list_move.m_array));
  array_list_move.m_size = 0;
  array_list_move.m_capacity = 0;
}

/* Inserts an element at the back of the array list.  */
template <typename T>
auto array_list<T>::push_back(const typename array_list<T>::value_type &value) noexcept
  -> void
{
  if (m_size == m_capacity)
  {
    m_capacity *= 2;

    std::int32_t i { -1 };
    auto array = new typename array_list<T>::value_type[m_capacity];

    while(++i < m_size)
    {
      array[i] = m_array[i];
    }

    m_array.reset(array);
  }

  m_array[m_size] = value;
  ++m_size;
}

template <typename T>
auto array_list<T>::begin() noexcept
  -> iterator
{
  return iterator { m_array.get() };
}

template <typename T>
auto array_list<T>::end() noexcept
  -> iterator
{
  return iterator { m_array.get() + m_size };
}



/* Checks whether the array list is empty.  */
template <typename T>
[[nodiscard]] inline auto array_list<T>::empty() const noexcept
  -> bool
{
  return m_size == 0;
}

/* Gets the size of the array list.  */
template <typename T>
[[nodiscard]] inline auto array_list<T>::size() const noexcept
  -> array_list<T>::size_type
{
  return m_size;
}

/* Obtains the capacity of the array list.  */
template <typename T>
[[nodiscard]] inline auto array_list<T>::capacity() const noexcept
  -> array_list<T>::size_type
{
  return m_capacity;
}

#endif