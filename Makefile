#
# Makefile for graphfactories
#
#
# Main developer: Nico Van Cleemput
# 
# Copyright (C) 2013 Ghent University.
# Licensed under the GNU GPL, read the file LICENSE.txt for details.
#

SHELL = /bin/sh

CC = gcc
CFLAGS = -O4 -Wall

FACTORIES = build/flower build/complete build/completebipartite \
            build/path build/cycle build/cycle_pl build/wheel_pl\
            build/subdivided_star build/regular_tree build/fatcomplete\
            build/fatcycle build/pearlchain build/flowersnark\
            build/petersen build/prism build/moebiusladder build/hypercube\
            build/kneser build/double_wheel_pl build/independent_set\
            build/linear_forest build/diminished_trapezohedron_pl
SOURCES = flower.c complete.c completebipartite.c \
          path.c cycle.c cycle_pl.c wheel_pl.c\
          subdivided_star.c regular_tree.c\
          fatcomplete.c fatcycle.c pearlchain.c\
          flowersnark.c petersen.c prism.c\
          moebiusladder.c hypercube.c\
          Makefile COPYRIGHT.txt LICENSE.txt README.md

all: $(FACTORIES)

clean:
	rm -rf dist
	rm -rf build

build/flower: flower.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@

build/complete: complete.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@

build/completebipartite: completebipartite.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@

build/path: path.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@
	
build/cycle: cycle.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@
	
build/cycle_pl: cycle_pl.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@
	
build/wheel_pl: wheel_pl.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@
	
build/double_wheel_pl: double_wheel_pl.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@

build/subdivided_star: subdivided_star.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@
	
build/regular_tree: regular_tree.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@
	
build/fatcomplete: fatcomplete.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@
	
build/fatcycle: fatcycle.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@
	
build/pearlchain: pearlchain.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@

build/flowersnark: flowersnark.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@
	
build/petersen: petersen.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@
	
build/prism: prism.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@
	
build/moebiusladder: moebiusladder.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@
	
build/hypercube: hypercube.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@
	
build/kneser: kneser.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@
	
build/independent_set: independent_set.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@
	
build/linear_forest: linear_forest.c shared/multicode_base.c shared/multicode_output.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@
	
build/diminished_trapezohedron_pl: diminished_trapezohedron_pl.c
	mkdir -p build
	${CC} $(CFLAGS) $^ -o $@

sources: dist/graphfactories-sources.zip dist/graphfactories-sources.tar.gz

dist/graphfactories-sources.zip: $(SOURCES)
	mkdir -p dist
	zip dist/graphfactories-sources $(SOURCES)

dist/graphfactories-sources.tar.gz: $(SOURCES)
	mkdir -p dist
	tar czf dist/graphfactories-sources.tar.gz $(SOURCES)
	