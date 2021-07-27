#pragma once

/**
 * @file
 *   This file defines RingBuffer class for framework
 */

#include <cstdint>
#include <optional>
#include <utility>
#include <type_traits>
#include <mpp/error.hpp>

namespace mpp {

template <typename T> class RingBuffer {
public:
  using value_type = std::decay_t<T>;
  static_assert( std::is_same_v< T, value_type >);

  RingBuffer( value_type* aBuffer, const std::size_t aSize )
    : mBuffer(aBuffer)
    , mCapacity(aSize)
    , mHead(aBuffer)
    , mTail(aBuffer)
    , mFull(false)
  {
  }

  void Reset() { mHead = mBuffer; mTail = mHead; }
  bool IsEmpty() { return ( mHead == mTail) && !mFull; }
  bool IsFull() { return mFull; }
  std::size_t Capacity() { return mCapacity; }
  std::size_t Size();
  template < typename K > void Push( K&& data );
  template < typename K > mppError TryPush( K&& data );
  std::optional<value_type> Pop();

private:
  inline void Assign( const value_type& value )
    requires std::is_copy_assignable_v<value_type>
  {
    *mHead = value;
  }

  inline void Assign( value_type&& value )
    requires std::is_move_assignable_v<value_type>
  {
    *mHead = std::move(value);
  }

private:
  const std::size_t mCapacity;
  value_type *mBuffer, *mHead, *mTail;
  bool mFull;
};




template< typename T >
std::size_t RingBuffer<T>::Size()
{
  std::size_t size = mCapacity;

  if (!mFull) {
    if ( mHead >= mTail )
    {
      size = mHead - mTail;
    }
    else
    {
      size = mCapacity + ( mHead - mTail );
    }
  }

  return size;
}




template< typename T >
template< typename K >
void RingBuffer<T>::Push( K&& data ) {
  Assign( std::forward<K>(data) );

  if ( mFull ) {
    if ( ++mTail == ( mBuffer + mCapacity ) )
    {
      mTail = mBuffer;
    }
  }

  if ( ++mHead == ( mBuffer + mCapacity ) )
  {
    mHead = mBuffer;
  }

  mFull = mHead == mTail;
}



template< typename T >
template< typename K >
mppError RingBuffer<T>::TryPush( K&& data ) {
  Error err = kErrorFailed;
  if ( !mFull ) {
    Push( std::forward<K>(data) );
    err = kErrorNone;
  }

  return err;
}




template< typename T >
auto RingBuffer<T>::Pop() -> std::optional<value_type> {
  if ( IsEmpty() )
    return std::nullopt;
  else {
    std::optional<T> ret{ *mTail };
    mFull = false;

    if ( ++mTail == ( mBuffer + mCapacity ) )
    {
      mTail = mBuffer;
    }

    return ret;
  }
}




} // namespace mpp
