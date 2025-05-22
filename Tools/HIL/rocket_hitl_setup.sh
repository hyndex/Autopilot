#!/usr/bin/env bash
# Configure a Pixhawk-6X board for Rocket HITL

SERIAL_DEVICE=${1:-/dev/ttyACM0}
SCRIPT_DIR=$(cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd)

# Example parameter setup for Pixhawk-6X with sensor stim rigs
${SCRIPT_DIR}/nsh_param_set.py --device ${SERIAL_DEVICE} --name SYS_AUTOSTART --value 4010 || true
${SCRIPT_DIR}/nsh_param_set.py --device ${SERIAL_DEVICE} --name CAL_GYRO0_ID --value 3000 || true
${SCRIPT_DIR}/nsh_param_set.py --device ${SERIAL_DEVICE} --name CAL_ACCEL0_ID --value 4000 || true
${SCRIPT_DIR}/nsh_param_set.py --device ${SERIAL_DEVICE} --name CAL_MAG0_ID --value 5000 || true

echo "Pixhawk-6X HITL configuration complete"
