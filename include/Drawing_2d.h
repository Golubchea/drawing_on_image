#pragma once



#include <Point.h>
#include <Pixel.h>
#include <Rectangle_2d.h>

#include <assert.h>


void setPixel(unsigned char* image,int x, int y,int width, int nchannels,struct Pixel_t p)
{
    assert(x<width);

    int indx=(y*width*nchannels)+x*nchannels;
    image[indx]=p.r;
    indx++;
    image[indx]=p.g;
    indx++;
    image[indx]=p.b;
    //  indx++;
    // image[indx]=p.a;
}

void strokePixel(unsigned char* image,int x, int y,Point window_size, int nchannels,struct Pixel_t p,int size)
{
    printf("x=%d \n",x);
    assert(x<window_size.x);
    assert(y<window_size.y);
    if(x<=window_size.x && y <=window_size.y)
    {
        for( int i=0 ;i<size;++i)
        {
            setPixel(image,x-i,y,(int)window_size.x,nchannels,p);
            setPixel(image,x,y-i,(int)window_size.x,nchannels,p);
        }

        for( int i=0 ;i<size;++i)
        {
            setPixel(image,x+i,y,(int)window_size.x,nchannels,p);
            setPixel(image,x,y+i,(int)window_size.x,nchannels,p);
        }
    }
    else
    {
        printf("can't stroke a cross in w h rectangle area\n");
    }
}

void strokeLine(unsigned char* image,Point p1,Point p2, Point window_size,Pixel color,int size,int channels)
{

    double  l1=(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y);
    l1=sqrt(l1);

    for(int i =0;i<l1;++i)
    {
        double x= p1.x+ i* (p2.x-p1.x)/l1;
        double y= p1.y+ i* (p2.y-p1.y)/l1;
        //printf(" x=%lf y=%lf  \n",x,y);
        setPixel(image,(int)x,   (int)y ,(int)window_size.x,channels,color);


    }

}




void drawAnswer(Rectangle_2d out,unsigned char * image,Point window_size, int channels, Pixel color_point, Pixel color_line, Pixel color_line2,int size)
{


    int x=(int)out.p0.x;
    int y=(int)out.p0.y;

    strokePixel(image,x,y,window_size,channels,color_point,size);

    x=(int)out.p1.x;
    y=(int)out.p1.y;
    strokePixel(image,x,y,window_size,channels,color_point,size);



    x=(int)out.p2.x;
    y=(int)out.p2.y;
    strokePixel(image,x,y,window_size,channels,color_point,size);

    x=(int)out.p3.x;
    y=(int)out.p3.y;
    strokePixel(image,x,y,window_size,channels,color_point,size);



    strokeLine(image,out.p0, out.p3,window_size,color_line,1,channels);
    strokeLine(image,out.p1, out.p2,window_size,color_line,1,channels);


    strokeLine(image,out.p0, out.p1,window_size, color_line2,1,channels);
    strokeLine(image,out.p3, out.p2,window_size, color_line2,1,channels);
}
