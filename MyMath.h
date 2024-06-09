#pragma once

#include <vector>
#include <iostream>
#include <string>

bool Contains(const std::vector<double>& vector, double element)
{
    bool ret = false;

    for (size_t i = 0; i < vector.size(); i++)
    {
        if (vector[i] == element)
        {
            ret = true;
            break;
        }
    }

    return ret;
}

template<typename T>
T FindMajority(const std::vector<T>& vector)
{
    struct ElementAndCount
    {
        T Element = 0;
        size_t Count = 0;
    };

    std::vector<ElementAndCount> arr;
    std::vector<T> arr1;

    for (size_t i = 0; i < vector.size(); i++)
    {
        if (!Contains(arr1, vector[i]))
        {
            arr1.push_back(vector[i]);
            arr.push_back(ElementAndCount{vector[i], 1});
        }
        else if (Contains(arr1, vector[i]))
        {
            for (size_t j = 0; j < arr.size(); j++)
            {
                if (arr[j].Element == vector[i])
                    arr[j].Count++;
            }
        }
    }

    size_t greatestCount = 0;
    size_t indexOfGreatestCount = 0;

    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i].Count > greatestCount)
        {
            greatestCount = arr[i].Count;
            indexOfGreatestCount = i;
        }
    }

    return arr[indexOfGreatestCount].Element;
}

namespace glm {

    class vec3
    {
    public:
        vec3() = default;
        vec3(float factor) :
            x(factor), y(factor), z(factor) {}
        vec3(float x, float y, float z) :
            x(x), y(y), z(z) {}
    public:
        float x = 0.0f, y = 0.0f, z = 0.0f;
    };

}

struct Triangle
{
    glm::vec3 P1 = glm::vec3(0.0f), P2 = glm::vec3(0.0f), P3 = glm::vec3(0.0f);
};

void DrawTriangle(const Triangle& triangle)
{
    std::cout << "{ " << triangle.P1.x << ", " << triangle.P1.y << ", " << triangle.P1.z << " }\n";
    std::cout << "{ " << triangle.P2.x << ", " << triangle.P2.y << ", " << triangle.P2.z << " }\n";
    std::cout << "{ " << triangle.P3.x << ", " << triangle.P3.y << ", " << triangle.P3.z << " }\n";
}

template<typename T>
T& Index(T* array, uint64_t index)
{
    return *((T*)(((uint64_t)(array)) + (index * sizeof(T))));
}

void DrawTriangles(std::vector<glm::vec3> verticies, std::vector<uint32_t> indicies)
{
    std::vector<Triangle> triangles;
    {
        uint32_t triCount = indicies.size() / 3;
        for (uint32_t i = 0; i < triCount; i++)
            triangles.push_back(Triangle{});
    }

    for (uint32_t i = 0; i < indicies.size(); i++)
    {
        glm::vec3* arr = ((glm::vec3*)(&(triangles[0])));

        Index(arr, i) = Index((glm::vec3*)(&verticies[0]), Index((uint32_t*)(&indicies[0]), i));
    }

    for (uint32_t i = 0; i < triangles.size(); i++)
        DrawTriangle(Index((&triangles[0]), i));
}

typedef double(*FunctionOfX)(double x);

FunctionOfX Derive(FunctionOfX f)
{
    static FunctionOfX staticF = f;
    staticF = f;

    FunctionOfX derivative = FunctionOfX([](double x){
        const double h = 1e-12;

        return (staticF(x + h) - staticF(x)) / h;
    });

    return derivative;
}

double Sigma(double start, double end, double step, FunctionOfX f, bool getFinalValue = false)
{
    if (getFinalValue)
        return f(end - step);

    double ret = 0;
    for (double i = start; i < end; i += step)
        ret += f(i);
    
    return ret;
}

double Factorial(double x)
{
    double n = 1;
    for (int64_t i = x; i > 0; i--)
        n *= i;

    return n;
}

double IntegerExponentPower(double x, double exponent)
{
    double n = 1;
    for (int64_t i = 0; i < exponent; i++)
        n *= x;

    return n;
}

double Cos(double x)
{
    static constexpr double Pi = 3.141592653589793238462643383279502884;

    while (x > 3 * Pi / 2)
        x -= 3 * Pi / 2;
    while (x < -3 * Pi / 2)
        x += 3 * Pi / 2;
    
    double ret = 1 - (IntegerExponentPower(x, 2) / Factorial(2)) + (IntegerExponentPower(x, 4) / Factorial(4)) - (IntegerExponentPower(x, 6) / Factorial(6)) + (IntegerExponentPower(x, 8) / Factorial(8)) - (IntegerExponentPower(x, 10) / Factorial(10)) + (IntegerExponentPower(x, 12) / Factorial(12));

    return ret;
}

double Sin(double x)
{
    static constexpr double Pi = 3.141592653589793238462643383279502884;

    return Cos(x - Pi / 2);
}

double Tan(double x)
{
    return Sin(x) / Cos(x);
}

double Exp(double x)
{
    double ret = 1;
    for (uint64_t i = 1; i < 12; i++)
        ret += IntegerExponentPower(x, i) / Factorial(i);
    
    return ret;
}

char ToUpper(char x)
{
    switch (x)
    {
    case 'q':
        return 'Q';
    case 'w':
        return 'W';
    case 'e':
        return 'E';
    case 'r':
        return 'R';
    case 't':
        return 'T';
    case 'y':
        return 'Y';
    case 'u':
        return 'U';
    case 'i':
        return 'I';
    case 'o':
        return 'O';
    case 'p':
        return 'P';
    case 'a':
        return 'A';
    case 's':
        return 'S';
    case 'd':
        return 'D';
    case 'f':
        return 'F';
    case 'g':
        return 'G';
    case 'h':
        return 'H';
    case 'j':
        return 'J';
    case 'k':
        return 'K';
    case 'l':
        return 'L';
    case 'z':
        return 'Z';
    case 'x':
        return 'X';
    case 'c':
        return 'C';
    case 'v':
        return 'V';
    case 'b':
        return 'B';
    case 'n':
        return 'N';
    case 'm':
        return 'M';
    default:
        return x;
    }

    return x;
}

std::string ToUpper(std::string string)
{
    for (uint32_t i = 0; i < string.size(); i++)
        string[i] = ToUpper(string[i]);

    return string;
}

bool Contains(std::string string, std::string value, bool caseSensitive = true)
{
    std::string temp;
    for (uint32_t i = 0; i < string.size(); i++)
    {
        if (caseSensitive)
        {
            temp = "";
            if (string[i] == value[0])
            {
                uint32_t j = i, k = 0;
                while (string[j] == value[k])
                {
                    temp += value[k];
                    j++;
                    k++;

                    if (temp == value)
                        return true;
                }
            }
        }
        else
        {
            temp = "";

            string = ToUpper(string);
            value = ToUpper(value);

            if (string[i] == value[0])
            {
                uint32_t j = i, k = 0;
                while (string[j] == value[k])
                {
                    temp += value[k];
                    j++;
                    k++;

                    if (temp == value)
                        return true;
                }
            }
        }
    }

    return false;
}

double Sqrt(double x)
{
    if (x == 0)
        return x;
    else if (x < 0)
        return -1;

    double a = x;

    x = 0.5 * (x + a / x);
    x = 0.5 * (x + a / x);
    x = 0.5 * (x + a / x);

    return x;
}

double NthRoot(double x, double n)
{
    static double staticN = n;
    staticN = n;

    double a = x;

    FunctionOfX Derivative = ([](double x){
        return staticN * IntegerExponentPower(x, staticN - 1);
    });

    for (int64_t i = 0; i < (n * n) * (x * x * x * x); i++)
        x = x - (IntegerExponentPower(x, n) - a) / (Derivative(x));

    return x;
}

uint64_t GetSizeOfStringAfterDecimalPoint(const std::string& string, double integerIncrement = 10)
{
    uint64_t size = 0;
    bool addToSize = false;
    for (uint64_t i = 0; i < string.size(); i++)
    {
        if (string[i] == '.')
            addToSize = true;
        
        if (addToSize)
            size *= integerIncrement;
    }

    return size + 10;
}

double Power(double x, double n)
{
    return NthRoot(x, 1 / n);
}

double Ln(double x)
{
    static double a = x;
    a = x;

    FunctionOfX f = FunctionOfX([](double x){
        return Exp(x) - a;
    });

    FunctionOfX Derivative = Derive(f);

    for (int64_t i = 0; i < a * a; i++)
        x = x - (f(x) / Derivative(x));

    return x;
}

double Log(double x, double n)
{
    return Ln(x) / Ln(n);
}