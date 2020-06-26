#pragma once


typedef struct Point_t
{
    double x;
    double y;
}Point;

struct Point_t Point_create(double x,double y)
{
    struct Point_t ans;

    ans.x=x;
    ans.y=y;
    return  ans;
}

void Point_print(Point p)
{
    printf("(%lf, %lf)\n",p.x,p.y);
}


Point intersect2Lines(Point l1p1,Point l1p2,Point l2p1,Point l2p2)
{
    Point p;
    double nom=( l1p2.x * l1p1.y - l1p1.x * l1p2.y ) * ( l2p2.x-l2p1.x) -  ( l2p2.x * l2p1.y - l2p1.x * l2p2.y ) * ( l1p2.x -  l1p1.x );
    double denom=( l1p2.x -   l1p1.x ) * ( l2p2.y-l2p1.y) -  (   l2p2.x -   l2p1.x ) * ( l1p2.y -  l1p1.y );
    p.x=nom/denom;

    nom=( l1p2.x * l1p1.y - l1p1.x * l1p2.y ) * ( l2p2.y-l2p1.y) -  ( l2p2.x * l2p1.y - l2p1.x * l2p2.y ) * ( l1p2.y -  l1p1.y );

    p.y=nom/denom;

    return p;
}