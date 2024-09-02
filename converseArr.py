import sys

while 1:

    # Step 1: Read all input from the user
    input_data = sys.stdin.readline()

    # Step 2: Replace all occurrences of [] with {}
    modified_data = input_data.replace('[', '{')
    modified_data = modified_data.replace(']', '}')

    # Step 3: Print the modified input
    print(modified_data)