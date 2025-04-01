#include <graphics.h>
#include <math.h>
#include <stdio.h>

#define PI 3.1415
#define DEG2RAD(x) ((x) * (PI / 180.0))

typedef struct {
  int x1, y1;
  int x2, y2;
} RECTANGLE;

void drawBeforeAfter(RECTANGLE *before, RECTANGLE *after) {
  setcolor(WHITE); // Original rectangle in white
  rectangle(before->x1, before->y1, before->x2, before->y2);

  setcolor(RED); // Transformed rectangle in red
  rectangle(after->x1, after->y1, after->x2, after->y2);
}

void translation(RECTANGLE *r) {
  int tx, ty;
  printf("Enter the translation factors (tx ty): ");

  if (scanf("%d %d", &tx, &ty) != 2) {
    printf("Invalid input! Please enter two integers.\n");
    return;
  }

  RECTANGLE before = *r; // Save original state

  r->x1 += tx;
  r->y1 += ty;
  r->x2 += tx;
  r->y2 += ty;

  drawBeforeAfter(&before, r);
}

void reflection(RECTANGLE *r) {
  int option;

  printf("-----------------------------\n");
  printf("Choose Reflection Axis:\n");
  printf("1. X-axis\n2. Y-axis\n");
  printf("-----------------------------\n");

  if (scanf("%d", &option) != 1) {
    printf("Invalid input! Please enter 1 or 2.\n");
    return;
  }

  RECTANGLE before = *r; // Save original state

  if (option == 1) {
    r->y1 = getmaxy() - r->y1;
    r->y2 = getmaxy() - r->y2;
  } else if (option == 2) {
    r->x1 = getmaxx() - r->x1;
    r->x2 = getmaxx() - r->x2;
  } else {
    printf("Invalid choice!\n");
    return;
  }

  drawBeforeAfter(&before, r);
}

void rotation(RECTANGLE *r) {
  int deg;
  printf("Enter the degree of rotation: ");

  if (scanf("%d", &deg) != 1) {
    printf("Invalid input! Please enter an integer.\n");
    return;
  }

  double rad = DEG2RAD(deg);
  int cx = (r->x1 + r->x2) / 2;
  int cy = (r->y1 + r->y2) / 2;

  int x1 = r->x1 - cx, y1 = r->y1 - cy;
  int x2 = r->x2 - cx, y2 = r->y1 - cy;
  int x3 = r->x2 - cx, y3 = r->y2 - cy;
  int x4 = r->x1 - cx, y4 = r->y2 - cy;

  RECTANGLE before = *r; // Save original state

  r->x1 = round(x1 * cos(rad) - y1 * sin(rad)) + cx;
  r->y1 = round(x1 * sin(rad) + y1 * cos(rad)) + cy;
  r->x2 = round(x2 * cos(rad) - y2 * sin(rad)) + cx;
  r->y2 = round(x2 * sin(rad) + y2 * cos(rad)) + cy;
  r->x2 = round(x3 * cos(rad) - y3 * sin(rad)) + cx;
  r->y2 = round(x3 * sin(rad) + y3 * cos(rad)) + cy;
  r->x1 = round(x4 * cos(rad) - y4 * sin(rad)) + cx;
  r->y1 = round(x4 * sin(rad) + y4 * cos(rad)) + cy;

  drawBeforeAfter(&before, r);
}

void scaling(RECTANGLE *r) {
  float sf;
  printf("Enter the scaling factor: ");

  if (scanf("%f", &sf) != 1 || sf <= 0) {
    printf("Invalid input! Please enter a positive number.\n");
    return;
  }

  int cx = (r->x1 + r->x2) / 2;
  int cy = (r->y1 + r->y2) / 2;

  RECTANGLE before = *r; // Save original state

  r->x1 = cx + round((r->x1 - cx) * sf);
  r->y1 = cy + round((r->y1 - cy) * sf);
  r->x2 = cx + round((r->x2 - cx) * sf);
  r->y2 = cy + round((r->y2 - cy) * sf);

  drawBeforeAfter(&before, r);
}

int main() {
  int gd = DETECT, gm;
  RECTANGLE r = {.x1 = 100, .y1 = 100, .x2 = 300, .y2 = 300};

  initgraph(&gd, &gm, (char *)"");
  rectangle(r.x1, r.y1, r.x2, r.y2);

  while (1) {
    int option;
    printf("Programmed By Rabin Acharya.\n");
    printf("-----------------------------\n");
    printf("Choose the 2D transformation operation\n");
    printf("1. Translation\n2. Reflection\n3. Rotation\n4. Scaling\n5. Exit\n");
    printf("-----------------------------\n");

    printf("Enter your choice: ");
    if (scanf("%d", &option) != 1) {
      printf("Invalid input! Please enter a number.\n");
      break;
    }

    switch (option) {
    case 1:
      translation(&r);
      break;
    case 2:
      reflection(&r);
      break;
    case 3:
      rotation(&r);
      break;
    case 4:
      scaling(&r);
      break;
    case 5:
      printf("Exiting program...\n");
      closegraph();
      return 0;
    default:
      printf("Invalid choice! Please enter a number between 1 and 5.\n");
    }
  }

  closegraph();
  return 0;
}
