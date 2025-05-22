/****************************************************************************
 *
 *   Copyright (c) 2025 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/
/**
 * @file rover_mecanum_params.c
 *
 * Parameters defined by the Rover Mecanum module.
 */

/**
 * Wheel track
 *
 * @unit m
 * @min 0
 * @group Rover Mecanum
 */
PARAM_DEFINE_FLOAT(RM_WHEEL_TRACK, 0.0f);

/**
 * Max yaw rate at max throttle
 *
 * @unit m/s
 * @min 0
 * @group Rover Mecanum
 */
PARAM_DEFINE_FLOAT(RM_MAX_THR_YAW_R, 0.0f);

/**
 * Mission speed gain
 *
 * @min -1
 * @group Rover Mecanum
 */
PARAM_DEFINE_FLOAT(RM_MISS_SPD_GAIN, -1.0f);

/**
 * Course control threshold
 *
 * @unit rad
 * @min 0
 * @group Rover Mecanum
 */
PARAM_DEFINE_FLOAT(RM_COURSE_CTL_TH, 0.17f);

