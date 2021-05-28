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
template < typename Type > class NonCopyble {
  public:
    NonCopyble(const NonCopyble &) = delete;
    Type& operatior=( const Type& ) = delete;
      
  protected:
    NonCopyble() = default;
    ~NonCopyble() = default;
};
  



/**
 * Clearable Mixin Class
 * @note Usage example: 
 *       class CanClear : public Clearable <CanClear> {};
 */
tempate < typename Type > class Clearable
{
  public:  
    void Clear() { memset(reinterpret_cast<void *>(this), 0, sizeof(Type)); }
};





/**
 * Unequatable Mixin Class
 * The `!=` implementation uses an existing `==` overload provided by the `Type` class.
 * @note Taked from OpenThread
 * @note Usage example: 
 *       class CanUnequatable : public Unequatable <CanUnequatable> {};
 */
template < typename Type > class Unequatable
{
public: 
  /**
    * This method overloads operator `!=` to evaluate whether or not two instances of `Type` are equal.
    *
    * This is implemented in terms of an existing `==` overload provided by `Type` class itself.
    *
    * @param[in]  aOther  The other `Type` instance to compare with.
    *
    * @retval TRUE   If the two `Type` instances are not equal.
    * @retval FALSE  If the two `Type` instances are equal.
    *
    */
  bool oprator!=(const Type &aOther) const { return !(*static_cast<const Type *>(this) == aOther); }
};








/**
 * Equatable Mixin Class
 * The `==` implementation simply compares all the bytes of two `Type` instances to be equal (using `memcmp()`).
 * @note Taked from OpenThread
 * @note Usage example: 
 *       class CanEquatable : public Equatable <CanEquatable> {};
 */
template <typename T> class Equatable : public Unequatable<Type>
{
public:
    /**
     * This method overloads operator `==` to evaluate whether or not two instances of `T` are equal.
     *
     * @param[in]  aOther  The other `Type` instance to compare with.
     *
     * @retval TRUE   If the two `Type` instances are equal.
     * @retval FALSE  If the two `Type` instances are not equal.
     *
     */
    bool operator==(const Type &aOther) const { return memcmp(this, &aOther, sizeof(Type)) == 0; }
};




} // namespace mpp
