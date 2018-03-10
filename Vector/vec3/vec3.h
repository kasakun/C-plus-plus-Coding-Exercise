//
// Author： Zeyu Chen
//

#pragma once
#include <iostream>


template<typename T>
class Vec3 {
public:
//fill in here
    // Constructor
    Vec3();
    Vec3(T ix);
    Vec3(T ix, T iy, T iz);
    Vec3(const Vec3& vec3);

    // Destructor
    ~Vec3();

    // Set
    void setX(T ix);
    void setY(T iy);
    void setZ(T iz);

    // Get
    T getX() const;
    T getY() const;
    T getZ() const;

    // Operator
    Vec3 operator+ (const Vec3& vec3);
    Vec3& operator+= (const Vec3& vec3);
    Vec3 operator- (const Vec3& vec3);
    Vec3& operator-= (const Vec3& vec3);
    Vec3& operator= (const Vec3& vec3);
    Vec3& operator++ ();
    Vec3 operator++ (int);
    Vec3& operator-- ();
    Vec3 operator-- (int);
    Vec3 operator* (T f);
    Vec3& operator*= (T f);
    Vec3 operator/ (T f);
    Vec3& operator/= (T f);
    bool operator== (const Vec3& vec3);
    bool operator!= (const Vec3& vec3);

    // dot
    T dot(const Vec3& vec3);


private:
    T x;
    T y;
    T z;
};
template<typename T>
Vec3<T>::Vec3(){}
template<typename T>
Vec3<T>::Vec3(T ix) : x(ix), y(ix), z(ix) {}
template<typename T>
Vec3<T>::Vec3(T ix, T iy, T iz) : x(ix), y(iy), z(iz) {}
template<typename T>
Vec3<T>::Vec3(const Vec3& vec3) : x(vec3.x), y(vec3.y), z(vec3.z) {}

template<typename T>
Vec3<T>::~Vec3() {}
// Set
template<typename T>
void Vec3<T>::setX(T ix) {x = ix;}
template<typename T>
void Vec3<T>::setY(T iy) {y = iy;}
template<typename T>
void Vec3<T>::setZ(T iz) {z = iz;}

// Get
template<typename T>
T Vec3<T>::getX() const {return x;}
template<typename T>
T Vec3<T>::getY() const {return y;}
template<typename T>
T Vec3<T>::getZ() const {return z;}

// operator
// +
template<typename T>
Vec3<T> Vec3<T>::operator+ (const Vec3& vec3) {
    return Vec3(x + vec3.x, y + vec3.y, z + vec3.z);
}
// +=
template<typename T>
Vec3<T>& Vec3<T>::operator+= (const Vec3& vec3) {
    x += vec3.x; y += vec3.y; z += vec3.z;
    return *this;
}
//-
template<typename T>
Vec3<T> Vec3<T>::operator- (const Vec3& vec3) {
    return Vec3(x - vec3.x, y - vec3.y, z - vec3.z);
}
// -=
template<typename T>
Vec3<T>& Vec3<T>::operator-= (const Vec3& vec3) {
    x -= vec3.x; y -= vec3.y; z -= vec3.z;
    return *this;
}
// =
template<typename T>
Vec3<T>& Vec3<T>::operator= (const Vec3& vec3) {
    x = vec3.x; y = vec3.y; z = vec3.z;
    return *this;
}
// ++vec
template<typename T>
Vec3<T>& Vec3<T>::operator++ () {
    T temp;
    temp = z; z = y; y = x; x = temp;
    return *this;
}
// vec++
template<typename T>
Vec3<T> Vec3<T>::operator++ (int) {
    Vec3<T> tmp = *this;
    T temp;

    temp = z; z = y; y = x; x = temp;
    return tmp;
}

// --vec
template<typename T>
Vec3<T>& Vec3<T>::operator-- () {
    T temp;
    temp = x; x = y; y = z; z = temp;
    return *this;
}
// vec--
template<typename T>
Vec3<T> Vec3<T>::operator-- (int) {
    Vec3<T> tmp = *this;
    T temp;

    temp = x; x = y; y = z; z = temp;
    return tmp;
}
template<typename T>
Vec3<T> Vec3<T>::operator* (T f) {
    return Vec3(x*f, y*f, z*f);
}
template<typename T>
Vec3<T>& Vec3<T>::operator*= (T f) {
    x *= f;y *= f;z *= f;
    return *this;
}
template<typename T>
Vec3<T> Vec3<T>::operator/ (T f) {
    return Vec3(x/f, y/f, z/f);
}
template<typename T>
Vec3<T>& Vec3<T>::operator/= (T f) {
    x /= f;y /= f;z /= f;
    return *this;
}
template<typename T>
bool Vec3<T>::operator== (const Vec3<T>& vec3){
    return (x == vec3.x && y == vec3.y && z == vec3.z);
}
template<typename T>
bool Vec3<T>::operator!= (const Vec3& vec3){
    return !(x == vec3.x && y == vec3.y && z == vec3.z);
}
template<typename T>
T Vec3<T>::dot(const Vec3<T>& vec3) {
    return (x*vec3.x + y*vec3.y + z*vec3.z);
}


//
//for printing
template<typename T>
std::ostream& operator<<(std::ostream& stream, const Vec3<T>& vec) {
    stream << "X=" << vec.getX() << ", Y=" << vec.getY() << ", Z=" << vec.getZ();
    return stream;
}