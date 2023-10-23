import re
import os

def move_minus_inside_parentheses(input_str):
    # Define a regular expression pattern to find the minus outside the parentheses
    pattern = r'-SIMDE_FLOAT16_VALUE\(( *)([0-9]*).([0-9]*)\)'

    def replace_minus(match):
        # Extract the minus sign and the number inside parentheses
        whitespace = match.group(1)
        numberint = match.group(2)
        numberfrac = match.group(3)
        # Reconstruct the string with the minus inside parentheses
        return f' SIMDE_FLOAT16_VALUE({whitespace[:-1]}-{numberint}.{numberfrac})'

    # Use re.sub to find and replace the pattern
    output_str = re.sub(pattern, replace_minus, input_str)

    return output_str

# Test the function with your example
input_str = "-SIMDE_FLOAT16_VALUE(   30.21)"
output_str = move_minus_inside_parentheses(input_str)
print(output_str)

# Get a list of all *.c files in the current directory
c_files = [file for file in os.listdir() if file.endswith('.c')]

for file in c_files:
    with open(file, 'r') as f:
        content = f.read()

    modified_content = move_minus_inside_parentheses(content)

    with open(file, 'w') as f:
        f.write(modified_content)

    print(f"Processed file: {file}")

print("All *.c files have been processed.")
