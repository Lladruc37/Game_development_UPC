#include <iostream>

template <class T>
class vec3 {
public:
    vec3() : x(0), y(0), z(0) {}
    vec3(T X, T Y, T Z) : x(X), y(Y), z(Z) {}
    vec3(const vec3& a) : x(a.GetX()), y(a.GetY()), z(a.GetZ()) {}
    ~vec3() {}
    T GetX() const { return x; }
    T GetY() const { return y; }
    T GetZ() const { return z; }
    void SetX(const T &a) { x = a; }
    void SetY(const T &a) { y = a; }
    void SetZ(const T &a) { z = a; }
    vec3 operator+(const vec3& a) const { return vec3((x + a.GetX()), (y + a.GetY()), (z + a.GetZ())); }
    vec3 operator-(const vec3& a) const { return vec3((x - a.GetX()), (y - a.GetY()), (z - a.GetZ())); }
    void operator+=(const vec3& a) {
        this->SetX(x + a.GetX());
        this->SetY(y + a.GetY());
        this->SetZ(z + a.GetZ());
    }
    void operator-=(const vec3& a) {
        this->SetX(x - a.GetX());
        this->SetY(y - a.GetY());
        this->SetZ(z - a.GetZ());
    }
    void operator=(const vec3& a) {
        this->SetX(a.GetX());
        this->SetY(a.GetY());
        this->SetZ(a.GetZ());
    }
    bool operator==(const vec3& a) const { return (x == a.GetX() && y == a.GetY() && z == a.GetZ()); }
    vec3 Normalize() {
        T len = (x ^ 2) + (y ^ 2) + (z ^ 2);
        len = sqrt(len);
        this->SetX(x / len);
        this->SetY(y / len);
        this->SetY(z / len);
    }
    void Zero() {
        this->SetX(0);
        this->SetY(0);
        this->SetZ(0);
    }
    bool IsZero() { return (x == 0 && y == 0 && z == 0); }
    T DistanceTo(const vec3& a) {
        T result = this - a;
        return (sqrt((result.x ^ 2) + (result.y ^ 2) + (result.z ^ 2)));
    }
private:
    T x, y, z;
};

int main() {
    vec3<float> a(3.0f, 2.0f, 5.0f);
    std::cout << "a = " << a.GetX() << ", " << a.GetY() << ", " << a.GetZ() << std::endl;
    vec3<float> b(4.0f, 7.0f, 1.0f);
    std::cout << "b = " << b.GetX() << ", " << b.GetY() << ", " << b.GetZ() << std::endl;
    vec3<float> c;
    std::cout << "c initialized to 0 = " << c.GetX() << ", " << c.GetY() << ", " << c.GetZ() << std::endl;
    vec3<float> d(b);
    std::cout << "d initialized to b = " << d.GetX() << ", " << d.GetY() << ", " << d.GetZ() << std::endl;

    vec3<float> result = a + b;
    std::cout << "a + b = " << result.GetX() << ", " << result.GetY() << ", " << result.GetZ() << std::endl;
    result = a - b;
    std::cout << "a - b = " << result.GetX() << ", " << result.GetY() << ", " << result.GetZ() << std::endl;
    d += a;
    std::cout << "d += a = " << d.GetX() << ", " << d.GetY() << ", " << d.GetZ() << std::endl;
    c -= b;
    std::cout << "c -= b =" << c.GetX() << ", " << c.GetY() << ", " << c.GetZ() << std::endl;
    c = a;
    std::cout << "c = a = " << c.GetX() << ", " << c.GetY() << ", " << c.GetZ() << std::endl;
    bool isZero = (c == b);
    std::cout << "isZero c with b = " << isZero << std::endl;

    system("pause");
    return 0;
}