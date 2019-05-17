/*-------------------------------------------------------------------------------------------------
| This file is distributed under the MIT License.
| See accompanying file /LICENSE for details.
| Author(s): Bruno Schmitt
*------------------------------------------------------------------------------------------------*/

#define FMT_HEADER_ONLY = true

#include "tweedledee/qasm/qasm.hpp"
#include "tweedledee/qasm/ast/visitor.hpp"

#include <fmt/color.h>
#include <fmt/format.h>
#include <iostream>

using namespace tweedledee::qasm;

int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cerr << "Input file not specified.\n";
	}
	auto program = read_from_file(argv[1]);
	if (program) {
	  ast_printer printer(std::cout);
	  printer.visit(*program);
	}
}
