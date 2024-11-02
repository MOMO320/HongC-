#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double PI = 3.14;

class Shape
{
public:
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual ~Shape() {}
};

class Circle : public Shape
{
private:
	double radius;

public:
	Circle(double r) : radius(r) {}

	double area() const override
	{
		return PI * radius * radius;
	}

	double perimeter() const override
	{
		return 2 * PI * radius;
	}
};

class Rectangle : public Shape
{
private:
	double width, height;

public:
	Rectangle(double w, double h) : width(w), height(h) {}

	double area() const override
	{
		return width * height;
	}

	double perimeter() const override
	{
		return 2 * (width + height);
	}
};

class Triangle : public Shape
{
private:
	double a, b, c;

public:
	Triangle(double side1, double side2, double side3)
		: a(side1), b(side2), c(side3)
	{}

	double area() const override
	{
		double s = (a + b + c) / 2;	// 반둘레
		return std::sqrt(s * (s - a) * (s - b) * (s - c));	//헤론의 공식
	}

	double perimeter() const override
	{
		return a + b + c;
	}
};

int mainVirtaulFunctionTest()
{
	//도형 객체를 저장할 벡터
	vector<Shape*> shapes;

	// 다양한 도형 객체 생성
	shapes.push_back(new Circle(5.0));
	shapes.push_back(new Rectangle(4.0, 6.0));
	shapes.push_back(new Triangle(3.0, 4.0, 5.0));

	// 각 도형의 면적과 둘레 출력
	for (const auto& shape : shapes)
		cout << "Area : " << shape->area() << ", Perimeter : " << shape->perimeter() << endl;

	// 메모리 해제
	for (const auto& shape : shapes)
		delete shape;

	return 0;
}

