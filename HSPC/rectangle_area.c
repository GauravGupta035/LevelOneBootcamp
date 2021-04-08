#include <stdio.h>
#include <math.h>

struct Rectangle
{
    float x1, y1, x2, y2, x3, y3, area;
};
typedef struct Rectangle Rect;

Rect input_one_coord()
{
    Rect rectangle;
    scanf("%f %f %f %f %f %f", &rectangle.x1, &rectangle.y1, &rectangle.x2, &rectangle.y2, &rectangle.x3, &rectangle.y3);

    return rectangle;
}

void input_n_coords(int n, Rect rectangles[n])
{
    for (int i = 0; i < n; i++)
        rectangles[i] = input_one_coord();
}

float compute_distance(float x1, float y1, float x2, float y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

float compute_area(float l, float b)
{
    return l * b;
}

void compute_one_rectangle(Rect *rectangle)
{
    float length = compute_distance(rectangle->x1, rectangle->y1, rectangle->x2, rectangle->y2);
    float breadth = compute_distance(rectangle->x2, rectangle->y2, rectangle->x3, rectangle->y3);
    float height = compute_distance(rectangle->x1, rectangle->y1, rectangle->x3, rectangle->y3);

    if (length > breadth && length > height)
        rectangle->area = compute_area(breadth, height);
    else if (breadth > length && breadth > height)
        rectangle->area = compute_area(length, height);
    else
        rectangle->area = compute_area(length, breadth);
}

void compute_n_rectangles(int n, Rect rectangles[n])
{
    for (int i = 0; i < n; i++)
        compute_one_rectangle(&rectangles[i]);
}

void output_one_rect(Rect rectangle)
{
    printf("Area of rectangle with vertices (%f,%f), (%f,%f), (%f,%f) is %.2f \n",rectangle.x1, rectangle.y1, rectangle.x2, rectangle.y2, rectangle.x3, rectangle.y3, rectangle.area);
}

void output_n_rect(int n, Rect rectangles[n])
{
    for (int i = 0; i < n; i++)
        output_one_rect(rectangles[i]);
}

int main()
{
    int n;
    scanf("%d", &n);
    Rect rectangles[n];
    input_n_coords(n, rectangles);
    compute_n_rectangles(n, rectangles);
    output_n_rect(n, rectangles);

    return 0;
}