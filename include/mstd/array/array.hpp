#pragma once

#include <cstddef>
#include <stdexcept>
#include <type_traits>

namespace mstd {

template<class T, std::size_t N>
struct array {
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
  // omit iterator aliases for now

  value_type elems[N]; // NOLINT

  // element access

  constexpr reference at(size_type pos) {
    if (pos >= N) {
      throw std::out_of_range("pos is out of range, pos >= size()");
    }
    return elems[pos];
  }

  constexpr const_reference at(size_type pos) const {
    if (pos >= N) {
      throw std::out_of_range("pos is out of range, pos >= size()");
    }
    return elems[pos];
  }
};

}

