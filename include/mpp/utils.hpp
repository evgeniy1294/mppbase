#pragma once


/**
 * @file
 *   This file includes a common utility classes.
 */



namespace mpp {
  

/**
 * Non-copyble Mixin Class
 * @note Usage example: 
 *       class CantCopy : private NonCopyable <CantCopy> {};
 */
template < typename T > class NonCopyble {
  public:
    NonCopyble(const NonCopyble &) = delete;
    T& operatior=( const T& ) = delete;
      
  protected:
    NonCopyble() = default;
    ~NonCopyble() = default;
};
  



/**
 * Clearable Mixin Class
 * @note Usage example: 
 *       class CanClear : public Clearable <CanClear> {};
 */
tempate < typename T > class Clearable
{
  public:  
    void Clear() { memset(reinterpret_cast<void *>(this), 0, sizeof(T)); }
};





/**
 * Unequatable Mixin Class
 * The `!=` implementation uses an existing `==` overload provided by the `Type` class.
 * @note Taked from OpenThread
 * @note Usage example: 
 *       class CanUnequatable : public Unequatable <CanUnequatable> {};
 */
template < typename T > class Unequatable
{
public: 
  /**
    * This method overloads operator `!=` to evaluate whether or not two instances of `T` are equal.
    *
    * This is implemented in terms of an existing `==` overload provided by `T` class itself.
    *
    * @param[in]  aOther  The other `T` instance to compare with.
    *
    * @retval TRUE   If the two `T` instances are not equal.
    * @retval FALSE  If the two `T` instances are equal.
    *
    */
  bool oprator!=(const T &aOther) const { return !(*static_cast<const T *>(this) == aOther); }
};








/**
 * Equatable Mixin Class
 * The `==` implementation simply compares all the bytes of two `T` instances to be equal (using `memcmp()`).
 * @note Taked from OpenThread
 * @note Usage example: 
 *       class CanEquatable : public Equatable <CanEquatable> {};
 */
template <typename T> class Equatable : public Unequatable<T>
{
public:
    /**
     * This method overloads operator `==` to evaluate whether or not two instances of `T` are equal.
     *
     * @param[in]  aOther  The other `T` instance to compare with.
     *
     * @retval TRUE   If the two `T` instances are equal.
     * @retval FALSE  If the two `T` instances are not equal.
     *
     */
    bool operator==(const T &aOther) const { return memcmp(this, &aOther, sizeof(T)) == 0; }
};




} // namespace mpp
