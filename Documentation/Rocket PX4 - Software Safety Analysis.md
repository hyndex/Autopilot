# Rocket PX4 – Software Safety Analysis

This document summarises the functional safety approach for the Rocket PX4 autopilot stack following the structure of MIL‑STD‑882E. It records the preliminary hazard analysis, safety requirements and verification strategy.

## 1. System Overview

Rocket PX4 is a modified PX4 firmware tailored for sub‑orbital sounding rockets and precision guided vehicles. The system manages ignition, ascent control, coast phase and precision terminal guidance.

## 2. Hazard Analysis Summary

| Hazard | Severity | Control | Verification |
| ------ | -------- | ------- | ------------ |
| SRM Over‑pressure | Catastrophic | `srm_manager` comparator triggers cutter charge if pressure > 0.85 of design burst. | Static‑fire test showing trip point |
| Radar blackout | Major | Maintain last valid obstacle map for 250 ms then coast inertially. | SIL fault‑injection |
| IMU clip (>±200 g) | Major | Dual IMU; EKF instance switch on saturation. | Sled drop test |

## 3. Safety Requirements

1. The autopilot shall detect solid rocket motor anomalies within 50 ms and command abort.
2. The obstacle avoidance pipeline shall fail‑safe to ballistic glide if map updates exceed 250 ms.
3. Dual‑IMU health monitoring shall command EKF fallback when clipping is detected.

## 4. Verification

Verification is performed via unit tests (`ctest`), software‑in‑the‑loop runs and hardware static‑fire campaigns. Pass criteria are defined in the Continuous Integration job and test manuals.

