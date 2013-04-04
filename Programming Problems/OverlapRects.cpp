#include <iostream>

/*
	Lower left corner coordinates indicated by x and y
*/
struct Rect {
	double x, y, width, height;
};

bool overlap(Rect r1, Rect r2) {
	return !(r1.x + r1.width < r2.x ||
			 r1.x > r2.x + r2.width ||
			 r1.y + r1.height < r2.y ||
			 r1.y > r2.y + r2.height);
}

Rect *userRect() {
	Rect *rect = new Rect;
	std::cout << "Enter x-coordinate of rectangle: ";
	std::cin >> rect->x;
	std::cout << "Enter y-coordinate of rectangle: ";
	std::cin >> rect->y;
	std::cout << "Enter width of rectangle: ";
	std::cin >> rect->width;
	std::cout << "Enter height of rectangle: ";
	std::cin >> rect->height;
	return rect;
}

Rect *createRect(double x, double y, double width, double height) {
	Rect *rect = new Rect;
	rect->x = x;
	rect->y = y;
	rect->width = width;
	rect->height = height;
	return rect;
}

/*
	Debugging/Testing
*/
int main(int argc, char *argv[]) {
	Rect *r1, *r2;
	std::cout << "Create Rectangle 1" << std::endl;
	r1 = userRect();
	std::cout << "Create Rectangle 2" << std::endl;
	r2 = userRect();
	std::cout << "Overlap: " << overlap(*r1, *r2) << std::endl;
	return 0;
}