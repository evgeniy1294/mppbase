#pragma once

/**
 * @file
 *   This file defines RingBuffer class for framework
 */

#include <cstdint>
#include <optional>
#include <mpp/error.hpp>

namespace mpp {

template <typename T> class RingBuffer {
public:
  using value_type = T;

  RingBuffer( T* aBuffer, const std::size_t aSize )
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
  template <typename dataT> void Push( dataT&& data );
  template <typename dataT> mppError TryPush( dataT&& data );
  std::optional<T> Pop();


private:
  const std::size_t mCapacity;
  T *mBuffer, *mHead, *mTail;
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
template< typename dataT >
void RingBuffer<T>::Push( dataT&& data ) {
  if constexpr ( std::is_move_assignable_v<T>) {
    *mHead = std::forward<dataT>(data);
  }
  else {
    static_assert ( std::is_copy_assignable_v<T> );
    static_assert ( std::is_copy_assignable_v<std::decay_t<dataT>> );
    *mHead = data;
  }


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
template< typename dataT >
mppError RingBuffer<T>::TryPush( dataT&& data ) {
  Error err = kErrorFailed;
  if ( !mFull ) {
    Push( std::forward<dataT>(data) );
    err = kErrorNone;
  }

  return err;
}




template< typename T >
std::optional<T> RingBuffer<T>::Pop() {
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
