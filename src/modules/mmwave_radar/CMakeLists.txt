px4_add_module(
    MODULE modules__mmwave_radar
    MAIN mmwave_radar
    SRCS
        mmwave_radar.cpp
        mmwave_radar_params.c
    DEPENDS
        px4_work_queue
)
