#include "LoaderParams.h"

LoaderParams::LoaderParams(int x, int y, int w, int h, const std::string& id)
: x_(x), y_(y), width_(w), height_(h), textureId_(id)
{
  //ctor
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
std::string LoaderParams::textureId() const
{
  return textureId_;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
int LoaderParams::height() const
{
  return height_;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
int LoaderParams::width() const
{
  return width_;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
int LoaderParams::y() const
{
  return x_;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
int LoaderParams::x() const
{
  return y_;
}

