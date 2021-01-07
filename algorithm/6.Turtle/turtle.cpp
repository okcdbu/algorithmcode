#include <stdio.h>
#pragma warning (disable:4996)

typedef struct Point {
	int x, y;
};
typedef struct Direct {
	Point data;
	Direct* prev;
	Direct* next;
};
int main() {
	FILE* fp1 = fopen("turtle.inp", "rt");
	FILE* fp2 = fopen("turtle.out", "wt");
	int T;
	fscanf(fp1, "%d ", &T);
	Direct Up = { {0,1} };
	Direct Left = { {-1,0} };
	Direct Down = { {0,-1} };
	Direct Right = { {1,0} };
	Up.next = &Left;
	Up.prev = &Right;
	Left.next = &Down;
	Left.prev = &Up;
	Down.next = &Right;
	Down.prev = &Left;
	Right.next = &Up;
	Right.prev = &Down;
	for (int i = 0; i < T; i++) {
		Direct* turtle = &Up;
		Point TurtleP = { 0,0 };
		int xmax=0, xmin=0, ymax=0, ymin=0;
		for (int j = 0; j < 500; j++) {
			char buffer;
			if (fscanf(fp1, "%c", &buffer) == EOF || buffer == '\n') {
				break;
			}
			
			switch (buffer) {
				case 'F':
					TurtleP.x += turtle->data.x;
					TurtleP.y += turtle->data.y;
					break;
				case 'L':
					turtle = turtle->next;
					break;
				case 'B':
					TurtleP.x -= turtle->data.x;
					TurtleP.y -= turtle->data.y;
					break;
				case 'R':
					turtle = turtle->prev;
					break;
			}
			if (TurtleP.x > xmax) {
				xmax = TurtleP.x;
			}
			if (TurtleP.y > ymax) {
				ymax = TurtleP.y;
			}
			if (TurtleP.x < xmin) {
				xmin = TurtleP.x;
			}
			if (TurtleP.y < ymin) {
				ymin = TurtleP.y;
			}
		}
		fprintf(fp2, "%d\n", (xmax - xmin) * (ymax - ymin));
	}
}