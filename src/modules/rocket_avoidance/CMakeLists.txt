px4_add_module(
    MODULE modules__rocket_avoidance
    MAIN rocket_avoidance
    SRCS
        rocket_avoidance.cpp
        rocket_avoidance_params.c
    DEPENDS
        px4_work_queue
)
