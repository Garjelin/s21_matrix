CC = g++
FLAG_C = -c
FLAG_O = -o
ASAN = -g -fsanitize=address
FLAG_COV = --coverage
FLAG_ER = -Wall -Werror -Wextra -std=c++11
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
FLAG_TESTS = -lcheck -lm -lgcov -lsubunit -lgtest -lgtest_main

s21_MATRIX_C = s21_*.cpp
s21_MATRIX_O = s21_*.o
OUTDIR = BUILD
TESTDIR = TESTS
LIBDIR = S21_MATRIX_OOP_LIB
SUITE_CASES_CPP = suite_*.cpp
SUITE_CASES_O = suite_*.o

all: clean gcov_report

s21_matrix_oop.a:
	rm -rf BUILD
	mkdir BUILD
	for file in $(LIBDIR)/$(s21_MATRIX_C); do \
		$(CC) -c $(FLAG_ER)  $(FLAG_COV) -o $(OUTDIR)/$$(basename $$file .cpp).o $$file; \
	done

	ar rc $(OUTDIR)/s21_matrix_oop.a $(OUTDIR)/$(s21_MATRIX_O) -lm
	ranlib $(OUTDIR)/s21_matrix_oop.a

test: s21_matrix_oop.a
	for file in $(TESTDIR)/$(SUITE_CASES_CPP); do \
		$(CC) $(FLAG_C) $(FLAG_ER) $$file -o $(OUTDIR)/$$(basename $$file .cpp).o; \
	done
	$(CC) $(FLAG_ER) $(FLAG_COV) -o $(OUTDIR)/tests $(OUTDIR)/$(SUITE_CASES_O) $(OUTDIR)/s21_matrix_oop.a $(FLAG_TESTS)
	./$(OUTDIR)/tests

asan: s21_matrix_oop.a
	for file in $(TESTDIR)/$(SUITE_CASES_CPP); do \
		$(CC) $(FLAG_C) $(FLAG_ER) $$file -o $(OUTDIR)/$$(basename $$file .cpp).o; \
	done
	$(CC) $(FLAG_ER) $(FLAG_COV) -o $(OUTDIR)/tests $(OUTDIR)/$(SUITE_CASES_O) $(OUTDIR)/s21_matrix_oop.a $(FLAG_TESTS) $(ASAN)
	./$(OUTDIR)/tests

valgrind_test: s21_matrix_oop.a
	for file in $(TESTDIR)/$(SUITE_CASES_CPP); do \
		$(CC) $(FLAG_C) $(FLAG_ER) $$file -o $(OUTDIR)/$$(basename $$file .cpp).o -g; \
	done
	$(CC) $(FLAG_ER) $(FLAG_COV) -o $(OUTDIR)/tests $(OUTDIR)/$(SUITE_CASES_O) $(OUTDIR)/s21_matrix_oop.a $(FLAG_TESTS)
	valgrind $(VALGRIND_FLAGS) ./$(OUTDIR)/tests

gcov_report: test
	gcovr --html-details -o $(OUTDIR)/report.html

cpp_check:
	cppcheck --enable=all --force $(LIBDIR)/*.h $(LIBDIR)/*.cpp $(TESTDIR)/*.cpp

style_check:
	cp ../materials/linters/.clang-format ./
	clang-format -n $(LIBDIR)/*.h $(LIBDIR)/*.cpp $(TESTDIR)/*.cpp
	clang-format -i $(LIBDIR)/*.h $(LIBDIR)/*.cpp $(TESTDIR)/*.cpp
	rm -rf .clang-format

clean:
	-rm -rf BUILD
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt
	-rm -f tests
	-rm -f report
	find . -type d -name 'tests.dSYM' -exec rm -r {} +
