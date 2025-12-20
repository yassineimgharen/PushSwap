#!/usr/bin/env python3

#you can move the script to another system
#python3 hello.py → “I know it’s Python, let me run it”
#./hello.py → “This is a program, run it with its intended interpreter”


# Running with python3 hello.py
# User types: python3 hello.py
#            │
#            ▼
# Linux/OS launches: python3 interpreter
#            │
#            ▼
# Python reads hello.py file
#            │
#            ▼
# Python executes the code inside the file
#            │
#            ▼
# Output: "Hello, world!"




# Running with ./hello.py (shebang + executable)
# User types: ./hello.py
#            │
#            ▼
# Linux/OS checks: Does file have execute permission?
#            │
#            ├─ No → Permission denied
#            └─ Yes → continue
#            │
#            ▼
# Linux/OS reads first line (shebang): #!/usr/bin/env python3
#            │
#            ▼
# OS launches interpreter: python3
#            │
#            ▼
# Python reads hello.py file
#            │
#            ▼
# Python executes the code
#            │
#            ▼
# Output: "Hello, world!"


print("Hello, world!")