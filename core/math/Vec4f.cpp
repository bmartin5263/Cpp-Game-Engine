//
// Created by Brandon on 2/21/22.
//

#include "Vec4f.h"
#include <cmath>

Vec4f::Vec4f(): x(.0f), y(.0f), z(.0f), w(1.0f) {

}

Vec4f::Vec4f(float x, float y, float z, float w): x(x), y(y), z(z), w(w) {

}

// Ignore W component
float Vec4f::dot(const Vec4f &v) const {
    return (this->x * v.x) + (this->y * v.y) + (this->z * v.z);
}

float &Vec4f::operator[](int index) {
    auto* i = reinterpret_cast<float*>(this);
    return *(i + index);
}

void Vec4f::set(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vec4f::set(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

bool Vec4f::operator==(const Vec4f &rhs) const {
    return x == rhs.x &&
           y == rhs.y &&
           z == rhs.z &&
           w == rhs.w;
}

bool Vec4f::operator!=(const Vec4f &rhs) const {
    return !(rhs == *this);
}

Vec4f Vec4f::operator+(const Vec4f &v) const {
    return {x + v.x, y + v.y, z + v.z, w};
}

Vec4f &Vec4f::operator+=(const Vec4f &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vec4f Vec4f::operator-(const Vec4f &v) const {
    return {x - v.x, y - v.y, z - v.z, w};
}

Vec4f &Vec4f::operator-=(const Vec4f &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vec4f Vec4f::operator+(float scalar) const {
    return {x + scalar, y + scalar, z + scalar, w};
}

Vec4f Vec4f::operator+() const {
    return {+x, +y, +z, w};
}

Vec4f Vec4f::operator-(float scalar) const {
    return {x - scalar, y - scalar, z - scalar, w};
}

Vec4f Vec4f::operator-() const {
    return {-x, -y, -z, w};
}

Vec4f &Vec4f::operator+=(float scalar) {
    x += scalar;
    y += scalar;
    z += scalar;
    return *this;
}

Vec4f &Vec4f::operator-=(float scalar) {
    x -= scalar;
    y -= scalar;
    z -= scalar;
    return *this;
}

Vec4f Vec4f::operator*(float scalar) const {
    return {x * scalar, y * scalar, z * scalar, w};
}

Vec4f &Vec4f::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

float Vec4f::mag() const {
    return sqrt(x*x + y*y + z*z);
}

void Vec4f::normalize() {
    float magnitude = mag();
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
}

Vec4f Vec4f::toNormalized() const {
    Vec4f out{*this};
    out.normalize();
    return out;
}

Vec4f Vec4f::cross(const Vec4f &b) const {
    auto& a = *this;
    auto x = (a.y * b.z) - (a.z * b.y);
    auto y = (a.z * b.x) - (a.x * b.z);
    auto z = (a.x * b.y) - (a.y * b.x);
    return {x, y, z, 1.f};
}

Vec4f &Vec4f::asCrossed(const Vec4f &b) {
    auto& a = *this;
    auto x = (a.y * b.z) - (a.z * b.y);
    auto y = (a.z * b.x) - (a.x * b.z);
    auto z = (a.x * b.y) - (a.y * b.x);
    a.x = x;
    a.y = y;
    a.z = z;
    return a;
}
