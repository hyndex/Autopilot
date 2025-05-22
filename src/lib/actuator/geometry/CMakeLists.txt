px4_add_library(actuator_geometry
    rocket_fins.c
)

target_compile_options(actuator_geometry PRIVATE ${MAX_CUSTOM_OPT_LEVEL})
