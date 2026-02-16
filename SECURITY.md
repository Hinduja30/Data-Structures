# Security Policy

## Supported Versions

As this is an educational repository for Data Structures and Algorithms, security updates are prioritized for the most recent implementations on the `main` branch.

| Version | Supported          |
| ------- | ------------------ |
| Main    | :white_check_mark: |
| < 1.0   | :x:                |

## Reporting a Vulnerability

I take the security of these implementations seriously, especially regarding memory management and edge-case handling. If you find a security vulnerability (e.g., a buffer overflow or a memory leak), please follow the steps below:

1. **Do not open a public issue** for security-related bugs.
2. Email me directly at **[INSERT_YOUR_EMAIL_HERE]**.
3. Provide a brief description of the vulnerability and, if possible, a small code snippet to reproduce the issue.

### Response Timeline
* **Acknowledgement:** Within 48 hours.
* **Status Updates:** Every 3–5 days until a fix is pushed.
* **Public Disclosure:** Once a fix is merged, I will credit you in the commit history (optional).

## Secure Coding Standards
This repository aims to follow best practices to prevent common vulnerabilities:
* **Bounds Checking:** Ensuring array indices are validated.
* **Memory Safety:** Using smart pointers or proper `delete`/`free` calls to prevent leaks.
* **Input Validation:** Hardening data structure methods against invalid or malicious inputs.
