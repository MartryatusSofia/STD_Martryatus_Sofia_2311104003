#include <iostream>
#include "list.h"

using namespace std;

void createList(List &L) {
    first(L) = NULL;
}

address allocate(infotype x) {
    address p = new elmlist; 
    if (p != NULL) {
        info(p) = x;         
        next(p) = NULL;      
    }
    return p;                
}

void insertFirst(List &L, address P) {
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        address last = first(L);
        while (next(last) != NULL) {
            last = next(last);
        }
        next(last) = P;
    }
}

void printInfo(List L) {
    address p = first(L);
    while (p != NULL) {
        cout << info(p) << " ";
        p = next(p);
    }
    cout << endl;
}

address searchInfo(List L, infotype x) {
    address p = first(L);
    while (p != NULL && info(p) != x) {
        p = next(p);
    }
    return p;
}

void deleteLast(List &L, address &P) {
    if (first(L) != NULL) {
        if (next(first(L)) == NULL) {
            P = first(L);
            first(L) = NULL;
        } else {
            address prec = first(L);
            while (next(next(prec)) != NULL) {
                prec = next(prec);
            }
            P = next(prec);
            next(prec) = NULL;
        }
    }
}

void deleteAfter(List &L, address prec, address &P) {
    if (next(prec) != NULL) {
        P = next(prec);
        next(prec) = next(P);
    }
}
