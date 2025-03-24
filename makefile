# Disabling this makes the results identical
SHELL = /bin/bash

default: create_folders clean
	gcc source/populateRoaFolder.c -o build/populateRoaFolder
	gcc source/makeCSV.c           -o build/makeCSV

	./build/populateRoaFolder    mtx/*
	./build/makeCSV mtxNames.csv mtx/*
	./build/makeCSV roaNames.csv roa/*

create_folders:
	mkdir -p build roa

clean:
	@$(RM) mtxNames.csv
	@$(RM) roaNames.csv
	@$(RM) build/*
	@$(RM) roa/*