#include <iostream>
#include <string>

class Figure
{
protected:
    std::string name{ "������" };
    int sides_count{};

public:
    std::string getName() { return name; }
    int getSides_count() { return sides_count; }

};

class Triangle : public Figure
{
public:
    Triangle()
    {
        name = "�����������";
        sides_count = 3;
    }
};

class Quadrangle : public Figure
{
public:
    Quadrangle()
    {
        name = "���������������";
        sides_count = 4;
    }
};

void print(Figure& fig)
{
    std::cout << fig.getName() << ": " << fig.getSides_count() << '\n';
}

int main()
{
    setlocale(LC_ALL, "rus");  //setting the language standard
    Figure f{};
    Triangle t{};
    Quadrangle q{};
    std::cout << "���������� �������: \n";
    print(f);
    print(t);
    print(q);
    return EXIT_SUCCESS;
}