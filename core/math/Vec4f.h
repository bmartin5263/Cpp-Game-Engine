//
// Created by Brandon on 2/21/22.
//

#ifndef CPP_GAME_ENGINE_VEC4F_H
#define CPP_GAME_ENGINE_VEC4F_H


struct Vec4f {
    Vec4f();
    Vec4f(float x, float y, float z, float w = 1.0f);

    float& operator [](int index);
    void set(float x, float y, float z);
    void set(float x, float y, float z, float w);

    Vec4f operator + (const Vec4f &v) const;
    Vec4f& operator += (const Vec4f &v);
    Vec4f operator + (float scalar) const;
    Vec4f& operator += (float scalar);
    Vec4f operator + () const;

    Vec4f operator - (const Vec4f &v) const;
    Vec4f& operator -= (const Vec4f &v);
    Vec4f operator - (float scalar) const;
    Vec4f& operator -= (float scalar);
    Vec4f operator - () const;

    Vec4f operator * (float scalar) const;
    Vec4f& operator *= (float scalar);

    bool operator==(const Vec4f &rhs) const;
    bool operator!=(const Vec4f &rhs) const;

    float dot(const Vec4f& v) const;
    Vec4f cross(const Vec4f& v) const;
    Vec4f& asCrossed(const Vec4f& v);
    float mag() const;
    float squaredMag() const { return dot(*this); };
    float length() const { return mag(); };
    bool perpendicular(const Vec4f& v) const { return dot(v) == 0; };
    bool sameDirection(const Vec4f& v) const { return dot(v) > 0; };
    void normalize();
    Vec4f toNormalized() const;

    float x;
    float y;
    float z;
    float w;
};


#endif //CPP_GAME_ENGINE_VEC4F_H
