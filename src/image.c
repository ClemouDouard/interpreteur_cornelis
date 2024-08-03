#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"

/*
@requires dir type is correctly defined
@assigns nothing
@ensures dir type is returned
*/
dir init_dir() {
    dir di;
    di.type = 0; //l'est est la direction de départ
    di.d[0] = 'e'; di.d[1] = 's'; di.d[2] = 'o'; di.d[3] = 'n'; //les directions possibles

    return di;
}

/*
@requires bor type is correctly defined
@assigns nothing
@ensures bor type is returned
*/
bor init_bord() {
    bor bo;
    bo.type = 0; //bâbord est le bord de départ
    bo.b[0] = 'b'; bo.b[1] = 't'; //les bords possibles

    return bo;
}

/*
@requires pix is correctly defined pixel
@assigns nothing
@ensures a double is returned
*/
double luminance(pixel pix) {
    int p0 = pix[0]; int p1 = pix[1]; int p2 = pix[2]; //on converti en entier les caractères (cela renvoie leur code ascii)
    return 0.202*p0 + 0.707*p1 + 0.071*p2;
}

/*
@requires f is a correctly defined image
@assigns nothing
@ensures f remains the same
*/
void print_array(image f) {
    for (int i=0; i<f.h; i++) {
        for (int j=0; j<f.w; j++) {
            for (int k=0; k<3; k++) printf("%3d ",(f.content[f.w*i+j])[k]);
            printf("|");
        }
        printf("\n");
    }
}

/*
@requires pix is a correctly defined pixel
@assigns nothing
@ensures a codant is returned
*/
codant pix_to_color(pixel pix) {
    codant col;
    col.couleur = 'z'; col.luminosite = 'z'; //le code si la couleur n'est pas codante

    int p0 = pix[0]; int p1 = pix[1]; int p2 = pix[2]; //on converti en entier les caractères (cela renvoie leur code ascii)

    switch (p0) {
        case 255 : 
            switch (p1) {
                case 255 :
                    switch (p2) {
                        case 128 : col.couleur = 'j'; col.luminosite = 'c'; break;
                        case 0 : col.couleur = 'j'; col.luminosite = 'n'; break;
                    } break;
                case 128 :
                    switch (p2) {
                        case 255 : col.couleur = 'm'; col.luminosite = 'c'; break;
                        case 128 : col.couleur = 'r'; col.luminosite = 'c'; break;
                    } break;
                case 0 :
                    switch (p2) {
                        case 255 : col.couleur = 'm'; col.luminosite = 'n'; break;
                        case 0 : col.couleur = 'j'; col.luminosite = 'n'; break;
                    } break;
        } break;
        case 128 :
            switch (p1) {
                case 255 :
                    switch (p2) {
                        case 255 : col.couleur = 'c'; col.luminosite = 'c'; break;
                        case 128 : col.couleur = 'v'; col.luminosite = 'c'; break;
                    } break;
                case 128 :
                    switch (p2) {
                        case 255 : col.couleur = 'b'; col.luminosite = 'c'; break;
                        case 0 : col.couleur = 'j'; col.luminosite = 'f'; break;
                    } break;
                case 0 :
                    switch (p2) {
                        case 128 : col.couleur = 'm'; col.luminosite = 'f'; break;
                        case 0 : col.couleur = 'r'; col.luminosite = 'f'; break;
                    } break;
            } break;
        case 0 :
            switch (p1) {
                case 255 :
                    switch (p2) {
                        case 255 : col.couleur = 'c'; col.luminosite = 'n'; break;
                        case 0 : col.couleur = 'v'; col.luminosite = 'n'; break;
                    } break;
                case 128 :
                    switch (p2) {
                        case 128 : col.couleur = 'c'; col.luminosite = 'f'; break; 
                        case 0 : col.couleur = 'v'; col.luminosite = 'f'; break;
                    } break;
                case 0 :
                    switch (p2) {
                        case 255 : col.couleur = 'b'; col.luminosite = 'n'; break;
                        case 128 : col.couleur = 'b'; col.luminosite = 'f'; break;
                    } break;
            } break;
    }

    return col;
}

/*
@requires pix is a correctly defined pixel
@assigns nothing
@ensures a char ('b' or 'p') is returned
*/
char pa_bl(pixel pix) {
    double l = luminance(pix);
    if (l<128) return 'b'; //bloquant
    else return 'p'; //passant
}

/*
@requires p1 and p2 are correctly defined pixels
@assigns nothing
@ensures 1 or 0 is returned
*/
int comp_pix(pixel p1, pixel p2) {
    int c0 = p1[0]; int c1 = p1[1]; int c2 = p1[2]; //on converti en entier les caractères (cela renvoie leur code ascii)
    int d0 = p2[0]; int d1 = p2[1]; int d2 = p2[2]; //on converti en entier les caractères (cela renvoie leur code ascii)
    if (c0 == d0) {
        if (c1 == d1) {
            if (c2 == d2) return 1;
        }
    }
    return 0;
}