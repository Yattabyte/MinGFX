#pragma once
#ifndef VEC_HPP
#define VEC_HPP

#include <cmath>

/** A vector of 2 floats. */
class vec2 {
    public:
    // (De)Constructors
    /** Default destruct this vector. */
    ~vec2() = default;
    /** Default construct this vector. */
    vec2() = default;
    /** Construct a vector using 1 specific value. */
    explicit vec2(const float& value) noexcept : m_data{ value, value } {}
    /** Construct a vector using 2 specific attributes.
    @param  _x  the x value to use.
    @param  _y  the y value to use. */
    vec2(const float& _x, const float& _y) noexcept : m_data{ _x, _y } {}
    /** Default copy constructor. */
    vec2(const vec2& o) = default;
    /** Default move constructor. */
    vec2(vec2&& o) noexcept = default;

    // Operators
    /** Default copy-assignment operator. */
    vec2& operator=(const vec2& p) = default;
    /** Default move-assignment operator. */
    vec2& operator=(vec2&& p) noexcept = default;
    /** Add another vector to this one.
    @param  o   the other vector.
    @return     this vector plus the other vector. */
    vec2 operator+(const vec2& o) const noexcept {
        return vec2{ x() + o.x(), y() + o.y() };
    }
    /** Subtract another vector from this one.
    @param  o   the other vector.
    @return     this vector minus the other vector. */
    vec2 operator-(const vec2& o) const noexcept {
        return vec2{ x() - o.x(), y() - o.y() };
    }
    /** Multiply by another vector.
    @param  o   the other vector.
    @return     this vector multiplied by the other vector. */
    vec2 operator*(const vec2& o) const noexcept {
        return vec2{ x() * o.x(), y() * o.y() };
    }
    /** Divide by another vector.
    @param  o   the other vector.
    @return     this vector divided by the other vector. */
    vec2 operator/(const vec2& o) const noexcept {
        return vec2{ x() / o.x(), y() / o.y() };
    }
    /** Negative Operator
    @return     negative version of this vector. */
    vec2 operator-() const noexcept { return vec2{ -x(), -y() }; }
    /** Compare this vector against another for sorting purposes.
    @param  o   the other vector.
    @return     true if this vector is less than the other vector. */
    bool operator<(const vec2& o) const noexcept {
        if (x() == o.x())
            return y() < o.y();
        return x() < o.x();
    }
    /** Compare against another vector.
    @param  o   the other vector.
    @return     true if this equals the other vector, false otherwise. */
    bool operator==(const vec2& o) const noexcept {
        return x() == o.x() && y() == o.y();
    }
    /** Compare against another vector.
    @param  o   the other vector.
    @return     true if this doesn't equal the other vector, false otherwise. */
    bool operator!=(const vec2& o) const noexcept { return !(*this == o); }
    /** Index operator.
    @param  i   the index.
    @return     reference to the data found at index; */
    float& operator[](const size_t& i) noexcept { return m_data[i]; }
    /** Const Index operator.
    @param  i   the index.
    @return     reference to the data found at index; */
    const float& operator[](const size_t& i) const noexcept {
        return m_data[i];
    }

    // Methods
    /** Get the X component of this vector.
    @return     reference to the X component. */
    float& x() noexcept { return m_data[0]; }
    /** Get the const X component of this vector.
    @return     const reference to the X component. */
    const float& x() const noexcept { return m_data[0]; }
    /** Get the Y component of this vector.
    @return     reference to the Y component. */
    float& y() noexcept { return m_data[1]; }
    /** Get the const Y component of this vector.
    @return     const reference to the Y component. */
    const float& y() const noexcept { return m_data[1]; }
    /** Get a pointer to the underlying data container.
    @return     pointer to the data array. */
    float* data() noexcept { return &m_data[0]; }
    /** Get a const pointer to the underlying data container.
    @return     pointer to the data array. */
    const float* data() const noexcept { return &m_data[0]; }
    /** Normalize this vector.
    @return     normalized version of this vector. */
    vec2 normalize() const noexcept { return normalize(*this); }
    /** Normalize the supplied vector.
    @param  v   the vector to normalize.
    @return     normalize version of the supplied vector. */
    static vec2 normalize(const vec2& v) noexcept {
        const auto length_of_v = sqrtf((v.x() * v.x()) + (v.y() * v.y()));
        return vec2{ v.x() / length_of_v, v.y() / length_of_v };
    }
    /** Calculate the dot product of this vector.
    @param  b   the other vector to dot against.
    @return     dot product of this and the supplied vector. */
    float dot(const vec2& b) const noexcept { return dot(*this, b); }
    /** Calculate the dot product the supplied vectors.
    @param  a   the first vector to dot against.
    @param  b   the second vector to dot against.
    @return     dot product of a and b. */
    static float dot(const vec2& a, const vec2& b) noexcept {
        return (a.x() * b.x()) + (a.y() * b.y());
    }

    private:
    float m_data[2] = { 0.0f, 0.0f };
};

/** A vector of 3 floats. */
class vec3 {
    public:
    // (De)Constructors
    /** Default destruct this vector. */
    ~vec3() = default;
    /** Default construct this vector. */
    vec3() = default;
    /** Construct a vector using 1 specific value. */
    explicit vec3(const float& value) noexcept
        : m_data{ value, value, value } {}
    /** Construct a vector using 3 specific attributes.
    @param  _x  the x value to use.
    @param  _y  the y value to use.
    @param  _z  the z value to use. */
    vec3(const float& _x, const float& _y, const float& _z) noexcept
        : m_data{ _x, _y, _z } {}
    /** Default copy constructor. */
    vec3(const vec3& o) = default;
    /** Default move constructor. */
    vec3(vec3&& o) noexcept = default;

    // Operators
    /** Default copy-assignment operator. */
    vec3& operator=(const vec3& p) = default;
    /** Default move-assignment operator. */
    vec3& operator=(vec3&& p) noexcept = default;
    /** Add another vector to this one.
    @param  o   the other vector.
    @return     this vector plus the other vector. */
    vec3 operator+(const vec3& o) const noexcept {
        return vec3{ x() + o.x(), y() + o.y(), z() + o.z() };
    }
    /** Subtract another vector from this one.
    @param  o   the other vector.
    @return     this vector minus the other vector. */
    vec3 operator-(const vec3& o) const noexcept {
        return vec3{ x() - o.x(), y() - o.y(), z() - o.z() };
    }
    /** Multiply by another vector.
    @param  o   the other vector.
    @return     this vector multiplied by the other vector. */
    vec3 operator*(const vec3& o) const noexcept {
        return vec3{ x() * o.x(), y() * o.y(), z() * o.z() };
    }
    /** Divide by another vector.
    @param  o   the other vector.
    @return     this vector divided by the other vector. */
    vec3 operator/(const vec3& o) const noexcept {
        return vec3{ x() / o.x(), y() / o.y(), z() / o.z() };
    }
    /** Negative Operator
    @return     negative version of this vector. */
    vec3 operator-() const noexcept { return vec3{ -x(), -y(), -z() }; }
    /** Compare this vector against another for sorting purposes.
    @param  o   the other vector.
    @return     true if this vector is less than the other vector. */
    bool operator<(const vec3& o) const noexcept {
        if (z() == o.z()) {
            if (x() == o.x())
                return y() < o.y();
            return x() < o.x();
        }
        return z() < o.z();
    };
    /** Compare against another vector.
    @param  o   the other vector.
    @return     true if this equals the other vector, false otherwise. */
    bool operator==(const vec3& o) const noexcept {
        return x() == o.x() && y() == o.y() && z() == o.z();
    }
    /** Compare against another vector.
    @param  o   the other vector.
    @return     true if this doesn't equal the other vector, false otherwise. */
    bool operator!=(const vec3& o) const noexcept { return !(*this == o); }
    /** Index operator.
    @param  i   the index.
    @return     reference to the data found at index; */
    float& operator[](const size_t& i) noexcept { return m_data[i]; }
    /** Const Index operator.
    @param  i   the index.
    @return     reference to the data found at index; */
    const float& operator[](const size_t& i) const noexcept {
        return m_data[i];
    }

    // Methods
    /** Get the X component of this vector.
    @return     reference to the X component. */
    float& x() noexcept { return m_data[0]; }
    /** Get the const X component of this vector.
    @return     const reference to the X component. */
    const float& x() const noexcept { return m_data[0]; }
    /** Get the Y component of this vector.
    @return     reference to the Y component. */
    float& y() noexcept { return m_data[1]; }
    /** Get the const Y component of this vector.
    @return     const reference to the Y component. */
    const float& y() const noexcept { return m_data[1]; }
    /** Get the Z component of this vector.
    @return     reference to the Z component. */
    float& z() noexcept { return m_data[2]; }
    /** Get the const Z component of this vector.
    @return     const reference to the Z component. */
    const float& z() const noexcept { return m_data[2]; }
    /** Get a pointer to the underlying data container.
    @return     pointer to the data array. */
    float* data() noexcept { return &m_data[0]; }
    /** Get a const pointer to the underlying data container.
    @return     pointer to the data array. */
    const float* data() const noexcept { return &m_data[0]; }
    /** Normalize this vector.
    @return     normalized version of this vector. */
    vec3 normalize() const noexcept { return normalize(*this); }
    /** Normalize the supplied vector.
    @param  v   the vector to normalize.
    @return     normalize version of the supplied vector. */
    static vec3 normalize(const vec3& v) noexcept {
        const auto length_of_v =
            sqrtf((v.x() * v.x()) + (v.y() * v.y()) + (v.z() * v.z()));
        return vec3{ v.x() / length_of_v, v.y() / length_of_v,
                     v.z() / length_of_v };
    }
    /** Calculate the cross product of this vector.
    @param  b   the other vector to cross against.
    @return     cross product of this and the supplied vector. */
    vec3 cross(const vec3& b) const noexcept { return cross(*this, b); }
    /** Calculate the cross product the supplied vectors.
    @param  a   the first vector to cross against.
    @param  b   the second vector to cross against.
    @return     cross product of a and b. */
    static vec3 cross(const vec3& a, const vec3& b) noexcept {
        return vec3{ a.y() * b.z() - a.z() * b.y(),
                     a.z() * b.x() - a.x() * b.z(),
                     a.x() * b.y() - a.y() * b.x() };
    }
    /** Calculate the dot product of this vector.
    @param  b   the other vector to dot against.
    @return     dot product of this and the supplied vector. */
    float dot(const vec3& b) const noexcept { return dot(*this, b); }
    /** Calculate the dot product the supplied vectors.
    @param  a   the first vector to dot against.
    @param  b   the second vector to dot against.
    @return     dot product of a and b. */
    static float dot(const vec3& a, const vec3& b) noexcept {
        return (a.x() * b.x()) + (a.y() * b.y()) + (a.z() * b.z());
    }

    private:
    float m_data[3] = { 0.0f, 0.0f, 0.0f };
};

/** A vector of 4 floats. */
class vec4 {
    public:
    // Public (De)Constructors
    /** Default destruct this vector. */
    ~vec4() = default;
    /** Default construct this vector. */
    vec4() = default;
    /** Construct a vector using 1 specific value. */
    explicit vec4(const float& value) noexcept
        : m_data{ value, value, value, value } {}
    /** Construct a vector using 3 specific attributes.
    @param  _x  the x value to use.
    @param  _y  the y value to use.
    @param  _z  the z value to use.
    @param  _w  the z value to use. */
    vec4(
        const float& _x, const float& _y, const float& _z,
        const float& _w) noexcept
        : m_data{ _x, _y, _z, _w } {}
    /** Default copy constructor. */
    vec4(const vec4& o) = default;
    /** Default move constructor. */
    vec4(vec4&& o) noexcept = default;

    // Public Operators
    /** Default copy-assignment operator. */
    vec4& operator=(const vec4& p) = default;
    /** Default move-assignment operator. */
    vec4& operator=(vec4&& p) noexcept = default;
    /** Add another vector to this one.
    @param  o   the other vector.
    @return     this vector plus the other vector. */
    vec4 operator+(const vec4& o) const noexcept {
        return vec4{ x() + o.x(), y() + o.y(), z() + o.z(), w() + o.w() };
    }
    /** Subtract another vector from this one.
    @param  o   the other vector.
    @return     this vector minus the other vector. */
    vec4 operator-(const vec4& o) const noexcept {
        return vec4{ x() - o.x(), y() - o.y(), z() - o.z(), w() - o.w() };
    }
    /** Multiply by another vector.
    @param  o   the other vector.
    @return     this vector multiplied by the other vector. */
    vec4 operator*(const vec4& o) const noexcept {
        return vec4{ x() * o.x(), y() * o.y(), z() * o.z(), w() * o.w() };
    }
    /** Divide by another vector.
    @param  o   the other vector.
    @return     this vector divided by the other vector. */
    vec4 operator/(const vec4& o) const noexcept {
        return vec4{ x() / o.x(), y() / o.y(), z() / o.z(), w() / o.w() };
    }
    /** Negative Operator
    @return     negative version of this vector. */
    vec4 operator-() const noexcept { return vec4{ -x(), -y(), -z(), -w() }; }
    /** Compare against another vector.
    @param  o   the other vector.
    @return     true if this equals the other vector, false otherwise. */
    bool operator==(const vec4& o) const noexcept {
        return x() == o.x() && y() == o.y() && z() == o.z() && w() == o.w();
    }
    /** Compare against another vector.
    @param  o   the other vector.
    @return     true if this doesn't equal the other vector, false otherwise. */
    bool operator!=(const vec4& o) const noexcept { return !(*this == o); }
    /** Index operator.
    @param  i   the index.
    @return     reference to the data found at index; */
    float& operator[](const size_t& i) noexcept { return m_data[i]; }
    /** Const Index operator.
    @param  i   the index.
    @return     reference to the data found at index; */
    const float& operator[](const size_t& i) const noexcept {
        return m_data[i];
    }

    // Public Methods
    /** Get the X component of this vector.
    @return     reference to the X component. */
    float& x() noexcept { return m_data[0]; }
    /** Get the const X component of this vector.
    @return     const reference to the X component. */
    const float& x() const noexcept { return m_data[0]; }
    /** Get the Y component of this vector.
    @return     reference to the Y component. */
    float& y() noexcept { return m_data[1]; }
    /** Get the const Y component of this vector.
    @return     const reference to the Y component. */
    const float& y() const noexcept { return m_data[1]; }
    /** Get the Z component of this vector.
    @return     reference to the Z component. */
    float& z() noexcept { return m_data[2]; }
    /** Get the const Z component of this vector.
    @return     const reference to the Z component. */
    const float& z() const noexcept { return m_data[2]; }
    /** Get the W component of this vector.
    @return     reference to the W component. */
    float& w() noexcept { return m_data[3]; }
    /** Get the const W component of this vector.
    @return     const reference to the W component. */
    const float& w() const noexcept { return m_data[3]; }
    /** Get a pointer to the underlying data container.
    @return     pointer to the data array. */
    float* data() noexcept { return &m_data[0]; }
    /** Get a const pointer to the underlying data container.
    @return     pointer to the data array. */
    const float* data() const noexcept { return &m_data[0]; }
    /** Normalize this vector.
    @return     normalized version of this vector. */
    vec4 normalize() const noexcept { return normalize(*this); }
    /** Normalize the supplied vector.
    @param  v   the vector to normalize.
    @return     normalize version of the supplied vector. */
    static vec4 normalize(const vec4& v) noexcept {
        const auto length_of_v = sqrtf(
            (v.x() * v.x()) + (v.y() * v.y()) + (v.z() * v.z()) +
            (v.w() * v.w()));
        return vec4{ v.x() / length_of_v, v.y() / length_of_v,
                     v.z() / length_of_v, v.w() / length_of_v };
    }

    private:
    float m_data[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
};

#endif // VEC_HPP