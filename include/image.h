#ifndef IMAGE_H
#define IMAGE_H

//DEFINITION DU TYPE PIXEL

typedef unsigned char pixel[3];

//DEFINITION DU TYPE IMAGE (taille arbitraire)

struct image {
    pixel* content;
    int h;
    int w;
};
typedef struct image image;

//DEFINITION DU TYPE DIRECTION

struct direction {
    int type;
    char d[4];
};
typedef struct direction dir;

//DEFINITION DU TYPE BORD

struct bord {
    int type;
    char b[2];
};
typedef struct bord bor;

//DEFINITION DU TYPE CODANT (luminosité pour clair, normal ou foncé)

struct codant {
    char couleur;
    char luminosite;
};
typedef struct codant codant;

/*
@requires dir type is correctly defined
@assigns nothing
@ensures dir type is returned
*/
dir init_dir();

/*
@requires bor type is correctly defined
@assigns nothing
@ensures bor type is returned
*/
bor init_bord();

/*
@requires f is a correctly defined image
@assigns nothing
@ensures f remains the same
*/
void print_array(image f);

/*
@requires pix is correctly defined pixel
@assigns nothing
@ensures a double is returned
*/
double luminance(pixel pix);

/*
@requires pix is a correctly defined pixel
@assigns nothing
@ensures a codant is returned
*/
codant pix_to_color(pixel pix);

/*
@requires pix is a correctly defined pixel
@assigns nothing
@ensures a char ('b' or 'p') is returned
*/
char pa_bl(pixel pix);

/*
@requires p1 and p2 are correctly defined pixels
@assigns nothing
@ensures 1 or 0 is returned
*/
int comp_pix(pixel p1, pixel p2);

#endif