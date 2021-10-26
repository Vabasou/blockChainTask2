run:
	g++ -o main main.cpp includes/block.cpp includes/blockchain.cpp includes/hash.cpp includes/record.cpp includes/RND.cpp includes/transaction.cpp includes/transactionPool.cpp includes/user.cpp includes/users.cpp includes/sha256.cpp

clear:
	del *.o *.exe 
