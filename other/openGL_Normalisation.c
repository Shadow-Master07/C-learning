#include <stdio.h>
#include <quadmath.h>

/*
When compiling, we need to give the library name to
prevent it from erroring out
syntax
gcc openGL_Normalisation.c -o openGL_Normalisation.exe -l quadmath

-l is used to let the compiler know which standard library library
we are using, without that it is failing to look for that library
*/

typedef struct un_normalised_location
{
    int x;
    int y;
    int ScreenX;
    int ScreenY;

} UnLocation;

typedef struct normalised_location
{
    __float128 x;
    __float128 y;

} NorLocation;

__float128 normalise(int locus, int screenMax);

int main()
{
    UnLocation locus;
    NorLocation new;
    char bufferX[128];
    char bufferY[128];

    locus.ScreenX = 360;
    locus.ScreenY = 360;

    for (int i = 0; i <= locus.ScreenX; i++)
    {
        locus.x = i;
        locus.y = i;

        new.x = normalise(locus.x, locus.ScreenX);
        new.y = normalise(locus.y, locus.ScreenY);
        quadmath_snprintf(bufferX, 128, "%.102Qf", new.x); // Used to assign value to buffer as this is not a standard function of gcc, we assign it to another variable that is buffer with a format string of "%Qf" that is meant to represent quad math float format for large prevision values
        quadmath_snprintf(bufferY, 128, "%.102Qf", new.y); // Used to assign value to buffer as this is not a standard function of gcc, we assign it to another variable that is buffer with a format string of "%Qf" that is meant to represent quad math float format for large prevision values
        printf("x = %s \t y = %s\n", bufferX, bufferY);
    }
    return 0;
}

__float128 normalise(int locus, int screenMax)
{
    return (((__float128)(2 * locus) / (__float128)screenMax) - 1);
}
