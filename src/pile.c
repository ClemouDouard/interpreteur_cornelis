#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "image.h"

/*
@requires nothing
@assigns nothing
@ensures an empty pile is returned
*/
pile empty_pile() {
    pile p;
    p.top = 0;
    
    return p;
}

/*
@requires p is correctly defined
@assigns val to p
@ensures val is on top of p
*/
void empile (pile* p, int val) {
   p->content[p->top] = val;
   p->top++; 
}

/*
@requires p is correctly defined
@assigns p's top value is removed
@ensures that value is returned if p is not NULL
*/
int depile_return(pile* p) {
    if (p->top>0) {
        int tete = p->content[p->top - 1];
        p->content[p->top - 1] = 0;
        p->top -= 1;
        
        return tete;
    }
    
    else return 0;
}

/*
@requires p is correctly defined
@assigns p's top value is removed if p is not NULL
@ensures nothing
*/
void depile(pile* p) {
    if (p->top>0) {
        p->content[p->top - 1] = 0;
        p->top -= 1;
    }
}

/*
@requires p is correctly defined
@assigns nothing
@ensures p stays the same
*/
void affi_pile(pile p) {
    for (int i=0; i<p.top; i++) printf("%d  ",p.content[p.top - i - 1]);
    printf("\n");
}

/*
@requires p is correctly defined
@assigns the 2 values on top of p gets added together
@ensures p's size decreases by one if p has at least two elements
*/
void plus(pile* p) {
    if (p->top>1) {
        int v1 = depile_return(p);
        int v2 = depile_return(p);
        empile(p,v1+v2);
    }
}

/*
@requires p is correctly defined
@assigns the difference of the 2 values on top of p is added to p
@ensures p's size decreases by one if p has at least two elements
*/
void moins(pile* p) {
    if (p->top>1) {
        int v1 = depile_return(p);
        int v2 = depile_return(p);
        empile(p,v2-v1);
    }
}

/*
@requires p is correctly defined
@assigns the product of the 2 values on top of p is added to p
@ensures p's size decreases by one if p has at least two elements
*/
void fois(pile* p) {
    if (p->top>1) {
        int v1 = depile_return(p);
        int v2 = depile_return(p);
        empile(p,v2*v1);
    }
}

/*
@requires p is correctly defined
@assigns the quotient of the 2 values on top of p is added to p
@ensures p's size decreases by one if p has at least two elements
*/
void divise(pile* p) {
    if (p->top>1) {
        int v1 = depile_return(p);
        int v2 = depile_return(p);
        if (v1 != 0) empile(p,v2/v1);
    }
}

/*
@requires p is correctly defined
@assigns the rest by the euclian division of the 2 values on top of p is added to p
@ensures p's size decreases by one if p has at least two elements
*/
void reste(pile* p) {
    if (p->top>1) {
        int v1 = depile_return(p);
        int v2 = depile_return(p);
        if (v1 != 0) empile(p,v2%v1);
    }
}

/*
@requires p is correctly defined
@assigns 1 or 0 to p
@ensures p's size stays the same
*/
void non(pile* p) {
    if (p->top>0) {
        int v = depile_return(p);
        if (v==0) empile(p,1);
        else empile(p,0);
    }
}

/*
@requires p is correctly defined
@assigns 1 or 0 to p
@ensures p's size stays the same
*/
void plus_grand(pile* p) {
    if (p->top>1) {
        int v1 = depile_return(p);
        int v2 = depile_return(p);
        if (v2>=v1) empile(p,1);
        else empile(p,0);
    }
}

/*
@requires p is correctly defined
@assigns di is changed
@ensures p's size decreases by one if p has at least one element
*/
void direction(pile* p, dir* di) {
    if (p->top>0) {
        int nb = depile_return(p);
        di->type = (di->type + nb)%4;//le type de direction est changé
    } 
}

/*
@requires p is correctly defined
@assigns bo is changed
@ensures p's size decreases by one if p has at least one element
*/
void bord(pile* p, bor* bo) {
    if (p->top>0) {
        int nb = depile_return(p);
        bo->type = (bo->type + nb)%2;//le type de bord est changé
    }
}

/*
@requires p is correctly defined
@assigns the value on top of p is added to p
@ensures p's size increases by one if p has at least one element
*/
void duplique(pile* p) {
    if (p->top>0) {
        int v = depile_return(p);
        empile(p,v);
        empile(p,v);
    }
}

/*
@requires p is correctly defined
@assigns different place for p's third value
@ensures p's size decreases by two if p has at least two elements
*/
void tourne(pile* p) {
    if (p->top>1) {
        int v1 = depile_return(p);
        int v2 = depile_return(p);

        if (p->top>v2 - 1) {//on vérifie qu'on peut aller à la profondeur souhaitée
            pile tmp = empty_pile();//pile qui va contenir les valeurs à remettre en place
            for (int i=0; i<v1; i++) {//le nombre de fois que l'on va tourner
                int sommet = depile_return(p);
                for (int j=0; j<v2-1; j++) empile(&tmp,depile_return(p));
                //on rempile les valeurs en commençant par celle qu'on voulait déplacer
                empile(p,sommet);
                for (int k=0; k<v2-1; k++) empile(p,depile_return(&tmp));
            }
        }
    }
}

/*
@requires p is correctly defined
@assigns an int of the stdin is added to p
@ensures p's size increases by one
*/
void in_nombre(pile* p) {
    int entier;
    scanf("%d", &entier);
    empile(p,entier);
}

/*
@requires p is correctly defined
@assigns the ASCII code of a char of the stdin is added to p
@ensures p's size increases by one
*/
void in_char(pile* p) {
    char caractere;
    scanf("%s", &caractere);
    int caractere_int = caractere;
    empile(p,caractere_int);
}

/*
@requires p is correctly defined
@assigns nothing
@ensures p's size decreases by one if p has at least one element
*/
void out_nombre(pile* p) {
    if (p->top>0) {
        int v = depile_return(p);
        printf("%d",v);
        fflush(stdout);
    }
}

/*
@requires p is correctly defined
@assigns nothing
@ensures p's size decreases by one if p has at least one element
*/
void out_char(pile* p) {
    if (p->top>0) {
        int v = depile_return(p);
        char c = v;
        printf("%c",c);
        fflush(stdout);
    }
}