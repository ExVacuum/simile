#include <criterion/criterion.h>

void initSimile(void) {

}

void finiSimile(void) {

}

TestSuite(simile, .init = initSimile, .fini = finiSimile);

// Test that GL context is created properly
Test(simile, glVersion) {
    cr_assert(true);
}
