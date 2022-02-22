//
// Created by Brandon on 2/21/22.
//

#ifndef CPP_GAME_ENGINE_VEC4_H
#define CPP_GAME_ENGINE_VEC4_H


struct Vec4 {
    Vec4();
    Vec4(float x, float y, float z, float w = 1.0f);

    float& operator [](int index);
    void set(float x, float y, float z);
    void set(float x, float y, float z, float w);

    Vec4 operator + (const Vec4 &v) const;
    Vec4& operator += (const Vec4 &v);
    Vec4 operator + (float scalar) const;
    Vec4& operator += (float scalar);
    Vec4 operator + () const;

    Vec4 operator - (const Vec4 &v) const;
    Vec4& operator -= (const Vec4 &v);
    Vec4 operator - (float scalar) const;
    Vec4& operator -= (float scalar);
    Vec4 operator - () const;

    Vec4 operator * (float scalar) const;
    Vec4& operator *= (float scalar);

    bool operator==(const Vec4 &rhs) const;
    bool operator!=(const Vec4 &rhs) const;

    float dot(const Vec4& v) const;
    Vec4 cross(const Vec4& v) const;
    Vec4& asCrossed(const Vec4& v);
    float mag() const;
    float squaredMag() const { return dot(*this); };
    float length() const { return mag(); };
    bool perpendicular(const Vec4& v) const { return dot(v) == 0; };
    bool sameDirection(const Vec4& v) const { return dot(v) > 0; };
    void normalize();
    Vec4 toNormalized() const;

    float x;
    float y;
    float z;
    float w;
};


#endif //CPP_GAME_ENGINE_VEC4_H
