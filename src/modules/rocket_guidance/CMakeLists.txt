px4_add_module(
    MODULE modules__rocket_guidance
    MAIN rocket_guidance
    SRCS
        rocket_guidance.cpp
        rocket_guidance_params.c
    DEPENDS
        px4_work_queue
)
