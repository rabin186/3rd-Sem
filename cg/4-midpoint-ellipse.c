#include <graphics.h>
#include <math.h>
#include <stdio.h>
#define COLOR YELLOW

typedef struct vector2D {
  int x;
  int y;
} vector2D;

void plot_ellipse_points(vector2D center, int x, int y) {
  putpixel(center.x + x, center.y + y, COLOR);
  putpixel(center.x - x, center.y + y, COLOR);
  putpixel(center.x + x, center.y - y, COLOR);
  putpixel(center.x - x, center.y - y, COLOR);
}

void mid_point_ellipse(vector2D center, vector2D radius) {
  int x = 0, y = radius.y;

  // Region 1: When dx < dy
  int p10 =
      pow(radius.y, 2) - pow(radius.x, 2) * radius.y + 0.25 * pow(radius.x, 2);
  int dx = 2 * pow(radius.y, 2) * x;
  int dy = 2 * pow(radius.x, 2) * y;

  while (dx < dy) {
    plot_ellipse_points(center, x, y);
    x++;
    dx += 2 * pow(radius.y, 2);
    if (p10 < 0) {
      p10 += dx + pow(radius.y, 2);
    } else {
      y--;
      dy -= 2 * pow(radius.x, 2);
      p10 += dx - dy + pow(radius.y, 2);
    }
  }

  // Region 2: When dx >= dy
  int p20 = pow(radius.y, 2) * pow(x + 0.5, 2) +
            pow(radius.x, 2) * pow(y - 1, 2) -
            pow(radius.x, 2) * pow(radius.y, 2);
  while (y >= 0) {
    plot_ellipse_points(center, x, y);
    y--;
    dy -= 2 * pow(radius.x, 2);
    if (p20 > 0) {
      p20 += pow(radius.x, 2) - dy;
    } else {
      x++;
      dx += 2 * pow(radius.y, 2);
      p20 += dx - dy + pow(radius.x, 2);
    }
  }
}

int main() {
  vector2D c, r;
  int gd = DETECT, gm;

  initgraph(&gd, &gm, (char *)"");
  printf("Enter the center of the ellipse:\n");
  scanf("%d%d", &c.x, &c.y);
  printf("Enter the radius of the ellipse (x-radius y-radius):\n");
  scanf("%d%d", &r.x, &r.y);
  printf("Programmed By Rabin Acharya.\n");
  mid_point_ellipse(c, r);
  delay(30000);
  closegraph();

  return 0;
}
