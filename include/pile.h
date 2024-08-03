#include "image.h"
#ifndef PILE_H
#define PILE_H

//DEFINITION DU TYPE PILE (la taille maximale étant prise arbitrairement, ici 5000)

struct pile {
    int content[5000];
    int top;  //taille
};
typedef struct pile pile;

/*
@requires nothing
@assigns nothing
@ensures an empty pile is returned
*/
pile empty_pile();

/*
@requires p is correctly defined
@assigns val to p
@ensures val is on top of p
*/
void empile(pile* p, int val);

/*
@requires p is correctly defined
@assigns p's top value is removed
@ensures that value is returned if p is not NULL
*/
int depile_return(pile* p);

/*
@requires p is correctly defined
@assigns p's top value is removed if p is not NULL
@ensures nothing
*/
void depile(pile* p);

/*
@requires p is correctly defined
@assigns nothing
@ensures p stays the same
*/
void affi_pile(pile p);

/*
@requires p is correctly defined
@assigns the 2 values on top of p gets added together
@ensures p's size decreases by one if p has at least two elements
*/
void plus(pile* p);

/*
@requires p is correctly defined
@assigns the difference of the 2 values on top of p is added to p
@ensures p's size decreases by one if p has at least two elements
*/
void moins(pile* p);

/*
@requires p is correctly defined
@assigns the product of the 2 values on top of p is added to p
@ensures p's size decreases by one if p has at least two elements
*/
void fois(pile* p);

/*
@requires p is correctly defined
@assigns the quotient of the 2 values on top of p is added to p
@ensures p's size decreases by one if p has at least two elements
*/
void divise(pile* p);

/*
@requires p is correctly defined
@assigns the rest by the euclian division of the 2 values on top of p is added to p
@ensures p's size decreases by one if p has at least two elements
*/
void reste(pile* p);

/*
@requires p is correctly defined
@assigns 1 or 0 to p
@ensures p's size stays the same
*/
void non(pile* p);

/*
@requires p is correctly defined
@assigns 1 or 0 to p
@ensures p's size stays the same
*/
void plus_grand(pile* p);

/*
@requires p is correctly defined
@assigns di is changed
@ensures p's size decreases by one if p has at least one element
*/
void direction(pile* p,dir* d);

/*
@requires p is correctly defined
@assigns bo is changed
@ensures p's size decreases by one if p has at least one element
*/
void bord(pile* p, bor* bo);

/*
@requires p is correctly defined
@assigns the value on top of p is added to p
@ensures p's size increases by one if p has at least one element
*/
void duplique(pile* p);

/*
@requires p is correctly defined
@assigns different place for p's third value
@ensures p's size decreases by two if p has at least two elements
*/
void tourne(pile* p);

/*
@requires p is correctly defined
@assigns an int of the stdin is added to p
@ensures p's size increases by one
*/
void in_nombre(pile* p);

/*
@requires p is correctly defined
@assigns the ASCII code of a char of the stdin is added to p
@ensures p's size increases by one
*/
void in_char(pile* p);

/*
@requires p is correctly defined
@assigns nothing
@ensures p's size decreases by one if p has at least one element
*/
void out_nombre(pile* p);

/*
@requires p is correctly defined
@assigns nothing
@ensures p's size decreases by one if p has at least one element
*/
void out_char(pile* p);

#endif