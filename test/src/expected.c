#include "../inc/expected.h"

typedef struct Result {
    const char* name;
    const char** results;
    unsigned int results_count;
} Result;

typedef struct Expectations {
    const Result* expected;
    unsigned int expected_count;
} Expectations;

static const cyaml_schema_value_t string_ptr_schema = {
    CYAML_VALUE_STRING(CYAML_FLAG_POINTER, char, 0, CYAML_UNLIMITED)
};

static const cyaml_schema_field_t result_fields_schema[] = {
    CYAML_FIELD_STRING_PTR("name", CYAML_FLAG_POINTER, Result, name, 0, CYAML_UNLIMITED),
    CYAML_FIELD_SEQUENCE("results", CYAML_FLAG_POINTER, Result, results, &string_ptr_schema, 0, CYAML_UNLIMITED),
    CYAML_FIELD_END
};

static const cyaml_schema_value_t result_schema = {
    CYAML_VALUE_MAPPING(CYAML_FLAG_DEFAULT, Result, result_fields_schema)
};

static const cyaml_schema_field_t expectations_fields_schema[] = {
    CYAML_FIELD_SEQUENCE("expected", CYAML_FLAG_POINTER, Expectations, expected, &result_schema, 0, CYAML_UNLIMITED),
    CYAML_FIELD_END
};

static const cyaml_schema_value_t expectations_schema = {
    CYAML_VALUE_MAPPING(CYAML_FLAG_POINTER, Expectations, expectations_fields_schema)
};

static const cyaml_config_t config = {
	.log_fn = cyaml_log,            /* Use the default logging function. */
	.mem_fn = cyaml_mem,            /* Use the default memory allocator. */
	.log_level = CYAML_LOG_WARNING, /* Logging errors and warnings only. */
};

static Expectations* expectations = NULL;

int initExpectations(const char* suite) {
    cyaml_err_t err;
    char* buf = calloc(1024, sizeof(char));
    sprintf(buf, PROJECT_ROOT_DIR "/data/expected/%s.yaml", suite);
    err = cyaml_load_file(buf, &config, &expectations_schema, (void**)&expectations, NULL);
    free(buf);
    if(err != CYAML_OK) {
        fprintf(stderr, "ERROR: %s\n", cyaml_strerror(err));
        return EXIT_FAILURE;
    }
    for(int i = 0; i < expectations->expected_count; i++) {
        
    }
    return EXIT_SUCCESS;
}

const char** getExpectedResult(char* testName) {
    for(int i = 0; i < expectations->expected_count; i++) {
        if(strcmp(testName, expectations->expected[i].name) == 0) {
            return expectations->expected[i].results;
        }
    } 
    return NULL;
}

void freeExpectations(void) {
    cyaml_free(&config, &expectations_schema, expectations, 0);
}
