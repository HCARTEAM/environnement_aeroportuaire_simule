MAKEFLAGS =--no-print-directory
SHELL := /bin/bash
CMAKE_BUILD_DIRECTORY := project-build
CMAKE_PLUGINS_DIRECTORY := plugins

.PHONY: compile build clearall clean clean-build

all: compile

compile: |build
	cd $(CMAKE_BUILD_DIRECTORY) && $(MAKE) $(MAKEFLAGS)

$(CMAKE_BUILD_DIRECTORY):
	mkdir $(CMAKE_BUILD_DIRECTORY) && 	source ./env-install.sh

build: |$(CMAKE_BUILD_DIRECTORY)
	cd ./$(CMAKE_BUILD_DIRECTORY) &&	cmake ../project-sources -DCMAKE_EXPORT_COMPILE_COMMANDS=1

clearall: clean clean-build

clean:
	cd $(CMAKE_BUILD_DIRECTORY) && $(MAKE) clean $(MAKEFLAGS)

clean-build:
	rm -rf $(CMAKE_BUILD_DIRECTORY)
	rm -rf $(CMAKE_PLUGINS_DIRECTORY)
