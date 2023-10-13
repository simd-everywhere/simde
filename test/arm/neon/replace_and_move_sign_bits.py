import os
import fileinput
import re

# Directory where you want to perform the replacements
directory = os.getcwd()

# Regular expression to match the pattern
pattern = r"-SIMDE_FLOAT16_VALUE\((\d+)"

# Iterate through all files in the directory
for root, _, files in os.walk(directory):
    for file in files:
        if file.endswith('.c') or file.endswith('.h'):  # Modify the extensions as needed
            file_path = os.path.join(root, file)
            with fileinput.FileInput(file_path, inplace=True) as file:
                for line in file:
                    line = re.sub(pattern, r"SIMDE_FLOAT16_VALUE( -\1", line)
                    print(line, end='')

print("Text replacement completed.")

