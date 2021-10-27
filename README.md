# blockChainTask2 V0.1

## Task

Create "central" blockchain and simulate the usage

1. Generate 1000 users, which should have those atributes:

- Name
- Public key
- Random balance

2. Generate 10000 transaction pool, which should have those atributes:

- Transaction ID
- Sender
- Receiver
- Transaction sum

3. Choose 100 random transactions from transaction pool and try to put it in new block.
4. Implement block mining function, which should have Proof-of-work algorithm.
5. After finding new block:

- Delete transactions, that were put in new block
- Execute transactions
- Add new block to the blockchain

6. Repeat 3-5 steps until there are no more transactions

---

## How to run the program

To compile the program, write in command line:
- On Windows ``` mingw32-make run ```
- On Linux, Mac OS ``` make run ```

To run the program, write in command line:
- On windows ``` ./main ```
- On Linux, Mac OS ``` ./main ```

---

## Operation of the program

- Generates users and assigns them random balance between 100 and 1000000. Data is saved in `results/usersBeginning.txt` file
- Generate random transaction pool. Data is saved in `results/poolBeggining.txt` file
- Start the loop:
    - Mine block which contains part of the transactions
    - If transactions are valid, put them inside the block
    - Delete transactions, that were put inside the block
    - Put block in the blockchain
    - Repeat cycle until the are no more transactions
- In the end there are created three more files:
    - `results/blocks.txt` to see mined blocks and their information
    - `results/poolEnding.txt` to see if the transaction pool is really empty
    - `results/usersEnding.txt` to see users info after transactions

