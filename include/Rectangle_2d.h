#pragma once
#include <stdio.h>

#include <Point.h>

typedef struct Rectangle_2d_t
{
    Point p0;
    Point p1;
    Point p2;
    Point p3;
    double size;
}Rectangle_2d;

Rectangle_2d Rectangle_2d_create(Point p0,Point p1,Point p2,Point p3)
{
    Rectangle_2d ans;
    ans.p0=p0;
    ans.p1=p1;
    ans.p2=p2;
    ans.p3=p3;
    ans.size=0.0;
    return  ans;
}




Rectangle_2d readBIN(const char * path)
{
    FILE *f=fopen(path,"rb");
    if(f==NULL)
    {
        printf("unable to open: %s\n",path);
        perror(path);
    }
    Rectangle_2d a;
    fread(&a,sizeof (a),1,f);
    fclose(f);

    return a;
}





// запись структуры в файл
int Rectangle_2d_save(char * filename, Rectangle_2d  *p)
{
    FILE * fp;
    char *c;
    int size = sizeof(  Rectangle_2d ); // количество записываемых байтов

    if ((fp = fopen(filename, "wb")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    // устанавливаем указатель на начало структуры
    c = (char *)p;
    // посимвольно записываем в файл структуру
    for (int i = 0; i < size; i++)
    {
        putc(*c++, fp);
    }
    fclose(fp);
    return 0;
}

// загрузка из файла структуры
Rectangle_2d Rectangle_2d_load(char * filename,int height)
{
    FILE * fp;
    char *c;
    int i; // для считывания одного символа
    // количество считываемых байтов
    int size = sizeof(  Rectangle_2d );
    // выделяем память для считываемой структуры
    Rectangle_2d  * ptr = ( Rectangle_2d  *) malloc(size);

    if ((fp = fopen(filename, "rb")) == NULL)
    {
        perror("Error occured while opening file");
        Rectangle_2d out;
         return out;
    }

    // устанавливаем указатель на начало блока выделенной памяти
    c = (char *)ptr;
    // считываем посимвольно из файла
    while ((i = getc(fp))!=EOF)
    {
        *c = i;
        c++;
    }

    fclose(fp);
    Rectangle_2d out;
    out.p0=ptr->p0;
    out.p1=ptr->p1;
    out.p2=ptr->p2;
    out.p3=ptr->p3;


    out.p0.y=height-out.p0.y;
    out.p1.y=height-out.p1.y;
    out.p2.y=height-out.p2.y;
    out.p3.y=height-out.p3.y;

    free(ptr);
    return out;
}


void Rectangle_2d_print(Rectangle_2d d)
{
    Point_print(d.p0);
    Point_print(d.p1);
    Point_print(d.p2);
    Point_print(d.p3);
    printf("size: %lf \n",d.size);
}


