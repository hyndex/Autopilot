px4_add_module(
    MODULE modules__rocket_planner
    MAIN rocket_planner
    SRCS
        rocket_planner.cpp
        rocket_planner_params.c
    DEPENDS
        px4_work_queue
)
