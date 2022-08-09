#!/usr/bin/env bash

build_path="./Build/"

if [ -e "${build_path}" ]; then 
	rm -r $build_path
fi

mkdir $build_path

cmake \
	-S ./Src \
	-B $build_path \
	-DCMAKE_BUILD_TYPE=$build_type

cmake --build $build_path