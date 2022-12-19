#ifdef F45F3D25_BC60_4A03_82C5_84AAE929011B

#include "array_list_iterator.hpp"

template<typename T>
auto array_list_iterator<T>::operator*() const noexcept
  -> typename array_list_iterator<T>::reference
{
  return *m_ptr;
}

template<typename T>
auto array_list_iterator<T>::operator->() noexcept
  -> typename array_list_iterator<T>::pointer
{
  return m_ptr;
}

template<typename T>
auto array_list_iterator<T>::operator++() noexcept
  -> array_list_iterator<T>&
{
    m_ptr++;
    return *this;
}

template<typename T>
auto array_list_iterator<T>::operator++(int) noexcept
  -> array_list_iterator<T>
{
    array_list_iterator<T> tmp = *this;
    (++*this);
    return tmp;
}

template<typename T>
auto operator==(const array_list_iterator<T> &it1, const array_list_iterator<T> &it2) noexcept
  -> bool
{
  return it1.m_ptr == it2.m_ptr;
}

template<typename T>
auto operator!=(const array_list_iterator<T> &it1, const array_list_iterator<T> &it2) noexcept
  -> bool
{
  return it1.m_ptr != it2.m_ptr;
}

#endif