#include<iostream>
using namespace std;

struct Point {
   double x, y;
};

struct line {
   Point p1, p2;
};

bool onLine(line l1, Point p) {   //check whether p is on the line or not
   if(p.x <= max(l1.p1.x, l1.p2.x) && p.x <= min(l1.p1.x, l1.p2.x) &&
      (p.y <= max(l1.p1.y, l1.p2.y) && p.y <= min(l1.p1.y, l1.p2.y)))
      return true;
   
   return false;
}

int direction(Point a, Point b, Point c) {
   int val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
   if (val == 0)
      return 0;     //colinear
   else if(val < 0)
      return 2;    //anti-clockwise direction
      return 1;    //clockwise direction
}

bool isIntersect(line l1, line l2) {
   //four direction for two lines and points of other line
   int dir1 = direction(l1.p1, l1.p2, l2.p1);
   int dir2 = direction(l1.p1, l1.p2, l2.p2);
   int dir3 = direction(l2.p1, l2.p2, l1.p1);
   int dir4 = direction(l2.p1, l2.p2, l1.p2);
   
   if(dir1 != dir2 && dir3 != dir4)
      return true; //they are intersecting

   if(dir1==0 && onLine(l1, l2.p1)) //when p2 of line2 are on the line1
      return true;

   if(dir2==0 && onLine(l1, l2.p2)) //when p1 of line2 are on the line1
      return true;

   if(dir3==0 && onLine(l2, l1.p1)) //when p2 of line1 are on the line2
      return true;

   if(dir4==0 && onLine(l2, l1.p2)) //when p1 of line1 are on the line2
      return true;
         
   return false;
}

int main() {
   line l1 = {{8,7}, {21, 7}};
   line l2 = {{3.02,3.18}, {16.78, 14.26}};
   
   if(isIntersect(l1, l2))
      cout << "Lines are intersecting";
   else
      cout << "Lines are not intersecting";
}