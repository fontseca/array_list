#ifndef F45F3D25_BC60_4A03_82C5_84AAE929011B
#define F45F3D25_BC60_4A03_82C5_84AAE929011B

#include <iterator>
#include <cstddef>

template <typename>
class array_list_iterator;

template <typename T>
auto operator==(const array_list_iterator<T> &,
  const array_list_iterator<T> &) noexcept
  -> bool;

template <typename T>
auto operator!=(const array_list_iterator<T> &,
  const array_list_iterator<T> &) noexcept
  -> bool;

/* Iterator for a array list.  */
template <typename T>
class array_list_iterator
{
public:
  using iterator_category = std::random_access_iterator_tag;
  using difference_type = std::ptrdiff_t;
  using value_type = T;
  using pointer = value_type*;
  using const_pointer = const value_type*;
  using reference = value_type&;
  using const_reference = const value_type&;

  array_list_iterator(pointer ptr)
    : m_ptr { ptr }
  { }

  auto operator*() const noexcept
    -> reference;

  auto operator->() noexcept
    -> pointer;

  auto operator++() noexcept
    -> array_list_iterator&;

  auto operator++(int) noexcept
    -> array_list_iterator;

  friend auto operator==<T>(const array_list_iterator &a, const array_list_iterator &b) noexcept
    -> bool;

  friend auto operator!=<T>(const array_list_iterator& a, const array_list_iterator &b) noexcept
    -> bool;

private:
  pointer m_ptr;
};

#include "../src/array_list_iterator.cpp"

#endif
