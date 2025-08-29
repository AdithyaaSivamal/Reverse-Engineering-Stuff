### Penetration Testing Report: Gift Voucher Code Cracking

This repository contains the files for a simulated CTF (Capture The Flag) exercise focused on exploiting a gift voucher service with a weak MD5 hashing implementation. The project includes a custom Python script used for a brute-force attack and a detailed report (`Q4.pdf`) documenting the entire process, from reconnaissance to post-exploitation.

---
NOTE: Original client_ID is masked, changed to 1234567

### Project Files

* **`md5_cracker.py`**: A Python script that brute-forces MD5 hashes using nested loops. [cite_start]This script was created to bypass memory allocation errors encountered with Hashcat on a resource-limited VM[cite: 78, 79].
* [cite_start]**`Q4.pdf`**: A comprehensive penetration test report outlining the methodology, findings, and recommendations for securing the vulnerable service[cite: 1, 2, 3, 4, 5, 6, 7, 8].
* [cite_start]**`hash.txt`**: A file containing the target MD5 hash, `b4188c1a03f5aeb46b2d6cc48609103b`[cite: 146].
* [cite_start]**`client_id.txt`**: A file containing the client ID, `1234567`, used to retrieve the voucher code[cite: 19].

---

### Methodology

The process followed these steps:

1.  [cite_start]**Reconnaissance**: An `nmap` UDP scan was used to identify the open port on the target VM, which was found to be `12435`[cite: 28, 40].
2.  [cite_start]**Exploitation**: `netcat` was used to send the client ID `1234567` to the discovered port, which returned the MD5 voucher code[cite: 61, 67]. [cite_start]The code obtained was `225f894b8c0275bf84f183818033198a`[cite: 67].
3.  [cite_start]**Cracking**: The MD5 hash was a concatenation of two lowercase letters (`A`), the client ID `1234567`, and two special symbols (`B`)[cite: 76]. [cite_start]The `md5_cracker.py` script was used to brute-force the hash, finding the plaintext `zf1234567"<` in 670,770 attempts[cite: 135, 154].

---

### Results and Verification

The `md5_cracker.py` script successfully cracked the hash, revealing the following components:

* [cite_start]**Plaintext**: `zf1234567"<`[cite: 135].
* [cite_start]**A (two letters)**: `zf`[cite: 136].
* [cite_start]**B (two symbols)**: `"<`[cite: 137].

[cite_start]The crack's accuracy was verified by hashing the plaintext with `md5sum`, which produced the exact target hash `b4188c1a03f5aeb46b2d6cc48609103b`[cite: 139, 140, 144]. [cite_start]This demonstrates the critical severity of using MD5 for sensitive data, as it is vulnerable to brute-force attacks[cite: 147, 148].
