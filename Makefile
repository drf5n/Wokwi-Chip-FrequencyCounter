# SPDX-FileCopyrightText: © 2022 Uri Shaked <uri@wokwi.com>
# SPDX-License-Identifier: MIT

# Copied from https://github.com/wokwi/inverter-chip/blob/main/Makefile 
# per https://discord.com/channels/787627282663211009/954892209486966825/1274468132618244128
# modified for mac homebrew environment
# Followed https://00f.net/2019/04/07/compiling-to-webassembly-with-llvm-and-clang/ on Mac
#  
#SYSROOT = /tmp/wasi-libc
SYSROOT = /opt/wasi-libc


SOURCES = src/main.c
TARGET  = dist/chip.wasm

.PHONY: all
all: $(TARGET) dist/chip.json

.PHONY: clean
clean:
		rm -rf dist

dist:
		mkdir -p dist

$(TARGET): dist $(SOURCES) src/wokwi-api.h
	  clang --target=wasm32-unknown-wasi --sysroot $(SYSROOT) -nostartfiles -Wl,--import-memory -Wl,--export-table -Wl,--no-entry -Werror -o $(TARGET) $(SOURCES)

dist/chip.json: dist chip.json
	  cp chip.json dist

.PHONY: test
test:
	  cd test && arduino-cli compile -e -b arduino:avr:uno blink
