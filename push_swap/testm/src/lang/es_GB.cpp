#include "complexity.hpp"

#include <iostream>

using namespace std;

const string getHelp() {
	string help;

	help += "\033[1mNAME\033[0m\n";
	help += "     \033[1mcomplexity\033[0m -- starting benchmark for push_swap\n";
	help += "\n";
	help += "\033[1mSYNOPSIS\033[0m\n";
	help += "     \033[1m./complexity\033[0m [\033[1m-hs\033[0m] [\033[1m-f\033[0m \033[4mfile\033[0m] \033[4mnumbers\033[0m \033[4miterations\033[0m [\033[4mgoal\033[0m] [\033[4mchecker\033[0m]\n";
	help += "\n";
	help += "\033[1mDESCRIPTION\033[0m\n";
	help += "     push_swap executable will be default searched from current and parent directory.\n";
	help += "     \n";
	help += "     Following options are available :\n";
	help += "     \n";
	help += "     \033[1m-v\033[0m, \033[1m--version\033[0m\n";
	help += "             Show version of tester.\n";
	help += "     \n";
	help += "     \033[1m-h\033[0m, \033[1m--help\033[0m\n";
	help += "             Show this help.\n";
	help += "     \n";
	help += "     \033[1m-s\033[0m, \033[1m--sorted\033[0m\n";
	help += "             Only pass sorted numbers to program.\n";
	help += "     \n";
	help += "     \033[1m-f\033[0m \033[4mpush_swap\033[0m, \033[1m--file\033[0m=\033[4mpush_swap\033[0m\n";
	help += "             Use \033[4mpush_swap\033[0m for push_swap executable.\n";
	return help;
}

void print_start(program_params params) {
	cout << "\033[97mStarting the test : \033[95m" << params.numbers << "\033[97m elements, \033[95m" << params.iterations << "\033[97m iterations\033[0m" << endl;
}

void print(program_params params, int done, int total, int best, int worst, int successful, int ok) {
	cout << "Peor = \033[31m" << (worst) << "\033[0m instructions" << endl;
	cout << "Mediana = \033[33m" << (total / done) << "\033[0m instructions" << endl;
	cout << "Mejor... = \033[36m" << (best) << "\033[0m instructions" << endl;
	if (params.objective.has_value())
		cout << "Objective = \033[94m" << (successful * 100 / done) << "\033[0m % under \033[94m" << (params.objective.value()) << "\033[0m (\033[91m" << (done - successful) << "\033[0m above)   " << endl;
	else
		cout << "Objective = enter a number as the third argument" << endl;
	if (params.checker.has_value())
		cout << "Precision = \033[97m" << (ok * 100 / done) << "\033[0m % OK (\033[91m" << (done - ok) << "\033[0m KO)   " << endl;
	else
		cout << "Precision = enter a tester as the fourth argument" << endl;
	cout << "\033[32m" << (done * 100 / params.iterations) << "\033[0m % effective" << endl;
}
