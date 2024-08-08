import os
import re

# Directory containing your C++ source files (you should pass this as an argument)
source_directory = "path/to/your/source/files"

# Regular expression to match class definitions inheriting from CORE::Behaviour
class_pattern = re.compile(r'class\s+(\w+)\s*:\s*public\s+CORE::Behaviour')

# This pattern checks if the registration code already exists
register_pattern = re.compile(r'static\s+Register<\w+>\s+\w+\(\w+\(\),\s*"\w+"\);')

def process_file(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    new_lines = []
    skip_next_line = False

    for i, line in enumerate(lines):
        if skip_next_line:
            skip_next_line = False
            continue

        class_match = class_pattern.search(line)
        if class_match:
            class_name = class_match.group(1)
            # Generate the registration code
            registration_code = f'static Register<{class_name}> {class_name}({class_name}(), "{class_name}");\n'
            
            # Check if the registration code already exists in the following line
            if i + 1 < len(lines) and register_pattern.search(lines[i + 1]):
                continue

            # Add the original class line and the registration code
            new_lines.append(line)
            new_lines.append(registration_code)

            skip_next_line = True
        else:
            new_lines.append(line)

    # Write the modified content back to the file
    with open(file_path, 'w') as file:
        file.writelines(new_lines)

def process_directory(directory):
    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith('.cpp') or file.endswith('.h'):  # Process only .cpp and .h files
                process_file(os.path.join(root, file))

if __name__ == "__main__":
    import sys
    if len(sys.argv) > 1:
        source_directory = sys.argv[1]
    process_directory(source_directory)
