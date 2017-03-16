#include <cmath>
#include "Vector2D.h"

Vector2D::Vector2D(float x, float y)
: x_(x), y_(y)
{
  //ctor
}

float Vector2D::x() const
{
  return x_;
}

float Vector2D::y() const
{
  return y_;
}

void Vector2D::x(float v)
{
  x_ = v;
}

void Vector2D::y(float v)
{
  y_ = v;
}

float Vector2D::length() const
{
  return sqrt(x_*x_ + y_*y_);
}

Vector2D Vector2D::operator+(const Vector2D& v) const
{
  return Vector2D(x_ + v.x(), y_ + v.y());
}

Vector2D Vector2D::operator-(const Vector2D& v) const
{
  return Vector2D(x_ - v.x(), y_ - v.y());
}

Vector2D Vector2D::operator*(float scalar) const
{
  return Vector2D(x_ * scalar, y_ * scalar);
}

Vector2D Vector2D::operator/(float scalar) const
{
  return Vector2D(x_ / scalar, y_ / scalar);
}

Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
{
  v1.x_ += v2.x_;
  v1.y_ += v2.y_;

  return v1;
}

Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
{
  v1.x_ -= v2.x_;
  v1.y_ -= v2.y_;

  return v1;
}

Vector2D& operator*=(Vector2D& v1, float scalar)
{
  v1.x_ *= scalar;
  v1.y_ *= scalar;

  return v1;
}

Vector2D& operator/=(Vector2D& v1, float scalar)
{
  v1.x_ /= scalar;
  v1.y_ /= scalar;

  return v1;
}

void Vector2D::normalize()
{
  float len = length();
  if (len) {
    (*this) /= len;
  }
}
