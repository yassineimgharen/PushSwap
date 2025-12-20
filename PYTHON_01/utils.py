def say_hello():
    print("Hello!")

print("This is top-level code.")

if __name__ == "__main__":
    print("This runs only if utils.py is executed directly.")
    say_hello()