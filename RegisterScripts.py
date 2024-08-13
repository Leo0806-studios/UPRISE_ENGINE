import os
import re

# Directory containing your C++ source files (you should pass this as an argument)
source_directory = "path/to/your/source/files"

# Regular expression to match class definitions inheriting from CORE::Behaviour
class_pattern = re.compile(r'class\s+(\w+)\s*:\s*public\s+CORE::Behaviour')

# This pattern checks if the registration code already exists
register_pattern = re.compile(r'static\s+Register<\w+>\s+\w+\(\w+\(\),\s*"\w+"\);')


def generate_guard_name(file_path):
    # Generate the guard name based on the filename (uppercase with underscores)
    filename = os.path.splitext(os.path.basename(file_path))[0]
    guard_name = f'_{filename.upper()}_REGISTER_'
    return guard_name

def process_file(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    new_lines = []
    registration_lines = []

    for i, line in enumerate(lines):
        new_lines.append(line)

        class_match = class_pattern.search(line)
        if class_match:
            class_name = class_match.group(1)
            # Generate the registration code
            registration_code = f'static Register<{class_name}> {class_name}_Register({class_name}(), "{class_name}");\n'
            
            # Check if the registration code already exists
            if any(register_pattern.search(l) for l in lines):
                continue

            # Store the registration code to append later
            registration_lines.append(registration_code)

    # Append the registration lines at the end of the file
    if registration_lines:
        guard_name = generate_guard_name(file_path)
        registration_block = [
            f'#ifndef {guard_name}\n',
            f'#define {guard_name}\n',
            *registration_lines,
            f'#endif // {guard_name}\n'
        ]
        new_lines.extend(registration_block)

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
