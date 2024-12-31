#include "./includes/Fixed.hpp"
#include "./includes/Point.hpp"
#include <iostream>

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(void)
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(2, 4);

	// Points inside the triangle
	Point inside1(2, 2);
	Point inside2(1, 1);
	Point inside3(3, 1);

	// Points outside the triangle
	Point outside1(5, 5);
	Point outside2(-1, 2);
	Point outside3(2, -1);

	// Points on the edges/vertices
	Point onEdge1(2, 0);
	Point onEdge2(1, 2);
	Point onVertex(0, 0);

	std::cout << "Inside points:\n";
	std::cout << "inside1: " << bsp(a, b, c, inside1) << std::endl;
	std::cout << "inside2: " << bsp(a, b, c, inside2) << std::endl;
	std::cout << "inside3: " << bsp(a, b, c, inside3) << std::endl;

	std::cout << "\nOutside points:\n";
	std::cout << "outside1: " << bsp(a, b, c, outside1) << std::endl;
	std::cout << "outside2: " << bsp(a, b, c, outside2) << std::endl;
	std::cout << "outside3: " << bsp(a, b, c, outside3) << std::endl;

	std::cout << "\nEdge/Vertex points:\n";
	std::cout << "onEdge1: " << bsp(a, b, c, onEdge1) << std::endl;
	std::cout << "onEdge2: " << bsp(a, b, c, onEdge2) << std::endl;
	std::cout << "onVertex: " << bsp(a, b, c, onVertex) << std::endl;
}