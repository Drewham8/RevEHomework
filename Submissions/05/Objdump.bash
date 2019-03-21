#!/bin/bash

objdump --no-show-raw-insn -M intel -d `ls /bin/*` | awk '{if ($2 !~ ":" && $2 != "data32" && $2 != "file" && $2 != "of" && length($2) > 0) {print $2}}' | sort >> Assembly_file
objdump --no-show-raw-insn -M intel -d `ls /sbin/*` | awk '{if ($2 !~ ":" && $2 != "data32" && $2 != "file" && $2 != "of" && length($2) > 0) {print $2}}' | sort >> Assembly_file
objdump --no-show-raw-insn -M intel -d `ls /lib/*` | awk '{if ($2 !~ ":" && $2 != "data32" && $2 != "file" && $2 != "of" && length($2) > 0) {print $2}}' | sort >> Assembly_file
objdump --no-show-raw-insn -M intel -d `ls /dev/*` | awk '{if ($2 !~ ":" && $2 != "data32" && $2 != "file" && $2 != "of" && length($2) > 0) {print $2}}' | sort >> Assembly_file

