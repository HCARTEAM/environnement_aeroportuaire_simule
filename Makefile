MAKEFLAGS =--no-print-directory
SHELL := /bin/bash

all: compile

compile:
	cd ./project-build && $(MAKE) $(MAKEFLAGS)

clean:
	cd ./project-build && $(MAKE) clean $(MAKEFLAGS)

build:
	source ./env-install.sh && cd ./project-build &&	cmake ../project-sources

clean-build: clean
	cd ./project-build &&	rm -rf *
