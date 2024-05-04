#ifndef POINT_H
#define POINT_H

typedef struct {
    char mark[17];
    char name[21];
    int r;
} Point;
Point point_new(char mark[17], char name[21], int r);
void point_array_print(const Point *arr, int len,FILE*);
char *getmy(FILE*);
int point_cmp_1(const Point *p1, const Point *p2);
int point_cmp_2(const Point *p1, const Point *p2);
int point_cmp_3(const Point *p1, const Point *p2);
int point_cmp_1r(const Point *p1, const Point *p2);
int point_cmp_2r(const Point *p1, const Point *p2);
int point_cmp_3r(const Point *p1, const Point *p2);
void comb_sort(Point *cars, int len);
void sortvib(Point *cars, int len);
#endif
