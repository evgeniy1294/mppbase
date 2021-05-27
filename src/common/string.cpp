#include "mpp/macro_utils.h"
#include "mpp/macro_assert.h"
#include "string.hpp"

#include <string>


/**
 * @file
 *  This file contains String class implementation.
 */


namespace mpp {
  
uint16_t StringLength(const char *aString, uint16_t aMaxLength)
{
  uint16_t ret;

  for (ret = 0; (ret < aMaxLength) && (aString[ret] != 0); ret++)
  {
      // Empty loop.
  }
  
  return ret;
}
  
  
  
  
const char *StringFind(const char *aString, char aChar)
{
  const char *ret = nullptr;

  for (; *aString != '\0'; aString++)
  {
    if (*aString == aChar)
    {
      ret = aString;
      break;
    }
  }

  return ret;
}




bool StringEndsWith(const char *aString, char aChar)
{
  size_t len = strlen(aString);

  return len > 0 && aString[len - 1] == aChar;
}





StringWriter::StringWriter(char *aBuffer, uint16_t aSize)
    : mBuffer(aBuffer)
    , mLength(0)
    , mSize(aSize)
{
    mBuffer[0] = '\0';
}




StringWriter &StringWriter::Append(const char *aFormat, ...)
{
    va_list args;
    va_start(args, aFormat);
    AppendVarArgs(aFormat, args);
    va_end(args);

    return *this;
}





StringWriter &StringWriter::AppendVarArgs(const char *aFormat, va_list aArgs)
{
  int len;

  len = vsnprintf(mBuffer + mLength, (mSize > mLength ? (mSize - mLength) : 0), aFormat, aArgs);
  MPP_ASSERT(len >= 0);

  mLength += static_cast<uint16_t>(len);

  if (IsTruncated())
  {
    mBuffer[mSize - 1] = '\0';
  }

  return *this;
}




StringWriter &StringWriter::AppendHexBytes(const uint8_t *aBytes, uint16_t aLength)
{
    while (aLength--)
    {
        Append("%02x", *aBytes++);
    }

    return *this;
}





bool IsValidUtf8String(const char *aString)
{
    return IsValidUtf8String(aString, strlen(aString));
}

bool IsValidUtf8String(const char *aString, size_t aLength)
{
    bool    ret = true;
    uint8_t byte;
    uint8_t continuationBytes = 0;
    size_t  position          = 0;

    while (position < aLength)
    {
        byte = *reinterpret_cast<const uint8_t *>(aString + position);
        ++position;

        if ((byte & 0x80) == 0)
        {
            continue;
        }

        // This is a leading byte 1xxx-xxxx.

        if ((byte & 0x40) == 0) // 10xx-xxxx
        {
            // We got a continuation byte pattern without seeing a leading byte earlier.
            ExitNow(ret = false);
        }
        else if ((byte & 0x20) == 0) // 110x-xxxx
        {
            continuationBytes = 1;
        }
        else if ((byte & 0x10) == 0) // 1110-xxxx
        {
            continuationBytes = 2;
        }
        else if ((byte & 0x08) == 0) // 1111-0xxx
        {
            continuationBytes = 3;
        }
        else // 1111-1xxx  (invalid pattern).
        {
            ExitNow(ret = false);
        }

        while (continuationBytes-- != 0)
        {
            VerifyOrExit(position < aLength, ret = false);

            byte = *reinterpret_cast<const uint8_t *>(aString + position);
            ++position;

            // Verify the continuation byte pattern 10xx-xxxx
            mfVerifyOrExit((byte & 0xc0) == 0x80, ret = false);
        }
    }

exit:
    return ret;
}





} // namespace mpp
