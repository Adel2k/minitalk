Awesome — let’s enhance your README with a clean, beginner-friendly **How It Works** section explaining the bitwise transmission via signals. Here’s your updated `README.md` with that added in:

---

````md
# 📡 minitalk

A small data exchange project written in C for 42 School. It enables interprocess communication using UNIX signals to transmit messages from a client process to a server process, one bit at a time.

---

## 📖 Table of Contents

- [About](#about)
- [Usage](#usage)
- [Compilation](#compilation)
- [How It Works](#how-it-works)
- [Example](#example)
- [Structure](#structure)
- [Limitations](#limitations)
- [Author](#author)

---

## 📌 About

**minitalk** is a communication program that allows a **client** to send a string message to a **server** process via **UNIX signals** (`SIGUSR1` and `SIGUSR2`).  
Each character is sent bit by bit, where:

- `SIGUSR1` represents a binary `1`
- `SIGUSR2` represents a binary `0`

The server reconstructs the message as it receives the signals.

---

## ⚙️ Usage

Both the server and the client must be running on the same machine.

### Start the server:
```bash
./server
````

It will print its **PID**:

```
Server PID: 12345
```

### Send a message from the client:

```bash
./client [server_pid] [message]
```

Example:

```bash
./client 12345 "Hello World"
```

---

## 🛠️ Compilation

To compile both server and client:

```bash
make
```

Clean object files:

```bash
make clean
```

Remove binaries and object files:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

---

## ⚙️ How It Works

The communication between client and server is done through **UNIX signals**:

* Each character is converted into its **binary ASCII value**.
* The **client sends 8 signals per character**:

  * `SIGUSR1` for a binary `1`
  * `SIGUSR2` for a binary `0`
* The **server has a signal handler** that listens for these signals and rebuilds the character by shifting bits into a byte.

### 📑 Example:

If the client wants to send character `A`:

* ASCII of `A` → 65 → `01000001` in binary.
* The client sends:

  * `SIGUSR2` (0)
  * `SIGUSR1` (1)
  * `SIGUSR2` (0)
  * `SIGUSR2` (0)
  * `SIGUSR2` (0)
  * `SIGUSR2` (0)
  * `SIGUSR2` (0)
  * `SIGUSR1` (1)

The server reconstructs this stream of bits back into the character `A`.

---

## 📊 Example

Terminal 1:

```bash
./server
```

Output:

```
Server PID: 43122
```

Terminal 2:

```bash
./client 43122 "42 is awesome!"
```

Server will display:

```
42 is awesome!
```

---

## 📂 Structure

```
.
├── Makefile
├── server.c         # Server-side program
├── client.c         # Client-side program
├── libft/           # Custom C library (if used)
├── includes/        # Header files
├── srcs/            # Project source files (if structured)
└── README.md
```

---

## ⚠️ Limitations

* Communication is limited to text strings.
* Only works locally on the same machine.
* Messages must be sent and handled sequentially.

---

## 👤 Author

**Adeline Eminian**
GitHub: [@Adel2k](https://github.com/Adel2k)

```

---

Would you like a **Bonus Ideas / Improvements** section as well? I can suggest a few fun upgrades you could optionally implement too. 🚀
```
