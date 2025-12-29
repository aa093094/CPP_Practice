#include <iostream>
#include <cmath>

class Point {
    int x, y;

    public:
        Point(int pos_x, int pos_y) { x = pos_x; y = pos_y; };

        int GetX() const {
            return x;
        }

        int GetY() const {
            return y;
        }
};

class Geometry {
    int num_points;
    Point* point_array[100];

    public:
        Geometry() {
            num_points = 0;
        }

        void AddPoint(const Point &point) {
            point_array[num_points++] = new Point(point.GetX(), point.GetY());
        }

        void PrintDistance();

        void PrintNumMeets();
};

void Geometry::PrintDistance() {
    for (int i = 0; i < num_points; i++) {
        for (int j = i+1; j < num_points; j++) {
            int x1 = point_array[i]->GetX();
            int y1 = point_array[i]->GetY();
            int x2 = point_array[j]->GetX();
            int y2 = point_array[j]->GetY();
    
            double distance = std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
            std::cout << i << "point to " << j << "point distance : " << distance << std::endl;
        }
    }
}

void Geometry::PrintNumMeets() {
    if (num_points >= 3) {
        int x1 = point_array[0]->GetX();
        int y1 = point_array[0]->GetY();
        int x2 = point_array[1]->GetX();
        int y2 = point_array[1]->GetY();

        int slope1;
        if ((x1 - x2) == 0) {
            slope1 = 1000;
        } else {
            slope1 = (y1 - y2) / (x1 - x2);
        }
        int point_num = 0;

        for (int i = 0; i < num_points; i++) {
            for (int j = i+1; j < num_points; j++) {
                if (i == 0 && j == 1) continue;
                x1 = point_array[i]->GetX();
                y1 = point_array[i]->GetY();
                x2 = point_array[j]->GetX();
                y2 = point_array[j]->GetY();

                int slope2;
                if ((x1 - x2) == 0) {
                    slope2 = 1000;
                } else {
                    slope2 = (y1 - y2) / (x1 - x2);
                }
                if (slope1 != slope2) point_num++;
            }
        }

        std::cout << "point_num = " << point_num << std::endl;    
    } else {
        std::cout << "point_num = 0" << std::endl;
    }
}

int main() {
    Geometry geometry;

    geometry.AddPoint(Point(0, 0));
    geometry.AddPoint(Point(0, 1));
    geometry.AddPoint(Point(1, 0));
    geometry.AddPoint(Point(1, 1));
    geometry.AddPoint(Point(0, 2));
    geometry.AddPoint(Point(1, 2));

    geometry.PrintDistance();
    geometry.PrintNumMeets();

    return 0;
}
