#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cyaml/cyaml.h"

int initExpectations(const char* suite);

const char** getExpectedResult(char* testName);

void freeExpectations(void);
