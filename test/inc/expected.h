#include "cyaml/cyaml.h"

typedef struct ExpectedValue {
	char *value;
} ExpectedValue;

/* CYAML mapping schema fields array for the top level mapping. */
static const cyaml_schema_field_t top_mapping_schema[] = {
	CYAML_FIELD_STRING_PTR("name", CYAML_FLAG_POINTER, ExpectedValue, value, 0, CYAML_UNLIMITED),
    CYAML_FIELD_END
};

/* CYAML value schema for the top level mapping. */
static const cyaml_schema_value_t top_schema = {
	CYAML_VALUE_MAPPING(CYAML_FLAG_POINTER,
			ExpectedValue, top_mapping_schema),
};
