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
            build/path build/cycle build/cycle_pl build/wheel_pl
SOURCES = flower.c complete.c completebipartite.c \
          path.c cycle.c cycle_pl.c wheel_pl.c\
          Makefile COPYRIGHT.txt LICENSE.txt README.md

all: $(FACTORIES)

clean:
	rm -rf dist
	rm -rf build

build/flower: flower.c
	mkdir -p build
	${CC} $(CFLAGS) flower.c -o build/flower

build/complete: complete.c
	mkdir -p build
	${CC} $(CFLAGS) complete.c -o build/complete

build/completebipartite: completebipartite.c
	mkdir -p build
	${CC} $(CFLAGS) completebipartite.c -o build/completebipartite

build/path: path.c
	mkdir -p build
	${CC} $(CFLAGS) path.c -o build/path
	
build/cycle: cycle.c
	mkdir -p build
	${CC} $(CFLAGS) cycle.c -o build/cycle
	
build/cycle_pl: cycle_pl.c
	mkdir -p build
	${CC} $(CFLAGS) cycle_pl.c -o build/cycle_pl
	
build/wheel_pl: wheel_pl.c
	mkdir -p build
	${CC} $(CFLAGS) wheel_pl.c -o build/wheel_pl

sources: dist/graphfactories-sources.zip dist/graphfactories-sources.tar.gz

dist/graphfactories-sources.zip: $(SOURCES)
	mkdir -p dist
	zip dist/graphfactories-sources $(SOURCES)

dist/graphfactories-sources.tar.gz: $(SOURCES)
	mkdir -p dist
	tar czf dist/graphfactories-sources.tar.gz $(SOURCES)
	