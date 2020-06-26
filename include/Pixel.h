#pragma once

typedef struct Pixel_t
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
}Pixel;

struct Pixel_t Pixel_create( unsigned char r,
                             unsigned char g,
                             unsigned char b,
                             unsigned char a)
{
    struct Pixel_t ans;

    ans.r=r;
    ans.g=g;
    ans.b=b;
    ans.a=a;
    return  ans;
}