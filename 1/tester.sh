#!/bin/bash

dev="redhue"

cat "/dev/${dev}"
echo 1 > "/dev/${dev}"

