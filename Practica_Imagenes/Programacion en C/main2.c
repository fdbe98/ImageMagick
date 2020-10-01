
#include <stdio.h>
#include <stdlib.h>
#include <ImageMagick-6/wand/magick-wand.h>
#include <string.h>

#define NOM "imagen"
#define EXT ".png"

int main(int argc, char **argv) {

    MagickBooleanType status;
    MagickWand *magick_wand;
    MagickWand *c_wand;
    DrawingWand *d_wand;
    PixelWand *p_wand;
    magick_wand = NewMagickWand();
    MagickWandGenesis();
    p_wand = NewPixelWand();
    
    char nomfich[50], numero[10];

    int i, desp1 = 0, desp2 = 20, num = 0;

    for (i = 0; i < 10; i++) {

        PixelSetColor(p_wand, "white");
        d_wand = NewDrawingWand();
        // Crear imagen blanca 400x400

        MagickNewImage(magick_wand, 400, 400, p_wand);

        //Asignar, dibujar y colocar pixel azul

        PixelSetColor(p_wand, "blue");
        DrawSetFillColor(d_wand, p_wand);
        DrawRectangle(d_wand, desp1, desp1, desp2, desp2);
        
        //Desplazar posicion de pixeles
        desp1 += 20;
        desp2 += 20;

        MagickDrawImage(magick_wand, d_wand);

        //Guardar imagen

        strcat(nomfich, NOM);
        sprintf(numero, "%d", num);
        strcat(nomfich, numero);
        strcat(nomfich, EXT);
        MagickWriteImage(magick_wand, nomfich);
        printf("Creado fichero: %s\n", nomfich);
        memset(nomfich, 0, 50);
        num++;
    }

    return (0);
}
