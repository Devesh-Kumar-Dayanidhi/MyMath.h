#pragma once

#include <iostream>

namespace Math {

    double Abs(double x)
    {
        if (x < 0)
            return -x;
        
        return x;
    }

    float Absf(float x)
    {
        if (x < 0.0f)
            return -x;
        
        return x;
    }

    class Complex
    {
    public:
        Complex() :
            x(0), y(0) {}
        Complex(double x, double y) :
            x(x), y(y) {}
    public:
        inline Complex operator+(const Complex& other) const noexcept { return Complex(x + other.x, y + other.y); }
        inline Complex operator-(const Complex& other) const noexcept { return Complex(x - other.x, y - other.y); }
        inline Complex operator*(const Complex& other) const noexcept
        {
            double real = x * other.x - y * other.y;
            double imaginary = x * other.y + y * other.x;

            return Complex(real, imaginary);
        }
        inline Complex operator/(const Complex& other) const noexcept 
        {
            double real = (x * other.x + y * other.y) / (other.x * other.x + other.y * other.y);
            double imaginary = (other.x * y - x * other.y) / (other.x * other.x + other.y * other.y);

            return Complex(real, imaginary);
        }
    public:
        friend std::ostream& operator<<(std::ostream& stream, const Complex& obj) noexcept;
    public:
        double x = 0, y = 0;
    };

    std::ostream& operator<<(std::ostream& stream, const Complex& obj) noexcept
    {
        if (obj.y == 0)
        {
            stream << obj.x;
            return stream;
        }

        if (obj.x == 0)
        {
            stream << obj.y << 'i';
            return stream;
        }

        if (obj.y >= 0)
        {
            stream << obj.x << " + " << obj.y << 'i';
            return stream;
        }

        stream << obj.x << " - " << Absf(obj.y) << 'i';
        return stream;
    }

    class Complexf
    {
    public:
        Complexf() :
            x(0.0f), y(0.0f) {}
        Complexf(float x, float y) :
            x(x), y(y) {}
    public:
        inline Complexf operator+(const Complexf& other) const noexcept { return Complexf(x + other.x, y + other.y); }
        inline Complexf operator-(const Complexf& other) const noexcept { return Complexf(x - other.x, y - other.y); }
        inline Complexf operator*(const Complexf& other) const noexcept
        {
            float real = x * other.x - y * other.y;
            float imaginary = x * other.y + y * other.x;

            return Complexf(real, imaginary);
        }
        inline Complexf operator/(const Complexf& other) const noexcept
        {
            float real = (x * other.x + y * other.y) / (other.x * other.x + other.y * other.y);
            float imaginary = (other.x * y - x * other.y) / (other.x * other.x + other.y * other.y);

            return Complexf(real, imaginary);
        }
    public:
        friend std::ostream& operator<<(std::ostream& stream, const Complexf& obj) noexcept;
    public:
        float x = 0.0f, y = 0.0f;
    };

    std::ostream& operator<<(std::ostream& stream, const Complexf& obj) noexcept
    {
        if (obj.y == 0.0f)
        {
            stream << obj.x;
            return stream;
        }

        if (obj.x == 0.0f)
        {
            stream << obj.y << 'i';
            return stream;
        }

        if (obj.y > 0.0f)
        {
            stream << obj.x << " + " << obj.y << 'i';
            return stream;
        }

        stream << obj.x << " - " << Absf(obj.y) << 'i';
        return stream;
    }

}