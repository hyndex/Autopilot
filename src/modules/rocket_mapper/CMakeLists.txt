px4_add_module(
    MODULE modules__rocket_mapper
    MAIN rocket_mapper
    SRCS
        rocket_mapper.cpp
        rocket_mapper_params.c
    DEPENDS
        px4_work_queue
)
