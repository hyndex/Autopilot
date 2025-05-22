px4_add_module(
    MODULE modules__srm_manager
    MAIN srm_manager
    SRCS
        srm_manager.cpp
        srm_manager_params.c
    DEPENDS
        px4_work_queue
)
