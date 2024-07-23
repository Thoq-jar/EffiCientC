#
 # This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 #
 # Copyright (c) 2024 - Present EffiCientC
 #
 # Makefile for EffiCientC
 #
 # make is better
 #
 # EffiCientC is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 # Thoq License for more details.
 #
 # You should have received a copy of the Thoq License
 # along with EffiCientC. If not, see
 # <https://raw.githubusercontent.com/Thoq-jar/Thoq-License/main/License>.
#

# I use clang and you will too
CC = clang

# C flags
CFLAGS = -Wall -Wextra -Wpedantic

# directory containing source files
SRCDIR := Effic Demo


# Define the output binary name for the application
APP_OUTPUTBIN = EfficDemo

# Compile all .c files into the APP_OUTPUTBIN
all: $(APP_OUTPUTBIN)

$(APP_OUTPUTBIN): $(SRCDIR:=/*.c)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(APP_OUTPUTBIN) $(TEST_OUTPUTBIN)
