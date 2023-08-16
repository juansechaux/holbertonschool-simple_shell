#!/bin/bash
pid_max=$(cat /proc/sys/kernel/pid_max)
echo "El valor máximo de PID es $pid_max"
