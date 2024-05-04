#include "Vrctor3.h"
#include "Doublevect.h"
#include "RingInfo.h"
#include "Complexvect.h"
#include "Testprog.h"
int main(){
    int m = 0;
    int op = 0;
    int opd = 0;
    int k = 0;
    while (m != 4) {
        printf("Введите тип данных с котороым хотите работать:\n1.Double\n2.Complex\n3.Протестировать программу.\n4.Завершить программу\n");
        if(scanf("%d", &m) == 1){
            if (m == 1){
                struct RingInfo* ringInfodouble = Create(sizeof(double), sumofdouble ,differenceofdouble, zerodouble, negativecomplex, productofcomplex, doubleunit);
                struct Vector3 *a = malloc(sizeof(struct Vector3));
                struct Vector3 *b = malloc(sizeof(struct Vector3));
                double x, y, z;
                printf("Введите координаты первого вектора:\n");
                if(scanf("%lf %lf %lf", &x, &y, &z) != 3){
                    getchar();
                    printf("Ошибка, попробуйте снова.\n");
                    break;
                }
                double x2, y2, z2;
                printf("Введите координаты второго вектора:\n");
                if(scanf("%lf %lf %lf", &x2, &y2, &z2) != 3){
                    getchar();
                    printf("Ошибка, попробуйте снова.\n");
                    break;
                }
                a->x = &x;
                a->y = &y;
                a->z = &z;
                b->x = &x2;
                b->y = &y2;
                b->z = &z2;
                a->ringInfo = ringInfodouble;
                b->ringInfo = ringInfodouble;
                printf("Выберите операцию:\n1.Сумма векторов\n2.Отрицательный вектор.\n3.Разность векторов.\n4.Скалярное произведение векторов\n5.Смешанное произведение векторов\n");
                opd = 0;
                if(scanf("%d", &opd) == 1){
                    if(opd == 1){
                        struct Vector3 *c = malloc(sizeof(struct Vector3));
                        c = Sumvect(a, b);
                        printf("%f %f %f\n", *(double*)c->x, *(double*)c->y, *(double*)c->z);
                        free(c);
                    } else if(opd == 2){
                        struct Vector3 *c = malloc(sizeof(struct Vector3));
                        c = Negativevect(a);
                        printf("%f %f %f\n", *(double*)c->x, *(double*)c->y, *(double*)c->z);
                        free(c);
                    } else if(opd == 3){
                        struct Vector3 *c = malloc(sizeof(struct Vector3));
                        c = Differencevect(a, b);
                        printf("%f %f %f\n", *(double*)c->x, *(double*)c->y, *(double*)c->z);
                        free(c);
                    } else if(opd == 4){
                        struct Vector3 *c = malloc(sizeof(struct Vector3));
                        c = Scalarproduct(a, b);
                        printf("%f\n", *(double*)c->x);
                        free(c);
                    } else if(opd == 5){
                        struct Vector3 *c = malloc(sizeof(struct Vector3));
                        c = Mixedproductvect(a, b);
                        printf("%f %f %f\n", *(double*)c->x, *(double*)c->y, *(double*)c->z);
                        free(c);
                    } else{
                        printf("Ошибка, попробуйте снова.\n");
                        getchar();
                    }
                }
                free(a);
                free(b);
                free(ringInfodouble);
            } else if(m == 2) {
                struct RingInfo* ringInfocomplex = Create(sizeof(struct compl), sumofcomplex, differenceofcomplex, zerocomplex, negativecomplex, productofcomplex, complexunit);
                // Создание векторов a1 и b1
                struct Vector3 *a1 = malloc(sizeof(struct Vector3));
                struct Vector3 *b1 = malloc(sizeof(struct Vector3));
                printf("Введите комплексный вектор:\n");
                struct compl x3, y3, z3;
                printf("Введите действительную и мнимую части x: ");
                if(scanf("%lf %lf", &(x3.a), &(x3.mn)) != 2){
                    getchar();
                    printf("Ошибка, попробуйте снова.\n");
                    break;
                }
                printf("Введите действительную и мнимую части y: ");
                if(scanf("%lf %lf", &(y3.a), &(y3.mn)) != 2){
                    getchar();
                    printf("Ошибка, попробуйте снова.\n");
                    break;
                }
                printf("Введите действительную и мнимую части z: ");
                if(scanf("%lf %lf", &(z3.a), &(z3.mn)) != 2){
                    getchar();
                    printf("Ошибка, попробуйте снова.\n");
                    break;
                }
                
                // Ввод комплексных чисел для вектора b1
                printf("Введите комплексный вектор:\n");
                struct compl x4, y4, z4;
                printf("Введите действительную и мнимую части x: ");
                if(scanf("%lf %lf", &(x4.a), &(x4.mn)) != 2){
                    getchar();
                    printf("Ошибка, попробуйте снова.\n");
                    break;
                }
                printf("Введите действительную и мнимую части y: ");
                if(scanf("%lf %lf", &(y4.a), &(y4.mn)) != 2){
                    getchar();
                    printf("Ошибка, попробуйте снова.\n");
                    break;
                }
                printf("Введите действительную и мнимую части z: ");
                if(scanf("%lf %lf", &(z4.a), &(z4.mn)) != 2){
                    getchar();
                    printf("Ошибка, попробуйте снова.\n");
                    break;
                }
                a1->x = &x3;
                a1->y = &y3;
                a1->z = &z3;
                b1->x = &x4;
                b1->y = &y4;
                b1->z = &z4;
                a1->ringInfo = ringInfocomplex;
                b1->ringInfo = ringInfocomplex;
                // Вычисление векторного произведения и вывод результата
                printf("Выберите операцию:\n1.Сумма векторов\n2.Отрицательный вектор.\n3.Разность векторов.\n4.Скалярное произведение векторов\n5.Смешанное произведение векторов\n");
                op = 0;
                if(scanf("%d", &op) == 1){
                    
                    if(op == 1){
                        struct Vector3 *c1 = Sumvect(a1, b1);
                        printf("%f + i * %f, %f + i * %f, %f + i * %f\n", ((struct compl*)c1->x)->a, ((struct compl*)c1->x)->mn, ((struct compl*)c1->y)->a, ((struct compl*)c1->y)->mn, ((struct compl*)c1->z)->a, ((struct compl*)c1->z)->mn);
                        free(c1);
                    } else if(op == 2){
                        struct Vector3 *c1 = Negativevect(a1);
                        printf("%f + i * %f, %f + i * %f, %f + i * %f\n", ((struct compl*)c1->x)->a, ((struct compl*)c1->x)->mn, ((struct compl*)c1->y)->a, ((struct compl*)c1->y)->mn, ((struct compl*)c1->z)->a, ((struct compl*)c1->z)->mn);
                        free(c1);
                    } else if(op == 3){
                        struct Vector3 *c1 = Differencevect(a1, b1);
                        printf("%f + i * %f, %f + i * %f, %f + i * %f\n", ((struct compl*)c1->x)->a, ((struct compl*)c1->x)->mn, ((struct compl*)c1->y)->a, ((struct compl*)c1->y)->mn, ((struct compl*)c1->z)->a, ((struct compl*)c1->z)->mn);
                        free(c1);
                    } else if(op == 4){
                        struct Vector3 *c1 = Scalarproduct(a1, b1);
                        printf("%f + i * %f\n", ((struct compl*)c1->x)->a, ((struct compl*)c1->x)->mn);
                        free(c1);
                    } else if(op == 5){
                        struct Vector3 *c1 = Mixedproductvect(a1, b1);
                        printf("%f + i * %f, %f + i * %f, %f + i * %f\n", ((struct compl*)c1->x)->a, ((struct compl*)c1->x)->mn, ((struct compl*)c1->y)->a, ((struct compl*)c1->y)->mn, ((struct compl*)c1->z)->a, ((struct compl*)c1->z)->mn);
                        free(c1);
                    } else{
                        printf("Ошибка, попробуйте снова.\n");
                    }
                    // Освобождение памяти
                    free(a1);
                    free(b1);
                    free(ringInfocomplex);
                }
            } else if(m == 3){
                k = 0;
                struct compl x3;
                struct compl y3;
                struct compl z3;
                struct compl x4;
                struct compl y4;
                struct compl z4;
                struct compl rx;
                struct compl ry;
                struct compl rz;
                if(testofdouble(5, 2, 8, 23, 11, 12, 28, 13, 20) == 0) k += 1;
                if(testofdouble(1, 1, 1, 1, 1, 1, 0, 0, 0) == 0) k += 1;
                if(testofdouble(3, 3, 3, 3, 3, 3, 27, 0, 0) == 0) k += 1;
                if(testofdouble(3, 5, 2, 5, 1, 3, 13, 1, -22) == 0) k += 1;
                if(testofdouble(3, 3, 3, 3, 3, 3, -3, -3, -3) == 0) k += 1;
                x3 = (struct compl) {2, 1};
                y3 = (struct compl) {2, 1};
                z3 = (struct compl) {2, 1};
                x4 = (struct compl) {2, 1};
                y4 = (struct compl) {2, 1};
                z4 = (struct compl) {2, 1};
                rx = (struct compl) {-2, -1};
                ry = (struct compl) {-2, -1};
                rz = (struct compl) {-2, -1};
                if(testofcomplex(x3, y3, z3, x4, y4, z4, rx, ry, rz) == 0) k += 1;
                x3 = (struct compl) {21, 34};
                y3 = (struct compl) {43, 67};
                z3 = (struct compl) {23, 54};
                x4 = (struct compl) {12, 45};
                y4 = (struct compl) {34, 32};
                z4 = (struct compl) {34, 32};
                rx = (struct compl) {33, 79};
                ry = (struct compl) {77, 99};
                rz = (struct compl) {57, 86};
                if(testofcomplex(x3, y3, z3, x4, y4, z4, rx, ry, rz) == 0) k += 1;
                x3 = (struct compl) {45, 43};
                y3 = (struct compl) {56, 21};
                z3 = (struct compl) {32, 87};
                x4 = (struct compl) {34, 22};
                y4 = (struct compl) {45, 87};
                z4 = (struct compl) {43, 21};
                rx = (struct compl) {5426, 4600};
                ry = (struct compl) {2520, 1827};
                rz = (struct compl) {1376, 1827};
                if(testofcomplex(x3, y3, z3, x4, y4, z4, rx, ry, rz) == 0) k += 1;
                
                if(k == 8){
                    printf("---Пройтено тестов %d из 8---\n", k);
                }
                
            }else if(m == 4){
                printf("Программа завершена.\n");
            } else {
                printf("Ошибка, попробуйте снова.\n");
            }
        }else{
            getchar();
            printf("Ошибка, попробуйте снова.\n");
        }
    }
    return 0;
}
