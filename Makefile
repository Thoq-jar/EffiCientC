#
 # This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 #
 # Copyright (c) 2024 - Present Tristan
 #
 # Makefile for EffiCientC
 #
 # EffiCientC is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 # Thoq License for more details.
 #
 # You should have received a copy of the Thoq License
 # along with EffiCientC. If not, see <https://raw.githubusercontent.com/Thoq-jar/Thoq-License/main/License>.
#


# Define the compiler
CC = clang

# Define the C flags
CFLAGS = -Wall -Wextra -Wpedantic

# Define the directory containing the source files
SRCDIR := Effic Demo

# Define the directory containing the test files
TESTSDIR := Tests

# Define the output binary name for the application
APP_OUTPUTBIN = EfficDemo

# Define the output binary name for the tests
TEST_OUTPUTBIN = testing

# Compile all .c files into the APP_OUTPUTBIN
all: $(APP_OUTPUTBIN)

$(APP_OUTPUTBIN): $(SRCDIR:=/*.c)
	$(CC) $(CFLAGS) $^ -o $@

# Compile all .c files in TESTSDIR into the TEST_OUTPUTBIN
tests: $(TESTSDIR:=/*.c)
	$(CC) $(CFLAGS) $^ -o $(TEST_OUTPUTBIN)

# Run the compiled tests
test: tests
	./$(TEST_OUTPUTBIN)

clean:
	rm -f $(APP_OUTPUTBIN) $(TEST_OUTPUTBIN)
