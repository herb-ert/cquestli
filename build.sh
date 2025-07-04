#!/bin/bash
set -e
mkdir -p build

echo "Building for Linux..."
gcc main.c item.c player.c -lncurses -o build/cquestli-linux

echo "Building for Windows..."
x86_64-w64-mingw32-gcc \
  -I./PDCurses-src \
  -DPDC_WIDE -DPDC_FORCE_UTF8 -D_XOPEN_SOURCE_EXTENDED=1 \
  main.c player.c item.c \
  PDCurses-src/wincon/libpdcurses.a \
  -lgdi32 -luser32 \
  -o build/cquestli-win.exe

echo "Build complete!"
