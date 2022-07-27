#include <iostream>
#include "StudentBinTree.h"
#include <cmath>
#include <stdexcept>

const float PI =  acosf(-1);

using namespace std;

struct FloatXY
{
	float x;
	float y;
};


class Point
{
	float x;
	float y;

public:
	static const Point ORIGIN;
	Point(float x = 0, float y = 0) : x(x) , y(y) {}
	Point(const Point& p) : Point(p.x, p.y) {}
	float distanceTo(const Point& p) {
		float dx = x - p.x;
		float dy = y - p.y;
		return static_cast<float>(sqrt(pow(dx, 2) + pow(dy, 2)));
	}
	FloatXY move(float dx, float dy) {
		x += dx;
		y += dy;
		return { dx, dy };
	}

	FloatXY displacementFrom(const Point& p) const{
		return { x - p.x, y - p.y };
	}

};

const Point Point::ORIGIN(0, 0);


class SegmentoReta
{
	Point start;
	Point end;

public:
	SegmentoReta(const Point& start, const Point& end) : start(start), end(end) {}
	void move(float dx1, float dy1, float dx2, float dy2) {
			start.move(dx1, dy1);
			end.move(dx2, dy2);
	}
	float distance(SegmentoReta& seg) {			// só para retas paralelas
		FloatXY a = seg.start.displacementFrom({ 0, 0 });
		FloatXY b = seg.end.displacementFrom({ 0, 0 });
		FloatXY c = start.displacementFrom({ 0, 0 });
		FloatXY d = end.displacementFrom({ 0, 0 });
		float slope_1 = ((b.y - a.y) / (b.x - a.x));
		float slope_2 = ((d.y - c.y) / (d.x - c.x));
		if (slope_1 != slope_2)
			throw runtime_error("Segementos de Reta não são paralelos ... ");
		return a.y - c.y;
	}
	bool intersects(SegmentoReta& seg) {
		FloatXY a = seg.start.displacementFrom({0, 0});
		FloatXY b = seg.end.displacementFrom({ 0, 0 });
		FloatXY c = start.displacementFrom({ 0, 0 });
		FloatXY d = end.displacementFrom({ 0, 0 });
		float det = ((b.x - a.x) * (d.y - c.y)) - ((b.y - a.y) * (d.x - c.x));
		if (det == 0)
			return false;
		return true;
	}
	
};



class TrianguloEquilatero
{
	Point p1;
	Point p2;
	Point p3;
	float _size;

public:
	TrianguloEquilatero(const Point& p1, const Point& p2, const Point& p3) {
		FloatXY a = p1.displacementFrom({ 0, 0 });
		FloatXY b = p2.displacementFrom({ 0, 0 });
		FloatXY c = p3.displacementFrom({ 0, 0 });

		if (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)) !=
			sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2)) !=
			sqrt(pow(c.x - a.x, 2) + pow(c.y - a.y, 2))
			)
			throw invalid_argument("nao é equilátero ... ");
		this->p1 = p1;
		this->p2 = p2;
		this->p3 = p3;
		this->_size = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	}
	TrianguloEquilatero(const Point& centre, float size) {
		// p1 e p2 base
		// p3 em cima
		FloatXY a = centre.displacementFrom({ 0, 0 });
		float alto = (powf(3, 1 / 3) / 3) * size;
		float baixo = (powf(3, 1 / 3) / 6) * size;
		p3 = {a.x, a.y + alto};
		FloatXY aux = { a.x, a.y - baixo };
		p1 = {aux.x - size/2, aux.y};
		p2 = {aux.y + size/2, aux.y};
		_size = size;
	}
	/*TrianguloEquilatero(const Point& p1, const Point& p2) {
		FloatXY a = p1.displacementFrom({ 0, 0 });
		FloatXY b = p2.displacementFrom({ 0, 0 });

		FloatXY medio = {(a.x - b.x)/2, (a.y - b.y) / 2 };
		float declive = ((b.y - a.y) / (b.x - a.x));
		float distance = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	}*/
	float area() const { 
		float mul = PI / 180;
		float height = ((sinf(60 * mul) * _size));
		return ((height * _size) / 2);
	}
	float perimeter() const {
		return 3 * _size;
	}
	void zoom(float zoom) {
		float mul = PI / 180;
		float h = ((sinf(45 * mul) * zoom));
		p1.move(h, h);
		p2.move(h, h);
		p3.move(h, h);
	}
	float size() const {
		return _size;
	}
};









int main()
{
	StudentBinTree tree;

	try
	{
		tree.add({ 5, "aaa" });
		tree.add({ 3, "ddd" });
		tree.add({ 1, "ggg" });
		tree.add({ 9, "eee" });
		tree.add({ 7, "bbb" });
		tree.add({ 6, "ccc" });
		tree.add({ 10, "hhh" });
		tree.add({ 7, "bbb" });
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}

	cout << endl << endl;

	if (!tree.contains("www"))
		cout << "Not contains" << endl;
	else
		cout << "Contains ... " << endl;

	if (!tree.contains("ggg"))
		cout << "Not contains" << endl;
	else
		cout << "Contains ... " << endl;



	vector<Student> elements = tree.inOrder();

	for (vector<Student>::iterator it = elements.begin(); it != elements.end(); it++)
		cout << it->number << " " << it->name << endl;

	//Point a(1, 1);
	//Point b(3, 3);
	//Point c(4, 4);
	//Point d(6, 6);

	//SegmentoReta seg_a(a, b);
	//SegmentoReta seg_b(c, d);
	//
	//try
	//{
	//	//cout << seg_a.distance(seg_b);
	//	if (seg_a.intersects(seg_b))
	//		cout << "intersects ... " << endl;
	//	else
	//		cout << "not intersects ... " << endl;
	//}

	//catch (exception& ex)
	//{
	//	cout << ex.what() << endl;
	//}

	return 0;
}