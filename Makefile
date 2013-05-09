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

FACTORIES = flower
SOURCES = flower.c Makefile COPYRIGHT.txt LICENSE.txt README.md

all: $(FACTORIES)

clean:
	rm -f $(FACTORIES) graphfactories-sources.zip graphfactories-sources.tar.gz

flower: flower.c
	${CC} $(CFLAGS) flower.c -o flower

sources: graphfactories-sources.zip graphfactories-sources.tar.gz

graphfactories-sources.zip: $(SOURCES)
	zip graphfactories-sources $(SOURCES)

graphfactories-sources.tar.gz: $(SOURCES)
	tar czf graphfactories-sources.tar.gz $(SOURCES)
	