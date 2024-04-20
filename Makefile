# PATHES
SRC_PATH = ./
SRC_ARITHEMTIC_PATH = ./arithmetic/
SRC_BIG_DECIMAL_PATH = ./big_decimal/
SRC_COMPARES_PATH = ./compares/
SRC_OTHERS_PATH = ./others/
SRC_CONVERTING_PATH = ./converting/

HDRS_PATH = ./
HDRS_ARITHEMTIC_PATH = ./arithmetic/
HDRS_BIG_DECIMAL_PATH = ./big_decimal/
HDRS_COMPARES_PATH = ./compares/
HDRS_OTHERS_PATH = ./others/
HDRS_CONVERTING_PATH = ./converting/

OBJ_PATH = ./obj/
OBJ_ARITHEMTIC_PATH = ./obj/arithmetic/
OBJ_BIG_DECIMAL_PATH = ./obj/big_decimal/
OBJ_COMPARES_PATH = ./obj/compares/
OBJ_OTHERS_PATH = ./obj/others/
OBJ_CONVERTING_PATH = ./obj/converting/

TEST_PATH = ./test/
TEST_ARITHEMTIC_PATH = ./test/arithmetic/
TEST_BIG_DECIMAL_PATH = ./test/big_decimal/
TEST_COMPARES_PATH = ./test/compares/
TEST_OTHERS_PATH = ./test/others/
TEST_CONVERTING_PATH = ./test/converting/

TEST_OBJ_PATH = ./obj/test/
TEST_OBJ_ARITHEMTIC_PATH = ./obj/test/arithmetic/
TEST_OBJ_BIG_DECIMAL_PATH = ./obj/test/big_decimal/
TEST_OBJ_COMPARES_PATH = ./obj/test/compares/
TEST_OBJ_OTHERS_PATH = ./obj/test/others/
TEST_OBJ_CONVERTING_PATH = ./obj/test/converting/

TARGET_PATH = ./
GCOV_REPORT_PATH = ./gcov_report/

# TARGETS
TARGET = decimal.a
TARGET_TEST = test.out
TARGET_GCOV = gcov_report.out

# COMPILE
CC_STANDART = -std=c11
CC_FLAGS = -Wall -Wextra -Werror
CC = gcc $(CC_STANDART) $(CC_FLAGS)

# SRC
SRC = $(wildcard $(SRC_PATH)*.c)
SRC_ARITHEMTIC = $(wildcard $(SRC_ARITHEMTIC_PATH)*.c)
SRC_BIG_DECIMAL = $(wildcard $(SRC_BIG_DECIMAL_PATH)*.c)
SRC_COMPARES = $(wildcard $(SRC_COMPARES_PATH)*.c)
SRC_OTHERS = $(wildcard $(SRC_OTHERS_PATH)*.c)
SRC_CONVERTING = $(wildcard $(SRC_CONVERTING_PATH)*.c)

# HDRS
HDRS = $(wildcard $(HDRS_PATH)*.h)
HDRS_ARITHEMTIC = $(wildcard $(HDRS_ARITHEMTIC_PATH)*.h)
HDRS_BIG_DECIMAL = $(wildcard $(HDRS_BIG_DECIMAL_PATH)*.h)
HDRS_COMPARES = $(wildcard $(HDRS_COMPARES_PATH)*.h)
HDRS_OTHERS = $(wildcard $(HDRS_OTHERS_PATH)*.h)
HDRS_CONVERTING = $(wildcard $(HDRS_CONVERTING_PATH)*.h)

# OBJ
OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))
OBJ_ARITHEMTIC = $(patsubst $(SRC_ARITHEMTIC_PATH)%.c, $(OBJ_ARITHEMTIC_PATH)%.o, $(SRC_ARITHEMTIC))
OBJ_BIG_DECIMAL = $(patsubst $(SRC_BIG_DECIMAL_PATH)%.c, $(OBJ_BIG_DECIMAL_PATH)%.o, $(SRC_BIG_DECIMAL))
OBJ_COMPARES = $(patsubst $(SRC_COMPARES_PATH)%.c, $(OBJ_COMPARES_PATH)%.o, $(SRC_COMPARES))
OBJ_OTHERS = $(patsubst $(SRC_OTHERS_PATH)%.c, $(OBJ_OTHERS_PATH)%.o, $(SRC_OTHERS))
OBJ_CONVERTING = $(patsubst $(SRC_CONVERTING_PATH)%.c, $(OBJ_CONVERTING_PATH)%.o, $(SRC_CONVERTING))

# TESTS
TEST_SRC = $(wildcard $(TEST_PATH)*.c)
TEST_SRC_ARITHMETIC = $(wildcard $(TEST_ARITHEMTIC_PATH)*.c)
TEST_SRC_BIG_DECIMAL = $(wildcard $(TEST_BIG_DECIMAL_PATH)*.c)
TEST_SRC_COMPARES = $(wildcard $(TEST_COMPARES_PATH)*.c)
TEST_SRC_OTHERS = $(wildcard $(TEST_OTHERS_PATH)*.c)
TEST_SRC_CONVERTING = $(wildcard $(TEST_CONVERTING_PATH)*.c)

TEST_HDRS = $(wildcard $(TEST_PATH)*.h)
TEST_HDRS_ARITHMETIC = $(wildcard $(TEST_ARITHEMTIC_PATH)*.h)
TEST_HDRS_BIG_DECIMAL = $(wildcard $(TEST_BIG_DECIMAL_PATH)*.h)
TEST_HDRS_COMPARES = $(wildcard $(TEST_COMPARES_PATH)*.h)
TEST_HDRS_OTHERS = $(wildcard $(TEST_OTHERS_PATH)*.h)
TEST_HDRS_CONVERTING = $(wildcard $(TEST_CONVERTING_PATH)*.h)

TEST_OBJ = $(patsubst $(TEST_PATH)%.c, $(TEST_OBJ_PATH)%.o, $(TEST_SRC))
TEST_OBJ_ARITHEMTIC = $(patsubst $(TEST_ARITHEMTIC_PATH)%.c, $(TEST_OBJ_ARITHEMTIC_PATH)%.o, $(TEST_SRC_ARITHMETIC))
TEST_OBJ_BIG_DECIMAL = $(patsubst $(TEST_BIG_DECIMAL_PATH)%.c, $(TEST_OBJ_BIG_DECIMAL_PATH)%.o, $(TEST_SRC_BIG_DECIMAL))
TEST_OBJ_COMPARES = $(patsubst $(TEST_COMPARES_PATH)%.c, $(TEST_OBJ_COMPARES_PATH)%.o, $(TEST_SRC_COMPARES))
TEST_OBJ_OTHERS = $(patsubst $(TEST_OTHERS_PATH)%.c, $(TEST_OBJ_OTHERS_PATH)%.o, $(TEST_SRC_OTHERS))
TEST_OBJ_CONVERTING = $(patsubst $(TEST_CONVERTING_PATH)%.c, $(TEST_OBJ_CONVERTING_PATH)%.o, $(TEST_SRC_CONVERTING))

# LIBS
UNAME_S := $(shell uname -s)
LIBS_CHECK = -lcheck
ifeq ($(UNAME_S), Linux)
	LIBS_CHECK += -lrt -lpthread -lsubunit -lm
endif

all : gcov_report

$(TARGET) : check-forders clang-format $(OBJ) $(OBJ_ARITHEMTIC) $(OBJ_BIG_DECIMAL) $(OBJ_COMPARES) $(OBJ_OTHERS) $(OBJ_CONVERTING)
	ar rc $(TARGET_PATH)$(TARGET) $(OBJ) $(OBJ_ARITHEMTIC) $(OBJ_BIG_DECIMAL) $(OBJ_COMPARES) $(OBJ_OTHERS) $(OBJ_CONVERTING)

test : $(TARGET) $(TEST_OBJ) $(TEST_OBJ_ARITHEMTIC) $(TEST_OBJ_BIG_DECIMAL) $(TEST_OBJ_COMPARES) $(TEST_OBJ_OTHERS) $(TEST_OBJ_CONVERTING)
	$(CC) $(TEST_OBJ) $(TEST_OBJ_ARITHEMTIC) $(TEST_OBJ_BIG_DECIMAL) $(TEST_OBJ_COMPARES) $(TEST_OBJ_OTHERS) $(TEST_OBJ_CONVERTING) $(TARGET) -o $(TARGET_PATH)$(TARGET_TEST) $(LIBS_CHECK)
	$(TARGET_PATH)$(TARGET_TEST)

gcov_report : test
	gcc $(CC_STANDART) $(CC_FLAGS) -I $(SRC_PATH) --coverage $(SRC) $(SRC_ARITHEMTIC) $(SRC_BIG_DECIMAL) $(SRC_COMPARES) $(SRC_OTHERS) $(SRC_CONVERTING) $(TEST_OBJ) $(TEST_OBJ_ARITHEMTIC) $(TEST_OBJ_BIG_DECIMAL) $(TEST_OBJ_COMPARES) $(TEST_OBJ_OTHERS) $(TEST_OBJ_CONVERTING) -o $(GCOV_REPORT_PATH)$(TARGET_GCOV) $(LIBS_CHECK)
	$(GCOV_REPORT_PATH)$(TARGET_GCOV)
	lcov -t "tests" -o $(GCOV_REPORT_PATH)gcov_test.info --no-external -c -d .
	genhtml -o $(GCOV_REPORT_PATH)report/ $(GCOV_REPORT_PATH)gcov_test.info

clean :
	rm -rf $(TARGET_PATH)$(TARGET) $(TARGET_PATH)$(TARGET_TEST) $(OBJ_PATH) $(GCOV_REPORT_PATH)

clang-format :
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i $(SRC) $(SRC_ARITHEMTIC) $(SRC_BIG_DECIMAL) $(SRC_COMPARES) $(SRC_OTHERS) $(SRC_CONVERTING)
	clang-format -i $(TEST_SRC) $(TEST_SRC_ARITHMETIC) $(TEST_SRC_BIG_DECIMAL) $(TEST_SRC_COMPARES) $(TEST_SRC_OTHERS) $(TEST_SRC_CONVERTING)
	clang-format -i $(HDRS) $(HDRS_ARITHEMTIC) $(HDRS_BIG_DECIMAL) $(HDRS_COMPARES) $(HDRS_OTHERS) $(HDRS_CONVERTING)
	clang-format -i $(TEST_HDRS) $(TEST_HDRS_ARITHMETIC) $(TEST_HDRS_BIG_DECIMAL) $(TEST_HDRS_COMPARES) $(TEST_HDRS_OTHERS) $(TEST_HDRS_CONVERTING)
	rm -rf .clang-format

rebuild : clean $(TARGET)

rebuild-test : clean test

rebuild-all : clean all

check-forders :
	if [ ! -d "$(OBJ_PATH)" ]; then mkdir $(OBJ_PATH); fi
	if [ ! -d "$(OBJ_ARITHEMTIC_PATH)" ]; then mkdir $(OBJ_ARITHEMTIC_PATH); fi
	if [ ! -d "$(OBJ_BIG_DECIMAL_PATH)" ]; then mkdir $(OBJ_BIG_DECIMAL_PATH); fi
	if [ ! -d "$(OBJ_COMPARES_PATH)" ]; then mkdir $(OBJ_COMPARES_PATH); fi
	if [ ! -d "$(OBJ_OTHERS_PATH)" ]; then mkdir $(OBJ_OTHERS_PATH); fi
	if [ ! -d "$(OBJ_CONVERTING_PATH)" ]; then mkdir $(OBJ_CONVERTING_PATH); fi
	if [ ! -d "$(TEST_OBJ_PATH)" ]; then mkdir $(TEST_OBJ_PATH); fi
	if [ ! -d "$(TEST_OBJ_ARITHEMTIC_PATH)" ]; then mkdir $(TEST_OBJ_ARITHEMTIC_PATH); fi
	if [ ! -d "$(TEST_OBJ_BIG_DECIMAL_PATH)" ]; then mkdir $(TEST_OBJ_BIG_DECIMAL_PATH); fi
	if [ ! -d "$(TEST_OBJ_COMPARES_PATH)" ]; then mkdir $(TEST_OBJ_COMPARES_PATH); fi
	if [ ! -d "$(TEST_OBJ_OTHERS_PATH)" ]; then mkdir $(TEST_OBJ_OTHERS_PATH); fi
	if [ ! -d "$(TEST_OBJ_CONVERTING_PATH)" ]; then mkdir $(TEST_OBJ_CONVERTING_PATH); fi
	if [ ! -d "$(GCOV_REPORT_PATH)" ]; then mkdir $(GCOV_REPORT_PATH); fi

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	$(CC) -c $< -o $@

$(OBJ_ARITHEMTIC_PATH)%.o : $(SRC_ARITHEMTIC_PATH)%.c
	$(CC) -c $< -o $@

$(OBJ_BIG_DECIMAL_PATH)%.o : $(SRC_BIG_DECIMAL_PATH)%.c
	$(CC) -c $< -o $@

$(OBJ_COMPARES_PATH)%.o : $(SRC_COMPARES_PATH)%.c
	$(CC) -c $< -o $@

$(OBJ_OTHERS_PATH)%.o : $(SRC_OTHERS_PATH)%.c
	$(CC) -c $< -o $@

$(OBJ_CONVERTING_PATH)%.o : $(SRC_CONVERTING_PATH)%.c
	$(CC) -c $< -o $@

$(TEST_OBJ_PATH)%.o : $(TEST_PATH)%.c
	$(CC) -c $< -o $@

$(TEST_OBJ_ARITHEMTIC_PATH)%.o : $(TEST_ARITHEMTIC_PATH)%.c
	$(CC) -c $< -o $@

$(TEST_OBJ_BIG_DECIMAL_PATH)%.o : $(TEST_BIG_DECIMAL_PATH)%.c
	$(CC) -c $< -o $@

$(TEST_OBJ_COMPARES_PATH)%.o : $(TEST_COMPARES_PATH)%.c
	$(CC) -c $< -o $@

$(TEST_OBJ_OTHERS_PATH)%.o : $(TEST_OTHERS_PATH)%.c
	$(CC) -c $< -o $@

$(TEST_OBJ_CONVERTING_PATH)%.o : $(TEST_CONVERTING_PATH)%.c
	$(CC) -c $< -o $@
