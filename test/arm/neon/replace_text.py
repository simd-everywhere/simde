import os
import fileinput

# Directory where you want to replace text in files
directory = os.getcwd()

# Text to search for and the replacement
search_text = "SIMDE_FLOAT16_C"
replace_text = "SIMDE_FLOAT16_VALUE"

# Iterate through all files in the directory
for root, _, files in os.walk(directory):
    for file in files:
        if file.endswith('.c') or file.endswith('.h'):  # Modify the extensions as needed
            file_path = os.path.join(root, file)
            with fileinput.FileInput(file_path, inplace=True) as file:
                for line in file:
                    print(line.replace(search_text, replace_text), end='')

print("Text replacement completed.")

