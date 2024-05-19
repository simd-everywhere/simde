# Makefile

# Define the directory to search for executables
DIR := build/test

# Define a shell command to find all executable files, excluding C/C++ files and directories
EXEC_FILES := $(shell find $(DIR) -type f -executable ! -name '*.c' ! -name '*.cpp' ! -name '*.h')

# Log file
LOG_FILE := test.mak.log

# Default target
all: run

# Target to run all executable files and log the output
run:
	@echo "Running executables in $(DIR)..." > $(LOG_FILE)
	@count=0; \
	@pass_count=0; \
	@fail_count=0; \
	for file in $(EXEC_FILES); do \
		echo "Executing $$file" | tee -a $(LOG_FILE); \
		$$file >> $(LOG_FILE) 2>&1; \
		case "$$?" in \
			0) echo "PASSED" | tee -a $(LOG_FILE); \
			   pass_count=$$((pass_count + 1)) ;; \
			*) echo "FAILED" | tee -a $(LOG_FILE); \
			   fail_count=$$((fail_count + 1)) ;; \
		esac; \
		echo ""; \
		echo "" >> $(LOG_FILE); \
		count=$$((count + 1)); \
	done; \
	echo "Total executables run: $$count" | tee -a $(LOG_FILE); \
	echo "Total passed: $$pass_count" | tee -a $(LOG_FILE); \
	echo "Total failed: $$fail_count" | tee -a $(LOG_FILE)

# Clean target (example, not strictly necessary for this task)
clean:
	@echo "Nothing to clean"