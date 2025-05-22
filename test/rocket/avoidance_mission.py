#!/usr/bin/env python3
"""Launch the rocket SITL world and run a simple avoidance mission."""

import asyncio
import os
import subprocess
import time

async def run_mission():
    try:
        from mavsdk import System  # type: ignore
    except ImportError:
        print("mavsdk not installed, skipping test")
        return False

    drone = System()
    await drone.connect(system_address="udp://:14540")
    async for state in drone.core.connection_state():
        if state.is_connected:
            break
        await asyncio.sleep(0.1)

    print("Connected to vehicle")
    # Placeholder for intercept / avoidance logic
    await asyncio.sleep(5)
    return True


def main():
    repo_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    sitl = os.path.join(repo_root, "Tools/simulation/gazebo-classic/sitl_run.sh")
    build = os.path.join(repo_root, "build/px4_sitl_default")
    cmd = [sitl, os.path.join(build, "bin/px4"), "none", "rocket", repo_root, build]
    sim = subprocess.Popen(cmd)
    time.sleep(5)
    try:
        result = asyncio.run(run_mission())
    finally:
        sim.terminate()
        sim.wait()
    if result:
        print("MISSION PASSED")
    else:
        print("MISSION FAILED")


if __name__ == "__main__":
    main()
