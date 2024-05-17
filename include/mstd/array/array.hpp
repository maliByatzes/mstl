#pragma once

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <type_traits>

namespace mstd
{

  template<class T, std::size_t N>
  struct array
  {
    // assert if T is MoveConstructible and MoveAssignable
    static_assert(std::is_move_constructible_v<T>, "Type T must be MoveConstructible");
    static_assert(std::is_move_assignable_v<T>, "Type T must be MoveAssignable");

    // member types
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using iterator = value_type*;
    using const_iterator = const value_type*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    value_type elems[N];  // NOLINT

    /*
    *****************************************
    * Element access
    *******************************************
    */

    // access specified element with bounds checking

    constexpr reference at(size_type pos)
    {
      if (pos >= N)
      {
        throw std::out_of_range("pos is out of range, pos >= size()");
      }
      return elems[pos];
    }

    constexpr const_reference at(size_type pos) const
    {
      if (pos >= N)
      {
        throw std::out_of_range("pos is out of range, pos >= size()");
      }
      return elems[pos];
    }

    // access specified element

    constexpr reference operator[](size_type pos)
    {
      return elems[pos];
    }

    constexpr const_reference operator[](size_type pos) const
    {
      return elems[pos];
    }

    // access first element

    constexpr reference front()
    {
      return elems[0];
    }

    constexpr const_reference front() const
    {
      return elems[0];
    }

    // access last element

    constexpr reference back()
    {
      return elems[N - 1];
    }

    constexpr const_reference back() const
    {
      return elems[N - 1];
    }

    // direct access to the underlying contiguous storage

    constexpr pointer data() noexcept
    {
      // TODO: check if size() is zero
      return static_cast<pointer>(elems);
    }

    constexpr const_pointer data() const
    {
      // TODO: check if size() is zero
      return static_cast<const_pointer>(elems);
    }

    /*
    *****************************************
    * Iterators
    *******************************************
    */

    // return an iterator to the beginning

    constexpr iterator begin() noexcept {
      return iterator(data());
    }

    constexpr const_iterator begin() const noexcept {
      return const_iterator(data());
    }

    constexpr const_iterator cbegin() const noexcept {
      return const_iterator(data());
    }

    // returns an iterator to the end

    constexpr iterator end() noexcept {
      return iterator(data() + N);
    }

    constexpr const_iterator end() const noexcept {
      return const_iterator(data() + N);
    }

    constexpr const_iterator cend() const noexcept {
      return const_iterator(data() + N);
    }

    // returns a reverse iterator to the beginning

    constexpr reverse_iterator rbegin() noexcept {
      return reverse_iterator(end());
    }

    constexpr const_reverse_iterator rbegin() const noexcept {
      return const_reverse_iterator(end());
    }

    constexpr const_reverse_iterator crbegin() const noexcept {
      return const_reverse_iterator(end());
    }

    // returns a reverse iterator to the end

    constexpr reverse_iterator rend() noexcept {
      return reverse_iterator(begin());
    }

    constexpr const_reverse_iterator rend() const noexcept {
      return const_reverse_iterator(begin());
    }

    constexpr const_reverse_iterator crend() const noexcept {
      return const_reverse_iterator(begin());
    }

    /*
    *****************************************
    * Capacity
    *******************************************
    */

    // checks whether the container is empty

    [[nodiscard]] constexpr bool empty() const noexcept {
      return begin() == end();
    }

    // returns number of elements

    [[nodiscard]] constexpr size_type size() const noexcept {
      return N;
    }

    // returns maximum number of elements

    [[nodiscard]] constexpr size_type max_size() const noexcept {
      return N;
    }

    /*
    *****************************************
    * Operations
    *******************************************
    */

    // fill container with specified value

    void fill(const_reference value) {
      std::fill_n(begin(), N, value);
    }
  };

}  // namespace mstd
