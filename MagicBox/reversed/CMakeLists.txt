# Navigation scaffold only.
# The sources under src/ are Ghidra decompiler output: they have no original
# headers, no original types and no linkable runtime. This file exists so IDEs
# and code browsers can enumerate the reconstructed translation units, not to
# produce a firmware image.

cmake_minimum_required(VERSION 3.16)
project(makcu_reversed C)

file(GLOB_RECURSE RE_SOURCES CONFIGURE_DEPENDS "src/*/*.c")
add_custom_target(re_sources SOURCES ${RE_SOURCES})
