input_file = "uzp.c"
output_file = "output_file.txt"

inside_removed_block = False

with open(input_file, "r") as infile, open(output_file, "w") as outfile:
    for line in infile:
        if "#else" in line:
            inside_removed_block = True
        elif "#endif" in line and inside_removed_block:
            inside_removed_block = False
        elif not inside_removed_block:
            outfile.write(line)

