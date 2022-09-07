#include <iostream>
#include <string>
#include <cstring>

struct foo {
    int * p;
};

auto main() -> int {
    int i1;
    int i2 {};
    int * pi1 {new int};
    int * pi2 {new int {}};

    printf("%d\n%d\n%d\n%d\n", i1, i2, *pi1, *pi2);

    foo f1;
    foo f2 {};
    foo * pf1 {new foo};
    foo * pf2 {new foo{}};

    printf("%p\n%p\n%p\n%p\n", f1.p, f2.p, pf1->p, pf2->p);
    
    return 0;
}