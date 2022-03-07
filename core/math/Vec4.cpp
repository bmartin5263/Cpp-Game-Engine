//
// Created by Brandon on 2/21/22.
//

#include "Vec4.h"
#include <cmath>

Vec4::Vec4(): x(.0f), y(.0f), z(.0f), w(1.0f) {

}

Vec4::Vec4(float x, float y, float z, float w): x(x), y(y), z(z), w(w) {

}

// Ignore W component
float Vec4::dot(const Vec4 &v) const {
    return (this->x * v.x) + (this->y * v.y) + (this->z * v.z);
}

float &Vec4::operator[](int index) {
    auto* i = reinterpret_cast<float*>(this);
    return *(i + index);
}

void Vec4::set(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vec4::set(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

bool Vec4::operator==(const Vec4 &rhs) const {
    return x == rhs.x &&
           y == rhs.y &&
           z == rhs.z &&
           w == rhs.w;
}

bool Vec4::operator!=(const Vec4 &rhs) const {
    return !(rhs == *this);
}

Vec4 Vec4::operator+(const Vec4 &v) const {
    return {x + v.x, y + v.y, z + v.z, w};
}

Vec4 &Vec4::operator+=(const Vec4 &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vec4 Vec4::operator-(const Vec4 &v) const {
    return {x - v.x, y - v.y, z - v.z, w};
}

Vec4 &Vec4::operator-=(const Vec4 &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vec4 Vec4::operator+(float scalar) const {
    return {x + scalar, y + scalar, z + scalar, w};
}

Vec4 Vec4::operator+() const {
    return {+x, +y, +z, w};
}

Vec4 Vec4::operator-(float scalar) const {
    return {x - scalar, y - scalar, z - scalar, w};
}

Vec4 Vec4::operator-() const {
    return {-x, -y, -z, w};
}

Vec4 &Vec4::operator+=(float scalar) {
    x += scalar;
    y += scalar;
    z += scalar;
    return *this;
}

Vec4 &Vec4::operator-=(float scalar) {
    x -= scalar;
    y -= scalar;
    z -= scalar;
    return *this;
}

Vec4 Vec4::operator*(float scalar) const {
    return {x * scalar, y * scalar, z * scalar, w};
}

Vec4 &Vec4::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

float Vec4::mag() const {
    return sqrt(x*x + y*y + z*z);
}

void Vec4::normalize() {
    float magnitude = mag();
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
}

Vec4 Vec4::toNormalized() const {
    Vec4 out{*this};
    out.normalize();
    return out;
}

Vec4 Vec4::cross(const Vec4 &b) const {
    auto& a = *this;
    auto x = (a.y * b.z) - (a.z * b.y);
    auto y = (a.z * b.x) - (a.x * b.z);
    auto z = (a.x * b.y) - (a.y * b.x);
    return {x, y, z, 1.f};
}

Vec4 &Vec4::asCrossed(const Vec4 &b) {
    auto& a = *this;
    auto x = (a.y * b.z) - (a.z * b.y);
    auto y = (a.z * b.x) - (a.x * b.z);
    auto z = (a.x * b.y) - (a.y * b.x);
    a.x = x;
    a.y = y;
    a.z = z;
    return a;
}
