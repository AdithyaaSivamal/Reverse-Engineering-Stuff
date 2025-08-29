import hashlib
import string
import time
import sys  

# Read the hash from the file provided as argument
if len(sys.argv) < 2:
    print("Usage: python3 md5_cracker.py <hash_file>")
    sys.exit(1)

hash_file = sys.argv[1]
try:
    with open(hash_file, 'r') as f:
        target_hash = f.read().strip().lower()  # Stripw whitespace and makes lowercase
except FileNotFoundError:
    print(f"Error: File '{hash_file}' not found.")
    sys.exit(1)

# Charsets: lowercase letters (a-z) for A, special symbols for B (matching ?s in Hashcat/crunch)
letters = string.ascii_lowercase  # characters
symbols = string.punctuation      # special characters

start_time = time.time()
found = None
total_tried = 0

# Bruce force attack (nested) loop starts
for a1 in letters:
    for a2 in letters:
        for b1 in symbols:
            for b2 in symbols:
                candidate = a1 + a2 + "1234567" + b1 + b2
                md5 = hashlib.md5(candidate.encode('utf-8')).hexdigest()
                total_tried += 1
                if md5 == target_hash:
                    found = candidate
                    break
            if found: break
        if found: break
    if found: break

end_time = time.time()

if found:
    print(f"Cracked in {end_time - start_time:.2f} seconds after {total_tried} attempts!")
    print(f"Plaintext: {found}")
    print(f"A (two letters): {found[:2]}")
    print(f"B (two symbols): {found[-2:]}")
else:
    print("Not found - check hash, charsets, or if the symbols are limited.")
                                                                                                      
