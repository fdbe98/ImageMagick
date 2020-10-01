// https://www.imagemagick.org/api/magick-image.php
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ImageMagick-6/wand/magick-wand.h>
#include <ImageMagick-6/wand/drawing-wand.h>
#include <time.h>

/* Escribir el siguiente comando antes de ejercutar el programa!!!!
 cc -o main1 main1.c `pkg-config --cflags --libs MagickWand`
 */

int main(int argc, char** argv) {
    
    char nomfich[100],nnomfich[100],fecha[100];
    MagickBooleanType status;
    MagickWand *magick_wand;
    PixelWand *background;
    background = NewPixelWand();
    magick_wand = NewMagickWand();
    DrawingWand *drawing_wand;
    drawing_wand = NewDrawingWand();
    
    time_t rawtime = time(NULL);
    struct tm ptm = *localtime(&rawtime);
    
    
    sprintf(fecha,"%d/%02d/%02d",ptm.tm_year-100,ptm.tm_mon+1,ptm.tm_mday);
    printf("FECHA: %s",fecha);
        
    //NOMFICH
    strcpy(nomfich,argv[1]);

    status = MagickReadImage(magick_wand, nomfich);
    
    if (status){  //Read image
        printf("\nIMAGEN LEIDA");
        //ROTATE
        MagickRotateImage(magick_wand, background, 270);
        printf("\nIMAGEN ROTADA");
        //ESCRIBIR FECHA
        MagickAnnotateImage(magick_wand,drawing_wand,1,10,0,fecha);
        printf("\nIMAGEN ESCRITA");
        //RENAME & CREATE
        strcpy(nnomfich,"rotated_");
        strcat(nnomfich, nomfich);
        MagickWriteImage(magick_wand, nnomfich);
        printf("\nIMAGEN GUARDADA\n");

    }
    else if(!status)
        (void)fprintf(stderr, "\n%s: %s\n", "Nombre de imagen incorrecto",argv[1]);

  
    return (EXIT_SUCCESS);
}

