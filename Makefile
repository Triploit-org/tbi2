OBJ = TBI2.o
CC = g++

compile: $(OBJ)
	@echo "[CPP] Link tbi2...         |"
	@$(CC) -fpermissive -o tbi2 TBI2.o
	@echo "[CPP] Finished!            |"
	@echo "––––––––––––––––––––––––––––"
	@rm TBI2.o

TBI2.o:
	@clear
	@echo "––––––––––––––––––––––––––––"
	@echo "[CPP] Compile tbi2...      |"
	@$(CC) -c TBI2.cpp
	@echo "[CPP] Finished!            |"
	@echo "––––––––––––––––––––––––––––"

test: compile
	@echo "[MK] Running the TBI....   |"
	@echo "============================"
	@./tbi2
	@echo "============================"
	@echo "[MK] END                   |"
	@echo "––––––––––––––––––––––––––––"

install: compile
	@echo "[CP] tbi2 /bin/            |"
	@sudo cp tbi2 /bin/
	@echo [CP] Finished!             |
	@echo "[CP] END                   |"
	@echo "––––––––––––––––––––––––––––"
