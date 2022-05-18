#include <criterion/criterion.h>
#include <simile/simile.hpp>

void initSimile(void) {

}

void finiSimile(void) {

}

TestSuite(simile, .init = initSimile, .fini = finiSimile);

Test(simile, hello) {
    simile::helloWorld();
    cr_assert(true);
}
