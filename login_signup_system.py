import json
import os
import getpass

# File to store user data
USER_FILE = "users.json"

# Load users from JSON file
def load_users():
    if not os.path.exists(USER_FILE):
        return {}
    with open(USER_FILE, "r") as file:
        return json.load(file)

# Save users to JSON file
def save_users(users):
    with open(USER_FILE, "w") as file:
        json.dump(users, file, indent=4)

# Colored print
def cprint(text, color_code=32):
    print(f"\033[{color_code}m{text}\033[0m")

# Signup function
def signup():
    users = load_users()
    cprint("\n🎉 Create a New Account 🎉", 34)
    username = input("Enter a new username: ").strip()
    if username in users:
        cprint("⚠️ Username already exists!", 31)
        return
    password = getpass.getpass("Enter password: ").strip()
    confirm = getpass.getpass("Confirm password: ").strip()
    if password != confirm:
        cprint("❌ Passwords do not match!", 31)
        return
    users[username] = password
    save_users(users)
    cprint(f"✅ User '{username}' registered successfully!", 32)

# Login function
def login():
    users = load_users()
    cprint("\n🔐 Login to Your Account 🔐", 34)
    username = input("Enter username: ").strip()
    if username not in users:
        cprint("⚠️ Username does not exist!", 31)
        return
    password = getpass.getpass("Enter password: ").strip()
    if users[username] == password:
        cprint(f"🎊 Welcome back, {username}! 🎊", 32)
    else:
        cprint("❌ Incorrect password!", 31)

# Main menu
def main():
    while True:
        cprint("\n=== Login/Signup System ===", 36)
        print("1. Signup")
        print("2. Login")
        print("3. Exit")
        choice = input("Enter your choice: ").strip()
        if choice == "1":
            signup()
        elif choice == "2":
            login()
        elif choice == "3":
            cprint("👋 Goodbye! See you soon!", 33)
            break
        else:
            cprint("⚠️ Invalid choice! Try again.", 31)

if __name__ == "__main__":
    main()
