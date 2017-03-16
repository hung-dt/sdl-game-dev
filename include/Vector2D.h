#ifndef VECTOR2D_H
#define VECTOR2D_H


class Vector2D
{
  public:
    Vector2D(float, float);

    float x() const;
    float y() const;
    void x(float);
    void y(float);

    float length() const;

    // Vector operations
    Vector2D operator+(const Vector2D&) const;
    Vector2D operator-(const Vector2D&) const;
    Vector2D operator*(float) const;
    Vector2D operator/(float) const;

    friend Vector2D& operator+=(Vector2D&, const Vector2D&);
    friend Vector2D& operator-=(Vector2D&, const Vector2D&);
    friend Vector2D& operator*=(Vector2D&, float);
    friend Vector2D& operator/=(Vector2D&, float);

    void normalize();
  private:
    float x_;
    float y_;
};

#endif // VECTOR2D_H
